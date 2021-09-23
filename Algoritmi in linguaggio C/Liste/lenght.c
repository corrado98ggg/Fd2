#include "list.h"

int Listlenght(const Item* i) {

	if (ListIsEmpty(i)) {
		return 0;
	}

	Item* tmp = i;
	int cont = 0;

	while (!ListIsEmpty(tmp)) {
		cont++;
		tmp = ListGetTail(tmp);
	}

	ListDelete(tmp);

	return cont;
}

/*
int main(void) {
	ElemType e[] = { 2,3,4,5 };
	Item* List = ListCreateEmpty();

	for (int i = 0; i < 4; i++) {
		List = ListInsertHead(&e[i], List);
	}

	return Listlenght(List);
}*/