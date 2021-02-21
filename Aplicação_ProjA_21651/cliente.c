#include "cliente.h"



//Adicionar cliente.

void infoCliente(ELEMENTOC *iniLista,CLIENTE *newInfo,int *total,int *totalR){
	int y=0;
	int x=0;
	ELEMENTOC *AUX=NULL;
	system("cls");
	printf("*************************************\n");
	printf("**  \tINFORMÇÃO DO CLIENTE.      **\n");
	printf("*************************************\n");
	printf("\nNome do cliente.\n");
	printf("->");
	fflush(stdin);
	gets(newInfo->nome);
	printf("\nMorada do cliente.\n");
	printf("->");
	fflush(stdin);
	gets(newInfo->morada);
	printf("\nLocalidade do cliente.\n");
	printf("->");
	fflush(stdin);
	gets(newInfo->localidade);
	printf("\nEmail do cliente.\n");
	printf("->");
	fflush(stdin);
	gets(newInfo->email);
	//verifica se ja existe esse email registado
	if(iniLista==NULL){
		
	}else{
		for(AUX=iniLista;AUX!=NULL;AUX=AUX->seguinte){
			if(strcmp(newInfo->email,AUX->info.email)==0){
				printf("Ja existe um cliente com esse email.\n");
				system("pause");
				return;
			}
		}
	}
	fflush(stdin);
	printf("\nNIF do cliente.\n");
	printf("->");
	scanf("%i",&newInfo->nif);
	//Verificar se ja existe cliente com esse NIF
	if(iniLista==NULL){
		
	}else{
		for(AUX=iniLista;AUX!=NULL;AUX=AUX->seguinte){
			if(x==AUX->info.nif){
				printf("Ja existe um cliente com esse NIF.\n");
				system("pause");
				return;
			}
		}
	}
	printf("\nNumero de telemovel do cliente.\n");
	printf("->");
	scanf("%i",&newInfo->tele);
	if(iniLista==NULL){
		
	}else{
		for(AUX=iniLista;AUX!=NULL;AUX=AUX->seguinte){
			if(newInfo->tele==AUX->info.tele){
				printf("Ja existe um cliente com esse numero de telemovel.\n");
				system("pause");
				return;
			}
		}
	}
	printf("\nNumero de cartão de cidadão do cliente.\n");
	printf("->");
	scanf("%i",&newInfo->nCC);
	if(iniLista==NULL){
		
	}else{
		for(AUX=iniLista;AUX!=NULL;AUX=AUX->seguinte){
			if(newInfo->nCC==AUX->info.nCC){
				printf("Ja existe um cliente com esse numero de cartão de cidadão.\n");
				system("pause");
				return;
			}
		}
	}
	(*total)=(*total)+1;
	(*totalR)=(*totalR)+1;
	newInfo->num=(*total);
	printf("\n Cliente adicionado com sucesso.\n");
	sleep(2);
}
int inserirCliente(ELEMENTOC **iniLista,CLIENTE newInfo){
	
	ELEMENTOC *novo=NULL,*aux=NULL;
	novo=(ELEMENTOC*)calloc(1,sizeof(ELEMENTOC));
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
	
	
}
	
//Alterar informação de cliente

