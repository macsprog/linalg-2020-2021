#include <stdlib.h>
#include <stdio.h>
#include "linalg_types.h"

#define TODOINT 1
#define TODODOUBLE 1.4653

const Matrix_t Null_Matrix = {.nb_li = 0, .nb_co = 0, .data = NULL, .line_data = NULL};

void Initialize_matrix(Matrix_t *pM, unsigned int nbli, unsigned int nbco)
{
    pM->nb_li = nbli;
    pM->nb_co = nbco;
    pM->data = malloc(sizeof(double) * (pM->nb_co) * (pM->nb_li));
    if (NULL == pM->data)
    {
        fprintf(stderr, "error: memory alloc for matrix is not possible.\n");
        exit(EXIT_FAILURE);
    }

    pM->line_data = malloc(sizeof(double *) * (pM->nb_li));
    if (NULL == pM->line_data)
    {
        fprintf(stderr, "error: memory alloc for matrix is not possible.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < pM->nb_li; i++)
    {
        pM->line_data[i] = pM->data + i * (pM->nb_co);
    }
}

void Finalize_matrix(Matrix_t *pM)
{
    free(pM->data);
    pM->data = NULL;
    free(pM->line_data);
    pM->line_data = NULL;
    pM->nb_co = 0;
    pM->nb_li = 0;
}

unsigned int Get_nb_columns(Matrix_t *pM)
{
    return pM->nb_co;
}

unsigned int Get_nb_lines(Matrix_t *pM)
{
    return pM->nb_li;
}

double Get_elem_matrix(Matrix_t *pM, unsigned int li, unsigned int co)
{
    /*
 pM  est de type ptr sur Matrix_t
 *pM est de type Matrix_t
*/

    //    return *((pM->data) + li*(pM->nb_co) + co); // autre syntaxe possible
    //    return *(pM->data + li*pM->nb_co + co); // autre syntaxe possible
    //return (*pM).data[li * (pM->nb_co) + co]; // autre syntaxe possible
    // return (*pM).data[li*(*pM).nb_co + co]; // autre syntaxe possible
    //return pM->line_data[li][co]; // autre syntaxe possible
    return pM->data[li * (pM->nb_co) + co];
}

void Set_elem_matrix(Matrix_t *pM, unsigned int li, unsigned int co, double val)
{
    pM->data[li * (pM->nb_co) + co] = val;
}

void Read_from_stream_matrix(Matrix_t *pM, FILE *stream)
{
    char buf[MAX_NB_CHAR_IN_LINE] = "";
    int nbline = 0;
    int nbcol = 0;

    // lire la 1ere ligne du fichier => nb de ligne de la matrice
    fgets(buf, MAX_NB_CHAR_IN_LINE, stream);
    sscanf(buf, "# %d", &nbline);

    // lire la 2e   ligne du fichier => nb de col de la matrice
    fgets(buf, MAX_NB_CHAR_IN_LINE, stream);
    sscanf(buf, "# %d", &nbcol);

    if (NULL != pM->data)
    {
        Finalize_matrix(pM);
    }

    Initialize_matrix(pM, nbline, nbcol);

    for (int i = 0; i < Get_nb_lines(pM); i++)
    {
        for (int j = 0; j < Get_nb_columns(pM); j++)
        {
            double val = 0.0;
            fgets(buf, MAX_NB_CHAR_IN_LINE, stream);
            sscanf(buf, "%lf", &val);
            Set_elem_matrix(pM, i, j, val);
        }
    }
    // lire les coef ligne à ligne dans le fichier
}

void Write_to_stream_matrix(Matrix_t *pM, FILE *stream)
{
    fprintf(stream, "# %d\n", Get_nb_lines(pM));
    fprintf(stream, "# %d\n", Get_nb_columns(pM));
    for (int i = 0; i < Get_nb_lines(pM); i++)
    {
        for (int j = 0; j < Get_nb_columns(pM); j++)
        {
            fprintf(stream, "%g\n", Get_elem_matrix(pM, i, j));
        }
    }
}
