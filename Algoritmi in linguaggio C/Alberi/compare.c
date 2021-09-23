#include "tree.h"
#include <stdlib.h>
#include <stdio.h>


bool treeareidenticalRec(const Node* t1, const Node* t2, bool* ret) {

	//caso base:
	if ((TreeIsEmpty(t1) && !TreeIsEmpty(t2)) || (!TreeIsEmpty(t1) && TreeIsEmpty(t2))) {
		*ret = false;
		return;
	}

	//caso base:
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return;
	}


	if (ElemCopy(TreeGetRootValue(t1)) != ElemCopy(TreeGetRootValue(t2))) {
		*ret = false;
	}

	treeareidenticalRec(TreeLeft(t1), TreeLeft(t2), ret);
	treeareidenticalRec(TreeRight(t1), TreeRight(t2), ret);

}




bool treeareidentical(const Node* t1, const Node* t2) {


	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}

	bool ret = true;

	treeareidenticalRec(t1, t2, &ret);

	return ret;
}


int main() {

	ElemType e[] = { 0,1,2,3,4 };
	bool s;

	Node* t0 = TreeCreateRoot(&e[0], NULL, NULL);
	//s = ismirror(t0);

	Node* t1 = TreeCreateRoot(&e[0],
		TreeCreateRoot(&e[1],
			TreeCreateRoot(&e[4], NULL, NULL),
			TreeCreateRoot(&e[2], NULL, NULL)),
		TreeCreateRoot(&e[1], NULL, NULL));

	Node* t2 = TreeCreateRoot(&e[0],
		TreeCreateRoot(&e[1],
			TreeCreateRoot(&e[4], NULL, NULL),
			TreeCreateRoot(&e[2], NULL, NULL)),
		TreeCreateRoot(&e[1], NULL, NULL));

	//      0
	//  1       1
	//4   2   2   4

	s = treeareidentical(t1, t2);
	s = treeareidentical(t0, t1);

	TreeDelete(t0);
	TreeDelete(t1);

	return 0;

}