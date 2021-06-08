#include "minheap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//NOTA BENE NON FUNZIONA IN TUTTI I CASI

Heap* MergeHeap(const Heap* h1, const Heap* h2) {

	Heap* new = HeapCreateEmpty();

	if (HeapIsEmpty(h2) && HeapIsEmpty(h1)) {
		return new;
	}

	new->size = h1->size + h2->size;
	new->data = malloc(sizeof(ElemType) * new->size);
	int k = 0;

	for (int i = 0; i < new->size; i++) {
		if (i <= h1->size) {
			new->data[i] = h1->data[i];
		}
		if (i > h1->size - 1) {
			new->data[i] = h2->data[k];
			k++;
		}
	}

	for (int i = new->size / 2 - 1; i >= 0; i--) {
		HeapMinMoveDown(new, i);
	}

	return new;
}

/*
int main(void) {
	Heap* h = HeapCreateEmpty();
	h->size = 5;
	h->data = malloc(sizeof(ElemType) * h->size);

	//mettendo dei dati ordinati in sesno crescente 
	//sicuramente rispettano le condizioni del min-heap
	h->data[0] = 5;
	h->data[1] = 4;
	h->data[2] = 3;
	h->data[3] = 2;
	h->data[4] = 1;


	Heap* h2 = HeapCreateEmpty();
	h2->size = 5;
	h2->data = malloc(sizeof(ElemType) * h2->size);


	//mettendo dei dati ordinati in sesno crescente 
	//sicuramente rispettano le condizioni del min-heap

	h2->data[4] = 9;
	h2->data[3] = 8;
	h2->data[2] = 7;
	h2->data[1] = 6;
	h2->data[0] = 5;

	MergeHeap(h, h2);
}*/
