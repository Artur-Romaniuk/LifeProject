#include "matrix.h"
#include "gameLogic.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

int main(int argc, char** argv)
{
    int N = argc > 1 ? atoi(argv[1]) : 10;   //Number of iterations
    FILE* in = argc > 2 ? fopen(argv[2], "r") : stdin;  //file to read from (defualt stdin)

    matrix_t* CS_Matrix = Load_Matrix(in);  //Current state matrix
    matrix_t* N_CS_Matrix = Make_Matrix(CS_Matrix->rows, CS_Matrix->collumns); //Neighbour curren state matrix

    char buf[64];

    if (CS_Matrix == NULL || N_CS_Matrix == NULL)
        return 1;
    for (int i = 1;i <= N;i++) {
        Neighbour_counter(CS_Matrix, N_CS_Matrix);
        Rule_applier(CS_Matrix, N_CS_Matrix);
        sprintf(buf, "out/gen%d.pbm", i);
        Write_Matrix_to_PBM(buf, CS_Matrix);
        // Display_Matrix(CS_Matrix);
    }

    //sprintf(buf, "./makegif %d", N);
    //system(buf);
    system("mkdir out/tmp");
    for (int i = 1;i <= N;i++) {
        sprintf(buf, "ppmtogif -quiet out/gen%d.pbm > out/tmp/gen%d.gif", i, i);
        system(buf);
    }

    for (int i = 1;i <= N;i++) {
        sprintf(buf, "gifsicle -b out/tmp/gen1.gif --append out/tmp/gen%d.gif", i);
        system(buf);
    }
    system("mv out/tmp/gen1.gif out/gen.gif");
    system("rm -r out/tmp");
    return 0;
}