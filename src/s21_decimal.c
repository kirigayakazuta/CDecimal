#include "s21_decimal.h"

int get_bit_ldec(long_decimal dec, int pos) {
  int num_arr = pos / BITS_IN_UINT;
  int num_bit = pos % BITS_IN_UINT;
  int res = ((dec.mantisa[num_arr]) >> num_bit) & 1;
  return res;
}

void set_bit_ldec(long_decimal *dec, int pos, int new) {
  int num_arr = pos / BITS_IN_UINT;
  int num_bit = pos % BITS_IN_UINT;
  unsigned int mask = 1;
  if (new == 0)
    dec->mantisa[num_arr] &= ~(mask << num_bit);
  else
    dec->mantisa[num_arr] |= mask << num_bit;
}

int get_bit_dec(s21_decimal dec, int pos) {
  int num_arr = pos / BITS_IN_UINT;
  int num_bit = pos % BITS_IN_UINT;
  int res = ((dec.bits[num_arr]) >> num_bit) & 1;
  return res;
}

void set_bit_dec(s21_decimal *dec, int pos, int new) {
  int num_arr = pos / BITS_IN_UINT;
  int num_bit = pos % BITS_IN_UINT;
  unsigned int mask = 1;
  if (new == 0)
    dec->bits[num_arr] &= ~(mask << num_bit);
  else
    dec->bits[num_arr] |= mask << num_bit;
}

int find_sign(s21_decimal dec) {
  return get_bit_dec(dec, S21_DEC_MAX_BITS - 1);
}

void set_sign(s21_decimal *dec, int sign) {
  set_bit_dec(dec, S21_DEC_MAX_BITS - 1, sign);
}

int find_exp(s21_decimal dec) {
  int res = 0;
  for (int i = S21_DEC_EXP_FBIT; i <= S21_DEC_EXP_LBIT; i++)
    res += (1u << (i - S21_DEC_EXP_FBIT)) * get_bit_dec(dec, i);
  return res;
}

void zeroing_ldec(long_decimal *ldec) {
  for (int i = 0; i < LDEC_LEN; i++) ldec->mantisa[i] = 0;
  ldec->exp = 0;
  ldec->sign = 0;
}

long_decimal left_shift(long_decimal ldec, int shift) {
  for (int i = LDEC_MAX_BITS - 1 - shift; i >= 0; i--)
    set_bit_ldec(&ldec, i + shift, get_bit_ldec(ldec, i));
  for (int i = 0; i < shift; i++) set_bit_ldec(&ldec, i, 0);
  return ldec;
}

void sub_take_1(long_decimal *ldec, int i) {
  for (int j = i + 1; j < LDEC_MAX_BITS; j++) {
    if (get_bit_ldec(*ldec, j) == 1) {
      set_bit_ldec(ldec, j, 0);
      break;
    } else
      set_bit_ldec(ldec, j, 1);
  }
}

int mini_is_less_or_equa(long_decimal v1, long_decimal v2) {
  int res = 1;
  for (int i = LDEC_MAX_BITS - 1; i >= 0; i--) {
    if (get_bit_ldec(v1, i) != get_bit_ldec(v2, i)) {
      res = get_bit_ldec(v1, i) < get_bit_ldec(v2, i) ? 1 : 0;
      break;
    }
  }
  return res;
}

void bankers_round(long_decimal *ldec) {
  long_decimal remainder = {0};
  long_decimal one = {{1, 0, 0, 0, 0, 0}, 0, 0};
  long_decimal ten = {{10, 0, 0, 0, 0, 0}, 0, 0};
  mini_div_ldec_with_remainder(*ldec, ten, ldec, &remainder);
  if (remainder.mantisa[0] > 5)
    mini_add_ldec(*ldec, one, ldec);
  else if (remainder.mantisa[0] == 5) {
    if (get_bit_ldec(*ldec, 0) == 1) mini_add_ldec(*ldec, one, ldec);
  }
}

