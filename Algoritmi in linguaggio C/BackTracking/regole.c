#include <string.h>
#include <stdio.h>
#include <stdbool.h>

//tutte le possibili sequenze di numeri in [1, n + 1] di lunghezza n + 1
//che è possibile costruire rispettando le regole
//ogni sequenza deve contenere tutti i numeri d a 1 a n + 1 compresi, senza ripetizioni

//se prendiamo "I", n = 1
//in questo caso occorre costruire la sequenza di due elementi in [1, 3] con il vincolo che il primo deve
//essere seguito da uno più grande.

//in questo caso ci sono due solzuoni valide:
//1 2


void regolerec(const char* r, int n, int i, int* vcurr, bool* usati) {

	if (i == n + 1) {
		for (int j = 0; j < n + 1; ++j) {
		
			printf("%d ", vcurr[j]);
		}
		printf("\n");
		return;
	}
	
	for (int j = 0; j <= n + 1; ++j) {
		
		bool I = !usati[j - 1];
		bool a = i == 0;
		bool b = (r[i - 1] == 'i' || r[i - 1] == 'I') && vcurr[i - 1] < j;
		bool c = (r[i - 1] == 'd' || r[i - 1] == 'D') && vcurr[i - 1] > j;
		bool II = a || b || c;

		if (I && II) {

			usati[j - 1] = 1;
			vcurr[i] = j;
			regolerec(r, n, i + 1, vcurr, usati);
			usati[j - 1] = 0;
		}

	}
}

void regole(const char* r) {

	int n = strlen(r);

	int* vcurr = malloc(sizeof(int) * (n+1));
	int* usati = calloc(n+1, sizeof(bool));

	regolerec(r, n, 0, vcurr, usati);

	free(vcurr);
	free(usati);
}



int main() {

	regole("IIDD");
	//i incremento
	//d decremento
	

}