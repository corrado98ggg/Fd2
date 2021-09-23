#include "tree.h"


Node* predecessorerec(const Node* t, const Node* predecc, const ElemType* e, int i, Node* ret) {

	if (TreeIsEmpty(t)) {
		return ret;
	}


	if (*TreeGetRootValue(t) == *e) {
		ret = predecc;
		return ret;
	}

	if(i != 0){
		ret = predecessorerec(TreeLeft(t), TreeLeft(predecc), e, i + 1, ret);
		ret = predecessorerec(TreeRight(t), TreeRight(predecc), e, i + 1, ret);

	}
	else {
		ret = predecessorerec(TreeLeft(t), predecc, e, i + 1, ret);
		ret = predecessorerec(TreeRight(t), predecc, e, i + 1, ret);
	}
}


const Node* predecessore(const Node* t, const ElemType* e) {


	if (TreeIsEmpty(t)) {
		return TreeCreateEmpty();
	}

	if (*TreeGetRootValue(t) == *e) {
		return NULL;
	}

	Node* predecess = t;

	Node* ret = TreeCreateEmpty();

	ret = predecessorerec(t, predecess, e, 0, ret);

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

	
	int internal = 0;
	int external = 0;

	ElemType e2 = 2;
	Node* cc = predecessore(t1, &e2);


	TreeDelete(t0);
	TreeDelete(t1);

	return 0;

}