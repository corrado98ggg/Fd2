#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool solcheck(char sol[]) {

	for (int i = 0; i < strlen(sol); i++) {
		if (sol[i] < 0) {
			return false;
		}
	}
	return true;
}

void BacktrackStrModRec(char alfabeto[], char sol[], int n, int k) {

	if (k == n - 1) {
		if (solcheck(sol) == true) {
			printf("{");
			for (int i = 0; i < n; i++) {
				printf("%c", sol[i]);
			}
			printf("}, ");
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			sol[k + 1] = alfabeto[i];
			BacktrackStrModRec(alfabeto, sol, n, k + 1);
		}
	}
}

void BacktrackStrMod(int n, int k) {

	if (n <= 0 || n > 26 || k <= 0) {
		return;
	}


	char alfabeto[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'v', 'z'}; //v
	char* sol = calloc(k, sizeof(int));  //sol

	char* alfabeto_da_passare = malloc(sizeof(char) * n);

	memcpy(alfabeto_da_passare, alfabeto, sizeof(char) * n);

	BacktrackStrModRec(alfabeto_da_passare, sol, k, -1);

	return;

}

/*
int main() {


	BacktrackStrMod(2, 3);
}
*/