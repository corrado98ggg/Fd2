#include "elemtype.h"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {

	ElemType e[] = { 0,1,2,3,4 };
	Item* list = ListCreateEmpty();

	for (size_t i = 0; i < 5; i++) {
		list = ListInsertHead(&e[i], list);
	}


	ListWriteStdout(list);

	//list = ListGetTail(list); ritorna il next della lista specificata
	{
		Item* tmp = list;

	while (!ListIsEmpty(tmp)) {
		//cose con tmp
		tmp = ListGetTail(tmp);
		}
	}


	//senza primitive, scorrere una lista diventa:
	{
		Item* tmp = list;
		while (tmp) {
			//faccio cose
			tmp = tmp->next;
		}
	}


	//oppure con il for con primtive:
	{
		for (Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			//faccio cose
		}
	}

	//oppure con il for senza primtive:
	{
		for (Item* tmp = list; !ListIsEmpty(tmp); tmp = tmp->next) {
			//faccio cose
		}
	}

	ListDelete(list);
	
}