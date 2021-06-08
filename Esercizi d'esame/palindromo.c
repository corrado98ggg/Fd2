#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool IsPalindromoRec(const char* str, size_t k, size_t i, bool value, size_t tmp) {

	//caso base:
	if (i == tmp) {
		return value;
	}


	if (str[i] != str[k]) {
		value = false;
		return value;
	}
	
	IsPalindromoRec(str, k - 1, i + 1, value, tmp);
}

bool IsPalindromo(const char* str) {

	if (str == NULL) {
		return false;
	}

	size_t c = 0;
	size_t tmp = strlen(str) - 1;

	return IsPalindromoRec(str, strlen(str) - 1, c, true, tmp);
}


/*
int main() {

	const char* stringa = "ossesso";
	return IsPalindromo(stringa);
}*/