#ifndef _LINALG_H_
#define _LINALG_H_

#include "linalg_types.h"

unsigned int Get_size_vect(Vect_t *pv);
double Get_elem_vect(Vect_t *pv, unsigned int id);
void Set_size_vect(Vect_t *pv, unsigned int size);
void Set_elem_vect(Vect_t *pv, unsigned int id, double val);
void Write_to_stream_vect(Vect_t *pv, FILE *stream);
void Read_from_stream_vect(Vect_t *pv, FILE *stream);
void Initialize_vect(Vect_t *pv, unsigned int size);
void Finalize_vect(Vect_t *pv);

void Initialize_matrix(Matrix_t *pM, unsigned int nbli, unsigned int nbco);
void Finalize_matrix(Matrix_t *pM); 
unsigned int Get_nb_columns(Matrix_t *pM);
unsigned int Get_nb_lines(Matrix_t *pM);
double Get_elem_matrix(Matrix_t *pM, unsigned int li, unsigned int co);
void Set_elem_matrix(Matrix_t *pM, unsigned int li, unsigned int co, double val);
void Read_from_stream_matrix(Matrix_t *pM, FILE *stream);
void Write_to_stream_matrix(Matrix_t *pM, FILE *stream);

#endif