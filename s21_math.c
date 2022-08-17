// Copyright 2021 rmarchel, jjalikak, rbabara//

#include "s21_math.h"

int s21_isinf(double x) {
  ieee754 i754;
  i754.f = x;
  return ((unsigned)(i754.u >> 32) & 0x7fffffff) == 0x7ff00000 &&
         ((unsigned)i754.u == 0);
}

int s21_isnan(double x) {
  ieee754 i754;
  i754.f = x;
  return ((unsigned)(i754.u >> 32) & 0x7fffffff) + ((unsigned)i754.u != 0) >
         0x7ff00000;
}

double s21_nan(void) {
  uint64_t nan = 0x7FFFFFFFFFFFFFFF;
  return *((double*)&nan);
}

double s21_inf(void) {
  uint64_t inf = 0x7FF0000000000000;
  return *((double*)&inf);
}

int s21_abs(int x) {
  int flag = 1;
  if (x < 0) {
    flag = -1;
  }
  x *= flag;
  return x;
}

long double s21_fabs(double x) {
  int flag = 1;
  if (x < 0) {
    flag = -1;
  }
  x *= flag;
  return x;
}

long double s21_norm_sqrt(double x) {
  double S = x, a = 1, b = x;
  long double result_value = 0.0;
  while (s21_fabs(a - b) > EPS) {
    a = (a + b) / 2;
    b = S / a;
  }
  result_value = (a + b) / 2;
  return result_value;
}

long double s21_bin_sqrt(double x) {
  double a = 1, b = (x - 1) / 2;
  while (s21_fabs(a * a - x) > SMALL_EPS) {
    if (a * a < x) {
      a += b;
    } else {
      a -= b;
    }
    b /= 2;
  }
  return a;
}

long double s21_sqrt(double x) {
  long double result = NAN;
  if (x > 0 && !s21_isnan(x)) {
    if (!s21_isinf(x)) {
      int exp;
      double norm = normalize_double(x, &exp);
      result = shift((double)s21_bin_sqrt(norm), (exp / 2));
      if (exp % 2 == 1) {
        result *= M_SQRT2;
      } else if (exp % 2 == -1) {
        result /= M_SQRT2;
      }
    } else {
      result = x;
    }
  } else if (x == 0 && !s21_isnan(x)) {
    result = 0;
  }
  return result;
}

long double normal_log(double num) {
  long double x = (num - 1.) / (num + 1.), ai = 2 * x, sum = ai, d = x * x,
              eps = 1e-25;
  for (int i = 3; s21_fabs((double)ai) > eps; i += 2) {
    ai *= d * (i - 2) / (long double)i;
    sum += ai;
  }
  return sum;
}

de_double disassemble_double(double num) {
  ieee754 conv;
  conv.f = num;
  de_double de_num;
  de_num.sign = (int)((conv.u & 0x8000000000000000) >> 63);
  de_num.exp = (int32_t)((conv.u & (uint64_t)0x7ff0000000000000) >> 52);
  de_num.mantiss = (uint64_t)(conv.u & (uint64_t)0x000fffffffffffff);
  return de_num;
}

// double assemble_double(de_double ded) {
//   double double_mantiss = 1 * (1 << (ded.exp - 1023));
//   uint64_t two_powed = 2, mask = 0x0008000000000000;
//   for (int i = -64; i <= -13; ++i) {
//     if (ded.mantiss & mask) {
//       double_mantiss += ((1 << (ded.exp - 1023)) * 1. / (double)two_powed);
//     }
//     two_powed *= 2;
//     mask /= 2;
//   }
//   return double_mantiss;
// }

double shift(double num, int shift) {
  while (shift) {
    if (shift > 0) {
      if (shift >= 63) {
        num *= (1ull << 63);
        shift -= 63;
      } else {
        num *= (1ull << shift);
        shift = 0;
      }
    } else {
      if (shift <= -63) {
        num *= 1. / (1ull << 63);
        shift += 63;
      } else {
        num *= 1. / (1ull << shift);
        shift = 0;
      }
    }
  }
  return num;
}

double normalize_double(double num, int* exp) {
  de_double ded = disassemble_double(num);
  double double_mantiss = 1;
  uint64_t two_powed = 2, mask = 0x0008000000000000;
  for (int i = -64; i <= -13; ++i) {
    if (ded.mantiss & mask) {
      double_mantiss += (1. / (double)two_powed);
    }
    two_powed *= 2;
    mask /= 2;
  }
  *exp = ded.exp - 1023;
  return double_mantiss;
}

