#include "remove.h"
#include <stdbool.h>


Item* removeduplicates(Item* i, bool ordered) {
	
	if (ListIsEmpty(i)) {
		return i;
	}

	Item* curr = i;
	Item* succ = ListGetTail(curr);

	while (!ListIsEmpty(succ)) {

		if (ElemCompare(ListGetHeadValue(curr), ListGetHeadValue(succ)) == 0) {

			//l'elemento successivo è uguale a quello corrente, quindi lo rimuovo e libero la memoria
			curr->next = ListGetTail(succ); //ovvero curr->next = succ->next
			succ->next = NULL; //rimuovo il collegamento tra succ e i suoi nodi
							   //a seguire della lista, così posso liberare la memoria invocando ListDelete()
							   //se non lo facessi la primitiva liberebbe la memoria di tutti gli elementi a seguire
			ListDelete(succ);
		}
		else {
			//importante! il puntatore al corrente deve avanzare solo se il
			//successivo non è stato eliminato, infatti quello ancora
			//potrebbe essere ancora uguale al corrente, ma se mando avanti curr
			//perdo la possibilità di fare questo confronto
			curr = ListGetTail(curr);
		}
		succ = ListGetTail(curr); //faccio puntare succ al next di curr e questo devo farlo in tutti i casi
								  //quindi lo scrivo una volta sola fuori dall'if
	}

	return i;
}


int main(void) {
	ElemType e[] = { 2,7,2,1 };
	ElemType e3 = 6;

	Item* list = NULL;
	for (int i = 0; i < 4; i++) {
		list = ListInsertHead(&e[i], list);
	}

	Item* ret = removeduplicates(list, false);


}