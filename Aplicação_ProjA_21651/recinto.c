#include "recintos.h"
//Alterar recintos
void alterarPreco(RECINTO recintos[],int num){
	printf("Introduza o novo preço do recinto.\n");
	printf("->");
	scanf("%f",&recintos[num].preco);
	printf("\nPreço alterado com sucesso.\n");
	system("pause");
}
void alterarHa(RECINTO recintos[],int num){
	printf("Introduza a nova hora de abertura do recinto.\n");
	printf("->");
	scanf("%i",&recintos[num].horaA);
	printf("\nHora de abertura alterada com sucesso.\n");
	system("pause");
}
void alterarHf(RECINTO recintos[],int num){
	printf("Introduza a nova hora de fecho do recinto.\n");
	printf("->");
	scanf("%i",&recintos[num].horaF);
	printf("\nHora de fecho alterada com sucesso.\n");
	system("pause");	
}
void alterarRecinto(RECINTO recintos[],int total){
	int x=0,y=0,i=0,z=0;
	system("cls");
	printf("*********************************************\n");
	printf("**  \tALTERAR INFORMÇÃO DO RECINTO.      **\n");	
	printf("*********************************************\n\n");
	printf("\nIntroduza o numero do recinto a alterar.\n");
	printf("->");
	scanf("%i",&x);
	for(i=0;i<total;i++){
		if(recintos[i].CI==x){
			printf("\nCodigo Interno: %i\nNome: %s.\nConcelho: %s.\nTipo: %s.\nHora de Abertura: %ih.\nHora de Fecho; %ih.\nPreço: %.2feuros\nIluminação: %i\nStatus: %i\n\n\n",recintos[i].CI,recintos[i].nome,recintos[i].conc,recintos[i].tipo,recintos[i].horaA,recintos[i].horaF,recintos[i].preco,recintos[i].ilu,recintos[i].status);
			system("pause");
			z=i;
			y=1;
		}
	}
	if(y==0){
		printf("Não existe esse recinto.\n");
		system("pause");
		return;
	}
	system("cls");
	printf("1-Alterar preço\n");
	printf("2-Alerar hora de abertura.\n");
	printf("3-Alterar hora de fecho.\n");
	printf("0-Cancelar\n");
	printf("->");
	scanf("%i",&x);
	
		switch(x){
			case 1:alterarPreco(recintos,z);break;
			case 2:alterarHa(recintos,z);break;
			case 3:alterarHf(recintos,z);break;
			case 0:return;
		}
	
}

//Adicionar recintos
void infoRecinto(RECINTO recintos[],int *total){
		int tot=(*total);
	
		if(tot<=MAX){
			system("cls");
			printf("*************************************\n");
			printf("**  \tINFORMÇÃO DO RECINTO.      **\n");
			printf("*************************************\n");
			printf("\nIntroduza nome do recinto.\n");
			printf("->");
			fflush(stdin);
			gets(recintos[tot].nome);
			printf("\nIntroduza o tipo de recinto.\n");
			printf("->");
			fflush(stdin);
			gets(recintos[tot].tipo);
			printf("\nIntroduza o concelho.\n");
			printf("->");
			fflush(stdin);
			gets(recintos[tot].conc);
			printf("\nIntroduza a hora de abertura.\n");
			printf("->");
			scanf("%i",&recintos[tot].horaA);
			printf("\nIntroduza a hora de fecho.\n");
			printf("->");
			scanf("%i",&recintos[tot].horaF);
			printf("\nSe tiver iluminação?\n1-SIM.\n0-Não.\n");
			printf("->");
			scanf("%i",&recintos[tot].ilu);	
			printf("\nIntroduza o preço por hora.\n");
			printf("->");
			scanf("%f",&recintos[tot].preco);
			printf("\nIntroduza o status do recinto.\n1-Interdito.\n0-Livre.\n");
			printf("->");
			scanf("%i",&recintos[tot].status);
			(*total)=(*total)+1;
			recintos[tot].CI=(*total);
			printf("\nRecinto adicionado com sucesoo.\n");
			system ("pause");
		}else{
			printf("Ja tem o maximo de recintos registados.\n");
			system("pause");
			
		}
			
}

