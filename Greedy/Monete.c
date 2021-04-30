#include <stdio.h>
#include <stdlib.h>

void MoneteRec(int* tagli, size_t tagli_size, int budget, int* ret, int i) {

	//tagli = {50,20,10,5,2,1} e budget = 126
	//ret {2,1,0,1,0,1}

	//caso base:
	if (tagli_size == i) {
		return;
	}

	while (budget - tagli[i] >= 0) {
		ret[i] = ret[i] + 1;
		budget = budget - tagli[i];
	}

	MoneteRec(tagli, tagli_size, budget, ret, i + 1);

}

int* Monete(int* tagli, size_t tagli_size, int budget) {

	if (budget <= 0) {
		return NULL;
	}

	int* ret = calloc(tagli_size, sizeof(int));

	MoneteRec(tagli, tagli_size, budget, ret, 0);

	for (int j = 0; j < tagli_size; j++) {
		printf("%d  ", ret[j]);
	}

	return ret;
}


int main(void) {

	size_t tagli_size = 6;
	int* tagli[] = { 50,20,10,5,2,1 };

	Monete(tagli, tagli_size, 126);
}