int bits_count(long_decimal ldec) {
  int res = 0;
  for (int i = LDEC_MAX_BITS - 1; i >= 0 && get_bit_ldec(ldec, i) != 1; i--)
    res++;
  return LDEC_MAX_BITS - res;
}

long_decimal dec_to_ldec(s21_decimal dec) {
  long_decimal res = {0};
  for (int i = 0; i < S21_DEC_MANTISA_LEN; i++) res.mantisa[i] = dec.bits[i];
  res.exp = find_exp(dec);
  res.sign = find_sign(dec);
  return res;
}

int is_zero(long_decimal ldec) {
  int status = 1;
  for (int i = 0; i < LDEC_LEN; i++) {
    if (ldec.mantisa[i] != 0) status = 0;
  }
  return status;
}

int ldec_to_dec(long_decimal ldec, s21_decimal *res) {
  int status = 0;
  int exp = ldec.exp;
  int sign = ldec.sign;

  if (is_zero(ldec)) {
    exp = 0;
    sign = 0;
  }

  while (bits_count(ldec) > S21_DEC_MAX_MANTISA_BITS || exp > S21_DEC_MAX_EXP) {
    bankers_round(&ldec);
    exp--;
  }

  if (exp < 0 && sign == 0) {
    status = 1;  // +inf
    zeroing_ldec(&ldec);
    exp = 0;
    sign = 0;
  } else if (exp < 0 && sign == 1) {
    status = 2;  // -inf
    zeroing_ldec(&ldec);
    exp = 0;
    sign = 1;
  }

  for (int i = 0; i < S21_DEC_MANTISA_LEN; i++) res->bits[i] = ldec.mantisa[i];
  res->bits[3] = (exp << 16) | (sign << 31);
  return status;
}

void normalization(long_decimal *lv1, long_decimal *lv2) {
  if (lv1->exp > lv2->exp) {
    for (int i = 0; i < (lv1->exp - lv2->exp); i++)
      mini_add_ldec(left_shift(*lv2, 1), left_shift(*lv2, 3), lv2);  // *= 10
    lv2->exp = lv1->exp;
  } else if (lv1->exp < lv2->exp) {
    for (int i = 0; i < (lv2->exp - lv1->exp); i++)
      mini_add_ldec(left_shift(*lv1, 1), left_shift(*lv1, 3), lv1);  // *= 10
    lv1->exp = lv2->exp;
  }
}

long_decimal left_shift_one(long_decimal *ldec) {
  int add_bits[LDEC_LEN] = {0};

  for (int i = 0; i < LDEC_LEN; i++) {
    add_bits[i] = get_bit_ldec(*ldec, BITS_IN_UINT * (i + 1) - 1);
    ldec->mantisa[i] = ldec->mantisa[i] << 1;
  }

  for (int i = 0; i < LDEC_LEN - 1; i++)
    set_bit_ldec(ldec, BITS_IN_UINT * (i + 1), add_bits[i]);

  return *ldec;
}

void right_shift_one(long_decimal *ldec) {
  int add_bits[LDEC_LEN] = {0};

  for (int i = 0; i < LDEC_LEN; i++) {
    add_bits[i] = get_bit_ldec(*ldec, BITS_IN_UINT * i);
    ldec->mantisa[i] = ldec->mantisa[i] >> 1;
  }

  for (int i = 1; i < LDEC_LEN; i++)
    set_bit_ldec(ldec, BITS_IN_UINT * i - 1, add_bits[i]);
}

void mini_add_ldec(long_decimal v1, long_decimal v2, long_decimal *res) {
  zeroing_ldec(res);
  int ost = 0;
  for (int i = 0; i < LDEC_MAX_BITS; i++) {
    int add_bit = get_bit_ldec(v1, i) + get_bit_ldec(v2, i) + ost;
    ost = add_bit / 2;
    set_bit_ldec(res, i, add_bit % 2);
  }
  res->exp = v1.exp;
  res->sign = v1.sign & v2.sign;
}

