#include "minheap.h"
#include <stdlib.h>
#include <stdio.h>


Heap* MergeHeap(const Heap* h1, const Heap* h2) {


	Heap* ret = HeapCreateEmpty();
	ret->size = h1->size + h2->size;
	ret->data = malloc(sizeof(ElemType) * ret->size);

	int k = 0;

	for (int i = 0; i < ret->size; i++) {
		if (i < h1->size) {
			ret->data[i] = h1->data[i];
		}
		else {
			ret->data[i] = h2->data[k];
			k++;
		}
	}

	for (int i = ret->size / 2 - 1; i >= 0; i--) {
		HeapMinMoveDown(ret, i);
	}

	return ret;

}

/*
int main() {

	Heap* h = HeapCreateEmpty();
	h->size = 4;
	h->data = malloc(sizeof(ElemType) * 4);

	h->data[0] = 1;
	h->data[1] = 2;
	h->data[2] = 3;
	h->data[3] = 4;

	Heap* h1 = HeapCreateEmpty();
	h1->size = 2;
	h1->data = malloc(sizeof(ElemType) * 2);

	h1->data[0] = 5;
	h1->data[1] = 6;



	Heap* tmp =MergeHeap(h, h1);

	HeapWriteStdout(tmp);
}*/