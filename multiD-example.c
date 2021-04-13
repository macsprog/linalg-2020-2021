#include <stdlib.h>
#include <stdio.h>

/* tableaux multi-D statiques en C */

struct complex_t
{
    double re;
    double im;
};

int main(void)
{
    /* definition d'une variable tableau multi-D */
    double A[10][5];         // tableau de double de taille 10 x 5 elts
    double B[20][15][3][52]; // tableau de double de taille 20 x 15 x 3 x 52 elts
    struct complex_t C[3][2][4]; // tableau de struct complex_t
    char* buf[20]; // tableau de char* (tableau de pointeurs sur char)

    /* accès aux elts */
    A[0][2] = 1.3;               /* accès en écriture */
    printf("val=%g\n", A[0][2]); /* accès en lecture */
    C[0][1][3].im = 1.2;
    (C[0][1][3]).re = 2.2984;
    A[-1][0] = 2.3; /* ouch! mais c'est valide! */
    A[200][3000] = 2.3; /* ouch! mais c'est valide! */

    /* comment ça se passe sous le capot ? (en mémoire)*/
    /* A ~ pointeur sur un pointeur de double  cad A est de type (double**) */
    /* A[0] ~ pointeur de double cad A[0] est de type (double*) */
    /* A[1] ~ pointeur de double  cad  A[1] ~ pointeur de double */
    /* ... */
    /* A[9] ~ pointeur de double cad A[9] ~ pointeur de double*/





    return EXIT_SUCCESS;
}

void fun1(double A[10][3]){ // ok

}

#if 0
void fun2(double A[][]){ // error: impossible de compiler

}
#endif

void fun2(double A[][5]){ // ok !
}


