#include "matrix.h"
#include <string.h>


matrix_t* Make_Matrix(int rows, int collumns)
{
    matrix_t* matrix = malloc(sizeof(*matrix));
    if (matrix == NULL)
        return NULL;
    matrix->values = malloc(rows * collumns * sizeof(*matrix->values));
    if (matrix->values == NULL)
    {
        free(matrix);
        return NULL;
    }
    matrix->rows = rows;
    matrix->collumns = collumns;
    memset(matrix->values, 0, (rows * collumns * sizeof * matrix->values));
    return matrix;
}

int Load_Matrix(FILE* input, matrix_t* m)
{

}

int Display_Matrix(matrix_t* m)
{
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->collumns; j++)
            printf(" %d", m->values[i * m->collumns + j]);
        printf("\n");
    }
    return 0;
}