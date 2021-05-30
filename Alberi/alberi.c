#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void MaxRec(const Node* t, const ElemType** max, int* livello_max, int livello) {

    //caso base
    if (TreeIsEmpty(t)) {
        return;
    }

    /*
    * visita albero in profondità in ordine posticipato:
    visitainPreOrdine(t->left, max, livello_max, livello + 1);
    visitainPreOrdine(t->right, max, livello_max, livello + 1);
    nel caso del nostro albero stampa:
    D-E-B-C-A
    */

    if ((ElemCompare(*max, TreeGetRootValue(t)) < 0) ||
        (ElemCompare(*max, TreeGetRootValue(t)) == 0 && *livello_max > livello)) {
        *max = TreeGetRootValue(t);
        *livello_max = livello;
    }

    MaxRec(t->left, max, livello_max, livello + 1);
    MaxRec (t->right, max, livello_max, livello + 1);

    /*      ->->->->->->->->->->
    visita albero in profondità in ordine anticipato:
    visitainPreOrdine(t->left, max, livello_max, livello + 1);
    visitainPreOrdine(t->right, max, livello_max, livello + 1);
    nel caso del nostro albero stampa:
    A-B-D-E-C
    */
}

//ritorna il valore del nodo di chiave massima dentro l'albero
ElemType* TreMax(const Node* t) {   //

    if (TreeIsEmpty(t)) {
        return NULL;
    }

    const ElemType* max = TreeGetRootValue(t);
    int livello_max = 0;

    MaxRec(t, &max, &livello_max, 0);
    return max;
}


void IsMemberRec(const Node* t, const ElemType* e, bool* ret) {

    //caso base:
    if (TreeIsEmpty(t)) {
        return;
    }

    if (ElemCompare(TreeGetRootValue(t), e) == 0) {
        *ret = true;
    }

    IsMemberRec(t->left, e, ret);
    IsMemberRec(t->right, e, ret);

}

//stabilire se un nodo è membro di un albero
bool* IsMember(const Node* t, const ElemType* e) {

    bool* ret = false;

    if (TreeIsEmpty(t)) {
        return ret;
    }

    IsMemberRec(t, e, &ret);

    return ret;
}

// Dato un BST la funzione ritorna l'indirizzo del figlio
// con chiave massima
Node* GetNodeWithMaximumKey(Node* n) {
    while (!TreeIsEmpty(TreeRight(n))) {
        n = TreeRight(n);
    }
    return n;
}

Node* DeleteBstNodeRec(Node* n, const ElemType* key) {

    //per ogni nodo verifico se è il nodo da eliminare
    //ci sono due casi; il nodo da eliminare si trova nel sottoalbero sx e dx
    //tutte le volte che delego a una sottofunzione la modifica di un alber devo aggiornare l'albero corrente

    //caso base
    if (TreeIsEmpty(n)) {
        return NULL;
    }

    if (ElemCompare(key, TreeGetRootValue(n)) < 0) {
        //se il nodo corrente non ha lo stesso valore del nodo da eliminare e il nodo da eliminare è minore allora mi sposto a sinistra
        n->left = DeleteBstNodeRec(TreeLeft(n), key);
    }
    else if (ElemCompare(key, TreeGetRootValue(n)) > 0) {
        //se il nodo corrente non ha lo stesso valore del nodo da eliminare e il nodo da eliminare è maggiore allora mi sposto a destra
        n->right = DeleteBstNodeRec(TreeRight(n), key);
    }
    else { //se il nodo da eliminare corrisponde al nodo corrente, distinguiamo i 3 casi

        // Caso 1: il nodo da eliminare è una foglia
        if (TreeIsLeaf(n)) {
            TreeDelete(n);
            return NULL;
        }
        // Caso 2: il nodo da eliminare ha entrambi i figli
        else if (TreeLeft(n) && TreeRight(n)) {

            // Trovo il predecessore
            Node* predecessor = GetNodeWithMaximumKey(TreeLeft(n));

            // Copio il valore del predecessore nel nodo corrente ed
            // elimino il predecessore ricorsivamente. Il predecessore
            // ha al più il figlio sinistro.
            ElemDelete(&n->value);
            n->value = ElemCopy(TreeGetRootValue(predecessor));
            n->left = DeleteBstNodeRec(TreeLeft(n), TreeGetRootValue(predecessor));
            return n;
        }
        // Caso 3: il nodo da eliminare ha un solo figlio
        else {
            // Quale?
            Node* child = (TreeLeft(n)) ? TreeLeft(n) : TreeRight(n);
            Node* curr = n;

            n = child;

            ElemDelete(&curr->value);

            return n;
        }
    }
    return n;
}

