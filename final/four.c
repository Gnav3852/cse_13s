#include "final.h"

#include <stdio.h>

int calc_depth(BinaryTree *tree) {
    if (!tree) return 0;
    int ldepth = calc_depth(tree->left);
    int rdepth = calc_depth(tree->right);
    return 1 + (ldepth > rdepth ? ldepth : rdepth);
}

int sum_depth(BinaryTree *tree, int dep, int cur_depth) {
    if (!tree) return 0;
    if (cur_depth == dep) return tree->val;

    return sum_depth(tree->left, dep, cur_depth + 1) + sum_depth(tree->right, dep, cur_depth + 1);
}

int sum_values_at_max_depth(BinaryTree *tree) {
    if (!tree) return 0;
    int dep = calc_depth(tree) - 1;
    return sum_depth(tree, dep, 0);
}