void alterarInfo(ELEMENTOC **iniLista){
	int x=0,y=0,z=0;
	ELEMENTOC *aux=NULL;

	do{
		system("cls");
		printf("1-Alterar e-mail.\n");
		printf("2-Alterar numero de telefone.\n");
		printf("3-Alterar morada.\n");
		printf("0-Sair.\n");
		printf("->");
		scanf("%i",&x);
		switch(x){
			case 1:{
				printf("Introduza o NIF do cliente.\n");
				printf("->");
				scanf("%i",&y);			
				if(*iniLista==NULL){
					printf("Não existe clientes.\n");
						system("pause");
					return;
				}else{
				for(aux=(*iniLista);aux!=NULL;aux=aux->seguinte){
					if(y==aux->info.nif){
						system("cls");
						printf("Num:%i\nNome: %s\nMorada: %s\nLocalidade: %s\nE-mail: %s\nNIF: %i\nNCC: %i\nTelemovel: %i\n\n\n\n ",aux->info.num,aux->info.nome,aux->info.morada,aux->info.localidade,aux->info.email,aux->info.nif,aux->info.nCC,aux->info.tele);
						system("pause");
						z=1;
						system("cls");
						fflush(stdin);
						printf("Introduza o e-mail novo.\n");
						printf("->");
						gets(aux->info.email);
					}
				}	
				if(z!=1){
					system("cls");
					printf("Não existe um cliente com esse NIF.\n");
					system("pause");
					return;	
				}
			  }
				
				break;
			}
			case 2:{
				
				printf("Introduza o NIF do cliente.\n");
				printf("->");
				scanf("%i",&y);		
	
				if(*iniLista==NULL){
					printf("Não existe clientes.\n");
					return;
				}else{
				for(aux=(*iniLista);aux!=NULL;aux=aux->seguinte){
					if(y==aux->info.nif){
						printf("Num:%i\nNome: %s\nMorada: %s\nLocalidade: %s\nE-mail: %s\nNIF: %i\nNCC: %i\nTelemovel: %i\n\n\n\n ",aux->info.num,aux->info.nome,aux->info.morada,aux->info.localidade,aux->info.email,aux->info.nif,aux->info.nCC,aux->info.tele);
						system("pause");
						z=1;
						system("cls");
						printf("Introduza o telemovel novo.\n");
						printf("->");
						scanf("%i",&aux->info.tele);
					}
				}	
				if(z!=1){
					system("cls");
					printf("Não existe um cliente com esse NIF.\n");
					system("pause");
					return;	
				}
			  }
				
				break;
			}
			case 3:{
				printf("Introduza o NIF do cliente.\n");
				printf("->");
				scanf("%i",&y);		
	
				if(*iniLista==NULL){
					printf("Não existe clientes.\n");
					return;
				}else{
				for(aux=(*iniLista);aux!=NULL;aux=aux->seguinte){
					if(y==aux->info.nif){
						printf("Num:%i\nNome: %s\nMorada: %s\nLocalidade: %s\nE-mail: %s\nNIF: %i\nNCC: %i\nTelemovel: %i\n\n\n\n ",aux->info.num,aux->info.nome,aux->info.morada,aux->info.localidade,aux->info.email,aux->info.nif,aux->info.nCC,aux->info.tele);
						system("pause");
						z=1;
						system("cls");
						
						fflush(stdin);
						printf("Introduza a morada nova.\n");
						printf("->");
						gets(aux->info.morada);
					}
				}	
				if(z!=1){
					system("cls");
					printf("Não existe um cliente com esse NIF.\n");
					system("pause");
					return;	
				}
			  }
				break;
			}
			case 0: {
				printf("SAINDO...");
				break;
			}
			default :{
				printf("Opção errada.\n");
				break;
			}
		}
		
	}while(x!=0);
	
}

//Listar por ondem alfabetica do nome

void listarOrdemAlfabetica(ELEMENTOC **iniLista,int total){
	
	ELEMENTOC *aux=NULL;
	CLIENTE AUX;
	int j=0;
	system("cls");
	if(iniLista==NULL){
		printf("Lista vazia\n");
		system("pause");
			return ;
	}
	for(j=0;j<total-1;j++){	
		for(aux=(*iniLista);aux->seguinte!=NULL;aux=aux->seguinte){
			if(strcmp(aux->info.nome,aux->seguinte->info.nome)>0){
					
					AUX=aux->info;
					aux->info=aux->seguinte->info;
					aux->seguinte->info=AUX;
			}
		}
	}
		for(aux=*(iniLista);aux!=NULL;aux=aux->seguinte){
			printf("Num:%i\nNome: %s\nMorada: %s\nLocalidade: %s\nE-mail: %s\nNIF: %i\nNCC: %i\nTelemovel: %i\n\n\n\n ",aux->info.num,aux->info.nome,aux->info.morada,aux->info.localidade,aux->info.email,aux->info.nif,aux->info.nCC,aux->info.tele);
		}
		system("pause");
	
}

//Listar por NIF

void listarPorNif(ELEMENTOC *iniLista){
	
	ELEMENTOC *aux=NULL;
	int y=0;
	int z=0;
	system("cls");
	printf("Introduza o NIF do cliente.\n");
	printf("->");		
	scanf("%i",&y);		
	system("cls");
		if(iniLista==NULL){
			printf("Não existe clientes.\n");
			system("pause");
			return;
		}else{
			for(aux=iniLista;aux!=NULL;aux=aux->seguinte){
				if(y==aux->info.nif){
						printf("Num:%i\nNome: %s\nMorada: %s\nLocalidade: %s\nE-mail: %s\nNIF: %i\nNCC: %i\nTelemovel: %i\n\n\n\n ",aux->info.num,aux->info.nome,aux->info.morada,aux->info.localidade,aux->info.email,aux->info.nif,aux->info.nCC,aux->info.tele);
						system("pause");
						z=1;
						system("cls");
				}
			}	
				if(z!=1){
					system("cls");
					printf("Não existe um cliente com esse NIF.\n");
					system("pause");
					return;	
				}
			  }
	
	
}

//Listar clientes de uma determinada localidade

void listaPorLocalidade(ELEMENTOC *iniLista){
	char loc[100];
	int y=0;
	ELEMENTOC *aux=NULL;
	system("cls");
	printf("Introduza a localidade.\n");
	fflush(stdin);
	gets(loc);
	system("cls");
	for(aux=iniLista;aux!=NULL;aux=aux->seguinte){
			
			if(strcmp(aux->info.localidade,loc)==0){
			printf("Num:%i\nNome: %s\nMorada: %s\nLocalidade: %s\nE-mail: %s\nNIF: %i\nNCC: %i\nTelemovel: %i\n\n\n\n ",aux->info.num,aux->info.nome,aux->info.morada,aux->info.localidade,aux->info.email,aux->info.nif,aux->info.nCC,aux->info.tele);	
			y=1;
			}
		}
	if(y==0){
		printf("Não existe nenhum cliente em %s.\n",loc);
	}
	system("pause");
	
}

