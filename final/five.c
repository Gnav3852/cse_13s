#include "final.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

WordCountTree *new_node(char *word, size_t count) {
    WordCountTree *node = (WordCountTree *)calloc(1, sizeof(WordCountTree));
    if (!node) return NULL;
    node->word = strdup(word);
    node->count = count;

    node->left = node->right = NULL;
    return node;
}

WordCountTree *insert(WordCountTree *root, char *word, size_t count) {
    if (!root) return new_node(word, count);
    
    int temp = strcmp(word, root->word);
    if (temp < 0) {
        root->left = insert(root->left, word, count);

    } else if (temp > 0) {
        root->right = insert(root->right, word, count);
    } else {
        root->count += count;
    }
    return root;
}

void merge_one(WordCountTree *tree, WordCountTree **new_tree) {
    if (!tree) return;
    *new_tree = insert(*new_tree, tree->word, tree->count);

    merge_one(tree->left, new_tree);
    merge_one(tree->right, new_tree);
}

WordCountTree *merge_trees(WordCountTree *tree1, WordCountTree *tree2) {

    WordCountTree *new_tree = NULL;
    merge_one(tree1, &new_tree);
    merge_one(tree2, &new_tree);
    return new_tree;
}
