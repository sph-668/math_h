// Copyright 2021 rmarchel, jjalikak, rbabara//

#include "s21_math_test.h"

START_TEST(inf_check) {
  int test_number = 1000;
  ck_assert_msg(s21_isinf((float)test_number) == isinf((float)test_number),
                "IsInf. Positive integer number");

  test_number = -1000;
  ck_assert_msg(s21_isinf((float)test_number) == isinf((float)test_number),
                "IsInf. Negative integer number");

  test_number = 0;
  ck_assert_msg(s21_isinf((float)test_number) == isinf((float)test_number),
                "IsInf. Zero integer number");

  double test_double_number = 123456.123456;
  ck_assert_msg(s21_isinf(test_double_number) == isinf(test_double_number),
                "IsInf. Positive double number");

  test_double_number = -123456.123456;
  ck_assert_msg(s21_isinf(test_double_number) == isinf(test_double_number),
                "IsInf. Negative double number");

  ck_assert_msg(s21_isinf((double)(2147483649 * 2147483649)) ==
                    isinf((double)(2147483649 * 2147483649)),
                "IsInf. Huge integer number");

  ck_assert_msg(s21_isinf((double)(-2147483649 * 2147483649)) ==
                    isinf((double)(-2147483649 * 2147483649)),
                "IsInf. Small integer number");

  ck_assert_msg(s21_isinf((double)(2147483649.123456 * 2147483649.123456)) ==
                    isinf((double)(2147483649.123456 * 2147483649.123456)),
                "IsInf. Huge double number");

  ck_assert_msg(s21_isinf((double)(-2147483649.123456 * 2147483649.123456)) ==
                    isinf((double)(-2147483649.123456 * 2147483649.123456)),
                "IsInf. Small double number");

  ck_assert_msg(s21_isinf((DBL_MAX)) == isinf((DBL_MAX)),
                "IsInf. DBL_MAX number");

  ck_assert_msg(s21_isinf((DBL_MIN)) == isinf((DBL_MIN)),
                "IsInf. DBL_MIN number");

  test_double_number = INFINITY;
  ck_assert_msg(s21_isinf(test_double_number) == isinf(test_double_number),
                "IsInf. Infinity number");

  test_double_number = -INFINITY;
  ck_assert_msg(s21_isinf(test_double_number) == isinf(test_double_number),
                "IsInf. Minus infinity number");

  ck_assert_msg(s21_isinf(0. / 0.) == isinf(0. / 0.), "IsInf. NaN number");

  ck_assert_msg(s21_isinf(sqrt(-1)) == isinf(sqrt(-1)),
                "IsInf. Sqrt NaN number");
}
END_TEST

START_TEST(nan_check) {
  int test_number = 1000;
  ck_assert_msg(s21_isnan((float)test_number) == isnan((float)test_number),
                "IsNaN. Positive integer number");

  test_number = -1000;
  ck_assert_msg(s21_isnan((float)test_number) == isnan((float)test_number),
                "IsNaN. Negative integer number");

  test_number = 0;
  ck_assert_msg(s21_isnan((float)test_number) == isnan((float)test_number),
                "IsNaN. Zero integer number");

  double test_double_number = 123456.123456;
  ck_assert_msg(s21_isnan(test_double_number) == isnan(test_double_number),
                "IsNaN. Positive double number");

  test_double_number = -123456.123456;
  ck_assert_msg(s21_isnan(test_double_number) == isnan(test_double_number),
                "IsNaN. Negative double number");

  ck_assert_msg(s21_isnan((DBL_MAX)) == isnan((DBL_MAX)),
                "IsNaN. DBL_MAX number");

  ck_assert_msg(s21_isnan((DBL_MIN)) == isnan((DBL_MIN)),
                "IsNaN. DBL_MIN number");

  ck_assert_msg(s21_isnan((double)(2147483649 * 2147483649)) ==
                    isnan((double)(2147483649 * 2147483649)),
                "IsInf. Huge integer number");

  ck_assert_msg(s21_isnan((double)(-2147483649 * 2147483649)) ==
                    isnan((double)(-2147483649 * 2147483649)),
                "IsInf. Small integer number");

  ck_assert_msg(s21_isnan((double)(2147483649.123456 * 2147483649.123456)) ==
                    isnan((double)(2147483649.123456 * 2147483649.123456)),
                "IsInf. Huge double number");

  ck_assert_msg(s21_isnan((double)(-2147483649.123456 * 2147483649.123456)) ==
                    isnan((double)(-2147483649.123456 * 2147483649.123456)),
                "IsInf. Small double number");

  test_double_number = INFINITY;
  ck_assert_msg(s21_isnan(test_double_number) == isnan(test_double_number),
                "IsNaN. Infinity number");

  test_double_number = -INFINITY;
  ck_assert_msg(s21_isnan(test_double_number) == isnan(test_double_number),
                "IsNaN. Minus infinity number");

  ck_assert_msg(s21_isnan(0. / 0.) == isnan(0. / 0.), "IsNaN. NaN number");

  ck_assert_msg(s21_isnan(sqrt(-1)) == isnan(sqrt(-1)),
                "IsNaN. Sqrt NaN number");
}
END_TEST

