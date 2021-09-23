#include "list.h"

Item* DiffNoRep(const Item* i1, const Item* i2) {

	if (ListIsEmpty(i1) && ListIsEmpty(i2)) return ListCreateEmpty();

	Item* ret = ListCreateEmpty();
	Item* tmp = i2;
	ElemType* e = 0;

	bool se_compare;
	bool doppio = false;

	while (!ListIsEmpty(i1)) {

		se_compare = false;
		tmp = i2;

		e = ListGetHeadValue(i1);

		while (!ListIsEmpty(tmp)) {

			if (*e == *ListGetHeadValue(tmp)) {
				se_compare = true;
				break;
			}

			tmp = ListGetTail(tmp);
		}

		if (se_compare == false) {

			Item* check = ret;

			while (!ListIsEmpty(check)) {

				if(*ListGetHeadValue(check) == *e){
					doppio = true;
				}
				check = ListGetTail(check);
			}

			if (doppio == false) {
				ret = ListInsertBack(ret, e);
			}
		}
		i1 = ListGetTail(i1);
	}

	return ret;
}

Item* IntersectNoRep(const Item* i1, const Item* i2) {

	if (ListIsEmpty(i1) && ListIsEmpty(i2)) return ListCreateEmpty();

	Item* ret = ListCreateEmpty();
	Item* tmp = i2;
	ElemType* e = 0;
	bool doppio = false;

	while (!ListIsEmpty(i1)) {

		tmp = i2;

		e = ListGetHeadValue(i1);

		while (!ListIsEmpty(tmp)) {

			if (*e == *ListGetHeadValue(tmp)) {

				Item* check = ret;

				while (!ListIsEmpty(check)) {

					if (*ListGetHeadValue(check) == *e) {
						doppio = true;
					}
					check = ListGetTail(check);
				}

				if (doppio == false) {
					ret = ListInsertBack(ret, e);
				}

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

	List = IntersectNoRep(List, List2);

	ListWriteStdout(List);
}*/