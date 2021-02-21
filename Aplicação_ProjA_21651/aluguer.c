#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluguer.h"
#include "recintos.h"
#include "cliente.h"
#include "tempo.h"
#define VALORIVA 0.23  //assim é mais facil de alterar um dia que o valor do IVA se altere.

//RESERVAR RECINTOS
int reservarRecinto(ELEMENTOA **iniALista,RECINTO recintos[],int totalR,ELEMENTOC *iniCLista){
	int t=0;
	TEMPO aux;
	ALUGUER info;
	system("cls");
	printf("***************************************\n");
	printf("**  \tINFORMÇÃO PARA ALUGUER.      **\n");
	printf("***************************************\n");
	printf("\nIntroduza o numero de cliente.\n");
	printf("->");
	scanf("%i",&info.idCliente);
	//Função verificar cleinte, esta no cliente.c
	t=veriCli(iniCLista,info.idCliente);
	
	if(t!=0){
		printf("Não existe esse cliente.\n");
		system("pause");
		return 2;
	}
	printf("\nIntroduza o numero do recinto.\n");
	printf("->");
	scanf("%i",&info.idRecinto);
	//Função verificar Recinto,que vai estar no recinto.c
	t=veriReci(recintos,info.idRecinto,totalR);
	if(t==-1){
		system("cls");
		printf("Não existe esse recinto.\n");
		system("pause");
		return 2;
	}
	if(t==2){
		system("cls");
		printf("Recinto interdito.\n");
		system("pause");
		return 2;
	}
	printf("\nIntroduza a data e hora que quer alugar.(DD/MM/AAAA-HH)\n");
	printf("->");
	scanf("%i/%i/%i-%i",&info.dataAluguer.dia,&info.dataAluguer.mes,&info.dataAluguer.ano,&info.dataAluguer.hora);
	printf("\nIntroduza o tempo de duração.\n");
	printf("->");
	scanf("%i",&info.tempoA);
	//Verificar se esta livre nesta altura.
	t=verificarAluguer(*iniALista,info,recintos);
	switch(t){
		case -1:printf("\nIntroduziu uma data impossivel de reservar.\n");system("pause");return 2;break;
		case -2:printf("\nRecinto não esta aberto nessa data/hora.\n");system("pause");return 2;break;
		case 2:printf("\nRecinto ja esta reservado para essa data/hora.\n");system("pause");return 2;break;
	}

	//Atribuir a data da reserva.
	tempoAtual(&info.dataReserva);
	info.modoPagamento=0;   //quer dizer que ainda nao foi pago.
	t=reserva(iniALista,info);
	if(t==0){
		printf("\nReserva feita com sucesso\n");
		system("pause");
		return 1;
	}
}

//Verificar disponiblidade.
int verificarAluguer(ELEMENTOA *iniALista,ALUGUER x,RECINTO recintos[]){
	ELEMENTOA *aux=NULL;
	TEMPO temp;
	int fimX=0,fimAux=0;
	tempoAtual(&temp);
	fimX=x.dataAluguer.hora+x.tempoA;
	
	if(verificarValidade(x.dataAluguer)==-1){
		return -1;
	}
	if(x.dataAluguer.mes==2 && x.dataAluguer.dia>29){
    
		return -1;
	}
	if(x.dataAluguer.ano%4==0 && (x.dataAluguer.ano%400==0 || x.dataAluguer.ano%100!=0)){
	
    }else{
    	if(x.dataAluguer.dia>28 && x.dataAluguer.mes==2){
    		
			return -1;
		}
	}
	if(x.dataAluguer.mes==7 ||x.dataAluguer.mes==8 || x.dataAluguer.mes==1 || x.dataAluguer.mes==3 || x.dataAluguer.mes==5|| x.dataAluguer.mes==10|| x.dataAluguer.mes==12){
		if(x.dataAluguer.dia>31){
			
			return -1;
		}
	}else{
		if(x.dataAluguer.dia>30){
		
			return -1;
		}
	}

	if(x.dataAluguer.hora>=recintos[x.idRecinto-1].horaF || recintos[x.idRecinto-1].horaF<fimX ){
		return -2;
	}
	if(x.dataAluguer.hora<recintos[x.idRecinto-1].horaA){
		return -2;
	}
	
	if(iniALista==NULL){
		
		return 0 ;
	}
	
	for(aux=iniALista;aux!=NULL;aux=aux->seguinte){
		
		if(aux->info.dataAluguer.dia==x.dataAluguer.dia && aux->info.dataAluguer.mes==x.dataAluguer.mes && aux->info.dataAluguer.ano==x.dataAluguer.ano && aux->info.idRecinto==x.idRecinto){
			fimAux=aux->info.dataAluguer.hora+aux->info.tempoA;
			if(aux->info.dataAluguer.hora<=x.dataAluguer.hora && x.dataAluguer.hora< fimAux){		
				return 2;
			}
			
			if(aux->info.dataAluguer.hora<fimX && fimX< fimAux){		
				return 2;
			}
		}
   }
		
	return 0;
}

