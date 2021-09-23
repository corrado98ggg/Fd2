#include "list.h"

Item* Taglia(Item* i, int n) {

	int lenght = 0;
	Item* lun = i;
	while (!ListIsEmpty(lun)) {
		lenght++;
		lun = ListGetTail(lun);
	}


	if (n < 0 || n >= lenght) {
		return i;
	}

	Item* tmp = i;
	for (int j = 0; j < n - 1; j++) {
		tmp = ListGetTail(tmp);
	}
	ListDelete(ListGetTail(tmp));
	tmp->next = NULL;

	ListWriteStdout(i);

	return i;

}

int main(void) {

	ElemType e[] = { 0,1,2,3 };
	Item* List = ListCreateEmpty();
	for (int i = 0; i < 4; i++) {
		List = ListInsertBack(List, &e[i]);
	}

	Taglia(List, 3);

}