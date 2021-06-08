#include "minheap.h"
#include <stdio.h>
#include <stdlib.h>


void HeapMinDownRec(Heap* h, int i) {

	//caso base: HeapIsLeaf (non è una primitiva)
	if (i > (h->size - 1 / 2)) {    //questo è un calcolo che ci dice se il nodo è foglia
		return;
	}

	int smallest = i; //indice del più piccolo, nodo da scambiare
	int left = HeapLeft(i);
	int right = HeapRight(i);

	if (left < (int)h->size && ElemCompare(HeapGetNodeValue(h, smallest), HeapGetNodeValue(h, left) > 0)) {
		smallest = left;
	}

	if (right < (int)h->size && ElemCompare(HeapGetNodeValue(h, smallest), HeapGetNodeValue(h, right) > 0)) {
		smallest = right;
	}

	if (smallest != i) {
		ElemSwap(HeapGetNodeValue(h, smallest), HeapGetNodeValue(h, i));
		HeapMinDownRec(h, smallest);
	}

}


int main(void) {
	Heap* h = HeapCreateEmpty();
	h->data = malloc(sizeof(Heap) * 1);
	h->size = 5;

	//mettendo dei dati ordinati in sesno crescente 
	//sicuramente rispettano le condizioni del min-heap
	//il primo nodo lo lasciamo più grande degli altri per testare la move down
	h->data[0] = 7;

	h->data[1] = 2;
	h->data[2] = 3;
	h->data[3] = 4;
	h->data[4] = 5;

	HeapDelete(h);
}