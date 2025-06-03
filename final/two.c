#include "final.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *remove_characters(char *text, char *toremove) {


    if (!text) return NULL; 
    
    size_t len = strlen(text);
    char *res = (char *)malloc(len + 1);
    if (!res) return NULL; 

    int rmap[256] = {0}; 
    
    while (*toremove) {
        rmap[(unsigned char)*toremove] = 1;
        toremove++;
    }
    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        if (!rmap[(unsigned char)text[i]]) {
            res[j++] = text[i];
        }
    }
    
    res[j] = '\0';

    return res;
}
