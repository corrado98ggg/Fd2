#include "tree.h"
#include <float.h>

void LenghtTree(const Node* t, int* cont) {
	
	if (TreeIsEmpty(t)) {
		return;
	}

	(*cont)++;

	LenghtTree(TreeLeft(t), cont);
	LenghtTree(TreeRight(t), cont);
}

ElemType* medianorecdispari(const Node* t, int lunghezza, ElemType* ret, int tmp) {

	if (TreeIsEmpty(t)) {
		return;
	}

	medianorecdispari(TreeLeft(t), lunghezza - 1, ret, tmp);

	if (lunghezza == tmp) {
		ret = TreeGetRootValue(t);
		return ret;
	}

	medianorecdispari(TreeRight(t), lunghezza - 1, ret, tmp);
}

ElemType* medianorecpari(const Node* t, int lunghezza, ElemType ret, int tmp, ElemType* gg) {

	if (TreeIsEmpty(t)) {
		return;
	}

	medianorecpari(TreeLeft(t), lunghezza - 1, ret, tmp, gg);

	if (lunghezza == tmp || lunghezza == tmp - 1) {
		ret = ret + ElemCopy(TreeGetRootValue(t));

		if (lunghezza == tmp - 1) {
			*gg = ret;
			return gg;
		}
	}

	medianorecpari(TreeRight(t), lunghezza - 1, ret, tmp, gg);
}


double Mediano(const Node* t) {

	if (TreeIsEmpty(t)) {
		return DBL_MAX;
	}

	int lunghezza = 0;

	double d = 0;
	LenghtTree(t, &lunghezza);


	if (lunghezza % 2 != 0) {
		lunghezza = (lunghezza - 1) / 2;
		
		ElemType* ret = 0;
		
		ret = medianorecdispari(t, lunghezza, ret, lunghezza);

		return *ret;
	}
	else {
		lunghezza = (lunghezza / 2) + 1;

		ElemType ret = 0;
		ElemType rett = 0;

		medianorecpari(t, lunghezza, ret, lunghezza - 1, &rett);

		d = rett / 2.;

		return d;

	}

}

int main() {

	ElemType e[] = { 0,1,2,3,4,5,6,7,8 };
	bool s;

	Node* t0 = TreeCreateRoot(&e[0], NULL, NULL);
	//s = ismirror(t0);

	Node* t1 = TreeCreateRoot(&e[0],
		TreeCreateRoot(&e[1],
			TreeCreateRoot(&e[4], NULL, NULL),
			TreeCreateRoot(&e[2], NULL, NULL)),
		TreeCreateRoot(&e[1], NULL, NULL));

	Node* t2 = TreeCreateRoot(&e[7],
		TreeCreateRoot(&e[4],
			TreeCreateRoot(&e[2], 
				TreeCreateRoot(&e[1], NULL, NULL), NULL),
			TreeCreateRoot(&e[5], NULL, NULL)),
		TreeCreateRoot(&e[8], NULL, NULL));

	//      0
	//  1       1
	//4   2   


	ElemType e2 = 1;

	double c = Mediano(t2);
	TreeDelete(t0);
	TreeDelete(t1);



	return 0;

}