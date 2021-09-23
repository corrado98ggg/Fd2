#include "list.h"

Item* filter(Item* i, ElemType e) {

	if (ListIsEmpty(i)) {
		return ListCreateEmpty();
	}

	Item* new = ListCreateEmpty();

	while (!ListIsEmpty(i)) {
		if (ElemCopy(ListGetHeadValue(i)) < e) {
			new = ListInsertHead(ListGetHeadValue(i), new);
		}
		i = ListGetTail(i);
	}

	ListWriteStdout(new);
	return new;
}


int main(void) {
	ElemType e[] = { 3,5,2,1,4 };
	ElemType e3 = 6;

	Item* ret = ListCreateEmpty();

	for (int i = 0; i < 5; i++) {
		ret = ListInsertBack(ret, &e[i]);
	}

	ret = filter(ret, 3);
}