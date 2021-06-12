#include "tree.h"
#include <stdio.h>

bool CheckSumNRec2(const Node* t, int n, ElemType* e, bool ret) {


    if (TreeIsEmpty(t)) {
        return ret;
    }

    if (*e + *TreeGetRootValue(t) == n) {
        ret = true;
        return ret;
    }

    CheckSumNRec2(TreeLeft(t), n, e, ret);
    CheckSumNRec2(TreeRight(t), n, e, ret);
}

bool CheckSumNRec(const Node* t, int n, ElemType* e, bool ret) {

    //caso base
    if (TreeIsEmpty(t)) {
        return ret;
    }

    e = TreeGetRootValue(t);

    ret = CheckSumNRec2(t, n, e, ret);
    
    if (ret == true) {
        ret = true;
        return ret;
    }
    else {
        CheckSumNRec(TreeLeft(t), n, e, ret);
        CheckSumNRec(TreeRight(t), n, e, ret);
    }
}


bool CheckSumN(const Node* t, int n) {

    if (TreeIsLeaf(TreeLeft(t)) || TreeIsLeaf(TreeRight(t))) {
        return false;
    }

    bool ret = false;
    ElemType* e = 0;

    ret = CheckSumNRec(t, n, e, ret);

    return ret;
}

/*
int main() {

    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };

    Node* t = TreeCreateRoot(e + 3,
        TreeCreateRoot(e + 5,
            TreeCreateRoot(e + 6, NULL, NULL),
            TreeCreateRoot(e + 7, NULL, NULL)),
        TreeCreateRoot(e + 5, TreeCreateRoot(e + 1, NULL, NULL), TreeCreateRoot(e + 6, NULL, NULL)));

              A
            /   \
          B       C
        /   \   E   F
       D
     G  H
          I

    TreeWriteStdoutInOrder(t);
    TreeWriteStdoutPostOrder(t);
    TreeWriteStdoutPreOrder(t);

   bool ret = CheckSumN(t, 10);

}*/