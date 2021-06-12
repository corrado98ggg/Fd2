#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool TreeIsMirrorRec(Node* t_right, Node* t_left, bool ret) {

    //caso base:
    if (TreeIsEmpty(t_left) || TreeIsEmpty(t_left)) {
        return ret;
    }

    if (*TreeGetRootValue(t_left) != *TreeGetRootValue(t_right)) {
        ret = false;
    }

    return TreeIsMirrorRec(TreeRight(t_right), TreeLeft(t_left), ret);
    return TreeIsMirrorRec(TreeLeft(t_right), TreeRight(t_left), ret);
}


bool TreeIsMirror(Node* t) {

    bool ret = true;

    if (TreeIsEmpty(t) || TreeIsLeaf(t)) {
        return ret;
    }

    ret = TreeIsMirrorRec(TreeRight(t), TreeLeft(t), ret);
    return ret;
}

/*
int main() {

    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };

    Node* t = TreeCreateRoot(e + 3,
        TreeCreateRoot(e + 5,
            TreeCreateRoot(e + 6, NULL, NULL),
            TreeCreateRoot(e + 1, NULL, NULL)),
        TreeCreateRoot(e + 5, TreeCreateRoot(e + 1, NULL, NULL), TreeCreateRoot(e + 6, NULL, NULL)));

    /*
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

   bool ret = TreeIsMirror(t);

}*/