long double s21_log(double x) {
  de_double ded = disassemble_double(x);
  long double double_mantiss = 1, return_val = NAN;
  if (s21_isnan(x) == 1) {
    return_val = NAN;
  } else if (!s21_isnan(x) && x > 0) {
    if (!s21_isinf(x)) {
      uint64_t two_powed = 2, mask = 0x0008000000000000;
      for (int i = -64; i <= -12; ++i) {
        if (ded.mantiss & mask) {
          double_mantiss += (1. / (double)two_powed);
        }
        two_powed *= 2;
        mask /= 2;
      }
      uint64_t logtwo = (uint64_t)0x3FE62E42FEFA39EF;
      return_val = normal_log((double)double_mantiss) +
                   (ded.exp - 1023) * (*((double*)(&logtwo)));
    } else {
      return_val = INFINITY;
    }
  } else if (x == 0) {
    return_val = -INFINITY;
  }
  return return_val;
}

long double s21_exp(double x) {
  long double result = 1, temporary = 1, count = 1;
  int flag = 0;
  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  while (s21_fabs(result) > EPS) {
    result *= x / count;
    count += 1;
    temporary += result;
    if (temporary > DBL_MAX) {
      temporary = INFINITY;
      break;
    }
  }
  temporary = flag == 1 ? temporary > DBL_MAX ? 0 : 1. / temporary : temporary;
  return temporary = temporary > DBL_MAX ? INFINITY : temporary;
}

long double s21_pow(double base, double ex) {
  long double result = 1;
  if (s21_isnan(base) || s21_isnan(ex)) {
    result = NAN;
  } else if (ex == -INFINITY) {
    result = 0;
  } else {
    if ((double)(int64_t)ex == ex) {
      double x = 1;
      if (ex > 0) {
        for (int i = 0; i < ex; ++i) x *= base;
      } else if (ex < 0) {
        for (int i = 0; i > ex; --i) x *= base;
        x = 1 / x;
      } else {
        x = 1;
      }
      result = x;
    } else {
      result = s21_exp((double)(s21_log(base) * ex));
    }
  }
  return result;
}

long double s21_ceil(double x) {
  long double result = NAN;
  if (!s21_isnan(x)) {
    if (s21_isinf(x)) {
      result = x;
    } else {
      if (x < 0 || (int64_t)x == x) x -= 1;
      result = (double)(int64_t)(x + 1);
    }
  }
  return result;
}

long double s21_floor(double x) {
  long double result = NAN;
  if (!s21_isnan(x)) {
    if (s21_isinf(x)) {
      result = x;
    } else {
      long double result_buffer = (long double)(double)(int64_t)(x);
      if ((x < 0) && (result_buffer != x)) x -= 1;
      result = (long double)(double)(int64_t)(x);
    }
  }
  return result;
}

long double s21_fmod(double x, double y) {
  long double result;
  int minus = (x < 0);
  if (s21_isinf(y) == 1) {
    result = x;
  } else if (s21_isnan(x) || s21_isnan(y) || s21_isinf(x) || y == 0) {
    result = NAN;
  } else {
    int n = (int)(x / y);
    result = (long double)x - (long double)(y * n);
  }
  return result;
}

long double s21_sin(double x) {
  long double result;
  x = (double)s21_fmod(x, 2 * M_PI);
  double an = x, sum = an;
  for (int i = 3; s21_fabs(an) > EPS || i < 50; i += 2) {
    an *= -1 * x * x / (i - 1) / i;
    sum += an;
  }
  result = sum;
  return result;
}

long double s21_cos(double x) {
  long double result;
  x = (double)s21_fmod(x, 2 * M_PI);
  double an = 1, sum = an;
  for (int i = 2; s21_fabs(an) > EPS || i < 50; i += 2) {
    an *= -1 * x * x / (i - 1) / i;
    sum += an;
  }
  result = sum;
  return result;
}
long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

long double absolute(double x) { return x < 0 ? -x : x; }

long double s21_asin(double x) {
  long double result = 0.0;
  if ((x > 1) || (x < -1)) {
    result = 0. / 0.;
  } else if (x == 1 || x == -1) {
    result = M_PI_2;
    if (x < 0) result *= -1;
  } else {
    long double temporary_result = 0.1;
    while (absolute((double)temporary_result) > EPS) {
      temporary_result =
          (x - s21_sin((double)result)) / s21_cos((double)result);
      result += temporary_result;
    }
  }
  return result;
}

long double s21_acos(double x) {
  long double result = 1.0;
  if ((x > 1) || (x < -1)) {
    result = 0. / 0.;
  } else if (x == 1 || x == -1) {
    result = 0;
    if (x < 0) result = M_PI;
  } else {
    long double temporary_result = 0.1;
    while (absolute((double)temporary_result) > EPS) {
      temporary_result =
          (s21_cos((double)result) - x) / s21_sin((double)result);
      result += temporary_result;
    }
  }
  return result;
}

long double s21_atan(double x) {
  long double result = 0.0;
  if (s21_isnan(x) == 1) {
    result = 0. / 0.;
  } else if (x == 0) {
    result = 0.0;
  } else if (x > 0) {
    result = s21_acos((double)(1 / (s21_sqrt(1 + (x * x)))));
  } else {
    result = -(s21_acos((double)(1 / (s21_sqrt(1 + (x * x))))));
  }
  return result;
}
