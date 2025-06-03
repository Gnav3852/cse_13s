#include "midterm.h"

#include <stdio.h>
#include <stdlib.h>

void should_be_exactly_equal(const char *message, long long expected,
                             long long actual) {
  printf("%s\n", message);
  printf("%s: wanted %lld, got %lld\n",
         (expected == actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

int main(void) {

  long long *result = factorial_numbers(6);
  should_be_exactly_equal("0th number should be 1", 1, result[0]);
  should_be_exactly_equal("1th number should be 1", 1, result[1]);
  should_be_exactly_equal("2th number should be 2", 2, result[2]);
  should_be_exactly_equal("3th number should be 6", 6, result[3]);
  should_be_exactly_equal("4th number should be 24", 24, result[4]);
  should_be_exactly_equal("5th number should be 120", 120, result[5]);

  return 0;
}
