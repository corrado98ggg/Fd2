#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void StepsRec(int n, int i, int* vcurr, size_t v_size) {

	//caso base
	if (i > n) {
		return;
	}

	if (i == n) {
		printf("[");
		for (size_t j = 0; j < v_size; j++) {
			printf("%u", vcurr[j]);
			if (j < v_size - 1) {
				printf(", ");
			}
		}
		printf("], ");

	}
	
	for (int k = 1; k <= 3; k++) {
		vcurr[v_size] = k;
		StepsRec(n, i + k, vcurr, v_size + 1);
	}
}


int Steps(int n) {

	if (n <= 0) {
		return;
	}


	int* vcurr = malloc((n+1)+ sizeof(int));

	StepsRec(n, 0, vcurr, 0);
	return;
}


int main() {
	Steps(3);
	
}