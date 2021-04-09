#include <stdio.h>
#include <stdlib.h>


int FibonacciREC(int n) {

	//caso base:
	if (n == 1) {
		return 1;
	}
	if (n == 0) {
		return 0;
	}

	return FibonacciREC(n - 1) + FibonacciREC(n - 2);

}

int Fibonacci(int n){

	if (n <= 0) {
		return -1;
	}

	return FibonacciREC(n);

}

int main() {
	int n = 5;
	return Fibonacci(n);
}