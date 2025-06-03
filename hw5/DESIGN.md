# Homework 5: Design Document

  * **Author:** Gandharva Naveen  
  * **Date:** February 2025  

## Introduction

For this homework, I will create 4 main functions that will create a version of Wordle. These functions will check guesses, load vocab, and deal with memory management. The essence of the game is that the player will try to guess a hidden 5-letter word. For each guess, the program will return `x` if the letter is not in the word, `y` if it is in the wrong position, and `g` if the letter is in the right position.

## Function 1: score_guess

The goal of `score_guess` is to compare the guess with the secret word and provide user feedback. It takes in `secret`, `guess`, and `result`. To do this task, first we need to initialize an array that tracks the state of the guess. Next, we loop through each letter, and if the letter matches the current letter, we add `g` to the tracking array. If the letter is present but misplaced, we add `y`. We do this through a helper function `check_letter`. If the letter isn’t there (else condition), we mark it as `x`. Overall, it would return `true` if it matches the word.

## Function 1a: check_letter

The goal of `check_letter` to be a helper function for `score_guess` which checks if a letter exists in a word. It takes in `word` and `letter` To do this task it has to iterate through the given word and check if it matches a letter. If it does return true, else false.

## Function 2: valid_guess

The goal of `valid_guess` is that it checks if a word was in a vocab list. It takes in `guess`, `vocabulary` (array), and `num_words`. To do this task by iterating through a vocab array and comparing each word with `strcmp`. It will return `true` if it is in the array, else `false`.

## Function 3: load_vocabulary

The goal of `load_vocabulary` is that it reads a 5-letter word in a file and stores it. It takes in `filename` and `num_words` It does this action through opening a file and reading the word line by line. It dynamically allocates memory with `strdup`. It would also use `realloc` if needed. It would track the number of words using a variable and return the array.

## Function 4: free_vocabulary

The goal of `free_vocabulary` is that it deallocates memory that is used by the vocab array. It takes in `vocabulary` and `num_words`. To do this task, it iterates through the array and frees each string. Then it fully frees the array itself.
