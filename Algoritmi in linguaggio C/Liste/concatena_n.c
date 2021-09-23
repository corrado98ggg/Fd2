#include "list.h"
#include <stdio.h>


Item* concatena(Item* i1, Item* i2, bool c) {

	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return ListCreateEmpty();
	}

	if (ListIsEmpty(i1)) {
		return i2;
	}

	if (ListIsEmpty(i2)) {
		return i2;
	}

	if (c == true) {

		Item* ret = ListCreateEmpty();

		while (!ListIsEmpty(i1)) {

			ret = ListInsertBack(ret, ListGetHeadValue(i1));

			i1 = ListGetTail(i1);
		}

		while (!ListIsEmpty(i2)) {

			ret = ListInsertBack(ret, ListGetHeadValue(i2));
			i2 = ListGetTail(i2);
		}

		return ret;
	}
	else {

			Item* tmp = i1;
			while (!ListIsEmpty(tmp->next)) {
				tmp = ListGetTail(tmp);
			}
			tmp->next = i2;

			return i1;
	}
}

int main(void) {

	ElemType e[] = { 0,1 };
	ElemType e2[] = { 2,3 };

	Item* List = ListCreateEmpty();
	for (int i = 0; i < 2; i++) {
		List = ListInsertBack(List, &e[i]);
	}

	Item* List2 = ListCreateEmpty();
	for (int i = 0; i < 2; i++) {
		List2 = ListInsertBack(List2, &e2[i]);
	}

	Item* v[] = { List, List2 };

	concatena(List, List2, true);
	concatena(List, List2, false);



}