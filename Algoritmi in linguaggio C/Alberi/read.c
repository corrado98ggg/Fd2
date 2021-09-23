#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

Node* TreeReadrec(FILE* f) {

	//leggo un carattere da file:
	ElemType c = 0;
	int read = fscanf(f, " %c", &c);

	
	//caso base 1: non ci sono più dati 
	if (read != 1) {
		return TreeCreateEmpty();
	}

	//caso base 2: ho letto un punto, quindi devo leggere una foglia:
	if (c == '.') {
		fscanf(f, " %c", &c);
		return TreeCreateRoot(&c, TreeCreateEmpty(), TreeCreateEmpty());
	}

	Node* l = TreeReadrec(f); //costruisco ricorsivamente il figlio sinistro e lo stesso per il dx
	Node* r = TreeReadrec(f);

	return TreeCreateRoot(&c, l, r);
}


Node* TreeRead(const char* filename) {

	FILE* f = fopen(filename, "r"); //apertura del file

	//caso particolare il file non esiste o non è stato aperto correttamente
	if (!f) {
		return TreeCreateEmpty();
	}

	//funzione ricorsiva che legge i file e costruisce l'albero ricorsivamente
	Node* t = TreeReadrec(f);

	fclose(f);

	return t;
}


int main() {

	char* filename = "albero1 (3).txt";

	TreeRead(filename);

	return 0;
}