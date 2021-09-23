#include "list.h"

Item* IntersectNoRepd(const Item* i1, const Item* i2) {

	if (ListIsEmpty(i1) && ListIsEmpty(i2)) return ListCreateEmpty();

	Item* ret = ListCreateEmpty();
	Item* tmp = i2;
	ElemType* e = 0;

	while (!ListIsEmpty(i1)) {

		tmp = i2;

		e = ListGetHeadValue(i1);

		while (!ListIsEmpty(tmp)) {

			if (*e == *ListGetHeadValue(tmp)) {
				ret = ListInsertBack(ret, ListGetHeadValue(tmp));

				tmp = ListGetTail(tmp);
				break;
			}

			tmp = ListGetTail(tmp);
		}

		i1 = ListGetTail(i1);
	}
	return ret;
}


/*
int main(void) {


	ElemType e[] = { 1,2,45,0,2,4,3,1 };
	Item* List = ListCreateEmpty();

	for (int i = 0; i < 8; i++) {
		List = ListInsertHead(&e[i], List);
	}

	Item* List2 = ListCreateEmpty();
	ElemType e2[] = { 5,7,45,3,2,5,8,45 };

	for (int i = 0; i < 8; i++) {
		List2 = ListInsertHead(&e2[i], List2);
	}

	List = Intersect(List, List2);

	ListWriteStdout(List);
}*/