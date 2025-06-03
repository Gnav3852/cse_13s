#include "hw1.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


// For the value of Pi, please use M_PI, which is defined in math.h.
double area_of_disk(double radius) {
  return M_PI * radius * radius;
}

double area_of_ring(double outer_radius, double inner_radius) {
  double oa = area_of_disk(outer_radius);
  double ia= area_of_disk(inner_radius);
  return oa - ia;
}

int bigger_minus_smaller(int a, int b) {
  if (a > b) {
    return a - b;
  } else {
    return b - a;
  }
}

bool value_in_range(int lower_bound, int x, int upper_bound) {
  if (x >= lower_bound && x <= upper_bound) {
    return true;
  } else {
    return false;
  }
}

int sum_of_greater_squares(int a, int b, int c) {
    int as = a * a;
    int bs = b * b;
    int cs = c * c;

    if (as <= bs && as <= cs) {
        return bs + cs;
    } else if (bs <= as && bs <= cs) {
        return as + cs;
    } else {
        return as + bs;
    }
}
