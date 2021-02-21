#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//para quando utilizar libraria mais que uma vez,caso contrario iria declarar as variaveis sempre que invocavamos a libraria 
#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct cliente{
	
	int num;
	char nome[100];
	char localidade[50];
	char morada[100];
	int nif;
	int nCC;
	char email[100];
	int tele;
	
}CLIENTE;

typedef struct ELEMC{
	CLIENTE info;
	struct ELEMC *seguinte;	
}ELEMENTOC;


//Funções

void infoCliente(ELEMENTOC *iniLista,CLIENTE *newInfo,int *total,int *totalR);
int inserirCliente(ELEMENTOC **iniLista,CLIENTE newInfo);
void alerarInfo(ELEMENTOC **iniLista);
void listarOrdemAlfabetica(ELEMENTOC **iniLista,int total);
void listaPorLocalidade(ELEMENTOC *iniLista);
void listarPorNif(ELEMENTOC *iniLista);
int removeCliente(ELEMENTOC  **iniLista,int *totalR);
int veriCli(ELEMENTOC *iniLista,int num);
void limparListaClientes(ELEMENTOC **iniListar);
int gravarClientes(ELEMENTOC *iniLista,int total);
int lerCliente(ELEMENTOC **iniLista,int *total);
int gravarCTexto(ELEMENTOC *iniLista);

#endif




