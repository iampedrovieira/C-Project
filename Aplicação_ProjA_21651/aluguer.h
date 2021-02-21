#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cliente.h"
#include "recintos.h"
#include "tempo.h"

typedef struct alugeres{
	
	int idRecinto;
	int idCliente;
	TEMPO dataReserva;                //data que fez a reservar
	TEMPO dataAluguer;                //data do aluguer
	int tempoA;
	float totalAPagar;
	TEMPO dataPagamento;
	int modoPagamento;                //1- dinheiro 2-multibanco 3-MBAWAY 0-Ainda nao fez pagamento,ainda é reserva
	
}ALUGUER;

typedef struct ELEMA{
	ALUGUER info;
	struct ELEMA *seguinte;
	
}ELEMENTOA;

int menuAlugueres(ELEMENTOA **iniALista,RECINTO recintos[],int totalR,ELEMENTOC *iniCLista);
int reservarRecinto(ELEMENTOA **iniALista,RECINTO recintos[],int totalR,ELEMENTOC *iniCLista);
int verificarAluguer(ELEMENTOA *iniLista,ALUGUER x,RECINTO recintos[]);
int reserva(ELEMENTOA **iniLista,ALUGUER newInfo);
void ativarReservar(ELEMENTOA **iniALista,RECINTO recintos[],int totalR,ELEMENTOC *iniCLista);
int funcaoPagamentos();
void aluguerClientes(ELEMENTOA *iniALista,ELEMENTOC *iniCLista);
void listarDadosAlugueresPorRecinto(ELEMENTOA *iniALista,RECINTO recintos[],int totalR,ELEMENTOC *iniCLista);
void listarRecintosLivres(ELEMENTOA *iniALista,RECINTO recintos[],int totalR);
void listarRecintosDiposniveisConc(RECINTO recintos[],int total);
void listarRecintosDisponiveisCoTi(RECINTO recintos[],int total);
void listarReservasAtivas(ELEMENTOA *iniALista);
void listarTotalPorRecinto(ELEMENTOA *iniALista,RECINTO recintos[],int totalR);
float calcularIVA(ELEMENTOA *iniALista,int x);
int reservaInativaPassada(ELEMENTOA **iniALista);
int verificarValidade(TEMPO x);
int fechoAnual(ELEMENTOA *iniALista);
int fechoMensal(ELEMENTOA *iniALista);
int fechoDiario(ELEMENTOA *iniALista);
int gravarATexto(ELEMENTOA *iniLista);
int gravarAlugueres(ELEMENTOA *iniLista);
int lerAlugueres(ELEMENTOA **iniLista);
void limparAlugueres(ELEMENTOA **iniLista);


