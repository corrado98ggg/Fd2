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

Heap* MergeHeap(const Heap* h1, const Heap* h2) {

	if (HeapIsEmpty(h1) && HeapIsEmpty(h2)) {
		return HeapCreateEmpty();
	}


	Heap* tot = HeapCreateEmpty();
	tot->size = h1->size + h2->size;
	tot->data = malloc(sizeof(ElemType) * (tot->size));

	int i = 0;
	int k = 0;
	for (i = 0; i < h1->size; i++) {
		tot->data[i] = h1->data[i];
	}
	for (i; i < (int)tot->size; i++) {
		tot->data[i] = h2->data[k];
		k++;
	}

	for (int i = 0; i < (int)tot->size; i++) {
		HeapMinMoveDown(tot, i);
	}

	return tot;

}


int main() {

	ElemType v[] = { 4,8,1,2 };
	ElemType v2[] = { 4,5,6,7 };

	size_t v_size = 4;

	Heap* ciao = HeapCreateEmpty();
	ciao = Heapify(v, v_size);

	Heap* ciao2 = HeapCreateEmpty();
	ciao2 = Heapify(v2, v_size);

	HeapWriteStdout(ciao);
	HeapWriteStdout(ciao2);



	ciao = MergeHeap(ciao, HeapCreateEmpty());
	HeapWriteStdout(ciao);
}