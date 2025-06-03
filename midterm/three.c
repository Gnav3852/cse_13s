#include "midterm.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

size_t count_strings_with_property(bool (*property)(char *), char **strings, size_t len) {
    size_t c = 0;

    for (size_t j = 0; j < len; j++) {

        if (property(strings[j])) {
            c++;
        }
    }

    return c;
}
