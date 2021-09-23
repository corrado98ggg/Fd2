#include "minheap.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Heap* Heapify(const ElemType* v, size_t v_size) {

	if (v_size == 0) {
		return HeapCreateEmpty();
	}

	Heap* h = HeapCreateEmpty();

	h->size = v_size;
	h->data = malloc(sizeof(ElemType) * (v_size));
	
	memcpy(h->data, v, sizeof(ElemType) * v_size);

	for (int i = (int)h->size / 2 - 1; i >= 0; i--) {
		HeapMinMoveDown(h, i);
	}

	return h;
}

int main() {

	ElemType v[] = { 4,8,1,2 };
	size_t v_size = 4;

	Heapify(v, v_size);
}