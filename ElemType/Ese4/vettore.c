#define _CRT_SECURE_NO_WARNINGS
#include "vettore.h"
#include "elemtype.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


void ordina_interi(int* src, int size) {

	FILE* f;

	f = fopen("prova.txt", "w");

	if (f == NULL) {
		return NULL;
	}

	int tmp = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (src[i] < src[j]) {
				tmp = src[i];
				src[i] = src[j];
				src[j] = tmp;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		printf("%d ", src[i]);
		printf("\n");
	}

	for (int i = 0; i < size; i++) {
		fprintf(f, "%d", src[i]);
		fprintf(f, "\n");
	}

	fclose(f);
}

int main(void) {


	int n[7] = { 1, 5, 9, -3, 0, 11, -453 };

	int size = 7;

	ordina_interi(&n, size);

	return 0;
}