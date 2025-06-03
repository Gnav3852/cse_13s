#include "final.h"

#include <stdio.h>

int apply_many_times(int (*func)(int), int x, size_t n) {

    for (size_t i = 0; i < n; i++) {

        x = func(x);
    }
    
    return x;
}
