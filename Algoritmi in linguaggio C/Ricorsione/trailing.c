#include <stdio.h>
#include <string.h>
#include <ctype.h>

int Atoirec(const char* str, int n, size_t len, int ordine_di_grandezza) {

	if (len == 0) {
		return n;
	}

	if (isalnum(str[len]) && str[len - 1]!= '+' && str[len - 1] != '-' && str[len - 1] != ' ') {

		n = n + ((str[len - 1] - 48) * ordine_di_grandezza);
		ordine_di_grandezza = ordine_di_grandezza * 10;
		Atoirec(str, n, len - 1, ordine_di_grandezza);
	}
	else {
		Atoirec(str, n, len - 1, ordine_di_grandezza);
	}
}


int AToI(const char* str) {

	if (str == NULL) {
		return 0;
	}

	int n = Atoirec(str, 0, strlen(str), 1);

	if (str[0] == '-') {
		return 0 - n;
	}
	else {
		return n;
	}
}

int main(void) {
	
	int t = AToI("- 46a");
}