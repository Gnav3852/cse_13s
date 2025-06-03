#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "search_util.h"

void check(const char *funct, int exp, int res) {
    printf("%s: %s (Expected: %d, Got: %d)\n",
           funct,
           (exp == res) ? "SUCCESS" : "FAILURE",
           exp, res);
}

void resetArray(char **vocabulary, size_t *num_words) {
    static char words[10][6] = {
        "stalk", "scrap", "shear", "batch", "motif",
        "tense", "ultra", "vital", "ether", "nadir"
    };

    for (size_t i = 0; i < *num_words; i++) {
        free(vocabulary[i]);
    }

    for (int i = 0; i < 10; i++) {
        vocabulary[i] = strdup(words[i]);
    }


    
    *num_words = 10;
}

int main(void) {
    char **vocabulary = calloc(10, sizeof(char*));
    size_t num_words = 10;

    resetArray(vocabulary, &num_words);

    printf("\n tests for score_word \n");
 
    int letter_scores[26] = {0};
    for (char c = 'a'; c <= 'z'; c++) {
        letter_scores[c - 'a'] = score_letter(c, vocabulary, num_words);
    }
    check("score_word('stalk')", 22, score_word("stalk", letter_scores));
    check("score_word('batch')", 20, score_word("batch", letter_scores));
    check("score_word('vital')", 21, score_word("vital", letter_scores));

    printf("\n tests for score_letter \n");
    check("'a' in words", 7, score_letter('a', vocabulary, num_words));
    check("'t' in words", 7, score_letter('t', vocabulary, num_words));
    check("'v' in words", 1, score_letter('v', vocabulary, num_words));
    check("'z' in words", 0, score_letter('z', vocabulary, num_words));

    printf("\n tests for filter_vocabulary_green \n");

    resetArray(vocabulary, &num_words);
    size_t testRes = filter_vocabulary_green('t', 0, vocabulary, num_words);
    check("words where 't' is not in position 0", 9, testRes);

    resetArray(vocabulary, &num_words);
    testRes = filter_vocabulary_green('s', 1, vocabulary, num_words);
    check("words where 's' is not in position 1", 10, testRes);

    resetArray(vocabulary, &num_words);
    testRes = filter_vocabulary_green('r', 4, vocabulary, num_words);
    check("words where 'r' is not in position 4", 7, testRes);


    printf("\n tests for filter_vocabulary_yellow \n");

    resetArray(vocabulary, &num_words);
    testRes = filter_vocabulary_yellow('a', 2, vocabulary, num_words);
    check("words where 'a' is not at position 2", 4, testRes);

    resetArray(vocabulary, &num_words);
    testRes = filter_vocabulary_yellow('o', 3, vocabulary, num_words);
    check(" words where 'o' is not at position 3", 9, testRes);

    resetArray(vocabulary, &num_words);
    testRes = filter_vocabulary_yellow('n', 0, vocabulary, num_words);
    check(" words where 'n' is not at position 0", 9, testRes);

    printf("\n tests for filter_vocabulary_gray \n");

    resetArray(vocabulary, &num_words);
    testRes = filter_vocabulary_gray('e', vocabulary, num_words);
    check(" words containing 'e'", 3, testRes);

    resetArray(vocabulary, &num_words);
    testRes = filter_vocabulary_gray('s', vocabulary, num_words);
    check(" words containing 's'", 4, testRes);

    resetArray(vocabulary, &num_words);
    testRes = filter_vocabulary_gray('l', vocabulary, num_words);
    check(" words containing 'l'", 3, testRes);

    // ... OK we're done, clean up the vocabulary
    free_vocabulary(vocabulary, num_words);
    return 0;
}
