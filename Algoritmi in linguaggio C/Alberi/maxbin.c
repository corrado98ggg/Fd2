#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int mmassimo(const ElemType* v, int l, int r) {

	int max_i = l;

	for (int i = l; i < r; i++) {
		if (v[max_i] < v[i]) {
			max_i = i;
		}
	}
	return max_i;
}

Node* CreateMaxBinTreeRec(const ElemType* v, int l, int r) {

	if (l >= r) {
		return NULL;
	}

	int max_i = mmassimo(v, l, r);

	Node* sx = CreateMaxBinTreeRec(v, l, max_i);
	Node* dx = CreateMaxBinTreeRec(v, max_i + 1, r);

	return TreeCreateRoot(&v[max_i], sx, dx);
}

Node* CreateMaxBinTree(const ElemType* v, size_t v_size) {

	if (v_size == 0) {
		return TreeCreateEmpty();
	}

	return CreateMaxBinTreeRec(v, 0, v_size);
}


int main() {

	ElemType e[] = { 3,2,1,6,0,5 };
	size_t v_size = 6;

	Node* t = CreateMaxBinTree(e, v_size);

	return 0;
	
}