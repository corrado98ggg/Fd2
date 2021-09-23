#include "list.h"

int ListOccorenze(const Item* i, const ElemType* e){

	if (ListIsEmpty(i)) {
		return 0;
	}

	int ret = 0;

	while (!ListIsEmpty(i)) {

		if (ElemCompare(ListGetHeadValue(i), e) == 0) {
			ret++;
		}

		i = ListGetTail(i);
	}
	return ret;
}

int main(void) {
	ElemType e[] = { 2,4,3 };
	Item* List = ListCreateEmpty();

	for (int i = 0; i < 3; i++) {
		List = ListInsertHead(&e[i], List);
	}

	return ListOccorenze(List, &e[2]);
}