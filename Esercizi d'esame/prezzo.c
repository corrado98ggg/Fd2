#include "prezzo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void TrovaArticoliRec(const struct Articolo* a, size_t size, int sum, int i, int cont) {

	//caso base: se ho finito gli articoli da esaminare
	if (size == 0) {
		return;
	}

	char* str;

	if (a[i].prezzo == sum) {

		str = a[i].nome;

		for (int k = 0; k < strlen(str); k++) {
			printf("%c", str[k]);
		}

		cont++;

		printf(", ");

		if (cont == 2) {
			printf("\n");
		}

		TrovaArticoliRec(a, size - 1, sum, i + 1, cont);
	}
	else {
		TrovaArticoliRec(a, size - 1, sum, i + 1, cont);
	}
}


void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum) {

	if (a == NULL) {
		return;
	}

	TrovaArticoliRec(a, a_size, sum, 0, 0);
}

/*
int main(void) {


	struct Articolo oro;

	oro.nome = "oro";
	oro.prezzo = 2000;

	struct Articolo argento;

	argento.nome = "argento";
	argento.prezzo = 500;

	struct Articolo bronzo;

	bronzo.nome = "bronzo";
	bronzo.prezzo = 100;

	struct Articolo a[3] = { oro, argento, bronzo };

	TrovaArticoli(a, 3, 2000);

}*/