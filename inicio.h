#ifndef INICIO_H
#define INICIO_H
	
	struct node{
		struct node* sig;
		int y;
		int* barco;
	}
	
	struct list{
		struct node* list;
		int largo;
	}
	
	void insertList(struct list*, int);
	
	void construir(struct list**, struct list**, short***, short***);
	
	void init(struct list**, struct list**, short***, short***);
	
	
#endif //INICIO_H