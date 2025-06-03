# Homework 3: Design Document

  * author: Gandharva Naveen
  * date: January 2025

## Introduction

For this homework, I will create 7 functions regarding string and array manipulation. These functions include checking for suffixes, string repetition, palindromes, and dot products. Some of these functions will also use reduce to solve certain scenarios more efficiently.

## Function 1: str_suffix

The function str_suffix takes two inputs haystack and needle, which are both pointers to character arrays (strings). A string is called a suffix if it appears at the end of another string, and the function determines if needle is at the end of haystack. To do this, we calculate the length of the strings, and if needle is longer than haystack, we return false. Otherwise, we take the last part of haystack, which is equal to the length of needle, and check if they are equal. If they are, we return true.

## Function 2: str_repeat

The function str_repeat takes two inputs, a character array (string) s and a number n, and returns a new string that is s repeated n times. To do this, we determine the length of s, then allocate new memory with n * length(s) + 1. Then, we copy s into the new memory slot n times and return the new string.

## Function 3: string_is_palindrome

The function string_is_palindrome takes a character array (string) s and checks if it is a palindrome while ignoring whitespace, punctuation, numbers, and case. To do this, we allocate memory for a new string that contains only lowercase letters. Using two pointers, we compare each character from the beginning to the end. If all corresponding characters match, we return true; otherwise, we return false.

## Function 4: dot_product

The function dot_product takes two floating-point arrays of the same size, a and b, given their length. The function initializes a sum variable and iterates through both arrays while computing sum += vec_a[i] * vec_b[i]. At the end, we return the computed sum.

## Function 5: reduce

The function reduce takes in nums, a pointer to an array of integers; len, the length of the array; f, a pointer to a function that takes two integers and returns one; and initial, the original value. We start by setting a value to initial, then iterate through the array while updating the value to f(val, nums[i]). At the end, we return the accumulated value.

## Function 6: maximum_with_reduce

The function maximum_with_reduce takes a pointer to an array, nums, and the size of the array, size. The function returns the maximum value using reduce. To do this, we need a helper function max_val(int a, int b) that returns the larger value of the two. We then call reduce(nums, size, max_val, INT_MIN) and return the result.

## Function 7: sum_positive_with_reduce

The function sum_positive_with_reduce takes a pointer to an array, nums, and the size of the array, size. The function sums all the positive numbers using reduce. To do this, we define a helper function sum_pos(int val, int x), which adds x to val only if x > 0. Then, at the end, we call reduce(nums, size, sum_pos, 0) and return the result.