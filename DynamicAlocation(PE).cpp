#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stContaBancaria{
	int id;
	char senha[12];
	float saldo;
	struct stContaBancaria *prox;
}; typedef struct stContaBancaria ContaBancaria;


int main(){
	int validator = 0, c = 0;
	int id, i, flag = 0;
	char senha[12];
	float saldo;
	ContaBancaria *conta, *inicio, *conta_ver;	
	
	while(validator == 0){
		printf("Selecione uma opcao: \n-->  0: adicionar novo usuario\n-->  1: checar saldo\n-->  2: checar IDS\n--> -1: finalizar o programa\nInsira sua op: ");
		scanf("%i", &validator);
		while (validator != 0 && validator != 1 && validator != 2 && validator != -1){
			printf("\nOpcao invalida!\n");
			printf("Selecione uma opcao: \n-->  0: adicionar novo usuario\n-->  1: checar saldo\n-->  2: checar IDS\n--> -1: finalizar o programa\nInsira sua op: ");
			scanf("%i", &validator);
		}
		
		if(validator == -1){
			break;  
		}
		
		if(validator == 0){
			printf("Insira o ID da nova conta: ");
			scanf("%i", &id);
						
			if(c == 0){
				conta = (ContaBancaria *)malloc(sizeof(ContaBancaria));
				inicio = conta;
				printf("Insira a senha da conta: ");
				scanf("%s", senha);	
				printf("Insira o saldo da nova conta: ");
				scanf("%f", &saldo);
				
				conta->id = id;
				// strcpy(conta->senha, senha);
				for(i = 0; i < 12; ++i){
					conta->senha[i] = senha[i];
				}
				conta->saldo = saldo;
				conta->prox = NULL;
			}
			
			else{
							
				flag = 0;
				conta_ver = inicio;
				while(conta_ver != NULL){
					if(conta_ver->id == id){
						printf("Esta conta ja existe!\n");
						flag = 1;
						break;
					}
					conta_ver = conta_ver->prox;
				}
				
				if(flag == 0){
					printf("Insira a senha da conta: ");
					scanf("%s", senha);
					printf("Insira o saldo da nova conta: ");
					scanf("%f", &saldo);
					
					conta->prox = (ContaBancaria *)malloc(sizeof(ContaBancaria));
					conta = conta->prox;
					conta->id = id;
					// strcpy(conta->senha, senha);
					for(i = 0; i < 12; ++i){
						conta->senha[i] = senha[i];
					}
					conta->saldo = saldo;
					conta->prox = NULL;
					}
			}
			c += 1;	
			printf("\n");
			}
		
		if(validator == 1){  // Ta Errado...
			printf("Insira o ID: ");
			scanf("%i", &id);
			printf("Insira a senha da conta: ");
			scanf("%s", senha);
			
			printf("%s == %s", )
			
		}
		
		if(validator == 2){
			conta_ver = inicio;
			while(conta_ver->prox != NULL){
				printf("%i --- ", conta_ver->id);
				conta_ver = conta_ver->prox;
			}
			printf("%i\n\n", conta_ver->id);
			validator = 0;
		}
	
	}
	// Limpando a memoria
	
	return 0;
}


