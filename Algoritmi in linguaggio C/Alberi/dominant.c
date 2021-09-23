#include "tree.h"


void CountDominantRec(const Node* t, int* dominant, int* somma_figli) {

	if (TreeIsEmpty(t)) {
		return;
	}

	if (!TreeIsLeaf(t)) {

		*somma_figli = 0;

		if (!TreeIsEmpty(t->left) && TreeIsEmpty(t->right)) {
			*somma_figli = *TreeGetRootValue(t->left);

		}
		else if (TreeIsEmpty(t->left) && !TreeIsEmpty(t->right)) {
			*somma_figli = *TreeGetRootValue(t->right);
		}
		else {
			*somma_figli = *TreeGetRootValue(t->left) + *TreeGetRootValue(t->right);
		}

		if (*somma_figli < *TreeGetRootValue(t)) {
			(*dominant)++;
		}
	}

	CountDominantRec(TreeLeft(t), dominant, somma_figli);
	CountDominantRec(TreeRight(t), dominant, somma_figli);
}

int CountDominant(const Node* t) {

	if (TreeIsEmpty(t)) {
		return 0;
	}


	int dominant = 0;

	ElemType somma_figli = 0;

	CountDominantRec(t, &dominant, &somma_figli);

	return dominant;

}

/*
int main() {

	ElemType e[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,77,21 };
	bool s;

	Node* t0 = TreeCreateRoot(&e[0], NULL, NULL);
	//s = ismirror(t0);

	Node* t1 = TreeCreateRoot(&e[12],
		TreeCreateRoot(&e[4],
			TreeCreateRoot(&e[0], 
				TreeCreateRoot(&e[19], NULL, NULL),
				TreeCreateRoot(&e[8], NULL, NULL)),
			TreeCreateRoot(&e[2], 
				TreeCreateRoot(&e[9], NULL, NULL),
				NULL)),
		TreeCreateRoot(&e[20], 
			TreeCreateRoot(&e[5], NULL, NULL),
			TreeCreateRoot(&e[18], NULL, NULL)));

	Node* t2 = TreeCreateRoot(&e[0],
		TreeCreateRoot(&e[1],
			TreeCreateRoot(&e[4], NULL, NULL),
			TreeCreateRoot(&e[2], NULL, NULL)),
		TreeCreateRoot(&e[1], NULL, NULL));

	//      0
	//  1       1
	//4   2   2   4

	
	
	int n = CountDominant(t1);


	TreeDelete(t0);
	TreeDelete(t1);

	return 0;

}*/