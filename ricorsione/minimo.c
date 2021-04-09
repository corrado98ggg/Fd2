#include <stdio.h>
#include <stdlib.h>




int MinimoREC(const int* v, int v_size, int min) {

	//caso base
	if (v_size < 0) {
		return min;
	}

	if (v[v_size] < min) {
		min = v[v_size];
	}

	MinimoREC(v, v_size - 1, min);

}

int Minimo(const int* v, int v_size) {

	if (v == NULL || v_size <= 1) {
		return -1;
	}

	int i = 0;
	int min = v[v_size - 1];

	return MinimoREC(v, v_size - 1, min);

}

int main() {

	const int v[] = { 1,2,34,2 };
	int size = 4;

	return Minimo(v, size);

}