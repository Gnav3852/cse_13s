#include "search_util.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function should loop over the vocabulary (which contains num_words
// entries) and return the number of words in which that particular letter
// occurs. So if there are 15 words containing the letter 'x' for the particular
// vocabulary, then this function will return 15.
int score_letter(char letter, char **vocabulary, size_t num_words) {
  int c = 0;

  for (size_t i = 0; i < num_words; i++) {

    if (vocabulary[i] != NULL && strchr(vocabulary[i], letter) != NULL) {
      c++;

    }

  }
  return c;
}

// Calculate the score for a given word, where the letter_scores array has
// already been filled out for you and is guaranteed to be of length 26. Slot 0
// contains the score for 'a', and slot 25 contains the score for 'z'.
// The score for a word is the sum of all of the letter scores, *for unique
// letters*. So if the letter 'e' occurs three times, it only contributes to the
// score once.
int score_word(char *word, int *letter_scores) {
  int s = 0;

  bool record[26] = {false};

  for (size_t i = 0; word[i] != '\0'; i++) {
    int cur = word[i] - 'a';

    if (cur >= 0 && cur < 26 && !record[cur]) { 
      s += letter_scores[cur]; 

      record[cur] = true; 
    }
  }
  return s;
}



// Returns the optimum guess, based on our heuristic.
// This one works, you don't have to change it.
// Note that this function allocates a new string every time it runs, and those
// strings will need to be freed!
char *get_guess(char **vocabulary, size_t num_words) {
  int ls[26];

  for (int i = 0; i < 26; i++) {

    ls[i] = score_letter('a' + i, vocabulary, num_words);
  }

  char *topGuess = NULL;
  int topScore = 0;


  int sc = 0;

  for (size_t i = 0; i < num_words; i++) {
    if (vocabulary[i] == NULL) {
      continue;
    }

    sc = score_word(vocabulary[i], ls);
    if (sc > topScore) {

      topGuess = vocabulary[i];
      topScore = sc;
    }
  }

  return topGuess ? strdup(topGuess) : NULL;
}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter *does not occur* in the secret word. So for any of the words
// in the vocabulary that do contain that letter, free their pointers and set
// the corresponding slot to NULL.
// Returns the number of words that have been filtered from the vocabulary.
size_t filter_vocabulary_gray(char letter, char **vocabulary, size_t num_words) {
  size_t remCount = 0;

  for (size_t i = 0; i < num_words; i++) {

    if (vocabulary[i] != NULL) {

      if (strchr(vocabulary[i], letter) != NULL) {
        free(vocabulary[i]);
        vocabulary[i] = NULL;

        remCount++;
      }
    }

  }
  return remCount;
}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter occurs in the word, *but not at this particular position*.
// So remove any words that either don't contain the letter at all, or do
// contain it, but at the specified position.
// Returns the number of words that have been filtered from the vocabulary.
size_t filter_vocabulary_yellow(char letter, int position, char **vocabulary, size_t num_words) {
  size_t remCount = 0;

  for (size_t i = 0; i < num_words; i++) {

    if (vocabulary[i] != NULL) {

      if (strchr(vocabulary[i], letter) == NULL || vocabulary[i][position] == letter) {
        free(vocabulary[i]);
        vocabulary[i] = NULL;

        remCount++;
      }
    }
  }
  return remCount;
}



// This function will filter down the vocabulary based on the knowledge that the
// specified letter *definitely* occurs as the specified position. So remove any
// word that does not contain, for the specified position, the specified letter.
size_t filter_vocabulary_green(char letter, int position, char **vocabulary, size_t num_words) {
  size_t remCount = 0;

  for (size_t i = 0; i < num_words; i++) {
    
    if (vocabulary[i] != NULL) {

      if (strlen(vocabulary[i]) <= (size_t)position || vocabulary[i][position] != letter) {
        free(vocabulary[i]);
        vocabulary[i] = NULL;

        remCount++;
      }
    }
  }
  return remCount;
}


// Free each of the strings in the vocabulary, as well as the pointer vocabulary
// itself (which points to an array of char *).
void free_vocabulary(char **vocabulary, size_t num_words) {
  for (size_t i = 0; i < num_words; i++) {
    free(vocabulary[i]);
  }
  free(vocabulary);
}
