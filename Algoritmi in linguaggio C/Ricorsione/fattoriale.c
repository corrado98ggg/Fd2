double FattorialeRec(int n, int s) {

	//caso base:
	if (n == 0) {
		return s;
	}

	return FattorialeRec(n - 1, s * n);
}

double Fattoriale(int n) {

	if (n < 0) {
		return -1;
	}

	return FattorialeRec(n, 1);
}

int main(void) {
	double c = Fattoriale(4);
}