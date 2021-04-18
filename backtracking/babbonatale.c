#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
p:           portata massima della slitta;
pacchi :     array dei pesi dei regali disponibili;
n :          dimensione dell'array pacchi;
i :          la posizione attuale;
vcurr :      un array che indica i regali attualmente caricati nella soluzione corrente(ad esempio 1 = caricato, 0 = NON caricato);
vbest:       un array che indica i regali caricati nella miglior soluzione fino ad ora trovata (ad esempio 1 = caricato, 0 = NON caricato);
max:         numero di regali caricati nella soluzione best;
cnt:         numero di regali caricati nella soluzione vcurr;
sum:         somma dei pesi dei regali caricati nella soluzione vcurr;
*/


void BabboNatale(int p, int const* pacchi, int n, unsigned i, bool* vcurr, bool* vbest, unsigned* max, unsigned int cnt, int sum) {

	//caso base
	if (i == n) {
		if (cnt > (*max)) {
			(*max) = cnt;
			memcpy(vbest, vcurr, n * sizeof(bool));
		}
		return;
	}

	vcurr[i] = 0;
	BabboNatale(p, pacchi, n, i + 1, vcurr, vbest, max, cnt, sum);


	if (sum + pacchi[i] <= p) {
		vcurr[i] = 1;
		BabboNatale(p, pacchi, n, i + 1, vcurr, vbest, max, cnt + 1, sum + pacchi[i]);
	}

}

int main() {

	int p = 20;
	int pacchi[5] = { 10,11,1,3,3 };
	int n = 5;
	bool* vcurr = malloc(sizeof(bool) * 5);
	bool vbest[] = { 0,0,0,0,0 };
	int max[] = { 0,0,0,0,0 };
	unsigned cnt = 0;
	int sum = 0;
	int i = 0;

	BabboNatale(p, pacchi, n, i, vcurr, vbest, max, cnt, sum);

	return 0;
}