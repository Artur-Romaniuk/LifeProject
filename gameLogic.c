#include "gameLogic.h"

int Neighbour_counter(matrix_t* m, matrix_t* n)
{
    Clear_Matrix(n);
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

    for (int i = 1; i < m->rows - 1; i++)   //rest
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

int Rule_applier(matrix_t* m, matrix_t* n) {
/*
** 0 - dead
** 1 - alive
** 2 - died
** 3 - born
*/
  int size = m->collumns * m->rows;
  int *map = m->values;
  int *neighbour = n->values;

  for (int i = 0; i < size; i++) {
    if (map[i] == 1 && (neighbour[i] < 2 || neighbour[i] > 3)) {
      map[i] = 2;
    } else if (map[i] == 0 && neighbour[i] == 3) {
      map[i] = 3;
    }
  }

  for (int i = 0; i < size; i++) {
    if (map[i] == 2) {
      map[i] = 0;
    } else if (map[i] == 3) {
      map[i] = 1;
    }
  }

  return 0;
}