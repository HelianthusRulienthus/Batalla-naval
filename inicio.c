#include "inicio.h"
#include "utilities.h"
#include <cstdio.h>
#include <math.h>
#define ocupado 1
#define agua 0
			
bool alrededores(short** tablero, int x, int y){
	for(int i=-1; i<2; i++){
		for(int j=-1; j<2; j++){
			if(tablero[x-i][y-j] == ocupado)
				return true;
		}
	}
	return false;
}

void init(struct list** jugador1,
			struct list** jugador2,
			short*** tableros,
			short*** anotadores)
{
	jugador1 = malloc(sizeof(list)*10);
	jugador2 = malloc(sizeof(list)*10);
	
	for(int i=0; i<10; i++){
		jugador1[i].sig = jugador2[i].sig = null;
		jugador1[i].largo = jugador2[i].largo = null;
	}
	
	for(int j=0; j<10; j++){
		for(int k=0; k<10; k++){
			tableros[0][j][k] = \ 
			tableros[1][j][k] = agua;
			anotadores[0][i][j] = \
			anotadores[1][i][j] = agua;
		}
	}
	
}

void construir(struct list** jugadores,
			short*** tableros)
{
	/*
	Se predefinen para la cantidad de barcos y el tamaño:
	1 submarino
	2 destructores
	3 cruceros
	1 acorazado
	*/
	
	short jugador = 0;
	
	do{		
		short cantidades[] = {1, 2, 3, 1};
		const char* barcos[] = {"Submarino", "Destructor",
								"Crucero", "Acorazado"};
		nuevo_barco:
		cls();
		
		printf("\tJugador actual: Jugador%d\n", jugador);
		printf("\tBarcos restantes:\n");
		
		for(int i=0; i<4; i++)
			printf("%d\t%s\n", cantidades[i], barcos[i]);
		
		confirm_input:
		
		short entrada;
		printf("Ingrese un indice(0-3) para seleccionar un barco");
		scanf("%d%*c", &entrada);
		
		if(entrada < 0 || entrada > 3){
			printf("Indice erroneo. Vuelva a intentar");
			goto confirm_input;
		}
		if(cantidades[entrada] == 0){
			printf("Cantidad del barco \"%s\" es 0. Vuelva a intentar", barcos[entrada]);
			goto confirm_input;
		}
		
		{//else
		short x1, x2, y1, y2;
			
		insert_barco:
		cls();
		
		mostrar_mapa(tableros[jugador]);
		
		printf("\tBarco seleccionado: %s\n\n", barcos[entrada]);
		
		do{
			//incluir mensaje de error
			printf("Ingrese un valor x e y inicial");
			scanf("%d%d%*c", x1, y1);
		}while(x1 < 0 || x1 >= 10 ||
				y1 < 0 || y1 >= 10);
					
		do{
			//incluir mensaje de error
			printf("Ingrese un valor x e y final");
			scanf("%d%d%*c", x2, y2);
		}while(x2 < 0 || x2 >= 10 ||
				y2 < 0 || y2 >= 10);
					
		short dist_x = abs(x2-x1);
		short dist_y = abs(y2-y1);
			
		//entrada+1 = largo barco
		bool entrada_valida = (
		(dist_x == 0 && dist_y == entrada+1) ||
		(dist_y == 0 && dist_x == entrada+1));
		//barcos validos: horizontales y verticales
			
		if(!entrada_valida){
			printf("Forma del barco erronea. Vuelva a intentar");
			wait(3000);
			
			goto insert_barco;
		}
			
		//analizar los alrededores de (x1,y1)-(x2,y2)
		if(dist_x == 0){
			for(int i=min(y1, y2); i < max(y1, y2); i++){
				if(alrededores(tableros[jugador], x1, i)){
					printf("El rango seleccionado coincide con los alrededores o con una "
					"casilla de otro barco. Vuelva a intentar");
					wait(3000);
					
					goto insert_barco;
				}
			}
			
			//dibujar barco
			for(int i=min(y1, y2); i < max(y1, y2); i++){
				tableros[jugador][x1][i] = ocupado;
				
				insertList(&jugadores[jugador][x1], i);
			}
		} else { // dist_y = 0
			for(int i=min(x1, x2); i<max(x1, x2); i++){
				if(alrededores(tableros[jugador], i, y1)){
					printf("El rango seleccionado coincide con los alrededores o con una "
					"casilla de otro barco. Vuelva a intentar");
					wait(3000);
					
					goto insert_barco;
				}
			}
				
			//dibujar barco
			for(int i=min(x1, x2); i < max(x1, x2); i++){
				tableros[jugador][i][y1] = ocupado;
				
				insertList(&jugadores[jugador][i], y1);
			}
		}
			
		cantidades[entrada]--;
		}
		
		for(int i=0; i<4; i++){
			if(cantidades[i] != 0)
				goto nuevo_barco;
		}
		
		jugador++;
	}while(jugador < 2);
	
}