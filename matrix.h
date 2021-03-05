#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int rows;
    int collumns;
    int* values;
} matrix_t;

matrix_t* Make_Matrix(int rows, int collumns);
int Load_Matrix(FILE* input, matrix_t* m);  //Czyta z pliku input i zapisuje do macierzy m
int Diplay_Matrix(matrix_t* m);
int Neighbour_counter(matrix_t* m, matrix_t* nm);
int Rule_applier(matrix_t* m, matrix_t* nm);

#endif