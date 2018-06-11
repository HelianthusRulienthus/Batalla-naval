#ifndef UTILITIES_H
#define UTILITIES_H
#include <stdlib.h>
	
	void cls();

/*  SLEEP  */
#ifdef _Windows
	#include <windows.h>
	#define sleep( x ) Sleep( (x * 1000) )
#else
	#include <unistd.h>
#endif
	
	void insertList(struct list*, int, int*);
	
#endif //UTILITIES_H