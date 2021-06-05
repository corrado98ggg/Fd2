#include "minheap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool IsHeapRec(const Heap* h, int i, bool ret) {

	//caso base:
	if (HeapLeft(i) > (int)(h->size - 1) / 2 || HeapRight(i) > (int)(h->size - 1) / 2) {
		return ret;
	}

	size_t left = HeapLeft(i);
	size_t right = HeapRight(i);

	if (left < h->size && ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, left)) < 0) {

		if (right < h->size && ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, right)) < 0) {

			IsHeapRec(h, i + 1, ret);
		}
	}
	else {
		ret = false;
		IsHeapRec(h, i + 1, ret);
	}

}


bool IsHeap(const Heap* h) {

	if (HeapIsEmpty(h)) {
		return true;
	}
	
	bool tmp = true;

	return IsHeapRec(h, 0, tmp);
}

/*
int main(void) {

	Heap* h = HeapCreateEmpty();

	h->size = 6;

	h->data = malloc(sizeof(ElemType) * 6);

	h->data[0] = 6;
	h->data[1] = 5;
	h->data[2] = 4;
	h->data[3] = 3;
	h->data[4] = 2;
	h->data[5] = 1;

	//h->data[4] = 5;

	bool c = IsHeap(h);

}*/