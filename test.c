#include <stdlib.h>
#include <stdio.h>
#include "linalg_types.h"
#include "linalg.h"

int main(void)
{
    Vect_t v;
    unsigned int i = 0;
    unsigned int id = 2;
    double d = cos(3.24);

    i = Get_size_vect(&v);
    printf("taille du vecteur = %d\n", i);
    d = Get_elem_vect(&v, id);
    printf("la coord num %d est  %g\n", id, d);

    printf("test is done.\n");
    return EXIT_SUCCESS;
}