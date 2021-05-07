#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {

	size_t capacity;
	size_t size;
	int* data;

} Vector;

//funzione che inizilizza il vettore con numeri casuali;
void PushBack(Vector* v, int e) {

	if (v->size == v->capacity) {

		v->capacity *= 2;

		v->data = realloc(v->data, sizeof(int) * v->capacity);
	}
	v->data[v->size] = e;

	(v->size)++;
}

void Ordinamento_mio(Vector *v) {

	//[ 1, 5, 8, 10, 0]
	size_t tmp;

	for (size_t i = 0; i < v->size; i++) {
		for (size_t j = i + 1; j < v->size; j++) {
			if (v->data[i] > v->data[j]) {

				tmp = v->data[i];
				v->data[i] = v->data[j];
				v->data[j] = tmp;			
			}
		}
	}
}

int main(void) {
	Vector v;
	v.capacity = 1;
	v.size = 0;
	v.data = malloc(sizeof(int) * 1);

	srand(0); //generatore di numeri casuali del c

	for (size_t i = 0; i < 20; ++i) {
		PushBack(&v, rand());
	}

	printf("[ ");
	for (size_t i = 0; i < 20; ++i) {
		printf("%d, ", v.data[i]);
	}
	printf("]");

	Ordinamento_mio(&v); //A quanto pare sembra essere circa il NaiveSorte

	printf("\n");
	printf("[ ");
	for (size_t i = 0; i < 20; ++i) {
		printf("%d ", v.data[i]);
	}
	printf("]");

	free(v.data);

	return 0;
}
