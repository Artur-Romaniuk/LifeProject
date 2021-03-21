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

matrix_t* Make_Matrix(int rows, int collumns);          //make new, empty matrix
matrix_t* Load_Matrix(FILE* input);                     //Read from input file and save to a new matrix
void Clear_Matrix(matrix_t* m);                         //set all values in a matrix to 0
void Write_Matrix_to_PBM(char* filename, matrix_t* m);  //save to PBM file          

void Write_Matrix(FILE* output, matrix_t* m);           //NOT USED IN FINAL, only for testing
int Display_Matrix(matrix_t* m);                        //NOT USED IN FINAL, only for testing
#endif