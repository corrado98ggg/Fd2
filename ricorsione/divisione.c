#include <stdio.h>
#include <stdlib.h>

int DivisioneREC(int tmp, int a, int b) {


	//caso base
	if (a - b == 0) {
		tmp++;
		return tmp;
	}

	//caso base
	if (a - b < 0) {
		return tmp;
	}

	tmp++;

	DivisioneREC(tmp, a - b, b);
}


int Divisione(int a, int b) {

	if (b == 0) {
		return -1;
	}

	if (a < 0 || b < 0) {
		return -1;
	}
	int tmp = 0;

	return DivisioneREC(tmp, a, b);

}

int main() {

	int a = 12;
	int b = 3;

	return Divisione(a, b);
}