//fazer a reservar
int reserva(ELEMENTOA **iniLista,ALUGUER newInfo){
	
	ELEMENTOA *novo=NULL,*aux=NULL;
	novo=(ELEMENTOA*)calloc(1,sizeof(ELEMENTOA));
	if(novo==NULL){
		printf("Out of memory \n");
		return -1;
	}
	novo->info=newInfo;
	novo->seguinte=NULL;
	if(*iniLista==NULL){
		*iniLista=novo;
	}else{
		
	
	aux=*iniLista;
	
	while(aux->seguinte!=NULL){
		aux=aux->seguinte;
	}
	aux->seguinte=novo;
	}
	return 0;
}

//Ativar reservar
void ativarReservar(ELEMENTOA **iniALista,RECINTO recintos[],int totalR,ELEMENTOC *iniCLista){
	ELEMENTOA *aux=NULL;
	int x=0,y=0,t=0,mdp=0,w=0;
	float total=0;
	TEMPO tm;
	system("cls");
	printf("**************************************\n");
	printf("**      \tATIVAR RESERVA\t    **\n");
	printf("**************************************\n");
	printf("\nIntroduza o numero do cliente:\n");
	printf("->");
	scanf("%i",&x);
	t=veriCli(iniCLista,x);
	if(t!=0){
		printf("\nNão existe esse cliente.\n");
		system("pause");
		return;
	}
	do{
		for(aux=(*iniALista);aux!=NULL;aux=aux->seguinte){
			if(aux->info.idCliente==x && aux->info.modoPagamento==0){
				system("cls");
				total=(aux->info.tempoA) * (recintos[aux->info.idRecinto-1].preco);
				aux->info.totalAPagar=total;
				printf("\nNome do recinto: %s.\nTipo: %s.\nData de aluguer: %.2i/%.2i/%.2i\nhora:%i \n Duração: %i\nTotal a pagar: %.2f euros\n\n",recintos[aux->info.idRecinto-1].nome,recintos[aux->info.idRecinto-1].tipo,aux->info.dataAluguer.dia,aux->info.dataAluguer.mes,aux->info.dataAluguer.ano,aux->info.dataAluguer.hora,aux->info.tempoA,aux->info.totalAPagar);
				printf("\n\n É esta reserva que pretende ativar ?\n1-SIM\n2-Não\n");
				scanf("%i",&w);
				if(w==1){
					system("cls");
					recintos[aux->info.idRecinto-1].totalGanho=recintos[aux->info.idRecinto-1].totalGanho+total;
					printf("Total a pagar: %.f",total);
					mdp=funcaoPagamentos();
					if(mdp==0){
						printf("\nPagamento cancelado.\n");
						system("pause");
						return;
					}
					aux->info.modoPagamento=mdp;
					tempoAtual(&tm);
					aux->info.dataPagamento=tm;
					return;
				}
			}
		
		}
		system("cls");
		if(w==2){
			printf("Não existe mais recintos reservados por esse cliente\n");
			system("pause");
			return;
		}else{
			printf("Esse cliente não tem reservar feita,fazer nova reserva?\n1-SIM\n2-Não.\n");
			scanf("%i",&w);
			if(w==1){
				y=reservarRecinto(iniALista,recintos,totalR,iniCLista);
				if(y==2){
				return;
				}
			}
	}
    }while(y==1);	
}

