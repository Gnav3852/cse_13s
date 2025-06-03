#include "editor_lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Functions about ll_text...
// append a line: add to the end of the linked list
ll_text *append_text(ll_text *list, char *text) {
    ll_text *newNode = malloc(sizeof(ll_text));
    if (!newNode) return NULL;
    newNode->text = strdup(text);
    newNode->next = NULL;

    if (!list) return newNode;

    ll_text *dummhy = list;
    while (dummhy->next) dummhy = dummhy->next;
    dummhy->next = newNode;
    return list;
}


void save_to_file(ll_text *list, const char *filename) {
  FILE *outfile = fopen(filename, "w");
  for (ll_text *here = list; here; here = here->next) {
    fprintf(outfile, "%s\n", here->text);
  }
  fclose(outfile);
}

int ll_text_length(ll_text *list) {
    int c = 0;
    while (list) {
        c++;
        list = list->next;
    }
    return c;
}

// insert a specific line: add to specific place in the linked list; this is the
// new entry at the specified line
ll_text *insert_text(ll_text *list, char *text, int position) {
    ll_text *newNode = malloc(sizeof(ll_text));
    if (!newNode) return NULL;


    newNode->text = strdup(text);
    newNode->next = NULL;

    if (position == 0) {

        newNode->next = list;
        return newNode;
    }

    ll_text *dummy = list;
    for (int i = 0; dummy && i < position - 1; i++) dummy = dummy->next;
    if (!dummy) return list;

    newNode->next = dummy->next;
    dummy->next = newNode;
    return list;
}

// delete a specific line: delete the ith entry in the linked list and return
// the new front of the linked list.
ll_text *delete_text(ll_text *list, int position) {
    if (!list) return NULL;

    ll_text *dummy = list;
    if (position == 0) {
        list = list->next;

        free(dummy->text);
        free(dummy);

        return list;
    }

    ll_text *pre = NULL;

    for (int i = 0; dummy && i < position; i++) {
        pre = dummy;
        dummy = dummy->next;
    }

    if (!dummy) return list;

    pre->next = dummy->next;

    free(dummy->text);
    free(dummy);
    return list;
}

// replace a line: go to the specific entry, free the text that's there, replace
// it with a copy of the specified text.
ll_text *replace_text(ll_text *list, char *text, int position) {
    ll_text *dummy = list;

    for (int i = 0; dummy && i < position; i++) dummy = dummy->next;
    if (!dummy) return list;

    free(dummy->text);
    dummy->text = strdup(text);
    return list;
}

// duplicate a list. Returns a copy of the list, including newly copied versions
// of all of the strings.
ll_text *duplicate_ll_text(ll_text *list) {
    if (!list) return NULL;

    ll_text *newList = NULL;
    ll_text *end = NULL;
    for (ll_text *dummy = list; dummy; dummy = dummy->next) {
        ll_text *newNode = malloc(sizeof(ll_text));
        if (!newNode) return NULL;
        newNode->text = strdup(dummy->text);
        newNode->next = NULL;

        if (!newList) newList = newNode;
        else end->next = newNode;
        end = newNode;
    }
    return newList;
}

// functions about the state stack...
ll_text_stack *load_from_file(const char *filename) {
  ll_text *lines = NULL;
  ll_text_stack *stack = calloc(1, sizeof(ll_text_stack));
  char buf[1024];
  FILE *infile = fopen(filename, "r");
  while (fgets(buf, 1024, infile)) {
    chomp(buf);
    lines = append_text(lines, buf);
  }
  stack->lines = lines;
  return stack;
}


ll_text_stack *new_stack_empty_text(void) {
  ll_text_stack *stack = calloc(1, sizeof(ll_text_stack));
  stack->lines = NULL;
  return stack;
}


// Push a new state onto the stack that's an exact copy of the state currently
// at the top.
ll_text_stack *push_duplicate(ll_text_stack *stack) {
    if (!stack) return NULL;

    ll_text_stack *nStack = malloc(sizeof(ll_text_stack));

    if (!nStack) return NULL;
    nStack->lines = duplicate_ll_text(stack->lines);
    nStack->next = stack;
    return nStack;
}

// Push a new entry onto the stack that has an empty ll_text at the top.
ll_text_stack *push_empty(ll_text_stack *stack) {
    ll_text_stack *nStack = malloc(sizeof(ll_text_stack));
    if (!nStack) return NULL;
    nStack->lines = NULL;
    nStack->next = stack;
    return nStack;
}


// undo, removing the most recent state
// this has to free all the memory associated with that state
ll_text_stack *pop_stack(ll_text_stack *stack) {
    if (!stack) return NULL;
    ll_text_stack *dummy = stack;
    stack = stack->next;

    ll_text *curNode = dummy->lines;
    while (curNode) {
        ll_text *next = curNode->next;
        free(curNode->text);
        free(curNode);
        curNode = next;
    }
    free(dummy);
    return stack;
}


// Find the first newline in the input and replace it with \0
void chomp(char *s) {
  for (int i = 0; s[i]; i++) {
    if (s[i] == '\n' || s[i] == '\r') {
      // Check for \r in case we're on Windows or a very old Mac??
      // Look, I won't stop you from doing CSE 13s on a Mac from 2001 or prior.
      s[i] = '\0';
      break;
    }
  }
}
