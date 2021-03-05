#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int N = argc > 1 ? atoi(argv[1]) : 10;   //Number of iterations
    FILE* in = argc > 2 ? fopen(argv[2], "r") : stdin;  //file to read from (defualt stdin)
    int rows, collumns;
    scanf("%d %d", &rows, &collumns);
    matrix_t* CS_Matrix = Make_Matrix(rows, collumns);  //Current state matrix
    matrix_t* N_CS_Matrix = Make_Matrix(rows, collumns); //Neighbour curren state matrix
    if (CS_Matrix == NULL || N_CS_Matrix == NULL)
        return 1;
    
    
    return 0;
}