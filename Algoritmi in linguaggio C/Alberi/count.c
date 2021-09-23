#include "tree.h"

void TreecountNodes(const Node* t, int* internal, int* external) {

	//caso base:
	if (TreeIsEmpty(t)) {
		return;
	}

	//se un nodo è interno:
	if ((!TreeIsEmpty(TreeLeft(t)) && !TreeIsEmpty(TreeRight(t))) 
		|| (TreeIsEmpty(TreeLeft(t)) && !TreeIsEmpty(TreeRight(t)))
		|| (!TreeIsEmpty(TreeLeft(t)) && TreeIsEmpty(TreeRight(t)))){

		(*internal)++;
	}
	else {
		(*external)++;
	}

	TreecountNodes(TreeLeft(t), internal, external);
	TreecountNodes(TreeRight(t), internal, external);
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

	
	int internal = 0;
	int external = 0;
	TreecountNodes(t1, &internal, &external);


	TreeDelete(t0);
	TreeDelete(t1);

	return 0;

}