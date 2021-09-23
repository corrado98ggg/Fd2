#include "list.h"
#include <stdbool.h>

void back2front(Item** i) {

	if (*i == NULL) {
		return;
	}

	if (ListIsEmpty(*i)) {
		return;
	}


	Item* tmp = *i;

	while (!ListIsEmpty(tmp->next)) {
		tmp = ListGetTail(tmp);
	}
	ElemSwap(ListGetHeadValue(*i), ListGetHeadValue(tmp));

	return;

}

int main(void) {
	ElemType e[] = { 7,2,4 };
	ElemType e3 = 6;

	Item* list = NULL;
	for (int i = 0; i < 3; i++) {
		list = ListInsertBack(list, &e[i]);
	}

	Item** c = &list;
	back2front(c);
}