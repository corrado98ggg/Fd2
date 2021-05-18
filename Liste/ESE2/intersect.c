#include "elemtype.h"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>


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

Item* Intersect(const Item* i1, const Item* i2) {

	Item* ret = ListCreateEmpty();

	Item* tmp1 = ListCreateEmpty();
	Item* tmp2 = ListCreateEmpty();

	tmp1 = i1;
	tmp2 = i2;

	ElemType e;

	while (!ListIsEmpty(tmp1)) {

		e = ElemCopy(ListGetHeadValue(tmp1));

		if (contains(tmp2, e) == 1) {

			ret = ListInsertHead(&e, ret);
		}

		tmp1 = ListGetTail(tmp1);
	}
	return ret;
}

int main(void) {

	ElemType e[] = { 2, 8, 10, 3 };
	ElemType e2[] = { 2, 10, 3 };


	Item* list1 = ListCreateEmpty();
	Item* list2 = ListCreateEmpty();

	Item* list_int = ListCreateEmpty();

	for (int i = 0; i < 4; i++) {
		list1 = ListInsertHead(&e[i], list1);
	}

	for (int i = 0; i < 3; i++) {
		list2 = ListInsertHead(&e2[i], list2);
	}

	ListWriteStdout(list1);
	ListWriteStdout(list2);

	list_int = Intersect(list1, list2);

	ListWriteStdout(list_int);
}