void mini_sub_ldec(long_decimal v1, long_decimal v2, long_decimal *res) {
  zeroing_ldec(res);
  for (int i = 0; i < LDEC_MAX_BITS; i++) {
    if (get_bit_ldec(v1, i) == 0 && get_bit_ldec(v2, i) == 1) {
      sub_take_1(&v1, i);
      set_bit_ldec(res, i, 1);
    } else
      set_bit_ldec(res, i, get_bit_ldec(v1, i) - get_bit_ldec(v2, i));
  }
  res->exp = v1.exp;
}

void mini_div_ldec_with_remainder(long_decimal v1, long_decimal v2,
                                  long_decimal *res, long_decimal *remainder) {
  zeroing_ldec(res);
  zeroing_ldec(remainder);
  while (mini_is_less_or_equa(v2, v1)) {
    int k = 1;
    long_decimal v2_cp = {0};
    for (int i = 0; i < LDEC_LEN; i++) v2_cp.mantisa[i] = v2.mantisa[i];

    for (; mini_is_less_or_equa(left_shift_one(&v2_cp), v1); k++)
      ;
    k--;
    right_shift_one(&v2_cp);
    set_bit_ldec(res, k, 1); 
    mini_sub_ldec(v1, v2_cp, &v1);
  }
  for (int i = 0; i < LDEC_LEN; i++) remainder->mantisa[i] = v1.mantisa[i];
}

void mini_mull_ldec(long_decimal v1, long_decimal v2, long_decimal *res) {
  zeroing_ldec(res);

  int exp = v1.exp + v2.exp;
  int sign = v1.sign ^ v2.sign;
  long_decimal zero = {0};
  long_decimal remainder = {0};
  long_decimal ten = {{10, 0, 0, 0, 0, 0}, 0, 0};

  for (int i = 0; mini_is_less(zero, v2); i++) {
    long_decimal buff = {0};
    mini_div_ldec_with_remainder(v2, ten, &v2, &remainder);
    if (remainder.mantisa[0] == 1)
      mini_add_ldec(buff, v1, &buff);
    else if (remainder.mantisa[0] == 2)
      mini_add_ldec(buff, left_shift(v1, 1), &buff);
    else if (remainder.mantisa[0] == 3)
      mini_add_ldec(v1, left_shift(v1, 1), &buff);
    else if (remainder.mantisa[0] == 4)
      mini_add_ldec(buff, left_shift(v1, 2), &buff);
    else if (remainder.mantisa[0] == 5)
      mini_add_ldec(v1, left_shift(v1, 2), &buff);
    else if (remainder.mantisa[0] == 6)
      mini_add_ldec(left_shift(v1, 2), left_shift(v1, 1), &buff);
    else if (remainder.mantisa[0] == 7)
      mini_sub_ldec(left_shift(v1, 3), v1, &buff);
    else if (remainder.mantisa[0] == 8)
      mini_add_ldec(buff, left_shift(v1, 3), &buff);
    else if (remainder.mantisa[0] == 9)
      mini_add_ldec(v1, left_shift(v1, 3), &buff);

    for (int j = 0; j < i; j++)
      mini_add_ldec(left_shift(buff, 1), left_shift(buff, 3), &buff);

    mini_add_ldec(*res, buff, res);

    for (; bits_count(*res) > S21_DEC_MAX_MANTISA_BITS; i--) {
      bankers_round(res);
      exp--;
    }
  }

  res->exp = exp;
  res->sign = sign;
}

