#ifndef _LINALG_TYPES_H_
#define _LINALG_TYPES_H_

// we assume that each ascii file line has a max of 1024 char
#define MAX_NB_CHAR_IN_LINE 1024

typedef struct Vect_t Vect_t;
struct Vect_t
{
    unsigned int size;
    double *data;
};

extern const Vect_t Null_Vect; // defined in vect.c


typedef struct Matrix_t Matrix_t;
struct Matrix_t
{
    unsigned int nb_li;
    unsigned int nb_co;
    double *data; // pointeur sur les coef de la matrice 
    double **line_data; //pointeur sur les lignes      /* facultatif     */

};

extern const Matrix_t Null_Matrix; // defined in matrix.c


#endif

/*
Vect_t v;

------------ espace mémoire associée à v -----------
<=sizeof(int)=>|<=sizeof(double*)=>|
|_|_|_|_|_|_|_ |_|_|_|_|_|_|_|_|_|_|
 \_ &(v.size)   \_____ &(v.data)
&(v.size) = &v


------------ espace mémoire associée à data (dans le tas) -----------
<=sizeof(double)=>|<=sizeof(double)=> |<=sizeof(double)=>
|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|
 \_____ data = 1032
 */

/*
Vect_t Pv;

<=sizeof(Vect_t*)=>
|_|_|_|_|_|_|_|_|_|_|_ 
 \___ Pv


------------ espace mémoire associée à *Pv (dans le tas)-----------
<=sizeof(int)=>|<=sizeof(double*)=>|
|_|_|_|_|_|_|_ |_|_|_|_|_|_|_|_|_|_|
 \_ &(Pv->size)   \_____ &(Pv->data)
&(Pv->size) = Pv


------------ espace mémoire associée à data (dans le tas) -----------
<=sizeof(double)=>|<=sizeof(double)=> |<=sizeof(double)=>
|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|
 \_____ data = 1032
 */

/*
Matrix_t M;

attention: je note uint = unsigned int

------------ espace mémoire associée à M ----------- 
<=sizeof(uint)=>|<=sizeof(uint)=>|<=sizeof(double*)=>|
|_|_|_|_|_|_|_  |_|_|_|_|_|_|_   |_|_|_|_|_|_|_|_|_|_|
 \_ &(M.nb_li)   \_ &(M.nb_co)    \_____ &(M.data)
 &(M.nb_li) = &M


après Initialize_matrix: on peut acceder a la memoire
pointee par M.data

------------ espace mémoire associée à data (dans le tas) -----------
<=sizeof(double)=>|<=sizeof(double)=> |<=sizeof(double)=>
|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|
 \_____ data = 3201
 
l'espace memoire dont l'adresse de demarrage est M.data : 
permet de stocker (M.nb_li)*(M.nb_co)

comment va-t-on acceder aux elements de la matrice?

pour simplifier les notations : I = nb_li, J = nb_co

li 0   | e 0*J +0  | e 0*J +1   | ... | e 0*J + J-1
li 1   | e 1*J + 0 | e 1*J +1   | ... | e 1*J + J-1
li 2   | e 2*J + 0 | e 2*J +1   | ... | e 2*J + J-1
...    | 
li i   | e i*J + 0 | e i*J +1   | ... | e i*J + J-1
...
li I-1 | e (I-1)*J + 0 | e (I-1)*J +1   | ... | e (I-1)*J + J-1 

M(0,0) ~> data[0] = *(data + 0)
M(0,1) ~> data[1] = *(data + 1)
M(0,J-1) ~> data[J-1] = *(data + J-1)
M(1,0) ~> data[J] = *(data 1*J + 0)

M(i,j) ~> data[i*J+j] = *(data i*J + j)




 
 */

/*

0 X X X X X nbcol
1 X X X X X nbcol
2 X X a X X
3 X X X X X
4 X X X X X
5 X X X X X

0 X X X X X|1 X X X X X|2 X X a X X|3 X X X X X|4 X X X X X|5 X X X X X

ncol*2 + 3 => nb de double à "passer" avant d'accéder à l'elt a 

a = elt de ligne 2 et colonne 3

*/