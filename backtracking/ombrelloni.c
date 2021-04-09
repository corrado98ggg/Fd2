#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void OmbrelloniREC(int k, int n, bool* vcurr, int i, int* nsol, int tmp) {

	//caso base:
	if (i == k) {

		int cnt = 0;

		for (int j = 0; j < k; j++) {
			if (vcurr[j] == 1) {
				cnt++;
			}
		}

		if (cnt == n) {

			//eventuali ragazzi adiacenti
			for (int i = 1; i < k - 1; ++i) {
				if (vcurr[i] == 1 && (vcurr[i - 1] == 1 || vcurr[i + 1] == 1)) {
					return;
				}
			}
			(*nsol)++;

			printf("%d) ", tmp);
			for (int j = 0; j < k; j++) {
				printf("%d ", vcurr[j]);
			}
			printf("\n");

			tmp++;
		}
		return;
	}

	vcurr[i] = 1; //metto un ragazzo
	OmbrelloniREC(k, n, vcurr, i + 1, nsol, tmp);

	vcurr[i] = 0; //non metto un ragazzo;
	OmbrelloniREC(k, n, vcurr, i + 1, nsol, tmp);
}

int Ombrelloni(int k, int n) {
	int nsol = 0;
	bool* vcurr = malloc(sizeof(bool) * k);
	int tmp = 1;

	OmbrelloniREC(k, n, vcurr, 0, &nsol, tmp);
}


/*
int main() {
	Ombrelloni(4, 2);
	return;
}
*/