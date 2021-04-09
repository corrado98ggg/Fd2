#include <stdio.h>
#include <stdlib.h>
#include <math.h>



static int ProdottoNegativiREC(int tmp, int a, int b) {

	if (b == 1) {
		return a;
	}

	a = a + tmp;

	ProdottoNegativiREC(tmp, a, b - 1);
}



int ProdottoNegativi(int a, int b) {

	int tmp = a;

	if (a < 0 && b < 0) {
		b = fabs(b);
		a = fabs(a);
		tmp = fabs(a);

		return ProdottoNegativiREC(tmp, a, b);
	}

	if (a < 0) {

		a = fabs(a);
		tmp = fabs(a);

		return -ProdottoNegativiREC(tmp, a, b);
	}

	if (b < 0) {
		b = fabs(b);

		return -ProdottoNegativiREC(tmp, a, b);
	}

	return ProdottoNegativiREC(tmp, a, b);

}


int main() {

	int a = -5;
	int b = -3;

	return ProdottoNegativi(a, b);
}