#ifndef UTILITIES_H
#define UTILITIES_H
	
	void cls(){
	}
	
	void wait(int ms){
	}
	
	void insertList(struct list* List, int y){
		if(List->largo == 0){
			List->list->sig = malloc(sizeof(node));
			List->list->largo++;
			return;
		}
		
		struct node* temp = malloc(sizeof(node));
		temp->y = y;
		temp->sig = List->list->sig;
		List->list->sig = temp;
		List.largo++;
	}
#endif //UTILITIES_H