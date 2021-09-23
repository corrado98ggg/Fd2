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

bool HeapMinPop(Heap* h, ElemType* e) {


	if (HeapIsEmpty(h)) {
		return false;
	}

	*e = h->data[2];
	size_t i = 0;
	int k = 0;

	for (i; i < h->size - 1; i++) {

		if (h->data[i] < *e) {
			*e = h->data[i];
			k = i;
		}
	}

	ElemSwap(&h->data[k], &h->data[h->size - 1]);
	h->size--;
	h->data = realloc(h->data, sizeof(ElemType) * h->size);

	for (int j = h->size / 2 - 1; j >= 0; j--) {
		HeapMinMoveDown(h, j);
	}

	HeapWriteStdout(h);

	return true;

}

/*
int main() {

	ElemType v[] = { 4,8,1,2,0,10,3,8 };
	size_t v_size = 8;

	Heap* ciao = HeapCreateEmpty();
	ciao = Heapify(v, v_size);

	HeapWriteStdout(ciao);

	ElemType e = 8;
	bool c = HeapMinPop(ciao, &e);
	HeapWriteStdout(ciao);	
}*/