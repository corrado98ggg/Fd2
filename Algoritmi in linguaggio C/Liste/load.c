#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdbool.h>
#include <stdio.h>


Item* ListLoad(const char* filename) {

	FILE* f = fopen(filename, "r");
	
	if (!f) {
		return ListCreateEmpty();
	}

	ElemType c;
	Item* ret = ListCreateEmpty();

	while (1) {

		if (fscanf(f, "%d %d", &c.x, &c.y) != 2) {
			break;
		}
		ret = ListInsertHead(&c.x, ret);
		ret = ListInsertHead(&c.y, ret);

	}

	ListWriteStdout(ret);
	return ret;
}

int main(void) {
	
	ListLoad("data_00.txt");

}