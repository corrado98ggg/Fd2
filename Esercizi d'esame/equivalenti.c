#include "tree.h"
#include <stdio.h>
#include <stdlib.h>



bool* EquivalentiRec(const Node* t1, const Node* t2, bool* ret) {


	if (*ret == false) {
		return false;
	}

	const ElemType* e = 0;
	const ElemType* e2 = 0;

	//caso base
	if ((TreeIsEmpty(t1) && TreeIsEmpty(t2))) {
		return ret;
	}
	else {
		if ((TreeIsLeaf(t1) && !TreeIsLeaf(t1))) {
			*ret = false;
		}
	}

	if (!TreeIsEmpty(t1)) {
		e = TreeGetRootValue(t1);
	}
	else {
		*ret = false;
		return false;
	}
	if (!TreeIsEmpty(t2)) {
		e2 = TreeGetRootValue(t2);
	}
	else {
		*ret = false;
		return false;
	}


	//se sono foglia
	if (TreeIsLeaf(t1) && TreeIsLeaf(t2)) {

		if (*e % *e2 != 0 && *e2 % *e != 0) {
			*ret = false;
		}

	}
	//se non sono foglia
	else {
		if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) {
			*ret = false;
		}
	}

	EquivalentiRec(TreeRight(t1), TreeRight(t2), ret);
	EquivalentiRec(TreeLeft(t1), TreeLeft(t2), ret);

	//se hanno la stessa struttura
}


bool Equivalenti(const Node* t1, const Node* t2) {


	bool ret = true;
	ret = EquivalentiRec(t1, t2, &ret);

	return ret;
}

/*int main() {

	ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };

	Node* t = TreeCreateRoot(e + 1,
		TreeCreateRoot(e + 2,
			TreeCreateRoot(e + 4, NULL, NULL), NULL),
		TreeCreateRoot(e + 5, TreeCreateRoot(e + 1, NULL, NULL), NULL));



	ElemType e2[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };

	Node* t2 = TreeCreateRoot(e + 1,
		TreeCreateRoot(e + 2,
			TreeCreateRoot(e + 4, TreeCreateRoot(e + 3, NULL, NULL), NULL), NULL),
		TreeCreateRoot(e + 5, TreeCreateRoot(e + 1, NULL, NULL), NULL));
   bool ret = Equivalenti(t, t2);

}*/