#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int N = argc > 1 ? atoi(argv[1]) : 10;
    FILE* in = argc > 2 ? fopen(argv[2], "r") : stdin;
    int rows, collumns;
    scanf("%d %d", &rows, &collumns);
    if (Make_Matrix(rows, collumns) != NULL)
        printf("Dziala!");

    return 0;
}