START_TEST(abs_check) {
  int positive_number = 1000;
  ck_assert_msg(abs(positive_number) == s21_abs(positive_number),
                "Abs. Positive integer number");

  int negative_number = -1000;
  ck_assert_msg(abs(negative_number) == s21_abs(negative_number),
                "Abs. Negative integer number");

  int zero_number = 0;
  ck_assert_msg(abs(zero_number) == s21_abs(zero_number), "Abs. Zero number");

  ck_assert_msg(abs((int)2147483649) == s21_abs((int)2147483649),
                "Abs. Huge integer number");

  ck_assert_msg(abs((int)-2147483649) == s21_abs((int)-2147483649),
                "Abs. Small integer number");

  ck_assert_msg(s21_abs(0 * -5) == abs(0 * -5), "Abs. Minus Zero");
}
END_TEST

START_TEST(fabs_check) {
  int positive_number = 123456789;
  ck_assert_msg(
      fabs((double)positive_number) == s21_fabs((double)positive_number),
      "Fabs. Positive integer number");

  int negative_number = -123456789;
  ck_assert_msg(
      fabs((double)negative_number) == s21_fabs((double)negative_number),
      "Fabs. Negative integer number");

  double positive_double_number = 123456.123456;
  ck_assert_msg(
      fabs(positive_double_number) == s21_fabs(positive_double_number),
      "Fabs. Positive double number");

  double negative_double_number = -123456.123456;
  ck_assert_msg(
      fabs(negative_double_number) == s21_fabs(negative_double_number),
      "Fabs. Negative double number");

  int zero_number = 0;
  ck_assert_msg(fabs((double)zero_number) == s21_fabs((double)zero_number),
                "Fabs. Zero number");

  ck_assert_msg(fabs((double)(2147483649 * 2147483649)) ==
                    s21_fabs((double)(2147483649 * 2147483649)),
                "Fabs. Huge integer number");

  ck_assert_msg(fabs((double)(-2147483649 * 2147483649)) ==
                    s21_fabs((double)(-2147483649 * 2147483649)),
                "Fabs. Small integer number");

  ck_assert_msg(fabs((double)(2147483649.123456 * 2147483649.123456)) ==
                    s21_fabs((double)(2147483649.123456 * 2147483649.123456)),
                "Fabs. Huge double number");

  ck_assert_msg(fabs((double)(-2147483649.123456 * 2147483649.123456)) ==
                    s21_fabs((double)(-2147483649.123456 * 2147483649.123456)),
                "Fabs. Small double number");

  ck_assert_msg(s21_fabs((DBL_MAX)) == fabs((DBL_MAX)), "Fabs. DBL_MAX number");

  ck_assert_msg(s21_fabs((DBL_MIN)) == fabs((DBL_MIN)), "Fabs. DBL_MIN number");

  ck_assert_msg(isinf(s21_fabs(INFINITY)) == isinf(fabs(INFINITY)),
                "Fabs. Infinity number");

  ck_assert_msg(isinf(s21_fabs(-INFINITY)) == isinf(fabs(-INFINITY)),
                "Fabs. Minus Infinity number");

  ck_assert_msg(isnan(s21_fabs(0. / 0.)) == isnan(fabs(0. / 0.)),
                "Fabs. NaN number");

  ck_assert_msg(s21_fabs(0 * -5) == fabs((double)0 * -5), "Fabs. Minus Zero");
}
END_TEST

