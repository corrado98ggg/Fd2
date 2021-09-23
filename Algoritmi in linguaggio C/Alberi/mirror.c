#include "tree.h"
#include <stdlib.h>
#include <stdio.h>


void ismirrorRec(Node* t_left, Node* t_right, bool* ret) {

	//caso base se sono di lunghezza diversa:
	if ((TreeIsEmpty(t_left) && !TreeIsEmpty(t_right)) || (!TreeIsEmpty(t_left) && TreeIsEmpty(t_right))) {
		*ret = false;
		return;
	}

	//caso base:
	if (TreeIsEmpty(t_left) && TreeIsEmpty(t_right)) {
		return;
	}

	if (ElemCopy(TreeGetRootValue(t_left)) != ElemCopy(TreeGetRootValue(t_right))) {
		*ret = false;
	}

	ismirrorRec(TreeLeft(t_left), TreeRight(t_right), ret);
	ismirrorRec(TreeRight(t_left), TreeLeft(t_right), ret);

}


bool ismirror(Node* t) {

	if (TreeIsEmpty(t)) {
		return true;
	}

	bool ret = true;

	ismirrorRec(TreeLeft(t), TreeRight(t), &ret);

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

	//      0
	//  1       1
	//4   2   2   4

	s = ismirror(t1);

	TreeDelete(t0);
	TreeDelete(t1);

	return 0;
	
}