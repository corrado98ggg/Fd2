#include <stdio.h>
#include <stdlib.h>

int HailstoneRec(int n, int cont) {

	//caso base:
	if (n == 1) {
		return cont;
	}

	if (n % 2 == 0) {
		n = n / 2;
		printf(" %d ", n);
		cont++;

	}
	else
	{
		n = (3 * n) + 1;
		printf(" %d ", n);
		cont++;
	}

	HailstoneRec(n, cont);
}

int Hailstone(int n) {

	if (n == NULL) {
		return -1;
	}

	int cont = 1;

	printf("la seguente sequenza è: ");
	printf(" %d ", n);

	cont = HailstoneRec(n, cont);

	return cont;

}


int main(void) {

	int n = 5;

	int ret = Hailstone(n);
}