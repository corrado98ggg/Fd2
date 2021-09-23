#include "list.h"
#include <stdbool.h>

const Item* commontail(const Item* i1, const Item* i2) {

	while (!ListIsEmpty(i1)) {

		const Item* tmp = i2;

		while (!ListIsEmpty(tmp)) {

			if (i1 == tmp) {
				return i1;
			}
			tmp = ListGetTail(tmp);

		}
		i1 = ListGetTail(i1);
	}

	return ListCreateEmpty();

}


int main(void) {
	ElemType v[] = { 0,1,2,3,4,5,6,7,8,9 };
	//ElemType e3 = 6;

	Item* tail = ListInsertHead(&v[5], ListInsertHead(&v[4], NULL));

	Item* i1 = ListInsertHead(&v[7], ListInsertHead(&v[2], tail));

	Item* i2 = ListInsertHead(&v[8], ListInsertHead(&v[3],
		ListInsertHead(&v[6], tail)));

	Item* common = commontail(i1, i2);

}