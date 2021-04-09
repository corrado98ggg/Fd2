#include <stdio.h>
#include <stdlib.h>


unsigned long long FattorialeREC(int n) {


	//caso base
	if (n == 1) {
		return n;
	}

	return FattorialeREC(n - 1) * n;
}



unsigned long long Fattoriale(int n) {

	if (n < 0){
		return 0;
	}

	return FattorialeREC(n);
}



int main() {

	unsigned long long n = 6;

	return Fattoriale(n);

}