//Função pagamento
int funcaoPagamentos(){
	int x=0,i=0,y=0;
	
	do{
		printf("\n\t1-Transferencia.\n");
		printf("\t2-Dinheiro.\n");
		printf("\t3-MBaway.\n");
		printf("\t0-Cancelar.\n");
		printf("\t->");
		scanf("%i",&x);
		switch(x){
			case 1:{
				system("cls");
				printf("A estabelecer comunição.\n");
				for(i=0;i<10;i++){
					sleep(1);
					printf(".");
					fflush(stdout);
				}
				printf("\nTransfereincia feita com sucesso.\n");
				system("pause");
				return x;
				break;
			}
			case 2:printf("\n Pagamento concluido.\n");system("pause");return x;break;
			case 3:{
				printf("Introduza o numero de telemovel.\n");
				scanf("%i",&y);
				system("cls");
				printf("A aguardar comunição.\n");
				for(i=0;i<10;i++){
					sleep(1);
					printf(".");
					fflush(stdout);
				}
				printf("\n Pagamento concluido.\n");
				system("pause");
				return x;
				break;
			case 0:printf("Saindo.\n");system("pause");
			}
			default:{
			printf("Opção errada.\n");
			system("pause");
			break;
			}
		}
	}while(x!=0);
	return x;

}
void listarRecintosDiposniveisConc(RECINTO recintos[],int total){
	
	int i=0,y=0;
	char x[100];
	system("cls");
	printf("**********************************************\n");
	printf("**    \tRecintos livres por concelho\t    **\n");
	printf("**********************************************\n");
	printf("\nIntroduza o concelho.\n");
	printf("->");
	fflush(stdin);
	gets(x);
	system("cls");
	for(i=0;i<total;i++){
		if(recintos[i].status==0){
			if(strcmp(recintos[i].conc,x)==0){
			printf("\nCodigo Interno: %i\nNome: %s.\nConcelho: %s.\nTipo: %s.\nHora de Abertura: %ih.\nHora de Fecho; %ih.\nPreço: %.2feuros\nIluminação: %i\nStatus: %i\n\n\n",recintos[i].CI,recintos[i].nome,recintos[i].conc,recintos[i].tipo,recintos[i].horaA,recintos[i].horaF,recintos[i].preco,recintos[i].ilu,recintos[i].status);
			y=1;
			}	
		}
	}
	if(y==0){
		printf("\nNão existe nenhum recinto disponivel no concelho de %s \n",x);
	}
	system("pause");
}
void listarRecintosDisponiveisCoTi(RECINTO recintos[],int total){
	int i=0,y=0;
	char x[100],z[100];
	system("cls");
	printf("******************************************************\n");
	printf("**    \tRecintos livres por concelho de um tipo\t    **\n");
	printf("******************************************************\n");
	printf("\nIntroduza o concelho.\n");
	printf("->");
	fflush(stdin);
	gets(x);
	printf("\nIntroduza o tipo de recinto.\n");
	printf("->");
	fflush(stdin);
	gets(z);
	system("cls");
	
	for(i=0;i<total;i++){
		if(recintos[i].status==0){
			if(strcmp(x,recintos[i].conc)==0 && strcmp(z,recintos[i].tipo)==0){
			
				printf("\nCodigo Interno: %i\nNome: %s.\nConcelho: %s.\nTipo: %s.\nHora de Abertura: %ih.\nHora de Fecho; %ih.\nPreço: %.2feuros\nIluminação: %i\nStatus: %i\n\n\n",recintos[i].CI,recintos[i].nome,recintos[i].conc,recintos[i].tipo,recintos[i].horaA,recintos[i].horaF,recintos[i].preco,recintos[i].ilu,recintos[i].status);
				y=1;
	   		}
	
		}else{
			printf("\nNão existe nenhum recinto disponivel.\n");
			system("pause");
			return ;	
		}
		
		if(y==0){
			printf("Não existe recinto do tipo %s no concelho %s.\n",x,z);
			system("pause");
			return;
		}	
	}
	system("pause");
}

//Lista recintos disponivel numa determinada data e hora
void listarRecintosLivres(ELEMENTOA *iniALista,RECINTO recintos[],int totalR){
	ALUGUER x;
	ELEMENTOA *aux=NULL;
	int i=0,t=1,y=0;
	system("cls");
	printf("*******************************************************\n");
	printf("**     \tListar recintos livres numa data e hora\t     **\n");
	printf("*******************************************************\n");
	printf("\nIntroduza a data e hora que pretende(DD/MM/AA-HH).\n");
	printf("->");
	scanf("%i/%i/%i-%i",&x.dataAluguer.dia,&x.dataAluguer.mes,&x.dataAluguer.ano,&x.dataAluguer.hora);

	if(iniALista==NULL){
		for(i=0;i<totalR;i++){
			printf("\nCodigo Interno: %i\nNome: %s.\nConcelho: %s.\nTipo: %s.\nHora de Abertura: %ih.\nHora de Fecho; %ih.\nPreço: %.2feuros\nIluminação: %i\nStatus: %i\n\n\n",recintos[i].CI,recintos[i].nome,recintos[i].conc,recintos[i].tipo,recintos[i].horaA,recintos[i].horaF,recintos[i].preco,recintos[i].ilu,recintos[i].status);
		}
		system("pause");
		return;
	}
	system("cls");
	for(i=0;i<totalR;i++){
		if(recintos[i].status==0){
			x.idRecinto=recintos[i].CI;
			t=verificarAluguer(iniALista,x,recintos);	
			if(t==0){
				printf("\nCodigo Interno: %i\nNome: %s.\nConcelho: %s.\nTipo: %s.\nHora de Abertura: %ih.\nHora de Fecho; %ih.\nPreço: %.2feuros\nIluminação: %i\nStatus: %i\n\n\n",recintos[i].CI,recintos[i].nome,recintos[i].conc,recintos[i].tipo,recintos[i].horaA,recintos[i].horaF,recintos[i].preco,recintos[i].ilu,recintos[i].status);
				y=1;
			}
			if(t==-1){
				printf("\nIntroduziu uma data impossivel de reservar.\n");
				system("pause");
				return;
			}
		}	
	}
	
	if(y==0){
		printf("Não ha recintos disponiveis a essa hora.\n");
	}
	system("pause");
	
}

