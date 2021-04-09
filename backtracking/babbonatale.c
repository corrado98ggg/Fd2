#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void BabboNataleREC(const int* pacchi, size_t pacchi_size, int p, bool* vcurr, int sum, int i) {

	//caso base:
	if (i == pacchi_size) {

		for (int j = 0; j < pacchi_size; j++) {
			printf("%d ", vcurr[j]);
		}

		return;
	}

	//caso carico il regalo
	if (pacchi[i] < p && pacchi[i+1] + pacchi[i] < p && sum < p && sum + pacchi[i] < p) {
		vcurr[i] = 1;
		sum = sum + pacchi[i];
		BabboNataleREC(pacchi, pacchi_size, p, vcurr, sum, i + 1);
		return;
	}

	vcurr[i] = 0;
	BabboNataleREC(pacchi, pacchi_size, p, vcurr, sum, i + 1);
	return;

}

void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {
	bool* vcurr = malloc(sizeof(bool) * pacchi_size);
	int sum = 0;

	BabboNataleREC(pacchi, pacchi_size, p, vcurr, sum, 0);
	return;
}


/*
int main() {


	int pacchi[] = {  }; //kg dell'i-esimo pacco
	size_t pacchi_size = 5;
	BabboNatale(pacchi, pacchi_size, 20);
	return 0;


}
*/