/*
 * All of your code for these five functions goes in here. These are for you to
 * finish. The code for the calculator is separate. Feel free to include more
 * headers or define helper functions if you want, but you can do this homework
 * without doing either.
 */

#include "hw2.h"
#define NULL ((void*)0)

int next_collatz_number(int n) {

    if (n % 2 == 0) {
        return n / 2;

    } else {

        return 1+ 3 * n;
    }
}


int count_collatz_steps(int n) {
  
    int s = 0;
    while (n != 1) {
        n = next_collatz_number(n);
        s++;
    }
    return s;
}


int maximum(int *nums, int len) {

    int mv = nums[0];

    for (int i = 1; i < len; i++) {
        if (nums[i] > mv) {
            mv = nums[i];

        }
    }

    return mv;
}


int sum_positive(int *nums, int len) {

    int s = 0;

    for (int i = 0; i < len; i++) {
        if (nums[i] > 0) {

            s += nums[i];
        }
    }
    return s;
}


int count_negative(int *nums, int len) {
    int ct = 0;

    for (int i = 0; i < len; i++) {
        if (nums[i] < 0) {
            ct++;
        }
    }
    return ct;
}