//Alugueres feitos por um cliente
void aluguerClientes(ELEMENTOA *iniALista,ELEMENTOC *iniCLista){
	ELEMENTOA *aux=NULL;
	int x=0,y=0,t=0;
	system("cls");
	printf("***********************************************\n");
	printf("**     \tAlugueres feitos por um cliente\t     **\n");
	printf("***********************************************\n");
	printf("\nIntroduza o numero de cliente.\n");
	printf("->");
	scanf("%i",&x);
	t=veriCli(iniCLista,x);
	
	if(t!=0){
		printf("Não existe esse cliente.\n");
		system("pause");
		return;
	}
	
	if(iniALista==NULL){
		printf("Nao existe nenhuma reserva no sistema.\n");
		system("pause");
		return;
	}
	system("cls");
	for(aux=iniALista;aux!=NULL;aux=aux->seguinte){
		if(x==aux->info.idCliente && aux->info.modoPagamento!=0){
			printf("\nID do recinto: %i.\nID do cliente: %i.\nData de aluguer: %.2i/%.2i/%.2i\nhora:%i \nDuração: %i\nData de pagamento: %.2i/%.2i/%.2i \nModo de pagamento: %i\nTotal a pagar: %.2f\n\n\n",aux->info.idRecinto,aux->info.idCliente,aux->info.dataAluguer.dia,aux->info.dataAluguer.mes,aux->info.dataAluguer.ano,aux->info.dataAluguer.hora,aux->info.tempoA,aux->info.dataPagamento.dia,aux->info.dataPagamento.mes,aux->info.dataPagamento.ano,aux->info.modoPagamento,aux->info.totalAPagar);
			y=1;
		}
		
	}
	if(y=!1){
		printf("O cliente nunca fez um aluguer.\n");
		system("pause");
		return;
	}
	system("pause");
	
}

