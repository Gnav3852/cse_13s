/*
 * All of your code for hw3 goes in here. Your goal is to finish these
 * functions.
 */

#include "hw3.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool str_suffix(char *haystack, char *needle) {
  int hayL = strlen(haystack);
  int needleL = strlen(needle);
  
  if (needleL > hayL) {
    return false;
  }
  
  return strcmp(haystack + hayL - needleL, needle) == 0;
}

char *str_repeat(char *s, int n) {
  if (n <= 0) return strdup("");
  
  int l = strlen(s);
  char *res = malloc(l * n + 1);
  if (!res) return NULL;
  
  for (int i = 0; i < n; i++) {
    strcpy(res + i * l, s);
  }
  
  return res;
}

bool str_is_palindrome(char *s) {
  int l = 0;
  char *newStr = malloc(strlen(s) + 1);
  if (!newStr) return false;
  
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      newStr[l++] = s[i] + ('a' - 'A');
    } else if (s[i] >= 'a' && s[i] <= 'z') {
      newStr[l++] = s[i];
    }
  }
  newStr[l] = '\0';
  
  for (int i = 0, j = l - 1; i < j; i++, j--) {
    if (newStr[i] != newStr[j]) {
      free(newStr);
      return false;
    }
  }
  
  free(newStr);
  return true;
}

float dot_product(float *vec_a, float *vec_b, int length) {
  float tot = 0.0;
  for (int i = 0; i < length; i++) {
    tot += vec_a[i] * vec_b[i];
  }
  return tot;
}

int reduce(int *nums, int length, int (*f)(int, int), int initial) {
  int res = initial;
  for (int i = 0; i < length; i++) {
    res = f(res, nums[i]);
  }
  return res;
}

int max_val(int x, int y) {
  return (x > y) ? x : y;
}

int sum_pos(int val, int a) {
  return (a > 0) ? val + a : val;
}

// These two functions will end up as a *single call to reduce*, but you'll have
// to write a new helper function for each of them. Those helper functions will
// be quite short though!


int maximum_with_reduce(int *nums, int length) {
  return reduce(nums, length, max_val, INT_MIN);
}

int sum_positive_with_reduce(int *nums, int length) {
  return reduce(nums, length, sum_pos, 0);
}
