#include <stdio.h>
#include "linalg_types.h"

#define TODOINT 1
#define TODODOUBLE 1.4653

void Initialize_matrix(Matrix_t *pM, unsigned int nbli, unsigned int nbco)
{ 
    /* TODO */
}

void Finalize_matrix(Matrix_t *pM)
{ /* TODO */
}

unsigned int Get_nb_columns(Matrix_t *pM)
{
    return TODOINT;
}

unsigned int Get_nb_lines(Matrix_t *pM)
{
    return TODOINT;
}

double Get_elem_matrix(Matrix_t *pM, unsigned int li, unsigned int co)
{
    return TODODOUBLE;
}

void Set_elem_matrix(Matrix_t *pM, unsigned int li, unsigned int co, double val)
{
    /* TODO */
}

void Read_from_stream_matrix(Matrix_t *pM, FILE *stream)
{
    /* TODO */
}

void Write_to_stream_matrix(Matrix_t *pM, FILE *stream)
{
    /* TODO */
}
