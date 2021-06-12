#include "tree.h"
#include <stdlib.h>


void LevelOrderRec(Node* t_left, Node* t_right, ElemType* e_left, ElemType* e_right) {

    //caso base:
    if (TreeIsEmpty(t_left) && TreeIsEmpty(t_right)) {
        return;
    }


    if (!TreeIsEmpty(t_left)) {
        e_left = TreeGetRootValue(t_left);
        printf("%d ", *e_left);
    }

    if (!TreeIsEmpty(t_right)) {
        e_right = TreeGetRootValue(t_right);
        printf("%d ", *e_right);
    }
   
    LevelOrderRec(TreeLeft(t_left),TreeRight(t_left), e_left, e_right);
    LevelOrderRec(TreeLeft(t_right), TreeRight(t_right), e_left, e_right);

}

void LevelOrder(const Node* t) {

    if (TreeIsEmpty(t)) {
        return;
    }

    ElemType e = 0;
    ElemType e2 = 0;

    printf("%d ", *TreeGetRootValue(t));

    LevelOrderRec(TreeLeft(t), TreeRight(t), &e, &e2);
}

/*
int main(void) {
    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };

    Node* t = TreeCreateRoot(e + 4,
        TreeCreateRoot(e + 0,
            TreeCreateRoot(e + 1, TreeCreateRoot(e + 6, NULL, NULL), NULL),
            TreeCreateRoot(e + 2, NULL, TreeCreateRoot(e + 3, NULL, NULL))),
        TreeCreateRoot(e + 7, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e + 8, NULL, NULL)));

    LevelOrder(t);

    return 0;
}
*/