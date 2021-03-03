#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "teclas.h"

int dimension;
int nivel, edad,figu=0,jugadores=0;
char nombre[50],aliasRegistro[50],aliasJuego[50];

char nombres[100][50],alias[100][50];
int edades[100],niveles[100],figurasCreadas[100];
double tiempos[100];

//Declaración de funciones

void menuPlayer();
void registrarDatos();
void iniciarJuego();
void menuBasico();
void imprimirAvanzado();
void imprimirCuadrado(char caracter, int lado);
void imprimirRectangulo(char caracter, int lado1, int lado2);
void imprimirRombo(char caracter, int lado);
void imprimirTriangulo(char caracter, int lado);
void imprimirCruz(char caracter,int lado1, int lado2);
void imprimirTrapecio(char caracter, int altura);
int validarAlias(char alias1[50]);

void registrarTiempo(char alias1[50],double tiempo1);
void registrarNivel(char alias1[50],int nivel1);
void registrarFiguras(char alias1[50],int figura1);

void transferirDatosPlayer(char A[100][50],char B[100][50],int C[100],int D[100], int E[100], double F[100]);
void setDimensionPlayer(int dim);

//Implementación de funciones

int validarAlias(char alias1[50]){
	int i,validador=0;
	for(i=0;i<100;i++){
		if(strcmp(alias1,alias[i])==0){
			validador=1;
			break;	
		}
	}
	return validador;
}

void setDimensionPlayer(int dim){
	dimension=dim;
}

void transferirDatosPlayer(char A[100][50],char B[100][50],int C[100],int D[100], int E[100], double F[100]){
	int i;
	for(i=0;i<100;i++){
		strcpy(A[i],nombres[i]);
		strcpy(B[i],alias[i]);
		C[i]=edades[i];
		D[i]=niveles[i];
		E[i]=figurasCreadas[i];
		F[i]=tiempos[i];
	}
}

void menuPlayer(){
	int opPlayer=0;
	do{
		system("cls");
		printf("--------------MODO JUGADOR-------------\n");
		printf("1. Registrar datos\n");
		printf("2. Iniciar juego\n");
		printf("3. Atrás\n");
		printf("Seleccione una opción: ");
		scanf("%d",&opPlayer);
		
		switch(opPlayer){
			case 1:
				registrarDatos();
				break;
			case 2:
				iniciarJuego();
				break;
			case 3:
				break;
			default:
				printf("La opción ingresada es incorrecta\n");
				break;
		}
	}while(opPlayer!=3);
}

void registrarDatos(){
	printf("\n-----------REGISTRO DE DATOS DEL JUGADOR----------\n");
	printf("Ingrese un nombre: ");
	scanf("%s",&nombre);
	strcpy(nombres[jugadores],nombre);
	printf("Ingrese su edad: ");
	scanf("%i",&edad);
	edades[jugadores]=edad;
	printf("Ingrese un alias: ");
	scanf("%s",&aliasRegistro);
	strcpy(alias[jugadores],aliasRegistro);
	jugadores++;
}

void iniciarJuego(){
	printf("\nIngrese su alias: ");
	scanf("%s",&aliasJuego);
	int opJuego;
	figu=0;
	if(validarAlias(aliasJuego)==1){
		clock_t start = clock();
	
		do{
			system("cls");
			printf("-------------JUGADOR: %s--------------\n",aliasJuego);
			printf("1. Nivel Básico\n");
			printf("2. Nivel Avanzado\n");
			printf("3. Atrás\n");
			printf("Seleccione el nivel de dificultad: ");
			scanf("%d",&nivel);
			
			switch(nivel){
				case 1:
					registrarNivel(aliasJuego,nivel);
					menuBasico();
					break;
				case 2:
					registrarNivel(aliasJuego,nivel);
					imprimirAvanzado();
					figu++;
					break;
				case 3:
					break;
				default:
					printf("La opción ingresada es incorrecta\n");
					break;
			}
		}while(nivel!=3);
		registrarFiguras(aliasJuego,figu);
		
		double time = ((double)clock() - start) / CLOCKS_PER_SEC;
		registrarTiempo(aliasJuego,time);
	}else{
		printf("El alias ingresado no está registrado\n");
		printf("Digite 1 para continuar: ");
		scanf("%d",&opJuego);
	}
		
}

