#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>


Node* CreateTreeFromVectorRec(const int* v, size_t v_size, int i) {

	if (i >= (int)v_size) {
		return NULL;
	}


	Node* l = CreateTreeFromVectorRec(v, v_size, i * 2 + 1);
	Node* r = CreateTreeFromVectorRec(v, v_size, i * 2 + 2);

	return TreeCreateRoot(&v[i], l, r);
}

Node* CreateTreeFromVector(const int* v, size_t v_size) {

	return CreateTreeFromVectorRec(v, v_size, 0);
}

int main() {

	int v[] = { 1,2,3,4,5,6 };
	

	Node* t = CreateTreeFromVector(v, 6);

}