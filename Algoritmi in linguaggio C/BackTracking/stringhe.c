#include <stdio.h>
#include <stdlib.h>

void BacktrackStrRec(int n, int i, int* vcurr) {

	//caso base:
	if (i == n) {
		
		printf("{");
		//stampiamo quello che c'è in vcurr:
		for (int j = 0; j < n; ++j) {
			printf("%c ", vcurr[j]);
		}
		printf("}");

		return;
	}

	for (char c = 'a'; c < 'a' + n; ++c) {
		//la variabile c conterrà a partire da a, tutti i primi n caratteri
		//dell'alfabeto
		vcurr[i] = c;
		BacktrackStrRec(n, i + 1, vcurr);
	}
}

void BacktrackStr(int n) {

	if (n <= 0 || n > 26) {
		return;
	}

	char* vcurr = malloc(n * sizeof(char)); //sizeofchar == 1

	BacktrackStrRec(n, 0, vcurr); //essendo k == n, posso non metterlo

	//free(vcurr);
}


int main(void) {

	BacktrackStr(3);
}