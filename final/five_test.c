#include "final.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

WordCountTree *build_tree(char *word, size_t count, WordCountTree *left,
                          WordCountTree *right) {
  WordCountTree *out = calloc(1, sizeof(WordCountTree));
  out->word = strdup(word);
  out->count = count;

  out->left = left;
  out->right = right;

  return out;
}

size_t lookup_count(WordCountTree *tree, char *query) {
  if (!tree) {
    return 0;
  }
  int result = strcmp(query, tree->word);
  if (result < 0) {
    // query is "less" in dictionary order
    return lookup_count(tree->left, query);
  } else if (result > 0) {
    // query is "greater" in dictionary order
    return lookup_count(tree->right, query);
  } else {
    // found it!
    return tree->count;
  }
  // not found!
  return 0;
}

void should_be_exactly_equal(const char *message, size_t expected,
                             size_t actual) {
  printf("%s\n", message);
  printf("%s: wanted %zu, got %zu\n",
         (expected == actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

int main(void) {
  // this tree is sorted correctly just because we built it that way, not
  // because build_tree is careful to maintain the BST property.
  WordCountTree *tree1 =
      build_tree("marmot", 10, build_tree("atomic", 5, NULL, NULL),
                 build_tree("zapatos", 3, NULL, NULL));
  should_be_exactly_equal("tree1 has zapatos at count 3", 3,
                          lookup_count(tree1, "zapatos"));

  WordCountTree *tree2 = build_tree(
      "mastodon", 7000, build_tree("ablative", 19, NULL, NULL),
      build_tree("quince", 3, NULL, build_tree("zapatos", 7, NULL, NULL)));
  should_be_exactly_equal("tree2 has zapatos at count 7", 7,
                          lookup_count(tree2, "zapatos"));

  // NOW COMBINE THEM TOGETHER.
  WordCountTree *combined_tree = merge_trees(tree1, tree2);
  should_be_exactly_equal("combined_tree has zapatos at count 10", 10,
                          lookup_count(combined_tree, "zapatos"));
  should_be_exactly_equal("combined_tree has marmot at count 10", 10,
                          lookup_count(combined_tree, "marmot"));

  return 0;
}
