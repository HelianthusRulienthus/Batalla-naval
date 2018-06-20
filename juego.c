#include "juego.h"
#include "inicio.h"
#include <stdbool.h>

bool juego(struct list * jugador, struct list* oponente,
		int tablero_jugador[10][10], int anotador_jugador[10][10],int tablero_oponente[10][10], int anotador_oponente[10][10])
{
	//no encuentro funciones mostrar
	int x,y;
	input_correcto:{
		
	printf("Por favor, ingrese una coordenada x [1-10]":); //ya que se ingresan de 1 a 10 debemos restarle uno para operar mas adelante.
	scanf ("%i",&x);
	
	if(x<1||x>10){
		printf("Error. Coordenada invalida, vuelva a intentarlo.");
		goto input_correcto;
	}	
	
	printf("Por favor, ingrese una coordenada y [1-10]:");
	scanf("%i",&y);
	
	if(y<1||y>10){
		printf("Error. Coordenada invalida, vuelva a intentarlo.");
		goto input_correcto;
	}
	}
	
		if(anotador_jugador[x-1][y-1]){
			printf("Ya ha apuntado a esta casilla, vuelva a intentarlo.");
			goto input_correcto;
		}else{
			printf("Coordenadas ingresadas");
	}
	
	x--;  //rango x,y de 0 a 9.
	y--;
	
	//modifiquemos el anotador del jugador.
	if(tablero_oponente[x][y]==2){ //2 representa una parte de un barco.
		printf("\nUsted ha acertado su disparo sobre un barco!");
	
	//si ya no tiene barcos del oponente, gana el jugador.
		
		anotador_jugador[x][y]=4; //4 es fueguito
		
		
		
		
		ACA VA ALGO QUE NO ME SALE de borrar nodos C:
	
	}else{
		printf("\nUsted ha disparado al agua.");
		anotador_jugador[x][y]=1; //1 es agua
				
			
}
