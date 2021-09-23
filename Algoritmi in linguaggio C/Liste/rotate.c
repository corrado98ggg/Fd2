#include "list.h"
#include <stdio.h>
#include <stdlib.h>

Item* Rotate(Item* i, int n) {

	Item* tmp = i;

	for (int j = 1; j < n; j++) {
		tmp = ListGetTail(tmp); 
	}
	Item* tmp2 = tmp->next;
	tmp->next = NULL;

	Item* c = tmp2;
	while (!ListIsEmpty(c->next)) {
		c = ListGetTail(c);
	}
	c->next = i;

	ListWriteStdout(tmp2);

	return tmp2;
}

/*
int main() {

	ElemType e[] = { 1,3,4,7,8 };

	Item* i = ListCreateEmpty();

	for (int j = 0; j < 5; j++) {
		i = ListInsertBack(i, &e[j]);
	}

	ListWriteStdout(i);
	i = Rotate(i, 1);
}
*/