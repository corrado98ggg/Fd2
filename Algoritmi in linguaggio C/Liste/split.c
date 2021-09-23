#include "list.h"

void InsertionSort(Item** i) {

	if (ListIsEmpty(*i)) {
		return;
	}

	Item* tmp = *i;
	ElemType* e = 0;
	size_t len = 0;
	while (!ListIsEmpty(tmp)) {
		len++;
		tmp = ListGetTail(tmp);
	}

	for (size_t j = 0; j < len; j++) {

		tmp = *i;
		while (!ListIsEmpty(tmp)) {
			e = ListGetHeadValue(tmp);

			if (tmp->next != NULL) {
				if (*e > *ListGetHeadValue(tmp->next)) {
					ElemSwap(e, ListGetHeadValue(tmp->next));
				}
			}

			tmp = ListGetTail(tmp);
		}
	}
	return;
}

int main(void) {


	ElemType e[] = { 4,2,9,3,5 };
	Item* List = ListCreateEmpty();

	for (int i = 0; i < 5; i++) {
		List = ListInsertHead(&e[i], List);
	}

	InsertionSort(&List);

	ListWriteStdout(List);
}