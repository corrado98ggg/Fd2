#include "minheap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void InserisciNodo(Heap* h, ElemType e) {

	h->size++;
	h->data = realloc(h->data, sizeof(ElemType) * h->size);

	h->data[h->size - 1] = e;

	for (int i = h->size / 2 - 1; i >= 0; i--) {
		HeapMinMoveDown(h, i);
	}

	return;
}

void CancellaNodo(Heap* h, ElemType e) {

	for (int i = 0; i < h->size; i++) {

		if (h->data[i] == e) {

			ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, h->size - 1));
			h->size--;
			h->data = realloc(h->data, sizeof(ElemType) * h->size);
		}
	}

	for (int i = h->size / 2 - 1; i >= 0; i--) {
		HeapMinMoveDown(h, i);
	}

	return;
}

void PopHeap(Heap* h, ElemType* e) {

	if (HeapIsEmpty(h)) {
		return;
	}

	*e = *HeapGetNodeValue(h, 0); 
	ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));

	h->size--;
	h->data = realloc(h->data, h->size * sizeof(ElemType));
	HeapMinMoveDown(h, 0);

	return;
}

int main() {

	ElemType c[5] = { 2,5,6,7,8 };
	ElemType e = 0;

	Heap* h = HeapCreateEmpty();
	h->data = malloc(sizeof(ElemType) * 5);
	h->size = 5;

	memcpy(h->data, c, sizeof(ElemType) * 5);

	for (int i = h->size / 2 - 1; i >= 0; i--) {
		HeapMinMoveDown(h, i);
	}

	HeapWriteStdout(h);
	PopHeap(h, &e);
	HeapWriteStdout(h);


	CancellaNodo(h, 6);
	HeapWriteStdout(h);

	InserisciNodo(h, 6);
	HeapWriteStdout(h);

	HeapDelete(h);

	return e;
}