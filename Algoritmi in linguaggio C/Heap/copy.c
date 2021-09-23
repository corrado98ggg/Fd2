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



Heap* Heapcopy(const Heap* h) {

	if (HeapIsEmpty(h)) {
		return NULL;
	}

	Heap* new_h = HeapCreateEmpty();
	new_h->size = h->size;

	new_h->data = malloc(sizeof(ElemType) * new_h->size);

	for (int i = 0; i < h->size; i++) {
		new_h->data[i] = h->data[i];
	}

	return new_h;

}

int main() {

	ElemType v[] = { 4,8,1,2 };
	size_t v_size = 4;

	Heap* ciao = HeapCreateEmpty();
	ciao = Heapify(v, v_size);

	HeapWriteStdout(ciao);

	ciao = Heapcopy(ciao, 1);
	HeapWriteStdout(ciao);
}