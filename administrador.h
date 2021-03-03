#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dimensionMatriz;
char currentPassword[20]="admin";
char nombres[100][50];
char alias[100][50];
int edades[100];
int niveles[100];
int figurasCreadas[100];
double tiempos[100];

//Declaración de funciones

int validarPassword();
void menuAdmin();
int imprimirEstadisticas();
void cambiarPassword();
void cambiarDimension();
void setRegistrosAdmin(char A[100][50],char B[100][50],int C[100],int D[100], int E[100], double F[100]);
void transferirDimensionAdmin(int dim);

//Implementación de funciones

void transferirDimensionAdmin(int dim){
	dim=dimensionMatriz;
}

void setRegistrosAdmin(char A[100][50],char B[100][50],int C[100],int D[100], int E[100], double F[100]){
	int i;
	for(i=0;i<100;i++){
		strcpy(nombres[i],A[i]);
		strcpy(alias[i],B[i]);
		edades[i]=C[i];
		niveles[i]=D[i];
		figurasCreadas[i]=E[i];
		tiempos[i]=F[i];
	}
}

int validarPassword(){
	char password[20];
	int validador=0;
	printf("Ingrese la contraseña: ");
	scanf("%s",password);
	if(strcmp(password,currentPassword)==0)
		validador=1;
	return validador;
}

int imprimirEstadisticas(){
	int i,opEst;
	printf("\n-------------------------------------\n");
	printf("Nombre\tEdad\tNivel\tFiguras Creadas\tTiempo Jugado\n");
	for(i=0;i<jugadores;i++){
		printf("%s\t%i\t%i\t%i\t\t%.2f\n",
			nombres[i],edades[i],niveles[i],figurasCreadas[i],tiempos[i]);
	}
	printf("-------------------------------------\n");	
	printf("¿Desea continuar en ADMINISTRADOR?(1.Si, 2.No): ");
	scanf("%d",&opEst);
	return opEst;
}

void cambiarPassword(){
	char newPassword[20];
	printf("Ingrese la nueva contraseña: ");
	scanf("%s",&newPassword);
	strcpy(currentPassword,newPassword);
}

void cambiarDimension(){
	int dimension;
	dimensionMatriz=8;
	printf("Ingrese la nueva dimensión de la matriz: ");
	scanf("%d",&dimension);
	if(dimension>1)
		dimensionMatriz=dimension;
	else
		printf("La dimensión no es válida\n");
}

void menuAdmin(){
	int opAdmin,opEst1=0;
	int result=validarPassword();
	if(result==1){
		do{
		
		
			system("cls");
			printf("-------------ADMINISTRADOR---------------\n");
			printf("1. Cambiar contraseña\n");
			printf("2. Estadísticas de jugadores\n");
			printf("3. Modificar tamaño de la matriz\n");
			printf("4. Atrás\n");
			printf("Seleccione una opcion: ");
			scanf("%d",&opAdmin);
			
			switch(opAdmin){
				case 1:
					cambiarPassword();
					break;
				case 2:
					opEst1=imprimirEstadisticas();
					break;
				case 3:
					cambiarDimension();	
					break;
				case 4:
					break;
				default:
					printf("La opcion ingresada es incorrecta\n");
					break;
			}	
		
		}while(opAdmin!=4 && opEst1!=2);
	}else
		printf("Contraseña incorrecta\n");
}








