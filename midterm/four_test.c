#include "midterm.h"

#include <stdio.h>
#include <stdlib.h>

void should_be_exactly_equal(const char *message, int expected, int actual) {
  printf("%s\n", message);
  printf("%s: wanted %d, got %d\n",
         (expected == actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

int main(void) {

  ShoeCustomer customers[3] = {{10, 0, 100}, // shoe size, id, num_purchases
                               {3, 1, 3},
                               {12, 2, 7}};

  bubble_sort_customers(customers, 3);

  should_be_exactly_equal("3 purchases", 3, customers[0].num_purchases);
  should_be_exactly_equal("7 purchases", 7, customers[1].num_purchases);
  should_be_exactly_equal("100 purchases", 100, customers[2].num_purchases);

  return 0;
}
