#include "midterm.h"

#include <stdio.h>

// PROBLEM 3
void bubble_sort_customers(ShoeCustomer *customers, size_t n_customers) {
  // Your code here! Make them sorted by number of purchases, increasing!


  if (n_customers < 2) {
      return;
  }

  for (size_t j = 0; j < n_customers - 1; j++) {
      bool check = false;
      for (size_t i = 0; i < n_customers - 1; i++) {
          if (customers[i].num_purchases > customers[i + 1].num_purchases) {
              ShoeCustomer temp = customers[i];

              customers[i] = customers[i + 1];
              customers[i + 1] = temp;

              check = true;
          }
      }
   

      if (!check) {
          break;
      }
  }


}