//Inativar ou ativar recintos
void stats(RECINTO recintos[],int total){
	int x=0,i=0,y=0;
	system("cls");
	printf("****************************************\n");		
	printf("**  \tInativar/ativar recinto.      **\n");
	printf("****************************************\n");
	printf("\nIntroduza o numero do recinto.\n");
	scanf("%i",&x);
	
	for(i=0;i<total;i++){
		if(recintos[i].CI==x){
			y=1;
			if(recintos[i].status==0){
				printf("Prentede inativar o recinto?\n");
				printf("1-Sim\n2-Não\n");
				printf("->");
				scanf("%i",&x);
					if(x==1){
						recintos[i].status=1;
						printf("Recinto inativado com sucesso.\n");
						system("pause");
						return ;
					}else{
						printf("Recinto continua livre.\n");
						system("pause");
						return;
					}
		
			}else{
				printf("Prentede ativar o recinto?\n");
				printf("1-Sim\n2-Não\n");
				printf("->");
				scanf("%i",&x);
				if(x==1){
					recintos[i].status=0;
					printf("Recinto ativado com sucesso.\n");
					system("pause");
					return;
				}else{
					printf("Recinto continua interdito.\n");
					return ;
				}
			}
		}
	}
	if(y==0){
		printf("Não existe esse recinto.\n");
		system("pause");
	}
}

//Listar por ordem de preço
void ordenarPrecoDecres(RECINTO recintos[],int total){
	
	int i=0,j=0,max=0;
	RECINTO aux;
	for(i=0;i<total-1;i++){
 	 	max=i;
		for(j=i;j<total;j++){
 			if(recintos[j].preco>recintos[max].preco){
 				max=j;
			 }	
		 }
		 if(max!=i){
		 	aux=recintos[max];
			 recintos[max]=recintos[i];
			 recintos[i]=aux;
		 }	 
	 }
}
void listarPreco(RECINTO recintos[],int total){
	int i=0;
	system("cls");
	for(i=0;i<total;i++){
		printf("\nCodigo Interno: %i\nNome: %s.\nConcelho: %s.\nTipo: %s.\nHora de Abertura: %ih.\nHora de Fecho; %ih.\nPreço: %.2feuros\nIluminação: %i\nStatus: %i\n\n\n",recintos[i].CI,recintos[i].nome,recintos[i].conc,recintos[i].tipo,recintos[i].horaA,recintos[i].horaF,recintos[i].preco,recintos[i].ilu,recintos[i].status);
	}
	system("pause");
}

//Listar por tipo
void listarTipo(RECINTO recintos [],int total){
	int i=0,y=0;
	char x[100];
	system("cls");
	printf("Introduza o tipo de recinto.\n");
	printf("->");
	fflush(stdin);
	gets(x);
	system("cls");
	for(i=0;i<total;i++){
		if(strcmp(x,recintos[i].tipo)==0){
			printf("Codigo Interno: %i\nNome: %s.\nConcelho: %s.\nTipo: %s.\nHora de Abertura: %ih.\nHora de Fecho; %ih.\nPreço: %.2feuros\nIluminação: %i\nStatus: %i\n\n\n",recintos[i].CI,recintos[i].nome,recintos[i].conc,recintos[i].tipo,recintos[i].horaA,recintos[i].horaF,recintos[i].preco,recintos[i].ilu,recintos[i].status);
	   		y=1;
	   }
	}
	if(y==0){
		printf("Não existe recinto do tipo %s.\n",x);
	}
	system("pause");
}

//Listar por concelho
void listarConce(RECINTO recintos[],int total){
	
	int i=0,y=0;
	char x[100];
	system("cls");
	printf("Introduza o concelho.\n");
	printf("->");
	fflush(stdin);
	gets(x);
	system("cls");
	for(i=0;i<total;i++){
		if(strcmp(recintos[i].conc,x)==0){
			printf("Codigo Interno: %i\nNome: %s.\nConcelho: %s.\nTipo: %s.\nHora de Abertura: %ih.\nHora de Fecho; %ih.\nPreço: %.2feuros\nIluminação: %i\nStatus: %i\n\n\n",recintos[i].CI,recintos[i].nome,recintos[i].conc,recintos[i].tipo,recintos[i].horaA,recintos[i].horaF,recintos[i].preco,recintos[i].ilu,recintos[i].status);
			y=1;
		}
	
	}
	if(y==0){
		printf("Não existe nenhum recinto no concelho de %s \n",x);
	}
	system("pause");
}

