#include "elemtype.h"
#include "vettore.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


void VectorSort(Vector* v) {

	if (v == NULL) {
		return;
	}

	for (size_t i = 0; i < v->capacity; i++) {
		for (size_t j = i + 1; j < v->capacity; j++) {
			if (v->data[i] > v->data[j]) {
				ElemSwap(&v->data[i], &v->data[j]);
			}
		}
	}
}

int main(void) {

	Vector v;
	v.capacity = 4;
	v.size = 4;
	v.data = malloc(sizeof(ElemType) * v.size);

	size_t t[4] = { 6,3,8,0 };

	for (size_t i = 0; i < v.capacity; i++) {
		v.data[i] = t[i];
	}

	VectorSort(&v);

	for (size_t i = 0; i < v.capacity; i++) {
		printf("%d ", v.data[i]);
	}

	return 0;
}