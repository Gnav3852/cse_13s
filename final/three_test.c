#include "final.h"

#include <stdio.h>
#include <stdlib.h>

void should_be_exactly_equal(const char *message, int expected, int actual) {
  printf("%s\n", message);
  printf("%s: wanted %d, got %d\n",
         (expected == actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

int addone(int x) { return x + 1; }

int main(void) {
  should_be_exactly_equal("apply_many_times(addone, 10, 5)", 15,
                          apply_many_times(addone, 10, 5));

  return 0;
}
