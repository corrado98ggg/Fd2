#include "tree.h"

Node *BstInsertRec(const ElemType *e, Node *n) {
    if (TreeIsEmpty(n)) {
        return TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
    }

    if (ElemCompare(e, TreeGetRootValue(n)) <= 0){
        // Va a sinistra
        n->left = BstInsertRec(e, TreeLeft(n));
    } else {
        // Va a destra
        n->right = BstInsertRec(e, TreeRight(n));
    }
    return n;
}

static void TreeMaxRec(const Node *n, const ElemType **max,
                       int *livello_max, int livello) {
    if (TreeIsEmpty(n)) {
        return;
    }

    if ((ElemCompare(*max, TreeGetRootValue(n)) < 0) ||
        (ElemCompare(*max, TreeGetRootValue(n)) == 0 && *livello_max > livello)) {
        *max = TreeGetRootValue(n);
        *livello_max = livello;
    }

    TreeMaxRec(TreeLeft(n), max, livello_max, livello + 1);
    TreeMaxRec(TreeRight(n), max, livello_max, livello + 1);
}

const ElemType *TreeMax(const Node *n) {
    if (TreeIsEmpty(n)) {
        return NULL;
    }

    const ElemType *max = TreeGetRootValue(n);
    int livello_max = 0;
    //TreeMaxRec(n, &max, &livello_max, 0);
    TreeMaxRec(TreeLeft(n), &max, &livello_max, 1);
    TreeMaxRec(TreeRight(n), &max, &livello_max, 1);
    return max;
}

int main(void) {
    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };

    Node *t = TreeCreateRoot(e + 15, 
                TreeCreateRoot(e + 10, 
                    TreeCreateRoot(e + 3, NULL, NULL),
                    TreeCreateRoot(e + 12, NULL, NULL)),
                TreeCreateRoot(e + 21, NULL, NULL));

    t = BstInsertRec(e + 22, t);
    const ElemType *res = TreeMax(t);
    TreeDelete(t);
    return 0;
}