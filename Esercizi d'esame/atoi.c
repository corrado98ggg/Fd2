#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int moltiplicatore(int unita, int c) {

	for (int i = 0; i < unita; i++) {
		c = c * 10;
	}

	return c;
}

int atoiRec(const char* str, size_t len, int ret, int unita) {

	if (len == 0) {
		return ret;
	}

	if (unita == 1) {
		ret = ret + (str[len - 1] - 48);
	}
	else {
		ret = ((str[len - 1] - 48) * moltiplicatore(unita - 1, 1)) + ret;
		
	}

	atoiRec(str, len - 1, ret, unita + 1);

}

int AToI(const char* str){

	if (str == NULL) {
		return 0;
	}

	return atoiRec(str, strlen(str), 0, 1);
}


/*
int main() {

	return AToI("412");
}*/