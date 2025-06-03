#include "midterm.h"

#include <stdio.h>

ll_float *delete_range(ll_float *list, float start, float end) {
    if (!list) {
        return NULL;
    }

   
    ll_float temp;
    temp.next = list;

    ll_float *prev = &temp;

    ll_float *cur = list;

    
    while (cur) {
        if (cur->value >= start && cur->value <= end) {
            prev->next = cur->next; 
            free(cur);

            cur = prev->next;
        } else {
            prev = cur; 
            cur = cur->next; 

        }
    }

    return temp.next;
}
