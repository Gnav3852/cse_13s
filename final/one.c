#include "final.h"

#include <stdio.h>

size_t count_increasing_columns(int **matrix, size_t rows, size_t cols) {
    size_t res = 0;


    for (size_t c = 0; c < cols; c++) {
        int inc = 1;
        for (size_t r = 1; r < rows; r++) {
            if (matrix[r][c] <= matrix[r - 1][c]) {
                inc = 0;  
                break;
            }
        }
        
        if (inc) {
            
            res++;
        }
    }
    
    return res;
}
