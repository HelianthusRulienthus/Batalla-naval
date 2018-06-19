#include "inicio.h"
#include <stdlib.h>
#include <stdio.h>

void insertList(struct list* List, int y, int* barco){
	if(List->largo == 0){
		List->list = malloc(sizeof(struct node));
		List->list->y = y;
		List->list->barco = barco;
		List->list->sig = NULL;
		List->largo++;
	} else {	
		struct node* temp = malloc(sizeof(struct node));
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

void mostrar_mapa(int mapa[10][10]){
	
}