//ALUGUERES DE DETERMINADO
void listarDadosAlugueresPorRecinto(ELEMENTOA *iniALista,RECINTO recintos[],int totalR,ELEMENTOC *iniCLista){
	ELEMENTOC *AUX=NULL;	
	ELEMENTOA *aux=NULL;
	int t=0,x=0,y=0;
	system("cls");
	printf("***********************************************\n");
	printf("**     \tDados de aluguer de um recinto\t     **\n");
	printf("***********************************************\n");
	printf("\nIntroduza o numero do recinto.\n");
	printf("->");
	scanf("%i",&x);
	
	t=veriReci(recintos,x,totalR);
	if(t==-1){
		system("cls");
		printf("Não existe esse recinto.\n");
		system("pause");
		return;
	}
	if(iniALista==NULL){
		printf("Nao existe nenhuma reserva no sistema.\n");
		system("pause");
		return;
	}
	system("cls");
	for(aux=iniALista;aux!=NULL;aux=aux->seguinte){
		if(aux->info.idRecinto==x && aux->info.modoPagamento!=0){
			for(AUX=iniCLista;AUX!=NULL;AUX=AUX->seguinte){
				if(AUX->info.num==aux->info.idCliente){
					printf("\nNome Cliente: %s\npreço pago: %.2f\nPeriodo de tempo alugado: %ih\n\n",AUX->info.nome,aux->info.totalAPagar,aux->info.tempoA);
					y=1;	
				}
			}		
		}
	}
		if(y=!1){
		printf("\nO recinto nunca foi um alugado.\n");
		system("pause");
		return;
	}
	system("pause");
}
void listarReservasAtivas(ELEMENTOA *iniALista){
	int y=0;
	ELEMENTOA *aux=NULL;
	TEMPO x;
	system("cls");
	printf("*****************************************************\n");
	printf("**     \tReservas ativas ainda não realizadas\t   **\n");
	printf("*****************************************************\n");
	if(iniALista==NULL){
		printf("Ainda não foram feitas reservas.\n");
		system("pause");
		return;
	}
	tempoAtual(&x);
	for(aux=iniALista;aux!=NULL;aux=aux->seguinte){
		y=0;
		
		if(aux->info.modoPagamento==0){
			y=1;
		}
		
		if(aux->info.dataAluguer.ano<x.ano){
			y=1;
		}
		if(aux->info.dataAluguer.ano==x.ano && aux->info.dataAluguer.mes<x.mes){
			y=1;
		}
		if(aux->info.dataAluguer.ano==x.ano && aux->info.dataAluguer.mes==x.mes && aux->info.dataAluguer.dia<x.dia){
			y=1;
		}
		
		if(aux->info.dataAluguer.ano==x.ano && aux->info.dataAluguer.mes==x.mes && aux->info.dataAluguer.dia==x.dia && aux->info.dataAluguer.hora<x.hora){
			y=1;
		}
		
		
		if(y!=1){
			printf("\nID do recinto: %i.\nID do cliente: %i.\nData de aluguer: %.2i/%.2i/%.2i\nhora:%i \n Duração: %i\nData de pagamento: %.2i/%.2i/%.2i \n Modo de pagamento: %i\nTotal a pago: %.2f\n\n",aux->info.idRecinto,aux->info.idCliente,aux->info.dataAluguer.dia,aux->info.dataAluguer.mes,aux->info.dataAluguer.ano,aux->info.dataAluguer.hora,aux->info.tempoA,aux->info.dataPagamento.dia,aux->info.dataPagamento.mes,aux->info.dataPagamento.ano,aux->info.modoPagamento,aux->info.totalAPagar);
			
		}
	}
	system("pause");
}
void listarTotalPorRecinto(ELEMENTOA *iniALista,RECINTO recintos[],int totalR){
	int i=0;
	system("cls");
	printf("*****************************************************\n");
	printf("**     \tTotal recibido por cada recintos\t   **\n");
	printf("*****************************************************\n");
	
	if(iniALista==NULL){
		printf("Não existe reservas feitas.\n");
		system("pause");
		return;
	}
	for(i=0;i<totalR;i++){
		
		printf("\nCodigo interno do recinto: %i\nNome do recinto: %s\nTotal faturado: %.2feuros\n\n",recintos[i].CI,recintos[i].nome,recintos[i].totalGanho);
	}
	system("pause");
	return;
}
//Fechos
int fechoDiario(ELEMENTOA *iniALista){
	
	ELEMENTOA *aux=NULL;
	FILE *fp=NULL;
	TEMPO x;
	float total=0;
	char nomeFicheiro[50];
	int y=0,t=0;
	
	system("cls");
	printf("********************************************************\n");
	printf("**        \t\tFecho diario\t\t      **\n");
	printf("********************************************************\n");
	
	if(iniALista==NULL){
		printf("Nao foi feito qualquer reserva.\n");
		system("pause");
		return -1;
	}
	
	printf("\nIntroduza o dia que quer o relatorio(DD/MM/AAAA)\n");
	printf("->");
	scanf("%i/%i/%i",&x.dia,&x.mes,&x.ano);
	
	sprintf(nomeFicheiro,"RelatorioDia%.2imes%.2iano%.2i.txt",x.dia,x.mes,x.ano);
	fp=fopen(nomeFicheiro,"w");
	if(fp==NULL){
		printf("Erro ao abrir o ficheiro de fecho diario\n");
		system("pause");
		return -1;
	}
	
	fprintf(fp,"Reservas feitas neste dia(ainda não ativas/pagas)\n\n");
	
	for(aux=iniALista;aux!=NULL;aux=aux->seguinte){
			if(aux->info.dataReserva.dia==x.dia && aux->info.dataReserva.mes==x.mes && aux->info.dataReserva.ano==x.ano && aux->info.modoPagamento==0){
			fprintf(fp,"ID do recinto: %i\nDia de Aluguer: %.2i/%.2i/%.2i\n\n",aux->info.idRecinto,aux->info.dataAluguer.dia,aux->info.dataAluguer.mes,aux->info.dataAluguer.ano);
			y=1;
			}	
	}
	fprintf(fp,"\n\n--------------------------\nAlgueres feitos neste dia(reservas pagas)\n\n");
	for(aux=iniALista;aux!=NULL;aux=aux->seguinte){
			if(aux->info.dataReserva.dia==x.dia && aux->info.dataReserva.mes==x.mes && aux->info.dataReserva.ano==x.ano && aux->info.modoPagamento!=0){
			fprintf(fp,"\nID do recinto: %i\nDia de Aluguer: %.2i/%.2i/%.2i\n\n",aux->info.idRecinto,aux->info.dataAluguer.dia,aux->info.dataAluguer.mes,aux->info.dataAluguer.ano);
			total=aux->info.totalAPagar+total;
			t=1;
			}	
	}
	if(t==0 && y==0){
		fprintf(fp,"Não houve reservas nesse dia.\n");
		fclose(fp);
		printf("\nRelatorio feito com sucesso.\n");
		system("pause");
		return -1;
	}
	fprintf(fp,"\n\n--------------------------\nTotal faturado neste dia %.2feuros",total);
	fclose(fp);
	printf("\nRelatorio feito com sucesso.\n");
	system("pause");
	return 0;
}
int fechoMensal(ELEMENTOA *iniALista){
	ELEMENTOA *aux=NULL;
	FILE *fp=NULL;
	TEMPO x;
	int t=0,y=0;
	float total=0;
	char nomeFicheiro[50];
	system("cls");
	printf("********************************************************\n");
	printf("**        \t\tFecho mensal\t\t      **\n");
	printf("********************************************************\n");
	printf("\nIntroduza o mes(MM/AAAA)\n");
	printf("->");
	scanf("%i/%i",&x.mes,&x.ano);
	
	sprintf(nomeFicheiro,"RelatorioMes%.2iano%.2i.txt",x.mes,x.ano);
	fp=fopen(nomeFicheiro,"w");
	if(fp==NULL){
		printf("Erro ao abrir o ficheiro de fecho mensal\n");
		return -1;
	}
	
	fprintf(fp,"Reservas feitas neste mes(ainda não ativas/pagas)\n\n");
	for(aux=iniALista;aux!=NULL;aux=aux->seguinte){
			if(aux->info.dataReserva.mes==x.mes && aux->info.dataReserva.ano==x.ano && aux->info.modoPagamento==0){
			fprintf(fp,"ID do recinto: %i\nDia de Aluguer: %.2i/%.2i/%.2i\n\n",aux->info.idRecinto,aux->info.dataAluguer.dia,aux->info.dataAluguer.mes,aux->info.dataAluguer.ano);
			y=1;
			}	
	}
	fprintf(fp,"\n\n--------------------------\nAlgueres feitos neste dia(reservas pagas)\n\n");
	for(aux=iniALista;aux!=NULL;aux=aux->seguinte){
			if(aux->info.dataReserva.mes==x.mes && aux->info.dataReserva.ano==x.ano && aux->info.modoPagamento!=0){
			fprintf(fp,"\nID do recinto: %i\nDia de Aluguer: %.2i/%.2i/%.2i\n\n",aux->info.idRecinto,aux->info.dataAluguer.dia,aux->info.dataAluguer.mes,aux->info.dataAluguer.ano);
			total=aux->info.totalAPagar+total;
			t=1;
			}	
	}
	if(t==0 && y==0){
		fprintf(fp,"Não houve reservas nesse mes.\n");
		fclose(fp);
		printf("Relatorio feito com sucesso.\n");
		system("pause");
		return -1;
	}
	fprintf(fp,"\n\n--------------------------\nTotal faturado neste mes %.2feuros",total);
	fclose(fp);
	printf("Relatorio feito com sucesso.\n");
	system("pause");
	return 0;	
}
int fechoAnual(ELEMENTOA *iniALista){
	ELEMENTOA *aux=NULL;
	FILE *fp=NULL;
	TEMPO x;
	int t=0,y=0;
	float total=0;
	char nomeFicheiro[50];
	float IVA=0;
	int T1=0,T2=0,T3=0,T4=0,T5=0,T6=0,T7=0,T8=0,T9=0,T10=0,T11=0,T12=0;
	float R1=0,R2=0,R3=0,R4=0,R5=0,R6=0,R7=0,R8=0,R9=0,R10=0,R11=0,R12=0;
	system("cls");
	printf("********************************************************\n");
	printf("**        \t\tFecho anual\t\t      **\n");
	printf("********************************************************\n");
	
	if(iniALista==NULL){
		printf("\nNao foi feito qualquer reserva.\n");
		system("pause");
		return -1;
	}
	
	printf("\nIntroduza o ano(AAAA)\n");
	printf("->");
	scanf("%i",&x.ano);
		sprintf(nomeFicheiro,"RelatorioAno%.2i.txt",x.ano);
	IVA=calcularIVA(iniALista,x.ano);
	fp=fopen(nomeFicheiro,"w");
	if(fp==NULL){
		printf("Erro ao abrir o ficheiro de fecho mensal\n");
		return -1;
	}
	
	for(aux=iniALista;aux!=NULL;aux=aux->seguinte){
		
		if(aux->info.dataPagamento.mes==1 && aux->info.dataPagamento.ano==x.ano && aux->info.modoPagamento!=0){
			
			T1++;
			R1+=aux->info.totalAPagar;	
		}
		if(aux->info.dataPagamento.mes==2 && aux->info.dataPagamento.ano==x.ano && aux->info.modoPagamento!=0){
			T2++;
			R2+=aux->info.totalAPagar;	
		}
		if(aux->info.dataPagamento.mes==3 && aux->info.dataPagamento.ano==x.ano && aux->info.modoPagamento!=0){
			T3++;
			R3+=aux->info.totalAPagar;	
		}
		if(aux->info.dataPagamento.mes==4 && aux->info.dataPagamento.ano==x.ano && aux->info.modoPagamento!=0){
			T4++;
			R4+=aux->info.totalAPagar;	
		}
		if(aux->info.dataPagamento.mes==5 && aux->info.dataPagamento.ano==x.ano && aux->info.modoPagamento!=0){
			T5++;
			R5+=aux->info.totalAPagar;	
		}
		if(aux->info.dataPagamento.mes==6 && aux->info.dataPagamento.ano==x.ano && aux->info.modoPagamento!=0){
			T6++;
			R6+=aux->info.totalAPagar;	
		}
		if(aux->info.dataPagamento.mes==7 && aux->info.dataPagamento.ano==x.ano && aux->info.modoPagamento!=0){
			T7++;
			R7+=aux->info.totalAPagar;	
		}
		if(aux->info.dataPagamento.mes==8 && aux->info.dataPagamento.ano==x.ano && aux->info.modoPagamento!=0){
			T8++;
			R8+=aux->info.totalAPagar;	
		}
		if(aux->info.dataPagamento.mes==9 && aux->info.dataPagamento.ano==x.ano && aux->info.modoPagamento!=0){
			T9++;
			R9+=aux->info.totalAPagar;	
		}
		if(aux->info.dataPagamento.mes==10 && aux->info.dataPagamento.ano==x.ano && aux->info.modoPagamento!=0){
			T10++;
			R10+=aux->info.totalAPagar;	
		}
		if(aux->info.dataPagamento.mes==11 && aux->info.dataPagamento.ano==x.ano && aux->info.modoPagamento!=0){
			T11++;
			R11+=aux->info.totalAPagar;	
		}
		if(aux->info.dataPagamento.mes==12 && aux->info.dataPagamento.ano==x.ano && aux->info.modoPagamento!=0){
			T12++;
			R12+=aux->info.totalAPagar;	
		}
	}
	total=R1+R2+R3+R4+R5+R6+R7+R8+R9+R10+R11+R12;
	fprintf(fp,"Janeiro\nTotal de recintos alugados: %i\nTotal faturado: %.2f\n\nFevereiro\nTotal de recintos alugados: %i\nTotal faturado: %.2f",T1,R1,T2,R2);
	fprintf(fp,"\n\nMarço\nTotal de recintos alugados: %i\nTotal faturado: %.2f\n\nAbril\nTotal de recintos alugados: %i\nTotal faturado: %.2f",T3,R3,T4,R4);
	fprintf(fp,"\n\nMaio\nTotal de recintos alugados: %i\nTotal faturado: %.2f\n\nJulho\nTotal de recintos alugados: %i\nTotal faturado: %.2f",T5,R5,T6,R6);
	fprintf(fp,"\n\nJulho\nTotal de recintos alugados: %i\nTotal faturado: %.2f\n\nAgosto\nTotal de recintos alugados: %i\nTotal faturado: %.2f",T7,R7,T8,R8);
	fprintf(fp,"\n\nSetembro\nTotal de recintos alugados: %i\nTotal faturado: %.2f\n\nOutobro\nTotal de recintos alugados: %i\nTotal faturado: %.2f",T9,R9,T10,R10);
	fprintf(fp,"\n\nNovembro\nTotal de recintos alugados: %i\nTotal faturado: %.2f\n\nDezembro\nTotal de recintos alugados: %i\nTotal faturado: %.2f",T11,R11,T12,R12);			
	fprintf(fp,"\n\nTotal anual faturado: %.2f\n\nValor a pagar em IVA: %.2f",total,IVA);
	fclose(fp);
	printf("Relatorio anual feito com sucesso.\n");
	system("pause");
	return 0;
}

