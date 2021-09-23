#include "tree.h"
#include <stdlib.h>
#include <stdio.h>


void TreeHeightrec(const Node* t, int cnt, int* best) {

	//caso base:
	if (TreeIsEmpty(t)) {
		return;
	}

	//caso base, se sono arrivato a una foglia:
	if (TreeIsLeaf(t)) {
		if (cnt > *best) {
			*best = cnt;
		}
		return;
	}

	TreeHeightrec(TreeLeft(t), cnt + 1, best);
	TreeHeightrec(TreeRight(t), cnt + 1, best);
}



int TreeHeight(const Node* t) {

	if (TreeIsEmpty(t)) {
		return -1;
	}

	int ret = 0;
	int best = -1;

	TreeHeightrec(t, ret, &best);

	return best;

}



int main() {

	ElemType e[] = { 0,1,2,3,4 };
	int s;

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

	s = TreeHeight(t1);

	TreeDelete(t0);
	TreeDelete(t1);

	return 0;

}