void menuBasico(){
	int figura, resp;
	char caracter;
	int filas=0,columnas=0;
	do{
		system("cls");
		printf("-------------FIGURAS GEOMÉTRICAS SIMPLES------------\n");
		printf("1. Cuadrado\n");
		printf("2. Rectángulo\n");
		printf("3. Rombo\n");
		printf("4. Triángulo\n");
		printf("5. Cruz\n");
		printf("6. Trapecio\n");
		printf("7. Atrás\n");
		printf("Seleccione una figura: ");
		scanf("%d",&figura);
		
		switch(figura){
			case 1:
				printf("Ingrese la longitud del lado: ");
				scanf("%i",&filas);
				printf("Seleccione el caracter para la gráfica: ");
				scanf(" %c",&caracter);
				imprimirCuadrado(caracter,filas);
				printf("¿Desea continuar?(1.Si, 2.No): ");
				scanf("%d",&resp);
				figu++;
				break;
			case 2:
				printf("Ingrese el número de filas: ");
				scanf("%i",&filas);
				printf("Ingrese el número de columnas: ");
				scanf("%i",&columnas);
				printf("Seleccione el caracter para la gráfica: ");
				scanf(" %c",&caracter);
				imprimirRectangulo(caracter,filas,columnas);
				printf("¿Desea continuar?(1.Si, 2.No): ");
				scanf("%d",&resp);
				figu++;
				break;
			case 3:
				printf("Ingrese la longitud del lado: ");
				scanf("%i",&filas);
				printf("Seleccione el caracter para la gráfica: ");
				scanf(" %c",&caracter);
				imprimirRombo(caracter,filas);
				printf("¿Desea continuar?(1.Si, 2.No): ");
				scanf("%d",&resp);
				figu++;
				break;
			case 4:
				printf("Ingrese la altura del triángulo: ");
				scanf("%i",&filas);
				printf("Seleccione el caracter para la gráfica: ");
				scanf(" %c",&caracter);
				imprimirTriangulo(caracter,filas);
				printf("¿Desea continuar?(1.Si, 2.No): ");
				scanf("%d",&resp);
				figu++;
				break;
			case 5:
				printf("Ingrese la longitud vertical: ");
				scanf("%i",&filas);
				printf("Ingrese la longitud horizontal: ");
				scanf("%i",&columnas);
				printf("Seleccione el caracter para la gráfica: ");
				scanf(" %c",&caracter);
				imprimirCruz(caracter,filas,columnas);
				printf("¿Desea continuar?(1.Si, 2.No): ");
				scanf("%d",&resp);
				figu++;
				break;
			case 6:
				printf("Ingrese la altura del trapecio: ");
				scanf("%i",&filas);
				printf("Seleccione el caracter para la gráfica: ");
				scanf(" %c",&caracter);
				imprimirTrapecio(caracter,filas);
				printf("¿Desea continuar?(1.Si, 2.No): ");
				scanf("%d",&resp);
				figu++;
				break;
			case 7:
				break;
			default:
				printf("La opción ingresada es incorrecta\n");
				break;						
		}	
	}while(resp !=2 && figura !=7);
}

void imprimirAvanzado(){
	system("cls");
	printf("-Movimiento con las teclas: ARRIBA, ABAJO, IZQUIERDA, DERECHA\n");
	printf("-Marcar casilla con tecla ESPACIO\n\n");
	
	int i,j;
	for(i=0;i<dimension;i++){
		for(j=0;j<dimension;j++){
			printf("%c ",'0');	
		}
		printf("\n");
	}
	
	printf("\nSi desea salir del nivel avanzado, presione ENTER\n");
	setLimites(2*(dimension-1),dimension+2);
	mover();
}

void registrarTiempo(char alias1[50],double tiempo1){
	int i;
	for(i=0;i<100;i++){
		if(strcmp(alias1,alias[i])==0)
			break;
	}
	tiempos[i]+=tiempo1;
}

void registrarNivel(char alias1[50],int nivel1){
	int i;
	for(i=0;i<100;i++){
		if(strcmp(alias1,alias[i])==0)
			break;
	}
	niveles[i]=nivel1;
}

void registrarFiguras(char alias1[50],int figura1){
	int i;
	for(i=0;i<100;i++){
		if(strcmp(alias1,alias[i])==0)
			break;
	}
	figurasCreadas[i]+=figura1;
}

void imprimirCuadrado(char caracter, int lado){
	int i,j;
	printf("\n");
	for(i=0;i<lado;i++){
		for(j=0;j<lado;j++){
				printf("%c  ",caracter);	
		}
		printf("\n");
	}
	printf("\n");
}

void imprimirRectangulo(char caracter, int lado1, int lado2){
	int i,j;
	printf("\n");
	for(i=0;i<lado1;i++){
		for(j=0;j<lado2;j++){
				printf("%c  ",caracter);	
		}
		printf("\n");
	}
	printf("\n");
}

void imprimirRombo(char caracter, int lado){
    int n, c, k;
    lado++;
    int space = lado - 1;
	//n=lado;
    for (k = 1; k <= lado; k++) {
        for (c = 1; c <= space; c++)
            printf(" ");
        space--;
        for (c = 1; c <= 2*k-1; c++)
            if (c%2 ==0)
                printf("%c",caracter);
            else
                printf(" ");
        printf("\n");
    }
    space = 1;
    for (k = 1; k <= lado - 1; k++) {
        for (c = 1; c <= space; c++)
            printf(" ");
        space++;
        for (c = 1 ; c <= 2*(lado-k)-1; c++)
            if (c%2 ==0)
                printf("%c",caracter);
            else
                printf(" ");
        printf("\n");
    }
}

void imprimirTriangulo(char caracter, int lado){
	int i, j;
	printf("\n");
	for(i=1; i<=lado; i++) {
		for (j=1; j<=lado-i; j++) 
			printf(" ");
		for (j=1; j<=2*i-1; j++) 
			printf("%c",caracter);
		printf("\n");
	}
	printf("\n");
}

void imprimirCruz(char caracter, int lado1, int lado2){
	int i,j;
	
	printf("\n");
	for(i=0;i<lado1;i++){
		for(j=0;j<lado2;j++){
			if(i==lado1/2)
				printf("%c  ",caracter);	
			else
				if(j==lado2/2)
					printf("%c  ",caracter);	
				else
					printf("   ");
		}
		printf("\n");
	}
	printf("\n\n");
	
}

void imprimirTrapecio(char caracter, int altura){
	int i, j;
	printf("\n");
	for(i=1; i<=2*altura; i++) {
		if(i>altura){
			for (j=1; j<=2*altura-i; j++) 
				printf(" ");
			for (j=1; j<=2*i-1; j++) 
				printf("%c", caracter);
			printf("\n");	
		}
	}
	printf("\n");
}

