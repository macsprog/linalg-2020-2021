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
|_|_|_|_|_|_|_ 

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

