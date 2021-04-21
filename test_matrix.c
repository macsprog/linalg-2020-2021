#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "linalg_types.h"
#include "linalg.h"

int main(void)
{
    unsigned int nb_li = 3;
    unsigned int nb_co = 4;
    Matrix_t M = Null_Matrix;
    Matrix_t N = Null_Matrix;
    FILE *stream = NULL;
    char file_name[] = "output_matrix.txt";
    char input_file_name[] = "input_matrix.txt";
    double val = 0.0;

    Initialize_matrix(&M, nb_li, nb_co);

    Set_elem_matrix(&M, 2, 3, 323.2);
    val = Get_elem_matrix(&M, 2, 3);
    printf("val = %g\n", val);

    for (int i = 0; i < Get_nb_lines(&M); i++)
    {
        for (int j = 0; j < Get_nb_columns(&M); j++)
        {
            double val = i * nb_co + j + 200;
            Set_elem_matrix(&M, i, j, val);
        }
    }

    stream = fopen(file_name, "w");
    if (NULL == stream)
    {
        fprintf(stderr, "problem: cannot open file %s\n", file_name);
    }
    Write_to_stream_matrix(&M, stream);
    fclose(stream);

    stream = fopen(input_file_name, "r");
    if (NULL == stream)
    {
        fprintf(stderr, "problem: cannot open file %s\n", file_name);
    }
    Read_from_stream_matrix(&N, stream);
    fclose(stream);

    for (int i = 0; i < Get_nb_lines(&N); i++)
    {
        for (int j = 0; j < Get_nb_columns(&N); j++)
        {
            fprintf(stdout, "N[%d][%d]=%g\n", i, j, Get_elem_matrix(&N, i, j));
        }
    }

    Finalize_matrix(&M);
    Finalize_matrix(&N);

    printf("test is done.\n");
    return EXIT_SUCCESS;
}