void mini_div_ldec(long_decimal v1, long_decimal v2, long_decimal *res) {
  zeroing_ldec(res);

  int exp = v1.exp - v2.exp;
  int sign = v1.sign ^ v2.sign;
  long_decimal remainder = {0};
  long_decimal buff1 = {0};
  long_decimal buff2 = {0};

  for (mini_div_ldec_with_remainder(v1, v2, &buff1, &buff2);
       bits_count(v1) < LDEC_MAX_BITS - 4 && !is_zero(buff2); exp++)
    mini_add_ldec(left_shift(v1, 3), left_shift(v1, 1), &v1);

  mini_div_ldec_with_remainder(v1, v2, res, &remainder);

  res->exp = exp;
  res->sign = sign;
}

int mini_is_less(long_decimal v1, long_decimal v2) {
  int res = 0;
  for (int i = LDEC_MAX_BITS - 1; i >= 0; i--) {
    if (get_bit_ldec(v1, i) != get_bit_ldec(v2, i)) {
      res = get_bit_ldec(v1, i) < get_bit_ldec(v2, i) ? 1 : 0;
      break;
    }
  }
  return res;
}

int add_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  long_decimal res_ld = {0};
  long_decimal lv1 = dec_to_ldec(value_1);
  long_decimal lv2 = dec_to_ldec(value_2);
  normalization(&lv1, &lv2);
  mini_add_ldec(lv1, lv2, &res_ld);
  int status = ldec_to_dec(res_ld, result);
  return status;
}

