#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int LunghezzaList(Item* tmp, int cont) {
	while (!ListIsEmpty(tmp)) {
		cont++;
		tmp = ListGetTail(tmp);
	}

	ListDelete(tmp);

	return cont;
}

Item* CopiaDaN(const Item* i, int n) {

	Item* tmp = i;
	int len = LunghezzaList(tmp, 0);

	if (ListIsEmpty(i) || len < n) {
		return NULL;
	}

	int cont = 1;
	Item* ret = ListCreateEmpty();

	while (!ListIsEmpty(i)) {

		if (cont == n) {
			while (!ListIsEmpty(i)) {
				ret = ListInsertBack(ret, ListGetHeadValue(i));
				i = ListGetTail(i);
			}
		}
		else {
			cont++;
			i = ListGetTail(i);
		}
	}

	ListDelete(i);

	return ret;
}

/*
int main(void) {

	//ElemType e[] = { 1, 4 };
	ElemType e2[] = { 1 };

	Item* list2 = ListCreateEmpty();

	Item* r = ListCreateEmpty();

	for (int i = 0; i < 1; i++) {
		list2 = ListInsertBack(list2, &e2[i]);
	}

	r = CopiaDaN(list2, 2);
	ListWriteStdout(r);
}*/