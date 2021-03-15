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
matrix_t* Load_Matrix(FILE* input);  //Czyta z pliku input i zapisuje do macierzy m
void Clear_Matrix(matrix_t* m);
void Write_Matrix(FILE* output, matrix_t* m);
void Write_Matrix_to_PBM(char* filename, matrix_t* m);
int Display_Matrix(matrix_t* m);
int Neighbour_counter(matrix_t* m, matrix_t* nm);
int Rule_applier(matrix_t* m, matrix_t* nm);

#endif