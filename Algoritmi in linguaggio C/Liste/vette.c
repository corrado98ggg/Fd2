#include "list.h"
#include <stdbool.h>

int vette(const Item* i) {

	int cont = 0;
	bool vetta = true;

	while (!ListIsEmpty(i)) {

		if (i->next == NULL) {
			cont++;
		}
		else {
			
			Item* tmp = i->next;
			while (!ListIsEmpty(tmp)) {
				if (i->value <= tmp->value) {
					vetta = false;
					break;
				}
				else {
					vetta = true;
				}
				tmp = ListGetTail(tmp);
			}

			if (vetta == true) {
				cont++;
			}
		}
		i = ListGetTail(i);
	}

	return cont;
}


int main(void) {
	ElemType e[] = { 7,2,5,5,4 };
	ElemType e3 = 6;

	Item* list = NULL;
	for (int i = 0; i < 5; i++) {
		list = ListInsertBack(list, &e[i]);
	}

	int c = vette(list);
}