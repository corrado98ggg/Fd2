#define _CRT_SECURE_NO_WARNINGS
#include "elemtype.h"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

Item* ListLoad(const char* filename) {

	FILE* f;
	Item* ret = ListCreateEmpty();

	f = fopen(filename, "r");

	if (!f) {
		return NULL;
	}

	while (1) {

		ElemType tmp;
		
		if (1 != fscanf(f, "%d", &tmp)) {
			break;
		}
		ret = ListInsertHead(&tmp, ret);
	}

	fclose(f);

	return ret;
}


int main(void) {

	char filename[] = "data_00.txt";
	Item* r = ListLoad(filename); //IL RISULTATO E' UNA LISTA, SALVIAMO IL CONTENUTO IN UN PUNTATOTE A LISTA

	ListWriteStdout(r);
}