int sub_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0;
  long_decimal res_ld = {0};
  long_decimal lv1 = dec_to_ldec(value_1);
  long_decimal lv2 = dec_to_ldec(value_2);

  normalization(&lv1, &lv2);
  if (s21_is_greater_or_equal(value_1, value_2)) {
    mini_sub_ldec(lv1, lv2, &res_ld);
    status = ldec_to_dec(res_ld, result);
  } else {
    mini_sub_ldec(lv2, lv1, &res_ld);
    status = ldec_to_dec(res_ld, result);
    set_sign(result, 1);
  }
  return status;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0;
  if (find_sign(value_1) && !find_sign(value_2)) {
    set_sign(&value_1, 0);
    status = sub_mod(value_2, value_1, result);
  } else if (!find_sign(value_1) && find_sign(value_2))
    status = sub_mod(value_1, value_2, result);
  else if (find_sign(value_1) && find_sign(value_2)) {
    status = add_mod(value_1, value_2, result);
    set_sign(result, 1);
  } else
    status = add_mod(value_1, value_2, result);
  return status;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0;
  if (find_sign(value_1) && !find_sign(value_2)) {
    set_sign(&value_2, 1);
    status = add_mod(value_1, value_2, result);
  } else if (!find_sign(value_1) && find_sign(value_2)) {
    set_sign(&value_2, 0);
    status = add_mod(value_1, value_2, result);
  } else if (find_sign(value_1) && find_sign(value_2)) {
    set_sign(&value_2, 0);
    set_sign(&value_1, 0);
    status = sub_mod(value_2, value_1, result);
  } else
    status = sub_mod(value_1, value_2, result);
  return status;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  long_decimal lres = {0};
  long_decimal lv1 = dec_to_ldec(value_1);
  long_decimal lv2 = dec_to_ldec(value_2);
  mini_mull_ldec(lv1, lv2, &lres);
  int status = ldec_to_dec(lres, result);
  return status;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0;
  s21_decimal zero = {0};
  zero.bits[3] = value_2.bits[3];
  if (s21_is_not_equal(value_2, zero)) {
    long_decimal lv1 = dec_to_ldec(value_1);
    long_decimal lv2 = dec_to_ldec(value_2);
    long_decimal lres = {0};
    mini_div_ldec(lv1, lv2, &lres);
    status = ldec_to_dec(lres, result);
  } else
    status = 3;
  return status;
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int status = 1;
  for (int i = 0; i < S21_DEC_MAX_BITS; i++) {
    if (get_bit_dec(value_1, i) != get_bit_dec(value_2, i)) status = 0;
  }
  return status;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_equal(value_1, value_2);
}

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int status = 0;
  long_decimal lv1 = dec_to_ldec(value_1);
  long_decimal lv2 = dec_to_ldec(value_2);
  normalization(&lv1, &lv2);
  if (lv1.sign == 1 && lv2.sign == 0)
    status = 1;
  else if (lv1.sign == 0 && lv2.sign == 1)
    status = 0;
  else if (lv1.sign == 0 && lv2.sign == 0)
    status = mini_is_less(lv1, lv2);
  else if (lv1.sign == 1 && lv2.sign == 1)
    status = !mini_is_less_or_equa(lv1, lv2);
  return status;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int status = 0;
  long_decimal lv1 = dec_to_ldec(value_1);
  long_decimal lv2 = dec_to_ldec(value_2);
  normalization(&lv1, &lv2);
  if (lv1.sign == 1 && lv2.sign == 0)
    status = 1;
  else if (lv1.sign == 0 && lv2.sign == 1)
    status = 0;
  else if (lv1.sign == 0 && lv2.sign == 0)
    status = mini_is_less_or_equa(lv1, lv2);
  else if (lv1.sign == 1 && lv2.sign == 1)
    status = !mini_is_less(lv1, lv2);
  return status;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_less_or_equal(value_1, value_2);
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_less(value_1, value_2);
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  long_decimal lv = dec_to_ldec(value);
  int sign = lv.sign;
  int exp = lv.exp;
  long_decimal ten = {{10, 0, 0, 0, 0, 0}, 0, 0};
  long_decimal remainder = {0};
  for (; exp > 0; exp--) mini_div_ldec_with_remainder(lv, ten, &lv, &remainder);
  lv.sign = sign;
  int status = ldec_to_dec(lv, result);
  return status > 0 ? 1 : 0;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  s21_decimal one = {{1, 0, 0, 0}};
  int status = s21_truncate(value, result);
  if (find_sign(*result)) status |= s21_sub(*result, one, result);
  return status;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  for (int i = 0; i < S21_DEC_LEN; i++) result->bits[i] = value.bits[i];
  if (!is_zero(dec_to_ldec(value))) set_sign(result, !find_sign(value));
  return 0;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  long_decimal lv = dec_to_ldec(value);
  int sign = lv.sign;
  int exp = lv.exp;
  int remainder = 0;
  long_decimal buff = {0};
  long_decimal ten = {{10, 0, 0, 0, 0, 0}, 0, 0};
  long_decimal one = {{1, 0, 0, 0, 0, 0}, 0, 0};
  for (; exp > 0; exp--) {
    mini_div_ldec_with_remainder(lv, ten, &lv, &buff);
    remainder = buff.mantisa[0];
  }
  if (remainder >= 5) mini_add_ldec(lv, one, &lv);
  lv.sign = sign;
  int status = ldec_to_dec(lv, result);
  return status > 0 ? 1 : 0;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int res = 1;
  if (dst != NULL) {
    memset(dst->bits, 0, sizeof(dst->bits));
    if (src < 0) src *= -1, set_bit_dec(dst, S21_DEC_MAX_BITS - 1, 1);
    dst->bits[0] = src;
    res = (dst->bits[0] != (unsigned int)src) ? 1 : 0;
  }
  return res;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = 1;
  if (src.bits[1] == 0 && src.bits[2] == 0 && dst != NULL) {
    int sign = get_bit_dec(src, S21_DEC_MAX_BITS - 1);
    if (src.bits[0] <= (unsigned int)S21_INT_MAX ||
        (src.bits[0] == (unsigned int)S21_INT_MIN && sign)) {
      *dst = src.bits[0];
      if (sign) *dst *= -1;
      res = 0;
    } else {
      *dst = 0;
    }
  }
  return res;
}