//apagar reservas passadas nao ativas
int reservaInativaPassada(ELEMENTOA **iniALista){
	
	ELEMENTOA *aux=NULL,*ant=NULL;
	int t=0;
	if(*iniALista==NULL){
		return 0;
	}
	
	aux=*iniALista;
	for(aux=*iniALista;aux!=NULL;aux=aux->seguinte){
		
		while(aux!=NULL && verificarValidade(aux->info.dataAluguer)!=-1){
			ant=aux;
			aux=aux->seguinte;
		}
		if(aux==NULL){
			return 0;
		}		
		if(ant==NULL){
			*iniALista=aux->seguinte;
		}else{
			ant->seguinte=aux->seguinte;
		}
		free(aux); 
		t=t+1;		
	}
	return t;	
}

//Verificar validade;
int verificarValidade(TEMPO x){
		
	TEMPO temp;
	tempoAtual(&temp);
	if(x.ano<temp.ano){
		return -1;
	}
	if(x.ano==temp.ano && x.mes<temp.mes){
		return -1;
	}
	if(x.ano==temp.ano && x.mes==temp.mes && x.dia<temp.dia){
		return -1;
	}
	if(x.ano==temp.ano && x.mes==temp.mes && x.dia==temp.dia && x.hora<=temp.hora){
		
		return -1;
	}

	return 0;
}

