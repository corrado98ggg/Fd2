#include <stdio.h>

void invertiArrayrec(int* arr, size_t size, int i) {

	//caso base
	if (i >= size / 2) {
		return;
	}

	int tmp;
	tmp = arr[i];
	arr[i] = arr[size - 1];
	arr[size - 1] = tmp;

	invertiArrayrec(arr, size - 1, i + 1);

}

void invertiArray(int* arr, size_t size) {

	invertiArrayrec(arr, size, 0);

	return;
}

int main(void) {

	int array[] = {1, 2, 3, 4};

	invertiArray(array, 4);
}