//remover clientes

int removeCliente(ELEMENTOC  **iniLista,int *totalR){
	ELEMENTOC *aux=NULL,*ant=NULL;
	int x=0,y=0;
	if(*iniLista==NULL){
		printf("lista vazia");
		return -1;
	}
	system("cls");
	printf("*******************************\n");
	printf("**\tREMOVER CLIENTE\t     **\n");
	printf("*******************************\n\n");;
	printf("Introduza o NIF do cliente.\n");
	scanf("%i",&x);
	
	for(aux=(*iniLista);aux!=NULL;aux=aux->seguinte){
		if(aux->info.nif==x){
			printf("\nNum:%i\nNome: %s\nMorada: %s\nLocalidade: %s\nE-mail: %s\nNIF: %i\nNCC: %i\nTelemovel: %i\n\n\n\n ",aux->info.num,aux->info.nome,aux->info.morada,aux->info.localidade,aux->info.email,aux->info.nif,aux->info.nCC,aux->info.tele);
			printf("Tem a certeza que quer remover este cliente?\n");
			printf("1-Sim.\n2-Não.\n");
			printf("->");
			scanf("%i",&y);
			
			if(y==2){
				return;
			}
			
		}	
	}
	
	aux=*iniLista;
	while(aux!=NULL && aux->info.nif!=x){
		ant=aux;
		aux=aux->seguinte;
		
	}
	if(aux==NULL){
		printf("Nao existe \n");
		system("pause");
		return -1;
	}
	if(ant==NULL){
		*iniLista=aux->seguinte;
		
	}else{
		ant->seguinte=aux->seguinte;
	}
	free(aux);
	(*totalR)=(*totalR)-1;
	printf("Cliente removido com sucesso.\n");
	system("pause");
	return 0;
	
}

//verificar se exite cliente

int veriCli(ELEMENTOC *iniLista,int num){
	ELEMENTOC *aux=NULL;
	
	for(aux=iniLista;aux!=NULL;aux=aux->seguinte){
		if(aux->info.num==num){
			return 0;
		}
	}
	return -1;
}

//ler e gravar ficheiro e limpar lista
int lerCliente(ELEMENTOC **iniLista,int *total){
	CLIENTE info;
	int tot=0,res=0,lidos=0;
	
	FILE *fp=NULL;
	fp=fopen("DadosClientes.dab","rb");
	
	if(fp==NULL){
		printf("Erro ao abrir o ficheiro\n");
	return -1;
	}
	fread(&tot,sizeof(int),1,fp);
	if(total>0){
		while(!feof(fp)){
			
			res=fread(&info,sizeof(CLIENTE),1,fp);
			lidos=lidos+1;
			if(res){
			//função inserir
			inserirCliente(iniLista,info);
			}
		}
			
	}
	*total=tot;
	fclose(fp);
	
	return lidos-1;
}
int gravarClientes(ELEMENTOC *iniLista,int total){
	
	ELEMENTOC *aux=NULL;
	FILE *fp=NULL;
	fp=fopen("DadosClientes.dab","wb");
	
	if(fp==NULL){
		printf("Erro ao abrir o ficheiro\n");
	return -1;
	}
	fwrite(&total,sizeof(int),1,fp);
	
	for(aux=iniLista;aux!=NULL;aux=aux->seguinte){
		fwrite(&aux->info,sizeof(CLIENTE),1,fp);
	}
	fclose(fp);
	return 0;
}
int gravarCTexto(ELEMENTOC *iniLista){
 	ELEMENTOC *aux=NULL;
	FILE *fp=NULL;
	fp=fopen("ClientesRegistados.txt","w");
	
	if(fp==NULL){
		printf("Erro ao abrir o ficheiro\n");
		return -1;
	}
	for(aux=iniLista;aux!=NULL;aux=aux->seguinte){
		fprintf(fp,"Num:%i\nNome: %s\nMorada: %s\nLocalidade: %s\nE-mail: %s\nNIF: %i\nNCC: %i\nTelemovel: %i\n\n\n\n ",aux->info.num,aux->info.nome,aux->info.morada,aux->info.localidade,aux->info.email,aux->info.nif,aux->info.nCC,aux->info.tele);
	}
	fclose(fp);
	return 0;	
}
void limparListaClientes(ELEMENTOC **iniLista){
	
	ELEMENTOC *aux=NULL, *proximo=NULL;
	aux=*iniLista;
	*iniLista=NULL;
	while(aux!=NULL){
		proximo=aux;
		free(aux);
		aux=proximo->seguinte;
	}
}








