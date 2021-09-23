#include <stdio.h>
#include <stdlib.h>




char* GuidaLaPulceRec(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size, char* vcurr, int* nsol, int i) {


	if (n == i) {
		printf(
	}

	if (i == f_size) {
		return;
	}

	for (int j = 0; j < n; j++) {

	
		vcurr[j] = a;
		GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, vcurr, nsol, i + 1);


		if (vcurr[j - 1] != b) {
			vcurr[j] = b;
			GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, vcurr, nsol, i + 1);

		}
	}







}

char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size) {


	char* vcurr = malloc(sizeof(char) * n);

	int nsol = 0;

	GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, vcurr, &nsol, 0);
}




int main(void) {

	int f[] = { 12,4,7,1,15 };

	size_t ret_size = 0;

	GuidaLaPulce(f, 5, 3, 15, 9, 5, &ret_size);
}