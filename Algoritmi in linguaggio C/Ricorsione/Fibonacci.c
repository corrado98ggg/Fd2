
int fibonacciRec(int n) {

	//caso base:
	if (n == 0) {
		return 0;
	}

	if (n == 1) {
		return 1;
	}

	return fibonacciRec(n - 1) + fibonacciRec(n - 2);
}


int fibonacci(int n) {

	if (n < 0) {
		return -1;
	}

	return fibonacciRec(n);
}


int main(void) {
	int c = fibonacci(12);
}