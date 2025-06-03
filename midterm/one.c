#include "midterm.h"

long long *factorial_numbers(size_t n) {
  // You're going to have to allocate an array, fill it in, and return it.
  // The array should be of length n.
  // Recall the first few entries should be 1, 1, 2, 6, 24, 120...
    if (n == 0) {
        return NULL;
    }

    long long * factorialNums = (long long*)calloc(n, sizeof(long long));

    if (factorialNums == NULL) {
        return NULL; 
    }

 
    factorialNums[0] = 1; 


    for (size_t j = 1; j < n; j++) 
    {
      factorialNums[j] = factorialNums[j - 1] * j;
    }

    return factorialNums;
}