//Calcular IVA
float calcularIVA(ELEMENTOA *iniALista,int x){
		ELEMENTOA *aux=NULL;
		float iva=0;
		float total=0;
		if(iniALista==NULL){
		
		printf("Nao foi feito qualquer reserva.\n");
		system("pause");
		return -1;
		}
		
		for(aux=iniALista;aux!=NULL;aux=aux->seguinte){
			
			if(aux->info.modoPagamento!=0 && aux->info.dataPagamento.ano==x){
				total=total+aux->info.totalAPagar;
				
			}
		}
		iva=(float)VALORIVA*total;
		return iva;
}

//gravar e ler alugeuress
int lerAlugueres(ELEMENTOA **iniLista){
	ALUGUER info;
	int res=0,lidos=0;
	
	FILE *fp=NULL;
	fp=fopen("Alugueres.dab","rb");
	
	if(fp==NULL){
		printf("Erro ao abrir o ficheiro\n");
	return -1;
	}
	
		while(!feof(fp)){
			res=fread(&info,sizeof(ALUGUER),1,fp);
			lidos=lidos+1;
			if(res){
			//função inserir
			reserva(iniLista,info);
			}
		}
	fclose(fp);
	return lidos-1;
}
int gravarATexto(ELEMENTOA *iniLista){
 	ELEMENTOA *aux=NULL;
	FILE *fp=NULL;
	fp=fopen("ReservasFeitas.txt","w");
	
	if(fp==NULL){
		printf("Erro ao abrir o ficheiro de texto\n");
		return -1;
	}
	
	for(aux=iniLista;aux!=NULL;aux=aux->seguinte){
		
	fprintf(fp,"\nID do recinto: %i.\nID do cliente: %i.\nData de aluguer: %.2i/%.2i/%.2i\nhora:%i \n Duração: %i\nData de pagamento: %.2i/%.2i/%.2i \n Modo de pagamento: %i\nTotal a pagar: %.2f\n\n-----------------------",aux->info.idRecinto,aux->info.idCliente,aux->info.dataAluguer.dia,aux->info.dataAluguer.mes,aux->info.dataAluguer.ano,aux->info.dataAluguer.hora,aux->info.tempoA,aux->info.dataPagamento.dia,aux->info.dataPagamento.mes,aux->info.dataPagamento.ano,aux->info.modoPagamento,aux->info.totalAPagar);
	
	}
	fclose(fp);
	return 0;	
}
int gravarAlugueres(ELEMENTOA *iniLista){
	
	ELEMENTOA *aux=NULL;
	FILE *fp=NULL;
	fp=fopen("Alugueres.dab","wb");
	
	if(fp==NULL){
		printf("Erro ao abrir o ficheiro binario\n");
	return -1;
	}
	
	for(aux=iniLista;aux!=NULL;aux=aux->seguinte){
		fwrite(&aux->info,sizeof(ALUGUER),1,fp);
	}
	fclose(fp);
	return 0;
}	
void limparAlugueres(ELEMENTOA **iniLista){
	
	ELEMENTOA *aux=NULL, *proximo=NULL;
	aux=*iniLista;
	*iniLista=NULL;
	while(aux!=NULL){
		proximo=aux;
		free(aux);
		aux=proximo->seguinte;
	}
}