START_TEST(sqrt_check) {
  double test_number = 987654321;
  long double a = 0, b = 0;
  a = s21_sqrt(test_number);
  b = sqrt(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Sqrt. Positive integer number");

  test_number = 9.876e+108;
  a = s21_sqrt(test_number);
  b = sqrt(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Sqrt. Big positive integer number");

  test_number = -123456789;
  a = s21_sqrt(test_number);
  b = sqrt(test_number);
  ck_assert_msg(isnan(a) && isnan(b), "Sqrt. Negative integer number");

  test_number = -1.234e+109;
  a = s21_sqrt(test_number);
  b = sqrt(test_number);
  ck_assert_msg(isnan(a) && isnan(b), "Sqrt. Big negative integer number");

  test_number = 123456789.17263772472547254;
  a = s21_sqrt(test_number);
  b = sqrt(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Sqrt. Positive double number");

  test_number = -123456789.17263772472547254;
  a = s21_sqrt(test_number);
  b = sqrt(test_number);
  ck_assert_msg(isnan(a) && isnan(b), "Sqrt. Negative double number");

  test_number = 0;
  a = s21_sqrt(test_number);
  b = sqrt(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Sqrt. Zero number");

  test_number = (double)(2147483649 * 2147483649);
  a = s21_sqrt(test_number);
  b = sqrt(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Sqrt. Huge integer number");

  test_number = (double)(-2147483649 * 2147483649);
  a = (double)s21_sqrt(test_number);
  b = (double)sqrt(test_number);
  ck_assert_msg(isnan(a) && isnan(b), "Sqrt. Small integer number");

  test_number = (double)(2147483649.123456 * 2147483649.123456);
  a = s21_sqrt(test_number);
  b = sqrt(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Sqrt. Huge double number");

  ck_assert_msg(fabs((double)sqrt(DBL_MIN) - (double)s21_sqrt(DBL_MIN)) < EPS,
                "Sqrt. DBL_MIN number");

  test_number = (-2147483649.123456 * 2147483649.123456);
  a = s21_sqrt(test_number);
  b = sqrt(test_number);
  ck_assert_msg(isnan(a) && isnan(b), "Sqrt. Small double number");

  ck_assert_msg(isinf(s21_sqrt(INFINITY)) == isinf(sqrt(INFINITY)),
                "Sqrt. Infinity number");

  ck_assert_msg(isinf(s21_sqrt(-INFINITY)) == isinf(sqrt(-INFINITY)),
                "Sqrt. Minus Infinity number");

  ck_assert_msg(fabs((double)s21_sqrt(0 * -5) - (double)sqrt(0 * -5)) < EPS,
                "Sqrt. Minus Zero");
}
END_TEST

START_TEST(sin_check) {
  double test_number = 1234567;
  long double a = 0, b = 0;
  a = s21_sin(test_number);
  b = sin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Sin. Positive integer number");

  test_number = -12345;
  a = s21_sin(test_number);
  b = sin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Sin. Negative integer number");

  test_number = 12345.123456;
  a = s21_sin(test_number);
  b = sin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Sin. Positive double number");

  test_number = -12345.123456;
  a = s21_sin(test_number);
  b = sin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Sin. Negative double number");

  test_number = 0;
  a = s21_sin(test_number);
  b = sin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Sin. Zero number");

  test_number = 1;
  a = s21_sin(test_number);
  b = sin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Sin. 1 number");

  test_number = 30;
  a = s21_sin(test_number);
  b = sin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Sin. 30 number");

  test_number = 45;
  a = s21_sin(test_number);
  b = sin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Sin. 45 number");

  test_number = 60;
  a = s21_sin(test_number);
  b = sin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Sin. 60 number");

  test_number = 90;
  a = s21_sin(test_number);
  b = sin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Sin. 90 number");

  test_number = -1;
  a = s21_sin(test_number);
  b = sin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Sin. Minus 1 number");

  test_number = -30;
  a = s21_sin(test_number);
  b = sin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Sin. Minus 30 number");

  test_number = -45;
  a = s21_sin(test_number);
  b = sin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Sin. Minus 45 number");

  test_number = -60;
  a = s21_sin(test_number);
  b = sin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Sin. Minus 60 number");

  test_number = -90;
  a = s21_sin(test_number);
  b = sin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Sin. Minus 90 number");

  ck_assert_msg(isinf(s21_sin(INFINITY)) == isinf(sin(INFINITY)),
                "Sin. Infinity number");

  ck_assert_msg(isinf(s21_sin(-INFINITY)) == isinf(sin(-INFINITY)),
                "Sin. Minus Infinity number");

  ck_assert_msg(isnan(s21_sin(0. / 0.)) == isnan(sin(0. / 0.)),
                "Sin. NaN number");

  ck_assert_msg(s21_sin(0 * -5) == sin(0 * -5), "Sin. Minus Zero");
}
END_TEST

START_TEST(cos_check) {
  double test_number = 12345;
  long double a = 0, b = 0;
  a = s21_cos(test_number);
  b = cos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Cos. Positive integer number");

  test_number = -12345;
  a = s21_cos(test_number);
  b = cos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Cos. Negative integer number");

  test_number = 12345.123456;
  a = s21_cos(test_number);
  b = cos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Cos. Positive double number");

  test_number = -12345.123456;
  a = s21_cos(test_number);
  b = cos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Cos. Negative double number");

  test_number = 0;
  a = s21_cos(test_number);
  b = cos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Cos. Zero number");

  test_number = 1;
  a = s21_cos(test_number);
  b = cos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Cos. 1 number");

  test_number = 30;
  a = s21_cos(test_number);
  b = cos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Cos. 30 number");

  test_number = 45;
  a = s21_cos(test_number);
  b = cos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Cos. 45 number");

  test_number = 60;
  a = s21_cos(test_number);
  b = cos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Cos. 60 number");

  test_number = 90;
  a = s21_cos(test_number);
  b = cos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Cos. 90 number");

  test_number = -1;
  a = s21_cos(test_number);
  b = cos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Cos. Minus 1 number");

  test_number = -30;
  a = s21_cos(test_number);
  b = cos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Cos. Minus 30 number");

  test_number = -45;
  a = s21_cos(test_number);
  b = cos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Cos. Minus 45 number");

  test_number = -60;
  a = s21_cos(test_number);
  b = cos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Cos. Minus 60 number");

  test_number = -90;
  a = s21_cos(test_number);
  b = cos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Cos. Minus 90 number");

  ck_assert_msg(isinf(s21_cos(INFINITY)) == isinf(cos(INFINITY)),
                "Cos. Infinity number");

  ck_assert_msg(isinf(s21_cos(-INFINITY)) == isinf(cos(-INFINITY)),
                "Cos. Minus Infinity number");

  ck_assert_msg(isnan(s21_cos(0. / 0.)) == isnan(cos(0. / 0.)),
                "Cos. NaN number");

  ck_assert_msg(s21_cos(0 * -5) == cos(0 * -5), "Cos. Minus Zero");
}
END_TEST

START_TEST(tan_check) {
  double test_number = 12345;
  long double a = 0, b = 0;
  a = s21_tan(test_number);
  b = tan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Tan. Positive integer number");

  test_number = -12345;
  a = s21_tan(test_number);
  b = tan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Tan. Negative integer number");

  test_number = 12345.123456;
  a = s21_tan(test_number);
  b = tan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Tan. Positive double number");

  test_number = -12345.123456;
  a = s21_tan(test_number);
  b = tan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Tan. Negative double number");

  test_number = 0;
  a = s21_tan(test_number);
  b = tan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Tan. Zero number");

  test_number = 1;
  a = s21_tan(test_number);
  b = tan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Tan. 1 number");

  test_number = 30;
  a = s21_tan(test_number);
  b = tan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Tan. 30 number");

  test_number = 45;
  a = s21_tan(test_number);
  b = tan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Tan. 45 number");

  test_number = 60;
  a = s21_tan(test_number);
  b = tan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Tan. 60 number");

  test_number = 90;
  a = s21_tan(test_number);
  b = tan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Tan. 90 number");

  test_number = -1;
  a = s21_tan(test_number);
  b = tan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Tan. Minus 1 number");

  test_number = -30;
  a = s21_tan(test_number);
  b = tan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Tan. Minus 30 number");

  test_number = -45;
  a = s21_tan(test_number);
  b = tan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Tan. Minus 45 number");

  test_number = -60;
  a = s21_tan(test_number);
  b = tan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Tan. Minus 60 number");

  test_number = -90;
  a = s21_tan(test_number);
  b = tan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Tan. Minus 90 number");

  ck_assert_msg(isinf(s21_tan(INFINITY)) == isinf(tan(INFINITY)),
                "Tan. Infinity number");

  ck_assert_msg(isinf(s21_tan(-INFINITY)) == isinf(tan(-INFINITY)),
                "Tan. Minus Infinity number");

  ck_assert_msg(isnan(s21_tan(0. / 0.)) == isnan(tan(0. / 0.)),
                "Tan. NaN number");

  ck_assert_msg(s21_tan(0 * -5) == tan(0 * -5), "Tan. Minus Zero");
}
END_TEST

START_TEST(asin_check) {
  double test_number = 0.0;
  long double a = 0, b = 0;

  test_number = 0.9;
  a = s21_asin(test_number);
  b = asin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Asin. Positive integer number");

  test_number = -0.9;
  a = s21_asin(test_number);
  b = asin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Asin. Negative integer number");

  test_number = 0.5;
  a = s21_asin(test_number);
  b = asin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Asin. Positive double number");

  test_number = -0.5;
  a = s21_asin(test_number);
  b = asin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Asin. Negative double number");

  test_number = 0.123456;
  a = s21_asin(test_number);
  b = asin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Asin. Positive huge double number");

  test_number = -0.123456;
  a = s21_asin(test_number);
  b = asin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Asin. Negative huge double number");

  test_number = 0;
  a = s21_asin(test_number);
  b = asin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Asin. Zero number");

  test_number = -1;
  a = s21_asin(test_number);
  b = asin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Asin. -1 number");

  test_number = 1;
  a = s21_asin(test_number);
  b = asin(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Asin. 1 number");

  test_number = 10;
  a = s21_asin(test_number);
  b = asin(test_number);
  ck_assert_msg(isnan(a) == isnan(b), "Asin. Number > 1");

  test_number = -10;
  a = s21_asin(test_number);
  b = asin(test_number);
  ck_assert_msg(isnan(a) == isnan(b), "Asin. Number < -1");

  ck_assert_msg(isinf(s21_asin(INFINITY)) == isinf(asin(INFINITY)),
                "Asin. Infinity number");

  ck_assert_msg(isinf(s21_asin(-INFINITY)) == isinf(asin(-INFINITY)),
                "Asin. Minus Infinity number");

  ck_assert_msg(isnan(s21_asin(0. / 0.)) == isnan(asin(0. / 0.)),
                "Asin. NaN number");

  a = s21_asin(0 * -5);
  b = asin(0 * -5);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Acos. Minus Zero");
}
END_TEST

START_TEST(acos_check) {
  double test_number = 0.0;
  long double a = 0, b = 0;

  test_number = 0.9;
  a = s21_acos(test_number);
  b = acos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Acos. Positive integer number");

  test_number = -0.9;
  a = s21_acos(test_number);
  b = acos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Acos. Negative integer number");

  test_number = 0.5;
  a = s21_acos(test_number);
  b = acos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Acos. Positive double number");

  test_number = -0.5;
  a = s21_acos(test_number);
  b = acos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Acos. Negative double number");

  test_number = 0.123456;
  a = s21_acos(test_number);
  b = acos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Acos. Positive huge double number");

  test_number = -0.123456;
  a = s21_acos(test_number);
  b = acos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Acos. Negative huge double number");

  test_number = 0;
  a = s21_acos(test_number);
  b = acos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Acos. Zero number");

  test_number = -1;
  a = s21_acos(test_number);
  b = acos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Acos. -1 number");

  test_number = 1;
  a = s21_acos(test_number);
  b = acos(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Acos. 1 number");

  test_number = 10;
  a = s21_acos(test_number);
  b = acos(test_number);
  ck_assert_msg(isnan(a) == isnan(b), "Acos. Number > 1");

  test_number = -10;
  a = s21_acos(test_number);
  b = acos(test_number);
  ck_assert_msg(isnan(a) == isnan(b), "Acos. Number < -1");

  ck_assert_msg(isinf(s21_acos(INFINITY)) == isinf(acos(INFINITY)),
                "Acos. Infinity number");

  ck_assert_msg(isinf(s21_acos(-INFINITY)) == isinf(acos(-INFINITY)),
                "Acos. Minus Infinity number");

  ck_assert_msg(isnan(s21_acos(0. / 0.)) == isnan(acos(0. / 0.)),
                "Acos. NaN number");

  a = s21_acos(0 * -5);
  b = acos(0 * -5);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Acos. Minus Zero");
}
END_TEST

START_TEST(atan_check) {
  double test_number = 0.0;
  long double a = 0, b = 0;

  test_number = 0.9;
  a = s21_atan(test_number);
  b = atan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Atan. Positive integer number");

  test_number = -0.9;
  a = s21_atan(test_number);
  b = atan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Atan. Negative integer number");

  test_number = 0.5;
  a = s21_atan(test_number);
  b = atan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Atan. Positive double number");

  test_number = -0.5;
  a = s21_atan(test_number);
  b = atan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Atan. Negative double number");

  test_number = 0.123456;
  a = s21_atan(test_number);
  b = atan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Atan. Positive huge double number");

  test_number = -0.123456;
  a = s21_atan(test_number);
  b = atan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Atan. Negative huge double number");

  test_number = 0;
  a = s21_atan(test_number);
  b = atan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Atan. Zero number");

  test_number = -1;
  a = s21_atan(test_number);
  b = atan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Atan. -1 number");

  test_number = 1;
  a = s21_atan(test_number);
  b = atan(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Atan. 1 number");

  test_number = 10;
  a = s21_atan(test_number);
  b = atan(test_number);
  ck_assert_msg(isnan(a) == isnan(b), "Atan. Number > 1");

  test_number = -10;
  a = s21_atan(test_number);
  b = atan(test_number);
  ck_assert_msg(isnan(a) == isnan(b), "Atan. Number < -1");

  ck_assert_msg(isinf(s21_atan(INFINITY)) == isinf(atan(INFINITY)),
                "Atan. Infinity number");

  ck_assert_msg(isinf(s21_atan(-INFINITY)) == isinf(atan(-INFINITY)),
                "Atan. Minus Infinity number");

  ck_assert_msg(isnan(s21_atan(0. / 0.)) == isnan(atan(0. / 0.)),
                "Atan. NaN number");

  ck_assert_msg(s21_atan(0 * -5) == atan(0 * -5), "Atan. Minus Zero");
}
END_TEST

START_TEST(pow_check) {
  double test_number = 300;
  double test_number_exp = 8;
  long double a = 0, b = 0;
  a = s21_pow(test_number, test_number_exp);
  b = pow(test_number, test_number_exp);
  ck_assert_msg(a == b, "Pow. Positive integer number, positive exp");

  test_number = -300;
  test_number_exp = 8;
  a = s21_pow(test_number, test_number_exp);
  b = pow(test_number, test_number_exp);
  ck_assert_msg(a == b, "Pow. Negative integer number, positive exp");

  test_number = 123.123456;
  test_number_exp = 8;
  a = s21_pow(test_number, test_number_exp);
  b = pow(test_number, test_number_exp);
  ck_assert_msg(a == b, "Pow. Positive double number, positive exp");

  test_number = -123.123456;
  test_number_exp = 8;
  a = s21_pow(test_number, test_number_exp);
  b = pow(test_number, test_number_exp);
  ck_assert_msg(a == b, "Pow. Negative double number, positive exp");

  test_number = 300;
  test_number_exp = -8;
  a = s21_pow(test_number, test_number_exp);
  b = pow(test_number, test_number_exp);
  ck_assert_msg(a == b, "Pow. Positive integer number, negative exp");

  test_number = -300;
  test_number_exp = -8;
  a = s21_pow(test_number, test_number_exp);
  b = pow(test_number, test_number_exp);
  ck_assert_msg(a == b, "Pow. Negative integer number, negative exp");

  test_number = 123.123456;
  test_number_exp = -8;
  a = s21_pow(test_number, test_number_exp);
  b = pow(test_number, test_number_exp);
  ck_assert_msg(a == b, "Pow. Positive double number, negative exp");

  test_number = -123.123456;
  test_number_exp = -8;
  a = s21_pow(test_number, test_number_exp);
  b = pow(test_number, test_number_exp);
  ck_assert_msg(a == b, "Pow. Negative double number, negative exp");

  test_number = -123.123456;
  test_number_exp = 0;
  a = s21_pow(test_number, test_number_exp);
  b = pow(test_number, test_number_exp);
  ck_assert_msg(a == b, "Pow. Zero number");

  test_number = 0;
  test_number_exp = 0;
  a = s21_pow(test_number, test_number_exp);
  b = pow(test_number, test_number_exp);
  ck_assert_msg(a == b, "Pow. Exp zero number");

  ck_assert_msg(isinf(s21_pow(2., INFINITY)) == isinf(pow(2., INFINITY)),
                "Pow. Infinity number");

  ck_assert_msg(s21_pow(2., -INFINITY) == pow(2., -INFINITY),
                "Pow. Minus Infinity number");

  ck_assert_msg(isinf(s21_pow(INFINITY, 2)) == isinf(pow(INFINITY, 2)),
                "Pow. Infinity number");

  ck_assert_msg(s21_pow(-INFINITY, 2) == pow(-INFINITY, 2),
                "Pow. Minus Infinity number");

  ck_assert_msg(isnan(s21_pow(2., (0. / .0))) == isnan(pow(2., (0. / .0))),
                "Pow. NaN number");

  ck_assert_msg(isnan(s21_pow((0. / .0), 2)) == isnan(pow((0. / .0), 2)),
                "Pow. Exp NaN number");

  ck_assert_msg(isnan(s21_pow(-2., (0. / .0))) == isnan(pow(-2., (0. / .0))),
                "Pow. NaN number");

  ck_assert_msg(isnan(s21_pow((0. / .0), -2)) == isnan(pow((0. / .0), -2)),
                "Pow. Exp NaN number");
}
END_TEST

START_TEST(log_check) {
  double test_number = 987654321;
  long double a = 0, b = 0;
  a = s21_log(test_number);
  b = log(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Log. Positive integer number");

  test_number = 1;
  a = s21_log(test_number);
  b = log(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Log. '1' number");

  test_number = -123456789;
  a = s21_log(test_number);
  b = log(test_number);
  ck_assert_msg(isnan(a) == isnan(b), "Log. Negative integer number");

  test_number = 123456789.17263772472547254;
  a = s21_log(test_number);
  b = log(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Log. Positive double number");

  test_number = -123456789.17263772472547254;
  a = s21_log(test_number);
  b = log(test_number);
  ck_assert_msg(isnan(a) == isnan(b), "Log. Negative double number");

  ck_assert_msg(isnan(s21_log(0)) == isnan(log(0)), "Log. Zero number");

  test_number = (double)(2147483649 * 2147483649);
  a = s21_log(test_number);
  b = log(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Log. Huge integer number");

  test_number = (double)(-2147483649 * 2147483649);
  a = (double)s21_log(test_number);
  b = (double)log(test_number);
  ck_assert_msg(isnan(a) == isnan(b), "Log. Small integer number");

  test_number = (double)(2147483649.123456 * 2147483649.123456);
  a = s21_log(test_number);
  b = log(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Log. Huge double number");

  test_number = (-2147483649.123456 * 2147483649.123456);
  a = s21_log(test_number);
  b = log(test_number);
  ck_assert_msg(isnan(a) == isnan(b), "Log. Small double number");

  ck_assert_msg(isinf(s21_log(INFINITY)) == isinf(log(INFINITY)),
                "Log. Infinity number");

  ck_assert_msg(isinf(s21_log(-INFINITY)) == isinf(log(-INFINITY)),
                "Log. Minus Infinity number");

  ck_assert_msg(isnan(s21_log(0. / 0.)) == isnan(log(0. / 0.)),
                "Log. NaN number");

  ck_assert_msg(isinf(s21_log(0 * -5)) == isinf(log(0 * -5)),
                "Log. Minus Zero");
}
END_TEST

START_TEST(ceil_check) {
  int positive_number = 123456789;
  ck_assert_msg(
      ceil((double)positive_number) == s21_ceil((double)positive_number),
      "Сeil. Positive integer number");

  int negative_number = -123456789;
  ck_assert_msg(
      ceil((double)negative_number) == s21_ceil((double)negative_number),
      "Сeil. Negative integer number");

  double positive_double_number = 123456.123456;
  ck_assert_msg(
      ceil(positive_double_number) == s21_ceil(positive_double_number),
      "Сeil. Positive double number");

  double negative_double_number = -123456.123456;
  ck_assert_msg(
      ceil(negative_double_number) == s21_ceil(negative_double_number),
      "Сeil. Negative double number");

  int zero_number = 0;
  ck_assert_msg(ceil((double)zero_number) == s21_ceil((double)zero_number),
                "Сeil. Zero number");

  ck_assert_msg(ceil((double)(2147483649 * 2147483649)) ==
                    s21_ceil((double)(2147483649 * 2147483649)),
                "Сeil. Huge integer number");

  ck_assert_msg(ceil((double)(-2147483649)) == s21_ceil((double)(-2147483649)),
                "Сeil. Small integer number");

  ck_assert_msg(ceil((double)(2147483649.123456)) ==
                    s21_ceil((double)(2147483649.123456)),
                "Сeil. Huge double number");

  ck_assert_msg(ceil((double)(-2147483649.123456)) ==
                    s21_ceil((double)(-2147483649.123456)),
                "Сeil. Small double number");

  ck_assert_msg(isinf(s21_ceil(INFINITY)) == isinf(ceil(INFINITY)),
                "Сeil. Infinity number");

  ck_assert_msg(isinf(s21_ceil(-INFINITY)) == isinf(ceil(-INFINITY)),
                "Сeil. Minus Infinity number");

  ck_assert_msg(isnan(s21_ceil(0. / 0.)) == isnan(ceil(0. / 0.)),
                "Сeil. NaN number");

  ck_assert_msg(s21_ceil(0 * -5) == ceil((double)0 * -5), "Сeil. Minus Zero");
}
END_TEST

START_TEST(exp_check) {
  double test_number = 300;
  long double a = 0, b = 0;
  a = s21_exp(test_number);
  b = exp(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Exp. Positive integer number");

  test_number = -300;
  a = s21_exp(test_number);
  b = exp(test_number);
  ck_assert_msg(isnan(a) == isnan(b), "Exp. Negative integer number");

  test_number = 12.1726;
  a = s21_exp(test_number);
  b = exp(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Exp. Positive double number");

  test_number = -12.1726;
  a = s21_exp(test_number);
  b = exp(test_number);
  ck_assert_msg(isnan(a) == isnan(b), "Exp. Negative double number");

  test_number = 0;
  a = s21_exp(test_number);
  b = exp(test_number);
  ck_assert_msg(isnan(a) == isnan(b), "Exp. Zero number");

  test_number = (double)(214);
  a = s21_exp(test_number);
  b = exp(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Exp. Huge integer number");

  test_number = (double)(-214);
  a = (double)s21_exp(test_number);
  b = (double)exp(test_number);
  ck_assert_msg(isnan(a) == isnan(b), "Exp. Small integer number");

  test_number = (double)(214.123456);
  a = s21_exp(test_number);
  b = exp(test_number);
  ck_assert_msg(fabs((double)a - (double)b) < EPS, "Exp. Huge double number");

  test_number = (-214.12345);
  a = s21_exp(test_number);
  b = exp(test_number);
  ck_assert_msg(isnan(a) == isnan(b), "Exp. Small double number");

  ck_assert_msg(isinf(s21_exp(INFINITY)) == isinf(exp(INFINITY)),
                "Exp. Infinity number");

  ck_assert_msg(isinf(s21_exp(-INFINITY)) == isinf(exp(-INFINITY)),
                "Exp. Minus Infinity number");

  ck_assert_msg(isnan(s21_exp(0. / 0.)) == isnan(exp(0. / 0.)),
                "Exp. NaN number");

  ck_assert_msg(isinf(s21_log(0 * -5)) == isinf(log(0 * -5)),
                "Exp. Minus Zero");
}
END_TEST

START_TEST(floor_check) {
  long double a = 0, b = 0;
  double test_number = 0.0;

  test_number = 123456789;
  a = floor(test_number);
  b = s21_floor(test_number);
  ck_assert_msg(a == b, "Floor. Positive integer number");

  test_number = -123456789;
  a = floor(test_number);
  b = s21_floor(test_number);
  ck_assert_msg(a == b, "Floor. Negative integer number");

  test_number = 123456.123456;
  a = floor(test_number);
  b = s21_floor(test_number);
  ck_assert_msg(a == b, "Floor. Positive double number");

  test_number = -123456.123456;
  a = floor(test_number);
  b = s21_floor(test_number);
  ck_assert_msg(a == b, "Floor. Negative double number");

  test_number = 0;
  a = floor(test_number);
  b = s21_floor(test_number);
  ck_assert_msg(a == b, "Floor. Zero number");

  ck_assert_msg(floor((double)(2147483649 * 2147483649)) ==
                    s21_floor((double)(2147483649 * 2147483649)),
                "Floor. Huge integer number");

  ck_assert_msg(
      floor((double)(-2147483649)) == s21_floor((double)(-2147483649)),
      "Floor. Small integer number");

  ck_assert_msg(floor((double)(2147483649.123456)) ==
                    s21_floor((double)(2147483649.123456)),
                "Floor. Huge double number");

  ck_assert_msg(floor((double)(-2147483649.123456)) ==
                    s21_floor((double)(-2147483649.123456)),
                "Floor. Small double number");

  ck_assert_msg(isinf(s21_floor(INFINITY)) == isinf(floor(INFINITY)),
                "Floor. Infinity number");

  ck_assert_msg(isinf(s21_floor(-INFINITY)) == isinf(floor(-INFINITY)),
                "Floor. Minus Infinity number");

  ck_assert_msg(isnan(s21_floor(0. / 0.)) == isnan(floor(0. / 0.)),
                "Floor. NaN number");

  ck_assert_msg(s21_floor(0 * -5) == floor((double)0 * -5),
                "Floor. Minus Zero");
}
END_TEST

START_TEST(fmod_check) {
  double test_number = 987654321;
  double test_number_exp = 8;
  long double a = 0, b = 0;
  a = s21_fmod(test_number, test_number_exp);
  b = fmod(test_number, test_number_exp);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Fmod. Positive integer number, positive exp");

  test_number = -987654321;
  test_number_exp = 8;
  a = s21_fmod(test_number, test_number_exp);
  b = fmod(test_number, test_number_exp);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Fmod. Negative integer number, positive exp");

  test_number = 12345678.123456;
  test_number_exp = 8;
  a = s21_fmod(test_number, test_number_exp);
  b = fmod(test_number, test_number_exp);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Fmod. Positive double number, positive exp");

  test_number = -12345678.123456;
  test_number_exp = 8;
  a = s21_fmod(test_number, test_number_exp);
  b = fmod(test_number, test_number_exp);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Fmod. Negative double number, positive exp");

  test_number = 987654321;
  test_number_exp = -8;
  a = s21_fmod(test_number, test_number_exp);
  b = fmod(test_number, test_number_exp);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Fmod. Positive integer number, negative exp");

  test_number = -987654321;
  test_number_exp = -8;
  a = s21_fmod(test_number, test_number_exp);
  b = fmod(test_number, test_number_exp);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Fmod. Negative integer number, negative exp");

  test_number = 123456.123456;
  test_number_exp = -8;
  a = s21_fmod(test_number, test_number_exp);
  b = fmod(test_number, test_number_exp);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Fmod. Positive double number, negative exp");

  test_number = 654321;
  test_number_exp = 8.123456;
  a = s21_fmod(test_number, test_number_exp);
  b = fmod(test_number, test_number_exp);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Fmod. Positive integer number, positive double exp");

  test_number = -654321;
  test_number_exp = 8.123456;
  a = s21_fmod(test_number, test_number_exp);
  b = fmod(test_number, test_number_exp);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Fmod. Negative integer number, positive double exp");

  test_number = 123456.123456;
  test_number_exp = 8.123456;
  a = s21_fmod(test_number, test_number_exp);
  b = fmod(test_number, test_number_exp);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Fmod. Positive double number, positive double exp");

  test_number = -123456.123456;
  test_number_exp = 8.123456;
  a = s21_fmod(test_number, test_number_exp);
  b = fmod(test_number, test_number_exp);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Fmod. Negative double number, positive double exp");

  test_number = 654321;
  test_number_exp = -8.123456;
  a = s21_fmod(test_number, test_number_exp);
  b = fmod(test_number, test_number_exp);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Fmod. Positive integer number, negative double exp");

  test_number = -654321;
  test_number_exp = -8.123456;
  a = s21_fmod(test_number, test_number_exp);
  b = fmod(test_number, test_number_exp);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Fmod. Negative integer number, negative double exp");

  test_number = 123456.123456;
  test_number_exp = -8.123456;
  a = s21_fmod(test_number, test_number_exp);
  b = fmod(test_number, test_number_exp);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Fmod. Positive double number, negative double exp");

  test_number = -123456.123456;
  test_number_exp = -8;
  a = s21_fmod(test_number, test_number_exp);
  b = fmod(test_number, test_number_exp);
  ck_assert_msg(fabs((double)a - (double)b) < EPS,
                "Fmod. Positive double number, negative double exp");

  ck_assert_msg(
      isnan(s21_fmod((0. / .0), (0 * -5))) == isnan(fmod((0. / .0), (0 * -5))),
      "Fmod. Exp NaN number");

  test_number = -123456.123456;
  test_number_exp = 0;
  a = s21_fmod(test_number, test_number_exp);
  b = fmod(test_number, test_number_exp);
  ck_assert_msg(isnan(a) == isnan(b), "Fmod. Zero number");

  test_number = 0;
  test_number_exp = 0;
  a = s21_fmod(test_number, test_number_exp);
  b = fmod(test_number, test_number_exp);
  ck_assert_msg(isnan(a) == isnan(b), "Fmod. Exp zero number");

  ck_assert_msg(isinf(s21_fmod(2., INFINITY)) == isinf(fmod(2., INFINITY)),
                "Fmod. Infinity exp");

  ck_assert_msg(s21_fmod(2., -INFINITY) == fmod(2., -INFINITY),
                "Fmod. Minus Infinity exp");

  ck_assert_msg(isinf(s21_fmod(INFINITY, 2)) == isinf(fmod(INFINITY, 2)),
                "Fmod. Infinity number");

  ck_assert_msg(isnan(s21_fmod(-INFINITY, 2)) == isnan(fmod(-INFINITY, 2)),
                "Fmod. Minus Infinity number");

  ck_assert_msg(isnan(s21_fmod(2., (0. / .0))) == isnan(fmod(2., (0. / .0))),
                "Fmod. NaN number");

  ck_assert_msg(isnan(s21_fmod((0. / .0), 2)) == isnan(fmod((0. / .0), 2)),
                "Fmod. Exp NaN number");

  ck_assert_msg(isnan(s21_fmod(-2., (0. / .0))) == isnan(fmod(-2., (0. / .0))),
                "Fmod. NaN number");

  ck_assert_msg(isnan(s21_fmod((0. / .0), -2)) == isnan(fmod((0. / .0), -2)),
                "Fmod. Exp NaN number");

  ck_assert_msg(
      isnan(s21_fmod((0. / .0), (0 * -5))) == isnan(fmod((0. / .0), (0 * -5))),
      "Fmod. Minus Zero");
}
END_TEST

int main(void) {
  Suite *task1_suit = suite_create("Math.h. Task tests");
  TCase *task1_test_case = tcase_create("Core");
  SRunner *task1_sr = srunner_create(task1_suit);

  suite_add_tcase(task1_suit, task1_test_case);

  tcase_add_test(task1_test_case, inf_check);
  tcase_add_test(task1_test_case, nan_check);

  tcase_add_test(task1_test_case, abs_check);
  tcase_add_test(task1_test_case, fabs_check);
  tcase_add_test(task1_test_case, sqrt_check);

  tcase_add_test(task1_test_case, sin_check);
  tcase_add_test(task1_test_case, cos_check);
  tcase_add_test(task1_test_case, tan_check);
  tcase_add_test(task1_test_case, asin_check);
  tcase_add_test(task1_test_case, acos_check);
  tcase_add_test(task1_test_case, atan_check);

  tcase_add_test(task1_test_case, pow_check);
  tcase_add_test(task1_test_case, log_check);

  tcase_add_test(task1_test_case, ceil_check);
  tcase_add_test(task1_test_case, exp_check);
  tcase_add_test(task1_test_case, floor_check);
  tcase_add_test(task1_test_case, fmod_check);

  printf("\n\n");
  srunner_run_all(task1_sr, CK_ENV);
  srunner_free(task1_sr);
  printf("\n\n");
  return 0;
}
