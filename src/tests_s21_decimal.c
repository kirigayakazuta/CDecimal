#include <check.h>
#include <stdio.h>

#include "s21_decimal.h"

// Тесты для функции -- int s21_add(s21_decimal value_1, s21_decimal value_2,
//  s21_decimal *result);
START_TEST(s21_add_test_1) {
  s21_decimal value_1 = {12, 0, 0, 0};
  s21_decimal value_2 = {12, 0, 0, 0};
  s21_decimal result = {0};
  int error = s21_add(value_1, value_2, &result);
  s21_decimal my_res = {24, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_add_test_2) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 0};
  s21_decimal value_2 = {4294967295, 4294967295, 4294967295, 0};
  s21_decimal result = {0};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(s21_add_test_3) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 2147483648};
  s21_decimal value_2 = {4294967295, 4294967295, 4294967295, 2147483648};
  s21_decimal result = {0};
  int error = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(2, error);
}
END_TEST

START_TEST(s21_add_test_4) {
  s21_decimal value_1 = {1343434242, 0, 0, 0};
  s21_decimal value_2 = {3207468595, 3339546090, 0, 0};
  s21_decimal result = {0};
  int error = s21_add(value_1, value_2, &result);
  s21_decimal my_res = {255935541, 3339546091, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_add_test_5) {
  s21_decimal value_1 = {2865459246, 28, 0, 393216};
  s21_decimal value_2 = {3824279622, 2, 0, 393216};
  s21_decimal result = {0};
  int error = s21_add(value_1, value_2, &result);
  s21_decimal my_res = {2394771572, 31, 0, 393216};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_add_test_6) {
  s21_decimal value_1 = {3037963898, 2866, 0, 2147876864};
  s21_decimal value_2 = {3993900100, 286, 0, 2148007936};
  s21_decimal result = {0};
  int error = s21_add(value_1, value_2, &result);
  s21_decimal my_res = {2847611884, 286957, 0, 2148007936};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_add_test_7) {
  s21_decimal value_1 = {1234567890, 0, 0, 0};
  s21_decimal value_2 = {1234567890, 0, 0, 0};
  s21_decimal result = {0};
  int error = s21_add(value_1, value_2, &result);
  s21_decimal my_res = {2469135780, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_add_test_8) {
  s21_decimal value_1 = {4214978873, 3064733583, 175, 0};
  s21_decimal value_2 = {215559773, 3965748466, 126, 0};
  s21_decimal result = {0};
  int error = s21_add(value_1, value_2, &result);
  s21_decimal my_res = {135571350, 2735514754, 302, 0};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_add_test_9) {
  s21_decimal value_1 = {2251544842, 282, 0, 0};
  s21_decimal value_2 = {2495911691, 1970919899, 6739478, 917504};
  s21_decimal result = {0};
  int error = s21_add(value_1, value_2, &result);
  s21_decimal my_res = {2580223755, 1112290860, 13317508, 917504};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_add_test_10) {
  s21_decimal value_1 = {321432144, 0, 0, 2147483648};
  s21_decimal value_2 = {1087103323, 748372, 0, 655360};
  s21_decimal result = {0};
  int error = s21_add(value_1, value_2, &result);
  s21_decimal my_res = {2287165093, 747644157, 0, 2148139008};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_add_test_11) {
  s21_decimal value_1 = {5, 0, 0, 0};
  s21_decimal value_2 = {4, 0, 0, 2147483648};
  s21_decimal result = {0};
  int error = s21_add(value_1, value_2, &result);
  s21_decimal my_res = {1, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

// Тесты для функции -- int s21_sub(s21_decimal value_1, s21_decimal value_2,
//  s21_decimal *result);
START_TEST(s21_sub_test_1) {
  s21_decimal value_1 = {224248331, 7547, 0, 0};
  s21_decimal value_2 = {871913087, 287386, 0, 0};
  s21_decimal result = {0};
  int error = s21_sub(value_1, value_2, &result);
  s21_decimal my_res = {647664756, 279839, 0, 2147483648};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_sub_test_2) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 2147483648};
  s21_decimal value_2 = {12, 0, 0, 0};
  s21_decimal result = {0};
  int error = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(2, error);
}
END_TEST

START_TEST(s21_sub_test_3) {
  s21_decimal value_1 = {1146859364, 2873885, 0, 589824};
  s21_decimal value_2 = {1958397844, 5, 0, 393216};
  s21_decimal result = {0};
  int error = s21_sub(value_1, value_2, &result);
  s21_decimal my_res = {1254102340, 2868429, 0, 589824};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_sub_test_4) {
  s21_decimal value_1 = {34124, 0, 0, 0};
  s21_decimal value_2 = {234124, 0, 0, 0};
  s21_decimal result = {0};
  int error = s21_sub(value_1, value_2, &result);
  s21_decimal my_res = {200000, 0, 0, 2147483648};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_sub_test_5) {
  s21_decimal value_1 = {1957606834, 5, 0, 2147483648};
  s21_decimal value_2 = {3737903160, 754, 0, 0};
  s21_decimal result = {0};
  int error = s21_sub(value_1, value_2, &result);
  s21_decimal my_res = {1400542698, 760, 0, 2147483648};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_sub_test_6) {
  s21_decimal value_1 = {167210461, 79962, 0, 458752};
  s21_decimal value_2 = {789221948, 9626, 0, 0};
  s21_decimal result = {0};
  int error = s21_sub(value_1, value_2, &result);
  s21_decimal my_res = {2158024739, 1772477076, 22, 2147942400};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_sub_test_7) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 0};
  s21_decimal value_2 = {4294967295, 4294967295, 4294967295, 2147483648};
  s21_decimal result = {0};
  int error = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(s21_sub_test_8) {
  s21_decimal value_1 = {3337488897, 3973903618, 2295, 0};
  s21_decimal value_2 = {4175259739, 631492013, 127146, 0};
  s21_decimal result = {0};
  int error = s21_sub(value_1, value_2, &result);
  s21_decimal my_res = {837770842, 952555691, 124850, 2147483648};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_sub_test_9) {
  s21_decimal value_1 = {3632038186, 538, 0, 2147483648};
  s21_decimal value_2 = {682462676, 75510336, 0, 720896};
  s21_decimal result = {0};
  int error = s21_sub(value_1, value_2, &result);
  s21_decimal my_res = {1461165524, 4275760878, 12545, 2148204544};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_sub_test_10) {
  s21_decimal value_1 = {4220214290, 2324741435, 17571249, 786432};
  s21_decimal value_2 = {4004652172, 369715520, 127, 589824};
  s21_decimal result = {0};
  int error = s21_sub(value_1, value_2, &result);
  s21_decimal my_res = {2477562162, 1976407959, 17444163, 786432};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_sub_test_11) {
  s21_decimal value_1 = {2, 0, 0, 2147483648};
  s21_decimal value_2 = {3, 0, 0, 2147483648};
  s21_decimal result = {0};
  int error = s21_sub(value_1, value_2, &result);
  s21_decimal my_res = {1, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

// Тесты для функции -- int s21_mul(s21_decimal value_1, s21_decimal value_2,
//  s21_decimal *result);
START_TEST(s21_mul_test_1) {
  s21_decimal value_1 = {890956139, 10068396, 0, 0};
  s21_decimal value_2 = {2791205493, 54513, 0, 0};
  s21_decimal result = {0};
  int error = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(s21_mul_test_2) {
  s21_decimal value_1 = {490912276, 748418838, 0, 0};
  s21_decimal value_2 = {32432, 0, 0, 0};
  s21_decimal result = {0};
  int error = s21_mul(value_1, value_2, &result);
  s21_decimal my_res = {4118136256, 1859568026, 5651, 0};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_mul_test_3) {
  s21_decimal value_1 = {4127308727, 53838671, 0, 524288};
  s21_decimal value_2 = {63796174, 8, 0, 0};
  s21_decimal result = {0};
  int error = s21_mul(value_1, value_2, &result);
  s21_decimal my_res = {860045890, 1711568937, 431509079, 524288};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_mul_test_4) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 2147483648};
  s21_decimal value_2 = {4294967295, 4294967295, 4294967295, 0};
  s21_decimal result = {0};
  int error = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(2, error);
}
END_TEST

START_TEST(s21_mul_test_5) {
  s21_decimal value_1 = {4121527279, 4987, 0, 0};
  s21_decimal value_2 = {3163143567, 101361, 0, 262144};
  s21_decimal result = {0};
  int error = s21_mul(value_1, value_2, &result);
  s21_decimal my_res = {2130650497, 1465078838, 505588248, 262144};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_mul_test_6) {
  s21_decimal value_1 = {965584756, 8, 0, 2147483648};
  s21_decimal value_2 = {901777135, 7805, 0, 0};
  s21_decimal result = {0};
  int error = s21_mul(value_1, value_2, &result);
  s21_decimal my_res = {2821459276, 1843401363, 64196, 2147483648};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_mul_test_7) {
  s21_decimal value_1 = {542114754, 755, 0, 2147680256};
  s21_decimal value_2 = {432555345, 0, 0, 0};
  s21_decimal result = {0};
  int error = s21_mul(value_1, value_2, &result);
  s21_decimal my_res = {2883877474, 216368515, 76, 2147680256};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_mul_test_8) {
  s21_decimal value_1 = {3243412, 0, 0, 0};
  s21_decimal value_2 = {3243432, 0, 0, 2147483648};
  s21_decimal result = {0};
  int error = s21_mul(value_1, value_2, &result);
  s21_decimal my_res = {1411362080, 2449, 0, 2147483648};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_mul_test_9) {
  s21_decimal value_1 = {3753487542, 2, 0, 2147745792};
  s21_decimal value_2 = {1234343244, 0, 0, 2147483648};
  s21_decimal result = {0};
  int error = s21_mul(value_1, value_2, &result);
  s21_decimal my_res = {3799069704, 3547412277, 0, 262144};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_mul_test_10) {
  s21_decimal value_1 = {2305110551, 54, 0, 2147483648};
  s21_decimal value_2 = {3086884338, 726, 0, 2147942400};
  s21_decimal result = {0};
  int error = s21_mul(value_1, value_2, &result);
  s21_decimal my_res = {2082993342, 3612743566, 39632, 458752};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_mul_test_11) {
  s21_decimal value_1 = {0, 0, 0, 0};
  s21_decimal value_2 = {125, 0, 0, 0};
  s21_decimal result = {0};
  int error = s21_mul(value_1, value_2, &result);
  s21_decimal my_res = {0, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

// Тесты для функции -- int s21_div(s21_decimal value_1, s21_decimal value_2,
//  s21_decimal *result);
START_TEST(s21_div_test_1) {
  s21_decimal value_1 = {15, 0, 0, 0};
  s21_decimal value_2 = {5, 0, 0, 0};
  s21_decimal result = {0};
  int error = s21_div(value_1, value_2, &result);
  s21_decimal my_res = {3, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_div_test_2) {
  s21_decimal value_1 = {49, 0, 0, 2147483648};
  s21_decimal value_2 = {7, 0, 0, 2147483648};
  s21_decimal result = {0};
  int error = s21_div(value_1, value_2, &result);
  s21_decimal my_res = {7, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_div_test_3) {
  s21_decimal value_1 = {237437284, 0, 0, 0};
  s21_decimal value_2 = {1533827712, 5642472, 0, 0};
  s21_decimal result = {0};
  int error = s21_div(value_1, value_2, &result);
  s21_decimal my_res = {936964126, 1336973915, 5, 1835008};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_div_test_4) {
  s21_decimal value_1 = {2558947764, 564247235, 0, 720896};
  s21_decimal value_2 = {752897274, 552885, 0, 393216};
  s21_decimal result = {0};
  int error = s21_div(value_1, value_2, &result);
  s21_decimal my_res = {1100154761, 1213139069, 5532415, 1835008};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_div_test_5) {
  s21_decimal value_1 = {255, 0, 0, 0};
  s21_decimal value_2 = {255, 0, 0, 0};
  s21_decimal result = {0};
  int error = s21_div(value_1, value_2, &result);
  s21_decimal my_res = {1, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_div_test_6) {
  s21_decimal value_1 = {255, 0, 0, 0};
  s21_decimal value_2 = {0, 0, 0, 0};
  s21_decimal result = {0};
  int error = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(3, error);
}
END_TEST

START_TEST(s21_div_test_7) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 0};
  s21_decimal value_2 = {5, 0, 0, 65536};
  s21_decimal result = {0};
  int error = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(s21_div_test_8) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 0};
  s21_decimal value_2 = {5, 0, 0, 2147549184};
  s21_decimal result = {0};
  int error = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(2, error);
}
END_TEST

START_TEST(s21_div_test_9) {
  s21_decimal value_1 = {2802361139, 30554, 0, 458752};
  s21_decimal value_2 = {1231231, 0, 0, 720896};
  s21_decimal result = {0};
  s21_decimal my_res = {2243463643, 3917441180, 577800542, 1048576};
  int error = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_div_test_10) {
  s21_decimal value_1 = {0, 0, 0, 0};
  s21_decimal value_2 = {123, 0, 0, 0};
  s21_decimal result = {0};
  s21_decimal my_res = {0};
  int error = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

// Тесты для функции -- int s21_is_less(s21_decimal value_1, s21_decimal
//  value_2);
START_TEST(s21_is_less_test_1) {
  s21_decimal value_1 = {3321643205, 2451423364, 17, 0};
  s21_decimal value_2 = {3849532431, 1543678155, 2, 0};
  ck_assert_int_eq(0, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(s21_is_less_test_2) {
  s21_decimal value_1 = {437567498, 2625950029, 17424822, 786432};
  s21_decimal value_2 = {1312932836, 755098728, 0, 589824};
  ck_assert_int_eq(0, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(s21_is_less_test_3) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 2147483648};
  s21_decimal value_2 = {4294967295, 4294967295, 4294967295, 0};
  ck_assert_int_eq(1, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(s21_is_less_test_4) {
  s21_decimal value_1 = {508689012, 49898497, 0, 458752};
  s21_decimal value_2 = {2196090139, 54, 0, 0};
  ck_assert_int_eq(1, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(s21_is_less_test_5) {
  s21_decimal value_1 = {912378068, 1011, 0, 0};
  s21_decimal value_2 = {2364608787, 799336, 0, 524288};
  ck_assert_int_eq(0, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(s21_is_less_test_6) {
  s21_decimal value_1 = {1391840504, 3479472693, 175, 0};
  s21_decimal value_2 = {388117420, 3945429403, 126, 0};
  ck_assert_int_eq(0, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(s21_is_less_test_7) {
  s21_decimal value_1 = {3414341, 0, 0, 0};
  s21_decimal value_2 = {1244819474, 1505639046, 1269234, 786432};
  ck_assert_int_eq(1, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(s21_is_less_test_8) {
  s21_decimal value_1 = {1434683136, 545578876, 0, 0};
  s21_decimal value_2 = {1250256224, 804575, 0, 0};
  ck_assert_int_eq(0, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(s21_is_less_test_9) {
  s21_decimal value_1 = {3601596584, 1050672747, 71, 524288};
  s21_decimal value_2 = {1801121834, 3945215334, 126, 655360};
  ck_assert_int_eq(0, s21_is_less(value_1, value_2));
}
END_TEST

START_TEST(s21_is_less_test_10) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 0};
  s21_decimal value_2 = {4294967295, 4294967295, 4294967295, 0};
  ck_assert_int_eq(0, s21_is_less(value_1, value_2));
}
END_TEST

// Тесты для функции -- int s21_is_less_or_equal(s21_decimal, s21_decimal);
START_TEST(s21_is_less_or_equal_test_1) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 2147483648};
  s21_decimal value_2 = {4294967295, 4294967295, 4294967295, 2147483648};
  ck_assert_int_eq(1, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_less_or_equal_test_2) {
  s21_decimal value_1 = {3781791802, 545834992, 0, 524288};
  s21_decimal value_2 = {2413107340, 54, 0, 0};
  ck_assert_int_eq(1, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_less_or_equal_test_3) {
  s21_decimal value_1 = {2185777788, 74839, 0, 0};
  s21_decimal value_2 = {866883888, 289, 0, 327680};
  ck_assert_int_eq(0, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_less_or_equal_test_4) {
  s21_decimal value_1 = {1225288681, 1444125153, 67, 262144};
  s21_decimal value_2 = {487758580, 2498196480, 17, 524288};
  ck_assert_int_eq(0, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_less_or_equal_test_5) {
  s21_decimal value_1 = {423032844, 755, 0, 0};
  s21_decimal value_2 = {2201765143, 75, 0, 0};
  ck_assert_int_eq(0, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_less_or_equal_test_6) {
  s21_decimal value_1 = {1236277301, 1600659326, 1, 393216};
  s21_decimal value_2 = {1938406761, 5, 0, 0};
  ck_assert_int_eq(0, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_less_or_equal_test_7) {
  s21_decimal value_1 = {1938406761, 5, 0, 0};
  s21_decimal value_2 = {1236277301, 1600659326, 1, 393216};
  ck_assert_int_eq(1, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_less_or_equal_test_8) {
  s21_decimal value_1 = {2822938909, 5460424, 0, 327680};
  s21_decimal value_2 = {2822938909, 5460424, 0, 327680};
  ck_assert_int_eq(1, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_less_or_equal_test_9) {
  s21_decimal value_1 = {3931744536, 496, 0, 0};
  s21_decimal value_2 = {885677253, 5453, 0, 262144};
  ck_assert_int_eq(0, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_less_or_equal_test_10) {
  s21_decimal value_1 = {2839255115, 3510753340, 669137723, 393216};
  s21_decimal value_2 = {1830762702, 54511272, 0, 262144};
  ck_assert_int_eq(0, s21_is_less_or_equal(value_1, value_2));
}
END_TEST

// Тесты для функции -- int s21_is_greater(s21_decimal, s21_decimal);
START_TEST(s21_is_greater_test_1) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 0};
  s21_decimal value_2 = {4294967295, 4294967295, 4294967295, 0};
  ck_assert_int_eq(0, s21_is_greater(value_1, value_2));
}
END_TEST

START_TEST(s21_is_greater_test_2) {
  s21_decimal value_1 = {904818676, 1974707266, 125, 0};
  s21_decimal value_2 = {3638019471, 1161239889, 1, 0};
  ck_assert_int_eq(1, s21_is_greater(value_1, value_2));
}
END_TEST

START_TEST(s21_is_greater_test_3) {
  s21_decimal value_1 = {4154411551, 3647056405, 18611107, 655360};
  s21_decimal value_2 = {210999617, 545387469, 0, 393216};
  ck_assert_int_eq(1, s21_is_greater(value_1, value_2));
}
END_TEST

START_TEST(s21_is_greater_test_4) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 2147483648};
  s21_decimal value_2 = {4294967295, 4294967295, 4294967295, 0};
  ck_assert_int_eq(0, s21_is_greater(value_1, value_2));
}
END_TEST

START_TEST(s21_is_greater_test_5) {
  s21_decimal value_1 = {324324321, 0, 0, 0};
  s21_decimal value_2 = {3412341, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_greater(value_1, value_2));
}
END_TEST

START_TEST(s21_is_greater_test_6) {
  s21_decimal value_1 = {2590118029, 1413135284, 1270, 589824};
  s21_decimal value_2 = {2476103837, 3256296983, 1, 0};
  ck_assert_int_eq(0, s21_is_greater(value_1, value_2));
}
END_TEST

START_TEST(s21_is_greater_test_7) {
  s21_decimal value_1 = {2876838676, 727391, 0, 0};
  s21_decimal value_2 = {281186070, 4201284411, 126, 1114112};
  ck_assert_int_eq(1, s21_is_greater(value_1, value_2));
}
END_TEST

START_TEST(s21_is_greater_test_8) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 0};
  s21_decimal value_2 = {4294967295, 4294967295, 4294967295, 2147483648};
  ck_assert_int_eq(1, s21_is_greater(value_1, value_2));
}
END_TEST

START_TEST(s21_is_greater_test_9) {
  s21_decimal value_1 = {2020354283, 998991920, 2360602, 0};
  s21_decimal value_2 = {357450129, 3453119319, 245800, 0};
  ck_assert_int_eq(1, s21_is_greater(value_1, value_2));
}
END_TEST

START_TEST(s21_is_greater_test_10) {
  s21_decimal value_1 = {997951626, 75698, 0, 393216};
  s21_decimal value_2 = {621576558, 501592956, 0, 0};
  ck_assert_int_eq(0, s21_is_greater(value_1, value_2));
}
END_TEST

// Тесты для функции -- int s21_is_greater_or_equal(s21_decimal, s21_decimal);
START_TEST(s21_is_greater_or_equal_test_1) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 2147483648};
  s21_decimal value_2 = {4294967295, 4294967295, 4294967295, 2147483648};
  ck_assert_int_eq(1, s21_is_greater_or_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_2) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 2147483648};
  s21_decimal value_2 = {29496729, 4294967295, 4294967295, 0};
  ck_assert_int_eq(0, s21_is_greater_or_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_3) {
  s21_decimal value_1 = {1077272099, 1827436962, 17, 458752};
  s21_decimal value_2 = {3683556440, 54557, 0, 0};
  ck_assert_int_eq(0, s21_is_greater_or_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_4) {
  s21_decimal value_1 = {4053120472, 748390432, 0, 0};
  s21_decimal value_2 = {2951026111, 1891762699, 22412163, 2148007936};
  ck_assert_int_eq(1, s21_is_greater_or_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_5) {
  s21_decimal value_1 = {1842032330, 7274, 0, 0};
  s21_decimal value_2 = {1842032330, 7274, 0, 0};
  ck_assert_int_eq(1, s21_is_greater_or_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_6) {
  s21_decimal value_1 = {4254354352, 0, 0, 0};
  s21_decimal value_2 = {0, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_greater_or_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_7) {
  s21_decimal value_1 = {127807991, 54562, 0, 458752};
  s21_decimal value_2 = {3908890229, 754, 0, 2147483648};
  ck_assert_int_eq(1, s21_is_greater_or_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_8) {
  s21_decimal value_1 = {1051281298, 755166, 0, 0};
  s21_decimal value_2 = {3382688265, 105, 0, 0};
  ck_assert_int_eq(1, s21_is_greater_or_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_9) {
  s21_decimal value_1 = {1661992960, 1808227885, 5, 0};
  s21_decimal value_2 = {2764472320, 232830, 0, 0};
  ck_assert_int_eq(1, s21_is_greater_or_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_10) {
  s21_decimal value_1 = {3478995046, 8179930, 0, 0};
  s21_decimal value_2 = {2153894084, 3251873019, 1, 0};
  ck_assert_int_eq(0, s21_is_greater_or_equal(value_1, value_2));
}
END_TEST

// Тесты для функции -- int s21_is_equal(s21_decimal, s21_decimal);
START_TEST(s21_is_equal_test_1) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 2147483648};
  s21_decimal value_2 = {4294967295, 4294967295, 4294967295, 2147483648};
  ck_assert_int_eq(1, s21_is_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_equal_test_2) {
  s21_decimal value_1 = {3981033290, 75514, 0, 0};
  s21_decimal value_2 = {1719749390, 4969, 0, 0};
  ck_assert_int_eq(0, s21_is_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_equal_test_3) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 0};
  s21_decimal value_2 = {4294967295, 4294967295, 4294967295, 0};
  ck_assert_int_eq(1, s21_is_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_equal_test_4) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 0};
  s21_decimal value_2 = {4294967295, 4294967295, 4294967295, 2147483648};
  ck_assert_int_eq(0, s21_is_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_equal_test_5) {
  s21_decimal value_1 = {3528011293, 54561845, 0, 524288};
  s21_decimal value_2 = {2273278051, 794730457, 0, 2148007936};
  ck_assert_int_eq(0, s21_is_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_equal_test_6) {
  s21_decimal value_1 = {690690094, 2495428563, 17, 0};
  s21_decimal value_2 = {518307540, 4248967456, 669126, 0};
  ck_assert_int_eq(0, s21_is_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_equal_test_7) {
  s21_decimal value_1 = {3830670948, 3889962515, 22459, 0};
  s21_decimal value_2 = {3830670948, 3889962515, 22459, 0};
  ck_assert_int_eq(1, s21_is_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_equal_test_8) {
  s21_decimal value_1 = {1331143746, 755098728, 0, 458752};
  s21_decimal value_2 = {2078117750, 7947309, 0, 2147483648};
  ck_assert_int_eq(0, s21_is_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_equal_test_9) {
  s21_decimal value_1 = {101, 0, 0, 0};
  s21_decimal value_2 = {101, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_equal_test_10) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 2147483648};
  s21_decimal value_2 = {4294967295, 4294967295, 4294967295, 2147483648};
  ck_assert_int_eq(1, s21_is_equal(value_1, value_2));
}
END_TEST

// Тесты для функции -- int s21_is_not_equal(s21_decimal, s21_decimal);
START_TEST(s21_is_not_equal_test_1) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 0};
  s21_decimal value_2 = {4294967295, 4294967295, 4294967295, 2147483648};
  ck_assert_int_eq(1, s21_is_not_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_not_equal_test_2) {
  s21_decimal value_1 = {3159285888, 3480195155, 66, 0};
  s21_decimal value_2 = {2812850094, 2608110642, 18, 0};
  ck_assert_int_eq(1, s21_is_not_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_not_equal_test_3) {
  s21_decimal value_1 = {635317675, 2950767391, 66913782, 655360};
  s21_decimal value_2 = {635317675, 2950767391, 66913782, 655360};
  ck_assert_int_eq(0, s21_is_not_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_not_equal_test_4) {
  s21_decimal value_1 = {3385833462, 5455, 0, 2147483648};
  s21_decimal value_2 = {859222116, 798, 0, 0};
  ck_assert_int_eq(1, s21_is_not_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_not_equal_test_5) {
  s21_decimal value_1 = {43513099, 1058316, 0, 0};
  s21_decimal value_2 = {1616465397, 2708394889, 24, 262144};
  ck_assert_int_eq(1, s21_is_not_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_not_equal_test_6) {
  s21_decimal value_1 = {4294967295, 4294967295, 4294967295, 2147483648};
  s21_decimal value_2 = {4294967295, 4294967295, 4294967295, 2147483648};
  ck_assert_int_eq(0, s21_is_not_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_not_equal_test_7) {
  s21_decimal value_1 = {3781575252, 54557, 0, 2147483648};
  s21_decimal value_2 = {2396098437, 54, 0, 0};
  ck_assert_int_eq(1, s21_is_not_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_not_equal_test_8) {
  s21_decimal value_1 = {2961697980, 75512, 0, 0};
  s21_decimal value_2 = {543015762, 755, 0, 0};
  ck_assert_int_eq(1, s21_is_not_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_not_equal_test_9) {
  s21_decimal value_1 = {2751814709, 755165992, 0, 327680};
  s21_decimal value_2 = {2751814709, 755165992, 0, 327680};
  ck_assert_int_eq(0, s21_is_not_equal(value_1, value_2));
}
END_TEST

START_TEST(s21_is_not_equal_test_10) {
  s21_decimal value_1 = {1968881938, 755126, 0, 2147745792};
  s21_decimal value_2 = {43413432, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_not_equal(value_1, value_2));
}
END_TEST

// Тесты для функции -- int s21_floor(s21_decimal value, s21_decimal *result);
START_TEST(s21_floor_test_1) {
  s21_decimal value = {123123, 0, 0, 196608};
  s21_decimal result = {0};
  int error = s21_floor(value, &result);
  s21_decimal my_res = {123, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_floor_test_2) {
  s21_decimal value = {75, 0, 0, 2147549184};
  s21_decimal result = {0};
  int error = s21_floor(value, &result);
  s21_decimal my_res = {8, 0, 0, 2147483648};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_floor_test_3) {
  s21_decimal value = {39, 0, 0, 65536};
  s21_decimal result = {0};
  int error = s21_floor(value, &result);
  s21_decimal my_res = {3, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

// Тесты для функции -- int s21_round(s21_decimal value, s21_decimal *result);
START_TEST(s21_round_test_1) {
  s21_decimal value = {85343, 0, 0, 262144};
  s21_decimal result = {0};
  int error = s21_round(value, &result);
  s21_decimal my_res = {9, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_round_test_2) {
  s21_decimal value = {675545, 0, 0, 327680};
  s21_decimal result = {0};
  int error = s21_round(value, &result);
  s21_decimal my_res = {7, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_round_test_3) {
  s21_decimal value = {453323, 0, 0, 2147811328};
  s21_decimal result = {0};
  int error = s21_round(value, &result);
  s21_decimal my_res = {5, 0, 0, 2147483648};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

// Тесты для функции -- int s21_truncate(s21_decimal value, s21_decimal
// *result);
START_TEST(s21_truncate_test_1) {
  s21_decimal value = {3691447674, 985, 0, 589824};
  s21_decimal result = {0};
  int error = s21_truncate(value, &result);
  s21_decimal my_res = {4234, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_truncate_test_2) {
  s21_decimal value = {840328570, 543481259, 0, 2148597760};
  s21_decimal result = {0};
  int error = s21_truncate(value, &result);
  s21_decimal my_res = {23, 0, 0, 2147483648};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_truncate_test_3) {
  s21_decimal value = {9, 0, 0, 0};
  s21_decimal result = {0};
  int error = s21_truncate(value, &result);
  s21_decimal my_res = {9, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

// Тесты для функции -- int s21_negate(s21_decimal value, s21_decimal *result);
START_TEST(s21_negate_test_1) {
  s21_decimal value = {3020273018, 5453646, 0, 2148073472};
  s21_decimal result = {0};
  int error = s21_negate(value, &result);
  s21_decimal my_res = {3020273018, 5453646, 0, 589824};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_negate_test_2) {
  s21_decimal value = {1, 0, 0, 0};
  s21_decimal result = {0};
  int error = s21_negate(value, &result);
  s21_decimal my_res = {1, 0, 0, 2147483648};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_negate_test_3) {
  s21_decimal value = {0, 0, 0, 0};
  s21_decimal result = {0};
  int error = s21_negate(value, &result);
  s21_decimal my_res = {0, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(result, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

// Тесты для функции -- int s21_from_int_to_decimal(int src, s21_decimal *dst);
START_TEST(s21_from_int_to_decimal_test_1) {
  int num = 24321521;
  s21_decimal dst = {0};
  int error = s21_from_int_to_decimal(num, &dst);
  s21_decimal my_res = {24321521, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(dst, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_2) {
  int num = 1023;
  s21_decimal dst = {0};
  int error = s21_from_int_to_decimal(num, &dst);
  s21_decimal my_res = {1023, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(dst, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_3) {
  int num = 2147483647;
  s21_decimal dst = {0};
  int error = s21_from_int_to_decimal(num, &dst);
  s21_decimal my_res = {2147483647, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(dst, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_4) {
  int num = -2147483647;
  s21_decimal dst = {0};
  int error = s21_from_int_to_decimal(num, &dst);
  s21_decimal my_res = {2147483647, 0, 0, 2147483648};
  ck_assert_int_eq(1, s21_is_equal(dst, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

// Тесты для функции -- int s21_from_decimal_to_int(s21_decimal src, int *dst);
START_TEST(s21_from_decimal_to_int_test_1) {
  s21_decimal num = {12, 1, 1, 0};
  int dst = 0;
  int error = s21_from_decimal_to_int(num, &dst);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_2) {
  s21_decimal num = {12, 0, 0, 0};
  int dst = 0;
  int error = s21_from_decimal_to_int(num, &dst);
  int my_res = 12;
  ck_assert_int_eq(my_res, dst);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_3) {
  s21_decimal num = {15, 0, 0, 2147483648};
  int dst = 0;
  int error = s21_from_decimal_to_int(num, &dst);
  int my_res = -15;
  ck_assert_int_eq(my_res, dst);
  ck_assert_int_eq(0, error);
}
END_TEST

// Тесты для функции -- int s21_from_float_to_decimal(float src, s21_decimal
//*dst);
START_TEST(s21_from_float_to_decimal_test_1) {
  s21_decimal dst = {0};
  float src = 2423.4234867985946;
  int error = s21_from_float_to_decimal(src, &dst);
  s21_decimal my_res = {2423424, 0, 0, 196608};
  ck_assert_int_eq(1, s21_is_equal(dst, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_2) {
  s21_decimal dst = {0};
  float src = 345.3534534534553;
  int error = s21_from_float_to_decimal(src, &dst);
  s21_decimal my_res = {3453535, 0, 0, 262144};
  ck_assert_int_eq(1, s21_is_equal(dst, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_3) {
  s21_decimal dst = {0};
  float src = -23443.432143214;
  int error = s21_from_float_to_decimal(src, &dst);
  s21_decimal my_res = {2344343, 0, 0, 2147614720};
  ck_assert_int_eq(1, s21_is_equal(dst, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_4) {
  s21_decimal dst = {0};
  float src = 234234234.2342343;
  int error = s21_from_float_to_decimal(src, &dst);
  s21_decimal my_res = {234234200, 0, 0, 0};
  ck_assert_int_eq(1, s21_is_equal(dst, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_5) {
  s21_decimal dst = {0};
  float src = -634745634.3453454355435;
  int error = s21_from_float_to_decimal(src, &dst);
  s21_decimal my_res = {634745700, 0, 0, 2147483648};
  ck_assert_int_eq(1, s21_is_equal(dst, my_res));
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_6) {
  s21_decimal dst = {0};
  float src = 675374563475789347583475834758.364756375637486578346578346578;
  int error = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(1, error);
}
END_TEST

// Тесты для функции -- int s21_from_decimal_to_float(s21_decimal src, float
//*dst);
START_TEST(s21_from_decimal_to_float_test_1) {
  s21_decimal dst = {1235, 0, 0, 65536};
  float src = 0;
  int error = s21_from_decimal_to_float(dst, &src);
  float my_res = 123.5;
  ck_assert_float_eq(my_res, src);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_2) {
  s21_decimal dst = {232345, 0, 0, 2147745792};
  float src = 0;
  int error = s21_from_decimal_to_float(dst, &src);
  float my_res = -23.234501;
  ck_assert_float_eq(my_res, src);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_3) {
  s21_decimal dst = {123, 0, 0, 0};
  float src = 0;
  int error = s21_from_decimal_to_float(dst, &src);
  float my_res = 123;
  ck_assert_float_eq(my_res, src);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_4) {
  s21_decimal dst = {3168855713, 2861500730, 404, 1245184};
  float src = 0;
  int error = s21_from_decimal_to_float(dst, &src);
  float my_res = 746.477478;
  ck_assert_float_eq(my_res, src);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_5) {
  s21_decimal dst = {3324578355, 3118562186, 177, 2148139008};
  float src = 0;
  int error = s21_from_decimal_to_float(dst, &src);
  float my_res = -327846789120.000000;
  ck_assert_float_eq(my_res, src);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_6) {
  s21_decimal dst = {3530903579, 2287235292, 4329, 0};
  float src = 0;
  int error = s21_from_decimal_to_float(dst, &src);
  float my_res = 79865781949475571367936.000000;
  ck_assert_float_eq(my_res, src);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_7) {
  s21_decimal dst = {4030853249, 2813828934, 11613, 589824};
  float src = 0;
  int error = s21_from_decimal_to_float(dst, &src);
  float my_res = 214234092797952.000000;
  ck_assert_float_eq(my_res, src);
  ck_assert_int_eq(0, error);
}
END_TEST

// Набор тестов для функции -- int s21_add(s21_decimal value_1, s21_decimal
// value_2, s21_decimal *result);
Suite *s21_add_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("1)add");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_add_test_1);
  tcase_add_test(test_core, s21_add_test_2);
  tcase_add_test(test_core, s21_add_test_3);
  tcase_add_test(test_core, s21_add_test_4);
  tcase_add_test(test_core, s21_add_test_5);
  tcase_add_test(test_core, s21_add_test_6);
  tcase_add_test(test_core, s21_add_test_7);
  tcase_add_test(test_core, s21_add_test_8);
  tcase_add_test(test_core, s21_add_test_9);
  tcase_add_test(test_core, s21_add_test_10);
  tcase_add_test(test_core, s21_add_test_11);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции -- int s21_sub(s21_decimal value_1, s21_decimal
// value_2, s21_decimal *result);
Suite *s21_sub_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("2)sub");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_sub_test_1);
  tcase_add_test(test_core, s21_sub_test_2);
  tcase_add_test(test_core, s21_sub_test_3);
  tcase_add_test(test_core, s21_sub_test_4);
  tcase_add_test(test_core, s21_sub_test_5);
  tcase_add_test(test_core, s21_sub_test_6);
  tcase_add_test(test_core, s21_sub_test_7);
  tcase_add_test(test_core, s21_sub_test_8);
  tcase_add_test(test_core, s21_sub_test_9);
  tcase_add_test(test_core, s21_sub_test_10);
  tcase_add_test(test_core, s21_sub_test_11);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции -- int s21_mul(s21_decimal value_1, s21_decimal
// value_2, s21_decimal *result);
Suite *s21_mul_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("3)mul");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_mul_test_1);
  tcase_add_test(test_core, s21_mul_test_2);
  tcase_add_test(test_core, s21_mul_test_3);
  tcase_add_test(test_core, s21_mul_test_4);
  tcase_add_test(test_core, s21_mul_test_5);
  tcase_add_test(test_core, s21_mul_test_6);
  tcase_add_test(test_core, s21_mul_test_7);
  tcase_add_test(test_core, s21_mul_test_8);
  tcase_add_test(test_core, s21_mul_test_9);
  tcase_add_test(test_core, s21_mul_test_10);
  tcase_add_test(test_core, s21_mul_test_11);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции -- int s21_div(s21_decimal value_1, s21_decimal
// value_2, s21_decimal *result);
Suite *s21_div_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("4)div");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_div_test_1);
  tcase_add_test(test_core, s21_div_test_2);
  tcase_add_test(test_core, s21_div_test_3);
  tcase_add_test(test_core, s21_div_test_4);
  tcase_add_test(test_core, s21_div_test_5);
  tcase_add_test(test_core, s21_div_test_6);
  tcase_add_test(test_core, s21_div_test_7);
  tcase_add_test(test_core, s21_div_test_8);
  tcase_add_test(test_core, s21_div_test_9);
  tcase_add_test(test_core, s21_div_test_10);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции -- int s21_is_less(s21_decimal value_1, s21_decimal
// value_2);
Suite *s21_is_less_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("5)is_less");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_is_less_test_1);
  tcase_add_test(test_core, s21_is_less_test_2);
  tcase_add_test(test_core, s21_is_less_test_3);
  tcase_add_test(test_core, s21_is_less_test_4);
  tcase_add_test(test_core, s21_is_less_test_5);
  tcase_add_test(test_core, s21_is_less_test_6);
  tcase_add_test(test_core, s21_is_less_test_7);
  tcase_add_test(test_core, s21_is_less_test_8);
  tcase_add_test(test_core, s21_is_less_test_9);
  tcase_add_test(test_core, s21_is_less_test_10);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции -- int s21_is_less_or_equal(s21_decimal,
// s21_decimal);
Suite *s21_is_less_or_equal_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("6)is_less_or_equal");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_is_less_or_equal_test_1);
  tcase_add_test(test_core, s21_is_less_or_equal_test_2);
  tcase_add_test(test_core, s21_is_less_or_equal_test_3);
  tcase_add_test(test_core, s21_is_less_or_equal_test_4);
  tcase_add_test(test_core, s21_is_less_or_equal_test_5);
  tcase_add_test(test_core, s21_is_less_or_equal_test_6);
  tcase_add_test(test_core, s21_is_less_or_equal_test_7);
  tcase_add_test(test_core, s21_is_less_or_equal_test_8);
  tcase_add_test(test_core, s21_is_less_or_equal_test_9);
  tcase_add_test(test_core, s21_is_less_or_equal_test_10);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции -- int s21_is_greater(s21_decimal, s21_decimal);
Suite *s21_is_greater_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("7)is_greater");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_is_greater_test_1);
  tcase_add_test(test_core, s21_is_greater_test_2);
  tcase_add_test(test_core, s21_is_greater_test_3);
  tcase_add_test(test_core, s21_is_greater_test_4);
  tcase_add_test(test_core, s21_is_greater_test_5);
  tcase_add_test(test_core, s21_is_greater_test_6);
  tcase_add_test(test_core, s21_is_greater_test_7);
  tcase_add_test(test_core, s21_is_greater_test_8);
  tcase_add_test(test_core, s21_is_greater_test_9);
  tcase_add_test(test_core, s21_is_greater_test_10);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции -- int s21_is_greater_or_equal(s21_decimal,
// s21_decimal);
Suite *s21_is_greater_or_equal_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("8)is_greater_or_equal");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_is_greater_or_equal_test_1);
  tcase_add_test(test_core, s21_is_greater_or_equal_test_2);
  tcase_add_test(test_core, s21_is_greater_or_equal_test_3);
  tcase_add_test(test_core, s21_is_greater_or_equal_test_4);
  tcase_add_test(test_core, s21_is_greater_or_equal_test_5);
  tcase_add_test(test_core, s21_is_greater_or_equal_test_6);
  tcase_add_test(test_core, s21_is_greater_or_equal_test_7);
  tcase_add_test(test_core, s21_is_greater_or_equal_test_8);
  tcase_add_test(test_core, s21_is_greater_or_equal_test_9);
  tcase_add_test(test_core, s21_is_greater_or_equal_test_10);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции -- int s21_is_equal(s21_decimal, s21_decimal);
Suite *s21_is_equal_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("9)is_equal");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_is_equal_test_1);
  tcase_add_test(test_core, s21_is_equal_test_2);
  tcase_add_test(test_core, s21_is_equal_test_3);
  tcase_add_test(test_core, s21_is_equal_test_4);
  tcase_add_test(test_core, s21_is_equal_test_5);
  tcase_add_test(test_core, s21_is_equal_test_6);
  tcase_add_test(test_core, s21_is_equal_test_7);
  tcase_add_test(test_core, s21_is_equal_test_8);
  tcase_add_test(test_core, s21_is_equal_test_9);
  tcase_add_test(test_core, s21_is_equal_test_10);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции -- int s21_is_not_equal(s21_decimal, s21_decimal);
Suite *s21_is_not_equal_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("10)is_not_equal");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_is_not_equal_test_1);
  tcase_add_test(test_core, s21_is_not_equal_test_2);
  tcase_add_test(test_core, s21_is_not_equal_test_3);
  tcase_add_test(test_core, s21_is_not_equal_test_4);
  tcase_add_test(test_core, s21_is_not_equal_test_5);
  tcase_add_test(test_core, s21_is_not_equal_test_6);
  tcase_add_test(test_core, s21_is_not_equal_test_7);
  tcase_add_test(test_core, s21_is_not_equal_test_8);
  tcase_add_test(test_core, s21_is_not_equal_test_9);
  tcase_add_test(test_core, s21_is_not_equal_test_10);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции -- int s21_floor(s21_decimal value, s21_decimal
// *result);
Suite *s21_floor_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("11)floor");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_floor_test_1);
  tcase_add_test(test_core, s21_floor_test_2);
  tcase_add_test(test_core, s21_floor_test_3);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции -- int s21_round(s21_decimal value, s21_decimal
// *result);
Suite *s21_round_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("12)round");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_round_test_1);
  tcase_add_test(test_core, s21_round_test_2);
  tcase_add_test(test_core, s21_round_test_3);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции -- int s21_truncate(s21_decimal value, s21_decimal
// *result);
Suite *s21_truncate_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("13)truncate");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_truncate_test_1);
  tcase_add_test(test_core, s21_truncate_test_2);
  tcase_add_test(test_core, s21_truncate_test_3);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции -- int s21_negate(s21_decimal value, s21_decimal
// *result);
Suite *s21_negate_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("14)negate");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_negate_test_1);
  tcase_add_test(test_core, s21_negate_test_2);
  tcase_add_test(test_core, s21_negate_test_3);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции -- int s21_from_int_to_decimal(int src, s21_decimal
// *dst);
Suite *s21_from_int_to_decimal_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("15)int_to_decimal");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_from_int_to_decimal_test_1);
  tcase_add_test(test_core, s21_from_int_to_decimal_test_2);
  tcase_add_test(test_core, s21_from_int_to_decimal_test_3);
  tcase_add_test(test_core, s21_from_int_to_decimal_test_4);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции -- int s21_from_decimal_to_int(s21_decimal src, int
// *dst);
Suite *s21_from_decimal_to_int_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("16)from_decimal_to_int");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_from_decimal_to_int_test_1);
  tcase_add_test(test_core, s21_from_decimal_to_int_test_2);
  tcase_add_test(test_core, s21_from_decimal_to_int_test_3);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции -- int s21_from_float_to_decimal(float src,
// s21_decimal *dst);
Suite *s21_from_float_to_decimal_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("17)from_float_to_decimal");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_from_float_to_decimal_test_1);
  tcase_add_test(test_core, s21_from_float_to_decimal_test_2);
  tcase_add_test(test_core, s21_from_float_to_decimal_test_3);
  tcase_add_test(test_core, s21_from_float_to_decimal_test_4);
  tcase_add_test(test_core, s21_from_float_to_decimal_test_5);
  tcase_add_test(test_core, s21_from_float_to_decimal_test_6);
  suite_add_tcase(selection, test_core);
  return selection;
}

// Набор тестов для функции -- int s21_from_decimal_to_float(s21_decimal src,
// float *dst);
Suite *s21_from_decimal_to_float_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("18)from_decimal_to_float");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_from_decimal_to_float_test_1);
  tcase_add_test(test_core, s21_from_decimal_to_float_test_2);
  tcase_add_test(test_core, s21_from_decimal_to_float_test_3);
  tcase_add_test(test_core, s21_from_decimal_to_float_test_4);
  tcase_add_test(test_core, s21_from_decimal_to_float_test_5);
  tcase_add_test(test_core, s21_from_decimal_to_float_test_6);
  tcase_add_test(test_core, s21_from_decimal_to_float_test_7);
  suite_add_tcase(selection, test_core);
  return selection;
}

void case_tests(Suite *selection, int *fail) {
  SRunner *runner = srunner_create(selection);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int fail = 0;
  // Арифметические операторы
  case_tests(s21_add_suite(), &fail);
  case_tests(s21_sub_suite(), &fail);
  case_tests(s21_mul_suite(), &fail);
  case_tests(s21_div_suite(), &fail);
  // Операторы сравнения
  case_tests(s21_is_less_suite(), &fail);
  case_tests(s21_is_less_or_equal_suite(), &fail);
  case_tests(s21_is_greater_suite(), &fail);
  case_tests(s21_is_greater_or_equal_suite(), &fail);
  case_tests(s21_is_equal_suite(), &fail);
  case_tests(s21_is_not_equal_suite(), &fail);
  // Другие функции
  case_tests(s21_floor_suite(), &fail);
  case_tests(s21_round_suite(), &fail);
  case_tests(s21_truncate_suite(), &fail);
  case_tests(s21_negate_suite(), &fail);
  // Преобразователи
  case_tests(s21_from_int_to_decimal_suite(), &fail);
  case_tests(s21_from_decimal_to_int_suite(), &fail);
  case_tests(s21_from_float_to_decimal_suite(), &fail);
  case_tests(s21_from_decimal_to_float_suite(), &fail);
  return 0;
}