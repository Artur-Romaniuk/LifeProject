#include "matrix.h"


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
    return matrix;
}

int Load_Matrix(FILE* input, matrix_t* m)
{

}