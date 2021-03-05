#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>

typedef struct
{
    int rows;
    int collumns;
    int* value;
} matrix_t;


int Load_Matrix(FILE* input, matrix_t* m);
int Diplay_Matrix();
int Neighbour_counter(matrix_t* m, matrix_t* nm);
int Rule_applier(matrix_t* m, matrix_t* nm);

#endif