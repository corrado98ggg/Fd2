#include "minheap.h"
#include <stdio.h>
#include <stdlib.h>

void Push(Heap* h, const ElemType* e) {

	h->size++;
	h->data = realloc(h->data, sizeof(ElemType) * h->size);

	h->data[h->size - 1] = *e;

	for (int i = h->size / 2 - 1; i >= 0; i--) {
		HeapMinMoveDown(h, i);
	}

	return h;
}

/*
int main() {

	Heap* h = HeapCreateEmpty();
	h->size = 5;
	h->data = malloc(sizeof(ElemType) * h->size);

	h->data[0] = 4;
	h->data[1] = 5;
	h->data[2] = 6;
	h->data[3] = 7;
	h->data[4] = 8;

	const ElemType e = 4;
	Push(h, &e);

	Heap* h2 = HeapCreateEmpty();
	h2->size = 5;
	h2->data = malloc(sizeof(ElemType) * h2->size);

	h2->data[0] = 6;
	h2->data[1] = 7;
	h2->data[2] = 8;
	h2->data[3] = 9;
	h2->data[4] = 10;
}*/