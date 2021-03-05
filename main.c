#include "matrix.h"
#include "gameLogic.h"

#include <stdio.h>
#include <stdlib.h>


#include <unistd.h> //linuxowa biblioteka do sleep()

int main(int argc, char** argv)
{
    int N = argc > 1 ? atoi(argv[1]) : 10;   //Number of iterations
    FILE* in = argc > 2 ? fopen(argv[2], "r") : stdin;  //file to read from (defualt stdin)

    matrix_t* CS_Matrix = Load_Matrix(in);  //Current state matrix
    matrix_t* N_CS_Matrix = Make_Matrix(CS_Matrix->rows, CS_Matrix->collumns); //Neighbour curren state matrix
    if (CS_Matrix == NULL || N_CS_Matrix == NULL)
        return 1;
    for(int i=0;i<N;i++){
        system("clear");
    Display_Matrix(CS_Matrix);
    usleep(90000);
    
    Neighbour_counter(CS_Matrix, N_CS_Matrix);
    Rule_applier(CS_Matrix,N_CS_Matrix);
    
    printf("-------------------------\n");
    }
    


    return 0;
}