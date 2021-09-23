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



ElemType* kthLeast(const Heap* h, int k) {

	ElemType* v = malloc(sizeof(ElemType) * h->size);

	memcpy(v, h->data, sizeof(ElemType) * h->size);
	ElemType tmp = 0;

	for (int i = 0; i < h->size; i++) {
		for (int j = 0; j < h->size; j++) {
			if (v[i] < v[j]) {
				tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}

	for (int i = 0; i < h->size; i++) {
		printf("%d ", v[i]);
	}

	return &v[k - 1];
	
}

int main() {

	ElemType v[] = { 0,12,4,21,2,18,77,8,9 };
	size_t v_size = 9;

	Heap* ciao = HeapCreateEmpty();
	ciao = Heapify(v, v_size);


	HeapWriteStdout(ciao);

	ElemType* ciaoo = 0;
	//ciaoo = kthLeast(ciao, 1);
	ciaoo = kthLeast(ciao, 6);
	HeapWriteStdout(ciao);
}