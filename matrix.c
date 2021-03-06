#include "matrix.h"
#include <string.h>

matrix_t* Make_Matrix(int rows, int collumns) {
    matrix_t* matrix = malloc(sizeof(*matrix));
    if (matrix == NULL)
        return NULL;
    matrix->values = malloc(rows * collumns * sizeof(*matrix->values));
    if (matrix->values == NULL) {
        free(matrix);
        return NULL;
    }
    matrix->rows = rows;
    matrix->collumns = collumns;
    memset(matrix->values, 0, (rows * collumns * sizeof * matrix->values));
    return matrix;
}

matrix_t* Load_Matrix(FILE* input) {
    matrix_t* m;
    int size, a, b;

    fscanf(input, "%d %d", &a, &b);
    m = Make_Matrix(a, b);
    size = a * b;

    for (int i = 0; i < size; i++)
        if (fscanf(input, "%d", &m->values[i]) != 1)
            return NULL;
    return m;
}

void Clear_Matrix(matrix_t* m) {
    int size = m->rows * m->collumns;
    for (int i = 0; i < size; i++)
        m->values[i] = 0;
}

void Write_Matrix(FILE* output, matrix_t* m) {
    fprintf(output, "%d %d\n", m->rows, m->collumns);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->collumns - 1; j++)
            fprintf(output, "%d ", m->values[i * m->rows + j]);
        fprintf(output, "%d\n", m->values[i * m->rows + m->collumns - 1]);
    }
}

int Display_Matrix(matrix_t* m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->collumns; j++)
            printf(" %d", m->values[i * m->collumns + j]);
        printf("\n");
    }
    return 0;
}

void Write_Matrix_to_PBM(char* filename, matrix_t* m) {
    FILE* output = fopen(filename, "w");

    fprintf(output, "P1\n");
    fprintf(output, "%d %d\n", m->rows, m->collumns);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->collumns - 1; j++)
            fprintf(output, "%d ", m->values[i * m->rows + j]);
        fprintf(output, "%d\n", m->values[i * m->rows + m->collumns - 1]);
    }
    fclose(output);
}