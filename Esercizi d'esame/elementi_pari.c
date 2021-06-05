#include "list.h"
#include <stdio.h>
#include <stdlib.h>


Item* ElementiPari(const Item* i) {

	//le sole di inidici pari
	//0, 2, 4

	Item* ret = ListCreateEmpty();

	ElemType cont = 0;
	
	while (!ListIsEmpty(i)) {

		if (cont % 2 == 0) {
			ret = ListInsertBack(ret, ListGetHeadValue(i));
		}
		cont++;
		i = ListGetTail(i);
	}

	return ret;
}

/*
int main(void) {

	ElemType e[] = { 7,2,5,8,6 };
	Item* list = ListCreateEmpty();

	for (size_t i = 0; i < 5; i++) {
		list = ListInsertHead(&e[i], list);
	}

	ListWriteStdout(list);

	Item* pari = ElementiPari(list);

	ListWriteStdout(pari);
}
*/