//Listar po conselho e tipo
void listaCoTi(RECINTO recintos[],int total){
	int i=0,y=0;
	char x[100],z[100];
	system("cls");
	printf("Introduza o concelho.\n");
	printf("->");
	fflush(stdin);
	gets(x);
	printf("Introduza o tipo de recinto.\n");
	printf("->");
	fflush(stdin);
	gets(z);
	system("cls");
	for(i=0;i<total;i++){
		if(strcmp(x,recintos[i].conc)==0 && strcmp(z,recintos[i].tipo)==0){	
			printf("Codigo Interno: %i\nNome: %s.\nConcelho: %s.\nTipo: %s.\nHora de Abertura: %ih.\nHora de Fecho; %ih.\nPreço: %.2feuros\nIluminação: %i\nStatus: %i\n\n\n",recintos[i].CI,recintos[i].nome,recintos[i].conc,recintos[i].tipo,recintos[i].horaA,recintos[i].horaF,recintos[i].preco,recintos[i].ilu,recintos[i].status);
			y=1;
	   }
	}
	if(y==0){
		printf("Não existe recinto do tipo %s no concelho %s.\n",x,z);
	}
	system("pause");
}

//Listar por preço
void listarIntPre(RECINTO recintos[],int total){
	
	int i=0,y=0;
	float x=0,z=0;
	system("cls");
	printf("Introduza o preço mínimo.\n");
	printf("->");
	scanf("%f",&x);
	printf("Introduza o preço maximo.\n");
	printf("->");
	scanf("%f",&z);
	
	system("cls");
	for(i=0;i<total;i++){
		if(x<=recintos[i].preco &&recintos[i].preco<=z){
			printf("Codigo Interno: %i\nNome: %s.\nConcelho: %s.\nTipo: %s.\nHora de Abertura: %ih.\nHora de Fecho; %ih.\nPreço: %.2feuros\nIluminação: %i\nStatus: %i\n\n\n",recintos[i].CI,recintos[i].nome,recintos[i].conc,recintos[i].tipo,recintos[i].horaA,recintos[i].horaF,recintos[i].preco,recintos[i].ilu,recintos[i].status);
			y=1;
	   }
	}
	if(y==0){
		printf("Não existe recinto do tipo %s no concelho %s.\n",x,z);
	}
	system("pause");
}

//verificar se existe recinto pelo numero
int veriReci(RECINTO recintos[],int num,int total){
	int i=0;
	for(i=0;i<total;i++){
		if(recintos[i].CI==num){
			if(recintos[i].status==0){
			return 0;	
			}
			return 2;
		}
	}
	return -1;
}

//ler e gravar em ficheiros
int lerRecintos(RECINTO recintos[],int *total){
	FILE *fp=NULL;
	int x=0;
	fp=fopen("recintos.dab","rb");
	
	if(fp==NULL){
		printf("Erro ao abrir o ficheiro.\n");
		return -1;
	}
	
	fread(total,sizeof(int),1,fp);
	fread(&recintos[0],sizeof(RECINTO),(*total),fp);
	fclose(fp);	
	return 0;
	
}
int gravarRecintos(RECINTO recintos[],int total){
	
	FILE *fp=NULL;
	
	fp=fopen("recintos.dab","wb");
	
	if(fp==NULL){
		printf("Erro ao abrir o ficheiro.\n");
		return -1;
	}
	fwrite(&total,sizeof(int),1,fp);
	fwrite(&recintos[0],sizeof(RECINTO),total,fp);
	fclose(fp);
	return 0;	
}
int gravarRecintoTexto(RECINTO recintos[],int total){
	FILE *fp=NULL;
	int i=0;
	fp=fopen("recintosRegistados.txt","w");
	
	if(fp==NULL){
		printf("Erro ao abrir o ficheiro.\n");
		return -1;
	}
	
	for(i=0;i<total;i++){
		fprintf(fp,"Codigo Interno: %i\nNome: %s.\nConcelho: %s.\nTipo: %s.\nHora de Abertura: %ih.\nHora de Fecho; %ih.\nPreço: %.2feuros\nIluminação: %i\nStatus: %i\nTotal ganho: %.2f\n\n---------------------------------------------------------\n\n",recintos[i].CI,recintos[i].nome,recintos[i].conc,recintos[i].tipo,recintos[i].horaA,recintos[i].horaF,recintos[i].preco,recintos[i].ilu,recintos[i].status,recintos[i].totalGanho);
		
	}
	fclose(fp);
	return 0;
	}
	

