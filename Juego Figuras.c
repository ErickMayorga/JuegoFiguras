#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include "jugador.h"
#include "administrador.h"

char nombres[100][50];
char alias[100][50];
int edades[100];
int niveles[100];
int figurasCreadas[100];
double tiempos[100];
int dimensionMain;

int main(){
	
	setlocale(LC_CTYPE, "Spanish");
	dimensionMain=8;
	int sesion;
	do{
		system("cls");
		printf("------------JUEGO PARA CREAR FIGURAS------------\n");
		printf("1. Administrador\n");
		printf("2. Jugador\n");
		printf("3. Salir del juego\n");
		printf("Seleccione un modo de inicio de sesión: ");
		scanf("%d",&sesion);
		
		switch(sesion){
			case 1:
				setRegistrosAdmin(nombres,alias,edades,niveles,figurasCreadas,tiempos);
				menuAdmin();
				transferirDimensionAdmin(dimensionMain);
				break;
			case 2:
				setDimensionPlayer(dimensionMain);
				menuPlayer();
				transferirDatosPlayer(nombres,alias,edades,niveles,figurasCreadas,tiempos);	
				break;
			case 3:
				break;	
			default:
				printf("La opción ingresada es incorrecta\n");
				break;
		}
	}while(sesion!=3);
	
	return 0;
}