Node* DeleteBstNode(Node* n, const ElemType* key) {
    return DeleteBstNodeRec(n, key);
}

Node* BstInsertRec(const ElemType* e, Node* n) {
    if (TreeIsEmpty(n)) {
        return TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
    }

    if (ElemCompare(e, TreeGetRootValue(n)) <= 0) {
        // Va a sinistra
        n->left = BstInsertRec(e, TreeLeft(n));
    }
    else {
        // Va a destra
        n->right = BstInsertRec(e, TreeRight(n));
    }
    return n;
}

Node* BstFromVector(ElemType* v, size_t v_size) {
    Node* tree = TreeCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        tree = BstInsertRec(v + i, tree);
    }
    return tree;
}

int main(void) {
    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };

    Node* t = TreeCreateRoot(e + 10,
        TreeCreateRoot(e + 10,
            TreeCreateRoot(e + 12, NULL, NULL),
            TreeCreateRoot(e + 11, NULL, NULL)),
        TreeCreateRoot(e + 4, NULL, NULL));

    /*
              A
            /   \
          B       C
        /   \
       D     E

    */

    //t = BstInsertRec(e + 22, t);
    ElemType* res = TreMax(t);
    bool mem = IsMember(t, e + 11);
    TreeDelete(t);


    // Test del DeleteBstNode ((la creazione dell'albero nel main puo' essere usata))
    //funzioni esterne come BstFromVector e InsertBst no
    {
        ElemType key = 12;
        Node* t = TreeCreateEmpty();
        t = DeleteBstNode(t, &key);
        TreeDelete(t);
    }
    {
        ElemType key = 12;
        ElemType e[] = { 12, 4, 5 };
        size_t e_size = sizeof(e) / sizeof(ElemType);
        Node* t = BstFromVector(e, e_size);
        t = DeleteBstNode(t, &key);
        TreeDelete(t);
    }
    {
        ElemType key = 12;
        ElemType e[] = { 12, 4, 21, 0, 2, 5, 18, 77, 8, 9 };
        size_t e_size = sizeof(e) / sizeof(ElemType);
        Node* t = BstFromVector(e, e_size);
        t = DeleteBstNode(t, &key);
        TreeDelete(t);
    }
    {
        ElemType key = 21;
        ElemType e[] = { 12, 4, 21, 0, 2, 5, 18, 77, 8, 9 };
        size_t e_size = sizeof(e) / sizeof(ElemType);
        Node* t = BstFromVector(e, e_size);
        t = DeleteBstNode(t, &key);
        TreeDelete(t);
    }
    {
        ElemType key = 77;
        ElemType e[] = { 12, 4, 21, 0, 2, 5, 18, 77, 8, 9 };
        size_t e_size = sizeof(e) / sizeof(ElemType);
        Node* t = BstFromVector(e, e_size);
        t = DeleteBstNode(t, &key);
        TreeDelete(t);
    }
    {
        ElemType key = 0;
        ElemType e[] = { 12, 4, 21, 0, 2, 5, 18, 77, 8, 9 };
        size_t e_size = sizeof(e) / sizeof(ElemType);
        Node* t = BstFromVector(e, e_size);
        t = DeleteBstNode(t, &key);
        TreeDelete(t);
    }

    return 0;
}