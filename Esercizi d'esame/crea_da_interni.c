#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


Item* CreaDaInterni(const Item* i, double r) {

	Item* ret = ListCreateEmpty();
	double distanza = 0;

	while (!ListIsEmpty(i)) {

		distanza = sqrt(((i->value.x - 0) * (i->value.x - 0)) + ((0 - i->value.y) * (0 - i->value.y)));

		if (distanza <= r) {
			//se questa distanza è minore del raggio o ugaule il punto si trova dentro la criconferenza
			ret = ListInsertBack(ret, ListGetHeadValue(i));
		}

		i = ListGetTail(i);
	}
	return ret;
}

/*
int main(void) {

	Point2D punto1;
	punto1.x = 2;
	punto1.y = 3;

	Point2D punto2;
	punto2.x = 5;
	punto2.y = 6;

	Point2D punto3;
	punto3.x = 8;
	punto3.y = 4;

	Item* list = ListCreateEmpty();

	list = ListInsertBack(list, &punto2);
	list = ListInsertBack(list, &punto3);
	list = ListInsertBack(list, &punto1);

	Item* ret = ListCreateEmpty();
	ret = CreaDaInterni(list, 5);

	ListWriteStdout(ret);
}*/