#include <stdlib.h>
#include <stdio.h>
#include "linalg_types.h"

#define TODOINT 1
#define TODODOUBLE 1.4653

const Vect_t Null_Vect = {.size = 0, .data = NULL};

/* fonction pas très intéressante: utilisée seulement à titre d'exemple */
void Set_size_vect(Vect_t *pv, unsigned int size)
{
    pv->size = size;
}

void Initialize_vect(Vect_t *pv, unsigned int size)
{
    pv->size = size;
    pv->data = malloc(sizeof(double) * size);
    if (NULL == pv->data)
    {
        fprintf(stderr, "error w/ memory alloc for vect\n");
        exit(EXIT_FAILURE);
    }
}

void Finalize_vect(Vect_t *pv)
{
    free(pv->data);
    pv->data = NULL;
    pv->size = 0;
    // on peut aussi utiliser
    //    *pv=Null_Vect;
}

unsigned int Get_size_vect(Vect_t *pv)
{
    return pv->size;
}

double Get_elem_vect(Vect_t *pv, unsigned int id)
{
    return pv->data[id];
    /* ou 
   return (pv->data)[id];
    return *(pv->data+id);
    */
}

void Set_elem_vect(Vect_t *pv, unsigned int id, double val)
{
    pv->data[id] = val;
}

void Write_to_stream_vect(Vect_t *pv, FILE *stream)
{
    int vsize = Get_size_vect(pv);

    fprintf(stream, "# %d\n", vsize);
    for (int i = 0; i < vsize; i++)
    {
        double data = Get_elem_vect(pv, i);
        fprintf(stream, "%g\n", data);
    }
}

void Read_from_stream_vect(Vect_t *pv, FILE *stream)
{
    char buf[MAX_NB_CHAR_IN_LINE] = "";
    unsigned int vsize = 0;

    fgetc(stream); // read first char
    fgetc(stream); // read second char
    if (NULL != fgets(buf, MAX_NB_CHAR_IN_LINE, stream))
    {
        vsize = atoi(buf); // TODO: check if it's ok
    }
    else
    {
        fprintf(stderr, "cannot read first line\n");
        exit(EXIT_FAILURE);
    }

    if (0 != Get_size_vect(pv))
    {
        Finalize_vect(pv);
    }

    Initialize_vect(pv, vsize);

    for (int i = 0; i < vsize; i++) // boucle sur la taille du vecteur:
    {
        if (NULL != fgets(buf, MAX_NB_CHAR_IN_LINE, stream))
        {
            double val = atof(buf);    // lire la ligne
            Set_elem_vect(pv, i, val); // assigner la valeur lue à la coordonnée du vect
        }
        else
        {
            fprintf(stderr, "cannot read line %d\n", i + 1);
            exit(EXIT_FAILURE);
        }
    }
}