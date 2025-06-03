# Homework 5: Design Document

  * **Author:** Gandharva Naveen  
  * **Date:** February 2025  

## Introduction

In this homework, I will create a set of functions that will act as a solver for the popular game wordle. It will do this through analyzing letter patters, letter frequencies, word scoring, and filtering. The "solver" will suggest words to the user to guess for the most optimal solving time.

## Function 1: score_letter

This function loops through a list of `vocabulary` words and counts how many words have said `letter`. It results in the number. To implement this function, I will loop through the list with a counter initialized to `0`. Then, if the `letter` is in the word, I will add one to the counter; else, I will move on to the next word.

## Function 2: score_word

This function will calculate the amount of unique letters in a `word`. To do this, we will have a counter set to `0` and an array to track occurrences of a `letter`. It will loop through each letter in the `word`. If the letter has not been found before, it will add it to the counter and to the array.

## Function 3: get_guess

This function creates the best guess based on the previous `letter` scores. First, it creates an array that scores each letter from a to z, then it uses `score_letter` to score all the letters. Then, taking the `vocabulary`, it scores each `word` using `score_word`. If the new score is better than the current one, it updates a variable called `guess`, which is what it finally returns.

## Function 4: filter_vocabulary_gray

This function will remove words from the `vocabulary` list that have a letter that is not in the secret word. To do this, we create a `counter` to track words that are removed. Then, we iterate through each `word` in the `vocabulary`. If the `letter` is in the `word`, we will free the memory and set the pointer to `NULL`. Then, we return the number of words removed.

## Function 5: filter_vocabulary_yellow

This function filters the words that do not have the given `letter` or have it in the wrong position. First, we will create a `counter` for the filtered words. We then loop through the `vocabulary`, and if the `word` does not have a letter or it is in a different position, we add it to the set and set it to `NULL`. We then finally return the number of removed words.

## Function 6: filter_vocabulary_green

This function removes words that do not have a `letter` in a specific position and returns how many words were removed. To do this, we set a `counter` to `0` and iterate through the `vocabulary`. If the `word` does not have a `letter` in a specified position, we set it to `NULL` and add to the counter. We then return the final `counter`.

