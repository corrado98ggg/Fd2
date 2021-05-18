#include "elemtype.h"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>


bool contains(Item* i, ElemType e) {

	ElemType tmp;

	while (!ListIsEmpty(i)) {

		tmp = ElemCopy(ListGetHeadValue(i));

		if (tmp == e) {
			return true;
		}	
		i = ListGetTail(i);
	}
	return false;
}


Item* Diff(const Item* i1, const Item* i2) {

	Item* ret = ListCreateEmpty();
	ElemType e;

	while (!ListIsEmpty(i1)) {

		e = ElemCopy(ListGetHeadValue(i1));

		if (contains(i2, e) == false) {
			ret = ListInsertHead(&e, ret);
		}
		i1 = ListGetTail(i1);
	}
	return ret;
}


int main(void) {

	ElemType e[] = { 1, 45, 0, 2, 4, 1, 3 };
	ElemType e2[] = { 7, 45, 3, 2, 5 };

	Item* list = ListCreateEmpty();
	Item* list2 = ListCreateEmpty();

	Item* r = ListCreateEmpty();

	for (int i = 0; i < 7; i++) {
		list = ListInsertBack(list, &e[i]);
	}

	for (int i = 0; i < 5; i++) {
		list2 = ListInsertBack(list2, &e2[i]);
	}

	r = Diff(list, list2);

	ListWriteStdout(list);
	ListWriteStdout(list2);
	ListWriteStdout(r);
}