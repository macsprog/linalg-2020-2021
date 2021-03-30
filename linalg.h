#ifndef _LINALG_H_
#define _LINALG_H_

#include "linalg_types.h"

unsigned int Get_size_vect(Vect_t *pv);
double Get_elem_vect(Vect_t* pv, unsigned int id);
void Set_size_vect(Vect_t* pv, unsigned int size);
void Set_elem_vect(Vect_t *pv, unsigned int id, double val);
void Write_to_stream_vect(Vect_t *pv, FILE *stream);
void Initialize_vect(Vect_t* pv, unsigned int size);
void Finalize_vect(Vect_t* pv);



#endif