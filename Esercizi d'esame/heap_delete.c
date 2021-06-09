#include "minheap.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void HeapDeleteNode(Heap* h, int k) {

	if (k < 0 || k >= h->size) {
		return;
	}

	for (int i = 0; i < h->size; i++) {

		if (i == k) {

			ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, h->size - 1));
			h->size--;
			h->data = realloc(h->data, sizeof(ElemType) * h->size);
			break;
		}
	}

	for (int i = h->size / 2 - 1; i >= 0; i--) {
		HeapMinMoveDown(h, i);
	}

	return;
}

/*
int main() {

	ElemType c[] = { 0,2,4,8,12,18,77,21,9 };
	ElemType e = 0;

	Heap* h = HeapCreateEmpty();
	h->data = malloc(sizeof(ElemType) * 9);
	h->size = 9;

	memcpy(h->data, c, sizeof(ElemType) * 9);

	for (int i = h->size / 2 - 1; i >= 0; i--) {
		HeapMinMoveDown(h, i);
	}

	HeapWriteStdout(h);
	HeapDeleteNode(h, 6);
	HeapWriteStdout(h);

	HeapDelete(h);
}
*/