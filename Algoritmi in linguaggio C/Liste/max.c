#include "list.h"


ElemType* MaxElement(const Item* i) {

	if (ListIsEmpty(i)) {
		return NULL;
	}

	ElemType* max = ListGetHeadValue(i);

	i = i->next;

	while (!ListIsEmpty(i)) {

		if (*ListGetHeadValue(i) > *max) {
			max = ListGetHeadValue(i);
		}

		i = ListGetTail(i);
	}

	return max;
}


/*
int main(void) {


	ElemType e[] = { 80,60,45 };
	Item* List = ListCreateEmpty();

	for (int i = 0; i < 3; i++) {
		List = ListInsertHead(&e[i], List);
	}

	Item* List2 = ListCreateEmpty();
	ElemType e2[] = { 5,7,45,3,2,5,8,45 };

	for (int i = 0; i < 8; i++) {
		List2 = ListInsertHead(&e2[i], List2);
	}

	ElemType* massimo = MaxElement(List);

	ListWriteStdout(List);
}*/