#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void subsetequalRec(int n, int s, int i, bool* vcurr, int scurr, int* nsol) {

	//caso base 1: subset che somma è s
	if (scurr == s) {
		(*nsol)++;
		//posso stampare la soluzione:
		printf("{");
		for (int j = 1; j <= n; ++j) {
			if (vcurr[j] == true) {
				printf("%d ", j);
			}
		}
		printf("}");

		return;
	}

	//caso base 2:
	if (i > n) {
		return;
	}

	for (int e = i; e <= n; ++e) {

		if (scurr + e <= s) {
			vcurr[e] = true;

			subsetequalRec(n, s, e + 1, vcurr, scurr + e, nsol);
			vcurr[e] = false;
		}
	}
}

int subsetequal(int n, int s) {

	if (n <= 0 || s <= 0) {
		return 0;
	}

	int* vcurr = calloc(n + 1, sizeof(bool));
	int nsol = 0;

	subsetequalRec(n, s, 1, vcurr, 0, &nsol);

	return nsol;
}

int main(void) {
	subsetequal(4, 6);
}