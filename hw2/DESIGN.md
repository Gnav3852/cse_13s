# Homework 2: Design Document

  * author: Gandharva Naveen
  * date: January 2025

## introduction

In this homework, I will address some of the pressing concerns of humanity and
clarify what it means to live a good human life.

TODO(you): I will make several functions regarding arrays and math

## function 1: next_collatz_number

The function next_collatz_number is a function given N generates the next number in the Collatz sequence. If the number is even the result n/2 and if its odd it is 3*N+1.

## function 2: count_collatz_steps

Given N, count_collatz_steps figures out how many steps it takes N to reach 1 using the Collatz sequence. The function takes a iterative approach to calculating the number, keeping track of the amount of steps and current #.

## function 3: maximum

Given a pointer to an array and length of the array, the function maximum finds the max element in the array of numbers. The function goes through each memory adddress of the elements gets the value and see if its a new maximum.

## function 4: sum_positive

Given a pointer to an array and the length of the array, the function sum_positive returns the sum of all the positive elements in the array of numbers. The function has a running sum which gets added to when the function finds a positive value.

## function 5: count_negative

Given a pointer to an array and the length of the array, the function count_negative returns the number of negative numbers in the array of numbers. The function keeps the # of negative numbers stored outside the iterative loop and adds to it when a number is below 0.

## the calculator program

This program iteratively processes a file of lines that are alternating between integers and arithmetic operators. It then performs the operations in order starting from the first number and returns the final result. If the user trys to divide by zero the program returns and "ERROR."
