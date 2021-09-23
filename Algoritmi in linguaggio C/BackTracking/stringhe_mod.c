#include <stdio.h>
#include <stdlib.h>

void BacktrackStrModRec(int n, int k, int i, char* vcurr) {

	//caso base:
	if (n == i) {

		//stampiamo
		printf("{");
		for (int j = 0; j < n; ++j) {
			printf("%c", vcurr[j]);
		}
		printf("}");

		return;
	}

	for (char c = 'a'; c < 'a' + k; ++c) {
		vcurr[i] = c;
		BacktrackStrModRec(n, k, i + 1, vcurr);
	}
}

void BacktrackStrMod(int n, int k) {

	if (k <= 0 || k > 26 || n <= 0) {
		return;
	}

	char* vcurr = malloc(sizeof(n));
	
	BacktrackStrModRec(n, k, 0, vcurr);
}

int main(void) {

	BacktrackStrMod(3, 2);
}