#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "linalg_types.h"
#include "linalg.h"

int main(void)
{
    unsigned int vsize = 10;
    unsigned int i = 0;
    unsigned int id = 2;
    double d = cos(3.24);
    FILE *stream = NULL;
    char file_name[] = "output_vect.txt";
    Vect_t v = Null_Vect;

    /* ecriture equivalente (en plus lourd)
    Vect_t *pv = NULL;
    pv = &v;
    Initialize_vect(pv, vsize);
    */

    /* 
    
    <-  sizeof(Vect_t)   ->
    |_|_|_|_|_|_|_|_|_|_|_|
     \______ 32095487=&v
    */

    Initialize_vect(&v, vsize);

    Set_elem_vect(&v, 0, 13.645);

    i = Get_size_vect(&v);
    printf("taille du vecteur = %d\n", i);
    d = Get_elem_vect(&v, id);
    printf("la coord num %d est  %g\n", id, d);

    stream = fopen(file_name, "w");
    if (NULL == stream)
    {
        fprintf(stderr, "cannot open file %s", file_name);
        exit(EXIT_FAILURE);
    }
    Write_to_stream_vect(&v, stream);

    fclose(stream);
    stream = NULL;

    Finalize_vect(&v);

    // autre possibilite d'utilisation
    // via un pointeur sur Vect_t
    Vect_t* Pv = NULL;
    Pv = malloc(sizeof(Vect_t));
    Initialize_vect(Pv, vsize);
    Finalize_vect(Pv);
    free(Pv)

    printf("test is done.\n");
    return EXIT_SUCCESS;
}