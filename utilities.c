#include "inicio.h"

void insertList(struct list* List, int y, int* barco){
	if(List->largo == 0){
		List->list = malloc(sizeof(node));
		List->list->y = y;
		List->list->barco = barco;
		List->list->sig = nullptr;
		List->largo++;
	} else {	
		struct node* temp = malloc(sizeof(node));
		temp->y = y;
		temp->barco = barco;
		temp->sig = List->list;
		List->list = temp;
		List->largo++;
	}
}

void cls(){
	fflush(stdout);
#ifdef WIN32
	system("cls");
#else
	system("clear");
#endif
}

