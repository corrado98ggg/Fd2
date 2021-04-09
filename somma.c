#include "somma.h"
#include <stdio.h>
#include <stdlib.h>


static int SommaFinoARec(int n) {

	if (n == 1) {
		return n;
	}
	return SommaFinoARec(n-1) + n;
}


int SommaFinoA(int n) {

	if (n <= 1) {
		return -1;
	}
	return SommaFinoARec(n);

}


int main() {

	int c = 3;
	return SommaFinoA(c);
}