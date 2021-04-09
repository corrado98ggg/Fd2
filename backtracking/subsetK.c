#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


void SubsetKREC(int n, int k, bool *vcurr, int i, int* nsol) {

	//caso base: (sono arrivato a una foglia)
	if (i == n) {

		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (vcurr[j] == 1) {
				cnt++;
			}
		}

		if (cnt == k) {
			(*nsol++); //incremento nsol perchè ho appena trovato un soluzione valida
			//cioè se cnt == k, in questo caso se k == 2

			printf("{ ");
			for (int j = 0; j < n; j++) {
				if (vcurr[j] == 1) {
					printf("%d", j);
				}
			}
			printf("}, ");
		}
		return;
	}

	vcurr[i] = 0; //non prendo la soluzione
	SubsetKREC(n, k, vcurr, i + 1, nsol);

	vcurr[i] = 1; //prendo la soluzione
	SubsetKREC(n, k, vcurr, i + 1, nsol + 1);



	

}


int SubsetK(int n, int k) {

	bool* vcurr = calloc(n, sizeof(bool));
	int nsol = 0;
	
	SubsetKREC(n, k, vcurr, 0, &nsol);

	return nsol;

}

int main() {
	SubsetK(4, 2);
	return 0;
}