# Homework 4: Design Document

  * author: Gandharva Naveen
  * date: February 2025

## Introduction

For this homework, I will create nine functions regarding linked lists and stacks. These functions will allow the user to have their own text editor, which will be managed using these data structures.

## Function 1: append_text

The function `append_text` will take in a linked list, `list`, and a string (character array), `text`. On call, it will add a new node at the end of the linked list. It does this by copying text using `strdup()`. If the list is `NULL`, it will return a new node; otherwise, it will traverse the list to find the last node. Then, it sets the next pointer to the new node and returns the start of the list.
  
## Function 2: insert_text

The function `insert_text` takes a linked list, `list,` a string (character array), `text`, and a position, position. If position equals `0`, then the new node becomes the head, as it sets the pointer to the first head. In all other cases, the function will traverse to the `position - 1th` node. The next pointer of the previous node gets updated to the new node, and the new node’s next pointer is set to the subsequent node.

## Function 3: delete_text

The function `delete_text` removes a node at a specific position, given the list, `list`, and the position, `position`. If the position is `0` (the head), the list points to the next node and frees the memory. In every other case, it finds the `position - 1th` node and adjusts its next pointer to go after the deleted node, then it frees the memory. If the list is now empty, it will return `NULL`.

## Function 4: replace_text

The function `replace_text`, given a list, `list`, a string (character array), `text`, and a position, `position`, will replace the text at a certain node. It moves through the linked list until it reaches the desired node, then removes its existing text and assigns it a copy of the new text using `strdup()`.

## Function 5: duplicate_ll_text

The function `duplicate_ll_text` takes a list, `list`, and creates a copy of it. It moves through the original list and creates new nodes while copying the text using `strdup()`. The new nodes are in the exact same order and are completely independent.

## Function 6: ll_text_length

The function `ll_text_length` takes the list, `list`, and returns the length of the list. It does this by creating a `counter`, set to `0`, and then traversing the list. For each node, it increments the counter. If the list is `NULL`, it returns `0`.

## Function 7: push_duplicate

The function `push_duplicate` takes a stack, `stack`, and adds a new item at the top, which is a duplicate of the current top. It creates a new stack node, copies the top stack text using `duplicate_ll_text()`, and adds it. It then updates the stack to the new top pointer.

## Function 8: push_empty

The function `push_empty` takes a stack, `stack`, and adds an empty item at the top of the stack. It sets the next to `NULL` and updates the top pointer to the new node. This function is helpful when documenting blank states.

## Function 9: pop_stack

The function `pop_stack` takes a stack, `stack`, and removes the top entry. If the stack is completely empty, it returns `NULL`. However, in most cases, it updates the top of the stack to the next node and frees up the memory of the removed stack node. It then returns the new stack.

