#include "minheap.h"
#include <string.h>
#include <stdio.h>


ElemType KthLeast(const Heap* h, int k) {

	Heap* tmp = HeapCreateEmpty();
	ElemType ret = 0;

	tmp->size = h->size;
	tmp->data = malloc(sizeof(ElemType) * tmp->size);
	
	for (int i = 0; i < tmp->size; i++) {
		tmp->data[i] = h->data[i];
	}

	ElemType index = 0;

	while (tmp->size >= 2) {
		ElemSwap(HeapGetNodeValue(tmp, 0), HeapGetNodeValue(tmp, tmp->size - 1));

		tmp->size--;
		HeapMinMoveDown(tmp, 0);
	}

	tmp->size = h->size;
	index = h->size - k;

	ret = tmp->data[index];
	
	HeapDelete(tmp);

	return ret;
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

	return KthLeast(h, 4);

}
*/