void s21_parse_dec(float src_cp, s21_decimal *dst, int sign) {
  int capasity = 0;

  float src_cp1 = src_cp;
  for (; src_cp1 >= 1; capasity++) src_cp1 /= 10;
  capasity -= 8;

  src_cp /= powf(10, (float)capasity);
  dst->bits[0] = (int)src_cp;

  if ((int)src_cp % 10 >= 5)
    dst->bits[0] = (int)src_cp / 10 + 1;
  else
    dst->bits[0] /= 10;

  s21_decimal ten = {{10, 0, 0, 0}};
  for (int i = 0; i < (capasity + 1); i++) s21_mul(*dst, ten, dst);

  set_sign(dst, sign);
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int status = 1;

  for (int i = 0; i < 4; i++) dst->bits[i] = 0;

  if (!isinf(src) && !isinf(-src) && (src <= DEC_MAX && src >= DEC_MIN)) {
    status = 0;
    int exp = 0;
    int sign = 0;
    int src_int_bits = 0;

    if (src < 0) {
      sign = 1;
      src *= -1;
    }

    for (; src > (long long int)src; exp++) src *= 10;

    long long int src_int = (long long int)src;

    for (; src_int > 0; src_int_bits++) src_int >>= 1;

    for (; src_int_bits > 23 && exp > 0; exp--) {
      src_int_bits = 0;
      long long int mod = (long long int)src % 10;
      src /= 10;
      src_int = (long long int)src;
      for (; src_int > 0; src_int_bits++) src_int >>= 1;
      if (mod >= 5 && src_int_bits <= 23) src += 1;
    }

    if (src_int_bits <= 23) {
      dst->bits[0] = (int)src;
      dst->bits[3] = ((dst->bits[3] + exp) << 16);
      set_sign(dst, sign);
    } else
      s21_parse_dec(src, dst, sign);
  }
  return status;
}

int s21_parse_float(long_decimal lsrc, float *dst, int sign) {
  int exp = 0;
  long_decimal lsrc_cp = {0};
  long_decimal ten = {{10, 0, 0, 0, 0, 0}, 0, 0};

  for (int i = 0; i < 6; i++) lsrc_cp.mantisa[i] = lsrc.mantisa[i];

  for (; lsrc_cp.mantisa[0] > 0; exp++) {
    long_decimal remainder = {0};
    mini_div_ldec_with_remainder(lsrc_cp, ten, &lsrc_cp, &remainder);
  }

  exp -= 8;

  for (int i = exp; i > 0; i--) {
    long_decimal remainder = {0};
    mini_div_ldec_with_remainder(lsrc, ten, &lsrc, &remainder);
  }

  if (lsrc.mantisa[0] % 10 >= 5)
    lsrc.mantisa[0] = lsrc.mantisa[0] / 10 + 1;
  else
    lsrc.mantisa[0] /= 10;

  *dst = lsrc.mantisa[0];
  *dst *= powf(10, (float)(exp + 1));
  if (sign) *dst *= -1;
  return (exp + 1) ? 0 : 1;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  *dst = 0;
  int status = 1;
  int exp = find_exp(src);
  int sign = find_sign(src);
  long_decimal lsrc = dec_to_ldec(src);
  long_decimal one = {{1, 0, 0, 0, 0, 0}, 0, 0};
  long_decimal ten = {{10, 0, 0, 0, 0, 0}, 0, 0};

  for (; bits_count(lsrc) > 23 && exp > 0; exp--) {
    long_decimal remainder = {0};
    mini_div_ldec_with_remainder(lsrc, ten, &lsrc, &remainder);
    if (remainder.mantisa[0] >= 5) mini_add_ldec(lsrc, one, &lsrc);
  }

  if (bits_count(lsrc) <= 23) {
    float divider = powf(10, (float)exp);
    *dst = lsrc.mantisa[0];
    if (sign) *dst *= -1;
    *dst /= divider;
    status = 0;
  } else
    status = s21_parse_float(lsrc, dst, sign);

  return status;
}