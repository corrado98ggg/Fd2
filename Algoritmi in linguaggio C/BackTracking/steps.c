#include <stdio.h>
#include <stdlib.h>

int stepsrec(int n, int* vcurr, int i) {

	if (n == 0) {
		printf("[");
		for (int j = 0; j < i - 1; j++) {
			printf("%i, ", vcurr[j]);
		}
		printf("%i], ", vcurr[i - 1]);

		return;
	}

	for (int j = 1; j <= 3; j++) {

		if (j <= n) {

			vcurr[i] = j;
			stepsrec(n - j, vcurr, i + 1);
		}
	}
}

int steps(int n) {

	if (n <= 0) {
		return 0;
	}

	int* vcurr = malloc(sizeof(int) * n);
	int nsol = 0;

	stepsrec(n, vcurr, 0);
}



int main(void) {

	steps(3);
}