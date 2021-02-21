#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//para quando utilizar libraria mais que uma vez,caso contrario iria declarar as variaveis sempre que invocavamos a libraria 
#ifndef RECINTO_H
#define RECINTO_H
#define MAX 80

typedef struct recintos{
	
	int CI;
	char nome[100];
	char conc[100];           
	int horaF;                
	int horaA;                
	char tipo[25];             // Futebol7 ; Futebol11 ;Padel ;Tenis ;Futsal ;Voleibol ;Basquetebol; Andebol ;
	int ilu;                   //1 tem luz, 0 nao tem
	float preco;             
	int status;               // 1-Interdito, 0- livre
	float totalGanho;
	        
}RECINTO;

int menuRecintos(RECINTO recintos[],int *total);
void infoRecinto(RECINTO recintos[],int *total);
void alterarRecinto(RECINTO recintos[],int total);
void alterarPreco(RECINTO recintos[],int num);
void alterarHa(RECINTO recintos[],int num);
void alterarHf(RECINTO recintos[],int num);
void stats(RECINTO recintos[],int total);
void ordenarPrecoDecres(RECINTO recintos[],int total);
void listarPreco(RECINTO recintos[],int total);
void listarTipo(RECINTO recintos [],int total);
void listarConce(RECINTO recintos[],int total);
void listaCoTi(RECINTO recintos[],int total);
void listarIntPre(RECINTO recintos[],int total);
int veriReci(RECINTO recin[],int num,int total);
int gravarRecintos(RECINTO recintos[],int total);
int lerRecintos(RECINTO recintos[],int *total);
int gravarRecintoTexto(RECINTO recintos[],int total);

#endif



