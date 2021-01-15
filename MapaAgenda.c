#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM 5

struct cliente{
	char nome [30];
	char tel [15];
	char email [20];
};

void cabecalho();
void cabelho_listar();

int main(){
	setlocale (LC_ALL, "Portuguese");
	
	struct cliente cadastro[TAM];
	
	int i, menu, cont;
	cont = 0;
	
	do{
		cabecalho();
		printf("\n");
		printf("Selecione uma das opções abaixo:\n\n");
		printf(" 1 - Inserir um novo cadastro\n");
		printf(" 2 - Listar clientes cadastrados \n");
		printf(" 0 - Encerrar \n");
		scanf("%d", &menu);
		fflush(stdin);
		system("cls");
		
		switch (menu){
			
			case 1:
				if(cont < 5){
								
					cabecalho();
					
					printf("\n");
					printf("Digite seu nome:\n");
					fgets(cadastro[cont].nome, 30, stdin);
					fflush(stdin);
					
					printf("Informe seu telefone:\n");
					fgets(cadastro[cont].tel, 15, stdin);
					fflush(stdin);
					
					printf("Informe seu E-mail:\n");
					fgets(cadastro[cont].email, 20, stdin);
					fflush(stdin);
					printf("\n");
					cont++;	
							
				}else{
					cabecalho();
					printf("\n");
					printf(" Agenda lotada....\n\n");
					getch();
				}
				
			break;
			
			case 2:
				if(cont < 1){
					cabelho_listar();
					printf("\n");
					printf(" Agenda vazia...");
					getch();
				}else{
				
				cabelho_listar();
				for(i = 0; i < cont; i++){
				
					printf("\nCódigo: %d\n", i);
					printf("Nome: %s", cadastro[i].nome);
					printf("Telefone: %s", cadastro[i].tel);
					printf("E-mail: %s", cadastro[i].email);
					fflush(stdin);
					printf("\n-------------------------");
					printf("\n");
					
					}
				getch();
				}					
			break;
			
			case 0:
				printf("\n");
			break;
			
			default:
				cabecalho();
				printf("\n");
				printf("Número Inválido....");
				getch();
			break;
		}	
	}while(menu != 0);
			
	system("cls");
	system("pause");
	return(0);	
}

void cabecalho(){
	system("cls");
	printf("-------------------------\n");
	printf("  CADASTRO DE CLIENTES\n");
	printf("-------------------------\n");
}

void cabelho_listar(){
	system("cls");
	printf("-------------------------\n");
	printf("  CLIENTES CADASTRADOS\n");
	printf("-------------------------\n");	
}

