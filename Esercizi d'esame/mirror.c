#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool TreeIsMirrorRec(Node* left, Node* right, bool ret) {


    if (ElemCompare(TreeGetRootValue(left), TreeGetRootValue(right)) != 0) {
        ret = false;
    }

    //caso base:
    if (TreeIsLeaf(TreeLeft(right)) && TreeIsLeaf(TreeRight(left))){
        return ret;
    }

    TreeIsMirrorRec(TreeLeft(left), TreeRight(right), ret);
}

bool TreeIsMirror(Node* t) {

    if (TreeIsEmpty(t) || TreeIsLeaf(t)) {
        return true;
    }
  
    bool tmp = true;

    tmp = TreeIsMirrorRec(TreeLeft(t), TreeRight(t), tmp);

    return tmp;
}



/*
int main(void) {
    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };

    Node* t = TreeCreateRoot(e + 3,
        TreeCreateRoot(e + 4, 
            TreeCreateRoot(e+5, NULL, NULL),
            TreeCreateRoot(e+6, NULL, NULL)),
        TreeCreateRoot(e + 4,
            TreeCreateRoot(e + 5, NULL, NULL),
            TreeCreateRoot(e + 6, NULL, NULL)));


    bool tmp = TreeIsMirror(t);
}*/

