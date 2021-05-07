#include "elemtype.h"
#include "vettore.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


int VectorFind(const Vector* v, const ElemType* e) {

	int size = 1;
	// 0, 1, 2, 3        -       2 è in posizione: 3

	for (int i = 0; i < v->size; i++) {

		if (v->data[i] == *e) {
			return size;
		}
		size++;
	}
	return -1;
}

int main(void) {

	Vector v;

	v.capacity = 4;
	v.size = 4;
	v.data = malloc(sizeof(ElemType) * v.capacity);

	ElemType t[4] = { 0,1,2,3 };

	for (int i = 0; i < v.capacity; i++) {
		v.data[i] = t[i];
	}

	ElemType elem = 5;

	return VectorFind(&v, &elem);

}