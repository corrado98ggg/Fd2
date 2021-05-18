#include "elemtype.h"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>

const ElemType* MaxElement(const Item* i) {

	ElemType e = ElemCopy(ListGetHeadValue(i));
	ElemType tmp;
	
	while (!ListIsEmpty(i)) {

		tmp = ElemCopy(ListGetHeadValue(i));

		if (tmp > e) {
			e = tmp;
		}
		i = ListGetTail(i);
	}
	return e;
}

int main(void) {

	ElemType e[] = { 1, 45, 0, 2, 4, 1, 3 };
	ElemType e2[] = { 7, 3, 2, 5, 150 };

	Item* list = ListCreateEmpty();
	Item* list2 = ListCreateEmpty();

	Item* r = ListCreateEmpty();

	for (int i = 0; i < 7; i++) {
		list = ListInsertBack(list, &e[i]);
	}

	for (int i = 0; i < 5; i++) {
		list2 = ListInsertBack(list2, &e2[i]);
	}

	return MaxElement(list2);

	ListWriteStdout(list);
	ListWriteStdout(list2);
	ListWriteStdout(r);
}