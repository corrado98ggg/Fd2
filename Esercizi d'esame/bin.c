#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int binarioRec(int n, int v[], int i) {

	if (n == 0) {
		for (int k = i - 1; k >= 0 ; k--) {
			fprintf(stdout, "%d", v[k]);
		}
		return 0;
	}

	v[i] = n % 2;
	binarioRec(n / 2, v, i + 1);
}


int main(int argc, char* argv[]) {

	char* carattere = argv[1];

	if (argc != 2 || atoi(carattere) < 0) {
		return 1;
	}

	if (atoi(carattere) == 0) {
		printf("0");
		return 0;
	}

	if (atoi(carattere) == 1) {
		printf("1");
		return 0;
	}

	int* v = malloc(sizeof(int) * 100);

	int ret = binarioRec(atoi(carattere), v, 0);

	free(v);

	return ret;
}