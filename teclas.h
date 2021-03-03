#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ESPACIO 32
#define ENTER 13

int C=88;
int X;
int Y;
int Xmax;
int Ymax;
int matriz[8][8];

void vaciarMatriz(){
	int i,j;
	fflush(stdin);
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			matriz[i][j]=0;
		}
	}
}

void setLimites(int xMax, int yMax){
	Xmax=xMax;
	Ymax=yMax;
}

void gotoxy(int x, int y){
	
	HANDLE hCon;
	COORD dwPos;
	
	dwPos.X=x;
	dwPos.Y=y;
	
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}

void pintar(char caracter){
	gotoxy(X,Y);
	printf("%c",caracter);
}

void borrar(char caracter){
	gotoxy(X,Y);
	printf("%c",caracter);
}

void mover(){
	X=0;
	Y=3;
	vaciarMatriz();
	pintar(C);
	int enter=0, espaciadora=0;
	while(enter!=1){
		if(kbhit()){
			/*
			if(matriz[3-Y][X]==1)
				pintar('*');
			else if(matriz[3-Y][X]==0)
				pintar('0');
			*/	
			espaciadora=0;
			char tecla = getch();
			
			switch(tecla){
				case UP:
					if(Y!=3){
						if(matriz[3-Y][X]==1)
							pintar('*');
						else if(matriz[3-Y][X]==0)
							pintar('0');
						Y=Y-1;
					} 
					break;
				case DOWN:
					if(Y!=Ymax){
						if(matriz[3-Y][X]==1)
							pintar('*');
						else if(matriz[3-Y][X]==0)
							pintar('0');
						Y=Y+1;
					} 
					break;
				case RIGHT:
					if(X!=Xmax){
						if(matriz[3-Y][X]==1)
							pintar('*');
						else if(matriz[3-Y][X]==0)
							pintar('0');
						X=X+2;
					}
					break;
				case LEFT:
					if(X!=0){
						if(matriz[3-Y][X]==1)
							pintar('*');
						else if(matriz[3-Y][X]==0)
							pintar('0');
						X=X-2;	
					}
					break;
				case ESPACIO:
					espaciadora=1;
					matriz[3-Y][X]=1;
					pintar('*');
					break;
				case ENTER:
					enter=1;
					break;
			}
			if(espaciadora==0){
				pintar(C);	
			}
		}	
	}
}
	


