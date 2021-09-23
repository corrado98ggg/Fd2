#include "tree.h"
#include <stdlib.h>
#include <stdio.h>


void equivalentiRec(const Node* t1, const Node* t2, bool* ret) {

	//caso base:
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return;
	}
	
	//se non hanno la stessa struttura:
	if ((!t1 && t1) || (t1 && !t2)) {
		*ret = false;
		return;
	}

	//caso nodi:
	if (!TreeIsLeaf(t1) && !TreeIsLeaf(t2)) {
		if (*TreeGetRootValue(t1) != *TreeGetRootValue(t2)) {
			*ret = false;
			return;
		}
	}

	//caso foglie:
	if (TreeIsLeaf(t1) && TreeIsLeaf(t2)) {
		if ((*TreeGetRootValue(t1) % *TreeGetRootValue(t2) != 0) || (*TreeGetRootValue(t2) % *TreeGetRootValue(t1) != 0)) {
			*ret = false;
			return;
		}
	}

	equivalentiRec(TreeLeft(t1), TreeLeft(t2), ret);
	equivalentiRec(TreeRight(t1), TreeRight(t2), ret);
}




bool equivalenti(const Node* t1, const Node* t2) {

	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}

	bool equal = true;

	equivalentiRec(t1, t2, &equal);

	return equal;
}



int main() {

	ElemType e[] = { 0,1,2,3,4 };
	bool s;

	Node* t0 = TreeCreateRoot(&e[0], NULL, NULL);
	//s = ismirror(t0);

	Node* t1 = TreeCreateRoot(&e[1],
		TreeCreateRoot(&e[1],
			TreeCreateRoot(&e[4], NULL, NULL),
			TreeCreateRoot(&e[2], NULL, NULL)),
		TreeCreateRoot(&e[1], NULL, NULL));

	Node* t2 = TreeCreateRoot(&e[1],
		TreeCreateRoot(&e[1],
			TreeCreateRoot(&e[1], NULL, NULL),
			TreeCreateRoot(&e[2], NULL, NULL)),
		TreeCreateRoot(&e[1], NULL, NULL));

	//      0
	//  1       1
	//4   2   2   4

	s = equivalenti(t1, t0);

	TreeDelete(t0);
	TreeDelete(t1);

	return 0;

}