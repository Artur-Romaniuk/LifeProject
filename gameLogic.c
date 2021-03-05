#include "gameLogic.h"

int Neighbour_counter(matrix_t* m, matrix_t* n)
{
    if (m->values[0] == 1) //upper left corner check
    {
        n->values[1]++;
        n->values[m->collumns]++;
        n->values[m->collumns + 1]++;
    }
    if (m->values[m->collumns - 1] == 1) //upper right corner
    {
        n->values[m->collumns - 2]++;
        n->values[2 * m->collumns - 1]++;
        n->values[2 * m->collumns - 2]++;
    }
    if (m->values[(m->rows - 1) * m->collumns] == 1) //lower left corner
    {
        n->values[(m->rows - 2) * m->collumns]++;
        n->values[(m->rows - 1) * m->collumns + 1]++;
        n->values[(m->rows - 2) * m->collumns + 1]++;
    }
    if (m->values[m->rows * m->collumns - 1] == 1) //lower right corner
    {
        n->values[m->rows * m->collumns - 2]++;
        n->values[(m->rows - 1) * m->collumns - 1]++;
        n->values[(m->rows - 1) * m->collumns - 2]++;
    }

    for (int i = 1; i < m->collumns - 1; i++)  //top row
    {
        if (m->values[i] == 1)
        {
            n->values[i - 1]++;
            n->values[i + 1]++;
            n->values[i + m->collumns]++;
            n->values[i + m->collumns + 1]++;
            n->values[i + m->collumns - 1]++;
        }
    }
    for (int i = ((m->rows - 1) * m->collumns) + 1; i < m->collumns * m->rows - 1; i++) //bottom row
    {
        if (m->values[i] == 1)
        {
            n->values[i - 1]++;
            n->values[i + 1]++;
            n->values[i - m->collumns]++;
            n->values[i - m->collumns + 1]++;
            n->values[i - m->collumns - 1]++;
        }
    }

    for (int i = m->collumns; i < (m->rows - 1) * m->collumns; i += m->collumns) //left collumn
    {
        if (m->values[i] == 1)
        {
            n->values[i + 1]++;
            n->values[i + m->collumns]++;
            n->values[i + m->collumns + 1]++;
            n->values[i - m->collumns]++;
            n->values[i - m->collumns + 1]++;
        }
    }

    for (int i = 2 * m->collumns - 1; i < m->rows * m->collumns - 1; i += m->collumns) //right collumn
    {
        if (m->values[i] == 1)
        {
            n->values[i - 1]++;
            n->values[i + m->collumns]++;
            n->values[i + m->collumns - 1]++;
            n->values[i - m->collumns]++;
            n->values[i - m->collumns - 1]++;

        }
    }

    for (int i = 1; i < m->rows - 1; i++)
    {
        for (int j = 1; j < m->collumns - 1; j++)
        {
            if (m->values[(i * m->collumns) + j] == 1)
            {
                n->values[(i * m->collumns) + j - 1]++;
                n->values[(i * m->collumns) + j + 1]++;
                n->values[(i * m->collumns) + j - m->collumns]++;
                n->values[(i * m->collumns) + j - m->collumns + 1]++;
                n->values[(i * m->collumns) + j - m->collumns - 1]++;
                n->values[(i * m->collumns) + j + m->collumns]++;
                n->values[(i * m->collumns) + j + m->collumns + 1]++;
                n->values[(i * m->collumns) + j + m->collumns - 1]++;
            }
        }
    }

    return 0;
}