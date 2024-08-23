#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#define LDEC_LEN 7
#define BITS_IN_UINT 32
#define LDEC_MAX_BITS 7 * 32
#define S21_DEC_LEN 4
#define S21_DEC_MAX_EXP 28
#define S21_DEC_EXP_FBIT 112
#define S21_DEC_EXP_LBIT 119
#define S21_DEC_MANTISA_LEN 3
#define S21_DEC_MAX_BITS 4 * 32
#define S21_DEC_MAX_MANTISA_BITS 3 * 32
#define S21_INT_MIN -2147483647 - 1
#define S21_INT_MAX 2147483647
#define DEC_MAX 79228162514264337593543950335.0F
#define DEC_MIN -79228162514264337593543950335.0F

#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int mantisa[LDEC_LEN];
  int exp;
  int sign;
} long_decimal;

int get_bit_ldec(long_decimal dec, int pos);
void set_bit_ldec(long_decimal *dec, int pos, int new);
int get_bit_dec(s21_decimal dec, int pos);
void set_bit_dec(s21_decimal *dec, int pos, int new);
int find_sign(s21_decimal dec);
void set_sign(s21_decimal *dec, int sign);
int find_exp(s21_decimal dec);
void zeroing_ldec(long_decimal *ldec);
long_decimal left_shift(long_decimal ldec, int shift);
void sub_take_1(long_decimal *ldec, int i);
int mini_is_less_or_equa(long_decimal v1, long_decimal v2);
void bankers_round(long_decimal *ldec);
int bits_count(long_decimal ldec);
long_decimal dec_to_ldec(s21_decimal dec);
int is_zero(long_decimal ldec);
int ldec_to_dec(long_decimal ldec, s21_decimal *res);
void normalization(long_decimal *lv1, long_decimal *lv2);
long_decimal left_shift_one(long_decimal *ldec);
void right_shift_one(long_decimal *ldec);
void mini_add_ldec(long_decimal v1, long_decimal v2, long_decimal *res);
void mini_sub_ldec(long_decimal v1, long_decimal v2, long_decimal *res);
void mini_div_ldec_with_remainder(long_decimal v1, long_decimal v2,
                                  long_decimal *res, long_decimal *remainder);
void mini_mull_ldec(long_decimal v1, long_decimal v2, long_decimal *res);
void mini_div_ldec(long_decimal v1, long_decimal v2, long_decimal *res);
int mini_is_less(long_decimal v1, long_decimal v2);
int add_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int sub_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
void s21_parse_dec(float src, s21_decimal *dst, int sign);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_parse_float(long_decimal lsrc, float *dst, int sign);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

#endif