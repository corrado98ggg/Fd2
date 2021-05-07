#include "elemtype.h"

#ifndef VETTORE_H
#define VETTORE_H

typedef struct {
	size_t capacity;
	size_t size;
	ElemType* data;
} Vector;


extern void VectorSort(Vector* v);

#endif // !VETTORE_C
