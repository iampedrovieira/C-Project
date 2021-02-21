#include <locale.h>
#include "aluguer.h"
#include "cliente.h"
#include "recintos.h"
#include "tempo.h"

int menuPrincipal(){
	int x=0;
	printf("\n\n\n*****************************");
	printf("\n**\tMENU PRINCIPAL\t   **");
	printf("\n*****************************\n");
	printf("**\t1-Clientes.\t   **\n");
	printf("**\t2-Recintos.\t   **\n");
	printf("**\t3-Alugueres.\t   **\n");
	printf("**\t0-Sair.\t           **\n");
	printf("*****************************\n");
	printf("\t->");
	scanf("%i",&x);
	return x;
}

int menuRecintos(RECINTO recintos[],int *total){
	
	int x=0;
	RECINTO aux;
	do{
		system("cls");
		printf("\n\n\n**************************************************************************************\n");
		printf("**\t\t\tMENU RECINTOS\t\t\t\t\t\t    **\n");
		printf("**************************************************************************************\n");
		printf("**\t1-Adicionar recintos.\t\t\t\t\t\t\t    **\n");
		printf("**\t2-Alterar informação dos recintos.\t\t\t\t\t    **\n");
		printf("**\t3-Inativar/ativar recintos.\t\t\t\t\t\t    **\n");
		printf("**\t4-Listar recintos por ordem decrescente de preço.\t\t\t    **\n");
		printf("**\t5-Listar recintos por tipo.\t\t\t\t\t\t    **\n");
		printf("**\t6-Listar recintos por concelho.\t\t\t\t\t\t    **\n");
		printf("**\t7-Listar recintos de um determinado concelho por tipo de recinto.\t    **\n");
		printf("**\t8-Listar recintos entre intervalo de preço.\t\t\t\t    **\n");
		printf("**\t0-Voltar para o menu principal.\t\t\t\t\t\t    **\n");
		printf("**************************************************************************************\n");
		printf("\t->");
		scanf("%i",&x);
	
			switch(x){
		case 1:infoRecinto(recintos,total);break;
		case 2:alterarRecinto(recintos,*total);break;
		case 3:stats(recintos,*total);break;
		case 4:ordenarPrecoDecres(recintos,*total);listarPreco(recintos,*total);break;
		case 5:listarTipo(recintos,*total);break;
		case 6:listarConce(recintos,*total);break;
		case 7:listaCoTi(recintos,*total);break;
		case 8:listarIntPre(recintos,*total);break;
		case 0:printf("Saindo...\n");break;
		default :printf("Opção errada.\n");sleep(1);;break;
	}
	}while(x!=0);
	
}

int menuClientes(ELEMENTOC **iniCLista,int *total,int *totalR){
	int x=0;
	CLIENTE newInfo;
	do{
		system("cls");
		printf("\n\n\n***********************************************************\n");
		printf("**\t\t\tMENU CLIENTES\t\t\t **\n");
		printf("***********************************************************\n");
		printf("**\t1-Adicionar cliente.\t\t\t\t **\n");
		printf("**\t2-Alterar informação de um cliente.\t\t **\n");
		printf("**\t3-Listar clientes por ordem alfabetica.\t\t **\n");
		printf("**\t4-Apresentar dados de um cliente.\t\t **\n");
		printf("**\t5-Listar clientes por localidade.\t\t **\n");
		printf("**\t6-Remover cliente.\t\t\t\t **\n");
		printf("**\t0-Voltar para o menu principal.\t\t\t **\n");
		printf("***********************************************************\n");
		printf("\t->");
		scanf("%i",&x);
			switch(x){
		case 1:{
			infoCliente(*iniCLista,&newInfo,total,totalR);
			inserirCliente(iniCLista,newInfo);
			break;
		}
		case 2:alterarInfo(iniCLista);break;
		case 3:listarOrdemAlfabetica(iniCLista,*totalR);break;
		case 4:;listarPorNif(*iniCLista);break;
		case 5:listaPorLocalidade(*iniCLista);break;
		case 6:removeCliente(iniCLista,totalR);break;
		case 0:break;
		default :printf("Opção errada.\n");sleep(1);break;
	}
	}while(x!=0);	
}

