#include <stdio.h>
#include <stdlib.h>

struct stPeopleData{
	int id;
	char full_name[60];
	char email[60];
	float balance;
	struct stPeopleData *next;
}; typedef struct stPeopleData PeopleData;


int get_option(){
	int opt;
	int validator = 0;
	
	while(validator == 0){
		printf("Choose your option: ");
		printf("\n0 - Add new user;\n1 - Check user data;\n2 - Edit user data;\n3 - Delete user data;\n4 - Finish program.\nOpt: ");
		scanf("%i", &opt);
		if(opt != 0 && opt != 1 && opt != 2 && opt != 3 && opt != 4){
			printf("Invalid option!\n");
		}
		else{
			break;
		}
	}
	printf("\n");	
	return opt;
}


PeopleData first_user(int id){
	PeopleData *first_account;
	
	first_account = (PeopleData *)malloc(sizeof(PeopleData));
	
	first_account->id = id;
	printf("New user full name: ");
	scanf(" %[^\t\n]s", &(first_account->full_name));	
	printf("New user email: ");
	scanf(" %[^\t\n]s", &(first_account->email));
	printf("New user balance: ");
	scanf("%f", &(first_account->balance));
	
	first_account->next = NULL; 
	
	printf("\n");	
	return *first_account;
}


PeopleData create_user(PeopleData *first_account, int id){
	PeopleData *new_account, *aux_account;
	
	new_account = (PeopleData *)malloc(sizeof(PeopleData));
	
	new_account->id = id;
	printf("New user full name: ");
	scanf(" %[^\t\n]s", &(new_account->full_name));
	printf("New user email: ");
	scanf(" %[^\t\n]s", &(new_account->email));
	printf("New user balance: ");
	scanf("%f", &(new_account->balance));	
	
	new_account->next = NULL;
		
	printf("\n");
	return *new_account; 	
}


int exist_user(PeopleData *first_account, int id){
	PeopleData *aux_account;
	
	aux_account = first_account;
	while(aux_account != NULL){
		if(aux_account->id == id){
			return 1;  // 1 = Exists
		}
		aux_account = aux_account->next;
	}
	return 0; // 0 = Do not exist
}


int check_user(PeopleData *first_account, int id){
	PeopleData *aux_account;
	
	aux_account = first_account;
	while(aux_account != NULL){
		if(aux_account->id == id){
			printf("----------------------------------------------------------\n");
			printf("User id: %i\nUser full name: %s\nUser email: %s\nUser balance: $%.2f\n", aux_account->id, aux_account->full_name, aux_account->email, aux_account->balance);
			printf("----------------------------------------------------------\n\n");
			return 0;
		}
		aux_account = aux_account->next;
	}
	printf("There is no user with this id in our system.\n\n");
	return 0;
}
	
	

int main(){
	int opt, id, num_users = 0, validator = 0;
	PeopleData *first_account, *new_account, *aux_account; 
	
	while(validator == 0){
		opt = get_option();  // 0 - Add new user;	1 - Check user data;	2 - Edit user data;		3 - Delete user data;		4 - Finish program.
		
		if(opt == 0){
			if(num_users == 0){
				new_account = (PeopleData*)malloc(sizeof(PeopleData));
				printf("New user id: ");
				scanf("%i", &id);
				*new_account = first_user(id);
				first_account = new_account;
				num_users ++;
			}
			
			else{				
				printf("New user id: ");
				scanf("%i", &id);
				
				if(exist_user(first_account, id) == 1){
					printf("This user already exists!\n\n");					
				}
				
				else if(exist_user(first_account, id) == 0){
					new_account->next = (PeopleData*)malloc(sizeof(PeopleData));
					new_account = new_account->next;
					
					*new_account = create_user(first_account, id);
					num_users ++;
				}
				
			}	
		}
		
		
		else if(opt == 1){
			if(num_users > 0){
				printf("Type the user id: ");
				scanf("%i", &id);
				check_user(first_account, id);
			}
			else{
				printf("There is no user in our system.\n\n");
			}
		}
		
		
		else if(opt == 2){
			// Falta add
		}
		
		
		else if(opt == 3){
			// Falta add
		}
		
		
		else if(opt == 4){
			break;
		}
	
	
	}
	
	return 0; 
}


