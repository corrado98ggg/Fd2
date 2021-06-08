#include "minheap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Dato un vettore di elemtype e la sua size, ordina il vettore
senza l'utilizzo di algoritmi di ordinamento
N.B. se viene utilizzato un Min-Heap allora il vettore verrà ordinato
in maniera decrescente, nel caso in cui si dovesse utilizzare un Max-heap
allora il vettore sarà ordinato in maniera crescente*/

ElemType* Sort(const ElemType* v, size_t v_size) {


	//creo un Heap, utilizzando i dati a disposizione

	Heap* h = HeapCreateEmpty();
	h->size = v_size;
	h->data = malloc(sizeof(ElemType) * v_size);
	memcpy(h->data, v, sizeof(ElemType) * v_size);


	for (int i = h->size / 2 - 1; i >= 0; i--) {
		HeapMinMoveDown(h, i);
	}

	size_t original_size = v_size;

	while (h->size >= 2) {
		ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));
		h->size--;
		HeapMinMoveDown(h, 0);
	}

	h->size = original_size;

	memcpy(v, h->data, sizeof(ElemType) * v_size);

	HeapDelete(h);

	return v;
}


int main(void) {


	ElemType v[5] = { 4,5,6,2,1 };
	size_t v_size = 5;

	ElemType* ret = Sort(v, v_size);

	for (int i = 0; i < 7; i++) {
		printf(" %d ", ret[i]);
	}

}