int menuAlugueres(ELEMENTOA **iniALista,RECINTO recintos[],int totalR,ELEMENTOC *iniCLista){
	int x=0;
	do{
		system("cls");
		printf("\n\n\n********************************************************************************\n");
		printf("**\t\t\t\tMENU ALUGUER\t\t\t\t      **\n");
		printf("********************************************************************************\n");
		printf("**\t1-Reservar recinto.\t\t\t\t\t\t      **\n");
		printf("**\t2-Ativar reservar.\t\t\t\t\t\t      **\n");
		printf("**\t3-Listar recintos livres numa determinada data/hora.\t\t      **\n");
		printf("**\t4-Listar recintos livres por concelho.\t\t\t\t      **\n");
		printf("**\t5-Listar recintos livres por concelho e tipo.\t\t\t      **\n");
		printf("**\t6-Listar todos os alugueres feitos por um cliente.\t\t      **\n");
		printf("**\t7-Listar todos os dados de um aluguer de um recinto.\t\t      **\n");
		printf("**\t8-Listar reservas ativas ainda não realizadas.\t\t\t      **\n");
		printf("**\t9-Listar todo o dinheiro recebido num determinado recinto.\t      **\n");
		printf("**\t10-Fazer relatorio diario.\t\t\t\t\t      **\n");
		printf("**\t11-Fazer relatorio mensal.\t\t\t\t\t      **\n");
		printf("**\t12-Fazer relatorio anual.\t\t\t\t\t      **\n");
		printf("**\t0-Voltar para o menu Pricipal.\t\t\t\t\t      **\n");
		printf("********************************************************************************\n");
		printf("\t->");
		scanf("%i",&x);
			switch(x){
		case 1:reservarRecinto(iniALista,recintos,totalR,iniCLista);break;
		case 2:ativarReservar(iniALista,recintos,totalR,iniCLista);break;
		case 3:listarRecintosLivres(*iniALista,recintos,totalR);break;
		case 4:listarRecintosDiposniveisConc(recintos,totalR);break;
		case 5:listarRecintosDisponiveisCoTi(recintos,totalR);break;
		case 6:aluguerClientes(*iniALista,iniCLista);break;
		case 7:listarDadosAlugueresPorRecinto(*iniALista,recintos,totalR,iniCLista);break;
		case 8:listarReservasAtivas(*iniALista);break;
		case 9:listarTotalPorRecinto(*iniALista,recintos,totalR);break;
		case 10:fechoDiario(*iniALista);break;
		case 11:fechoMensal(*iniALista);break;
		case 12:fechoAnual(*iniALista);break;
		case 0:;break;
		default :printf("Opção errada.\n");sleep(1);break;
	}
	}while(x!=0);	
}

int main(){
	
	TEMPO tempo;
	int t=0;
	int opcao1=0,opcao2=0;
	setlocale(LC_ALL,"Portuguese");
	
	//Variaveis para clientes
	ELEMENTOC *iniCLista=NULL;
	int totalCRegistados=0;   //serve para saber quantos clientes estao gravados no momento.
	int idCliente=0;       //serve para dar um numero ao cliente.
	
	//Variaveis para recintos
	RECINTO recintos[MAX];
	int totalRecintos=0;
	
	//Variaveis para Alugueres
	ELEMENTOA *iniALista=NULL;
	int totalAlugueres=0;
	
	totalCRegistados=lerCliente(&iniCLista,&idCliente);
	lerRecintos(recintos,&totalRecintos);
	totalAlugueres=lerAlugueres(&iniALista);
	printf("Trabalho realizado por Joao Pedro Alves Vaz Vieira Nº21651\n");
	sleep(3);
	do{
	  system("cls");
	  tempoAtual(&tempo);
	  printf("%.2i:%.2i\t\t %.2i/%.2i/%.2i",tempo.hora,tempo.minutos,tempo.dia,tempo.mes,tempo.ano);
	  t=reservaInativaPassada(&iniALista);
	  if(t!=0){
	  	printf("\nForam removidas %i reservas inativas que ja passaram data.\n",t);
	  }
	  opcao1=menuPrincipal();
	  switch(opcao1){
		case 1:menuClientes(&iniCLista,&idCliente,&totalCRegistados);break;
		case 2:menuRecintos(recintos,&totalRecintos);break;
		case 3:menuAlugueres(&iniALista,recintos,totalRecintos,iniCLista);break;
		case 0:{
			gravarAlugueres(iniALista);
			gravarATexto(iniALista);
			gravarRecintos(recintos,totalRecintos);
			gravarRecintoTexto(recintos,totalRecintos);
			gravarClientes(iniCLista,idCliente);
			gravarCTexto(iniCLista);
			limparListaClientes(&iniCLista);
			limparAlugueres(&iniALista);
			printf("Saindo...\n");break;
			break;
		}
		default:printf("Opção errada.\n");sleep(1);;break;
	}
	}while(opcao1!=0);
}
