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



Heap* DeleteNode(Heap* h, int k) {

	if (k < 0 || k >= (int)h->size) {
		return h;
	}


	for (int i = 0; i < h->size; i++) {
		
		if (i == k) {

			ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, h->size - 1));
			ElemDelete(&h->data[h->size - 1]);

			h->size--;
			h->data = realloc(h->data, h->size * sizeof(ElemType));
		}
	}

	for (int i = h->size / 2 - 1; i >= 0; i--) {
		HeapMinMoveDown(h, i);
	}

	return h;
}

int main() {

	ElemType v[] = { 4,8,1,2 };
	size_t v_size = 4;

	Heap* ciao = HeapCreateEmpty();
	ciao = Heapify(v, v_size);

	HeapWriteStdout(ciao);

	ciao = DeleteNode(ciao, 1);
	HeapWriteStdout(ciao);


	
}