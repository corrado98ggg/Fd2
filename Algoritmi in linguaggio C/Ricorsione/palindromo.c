#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void Palindromorec(const char* str, bool* ret, size_t len, int i) {


	//caso base:
	if (len == len / 2) {
		return;
	}

	if (str[i] != str[len - 1]) {
		*ret = false;
		return;
	}


	Palindromorec(str, ret, len - 1, i + 1);

}

bool isPalindromo(const char* str) {

	if (str == NULL) {
		return false;
	}

	if (str == "") {
		return true;
	}

	bool ret = true;

	Palindromorec(str, &ret, strlen(str), 0);
	return ret;

}


int main() {

	const char* c = "osso";
	const char* b = "suca";
	const char* d = "giovanna";
	const char* f = "ossoosso";

	bool a = isPalindromo(c);
	a = isPalindromo(b);
	a = isPalindromo(d);
	a = isPalindromo(f);
}