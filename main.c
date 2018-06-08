#include <cstdio>
#include "juego.h"
#include "inicio.h"

int main(){
	struct list jugador1*, jugador2*;
	short tableros[2][10][10], anotadores[2][10][10];
	
	init(&jugador1, &jugador2, tableros);
	
	construir({jugador1, jugador2}, tableros);
	
	while(jugar(jugador1,
				jugador2,
				tablero1,
				tablero2)
	);
	
	terminar();
}