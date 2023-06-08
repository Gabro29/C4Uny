#include<stdio.h>
#include<stdlib.h>

// Definisco il nodo
typedef struct nodo{
	int dato;
	struct nodo* next;
}nodo;


// Prototipi di Funzione
nodo* crea_lista(char*);
nodo* rimuoviElemento(nodo*, int);
void stampa(nodo*);


int main(void){
	
	// Scopo del programma
	printf("\nQuesto programma prende in input un valore e lo ricerca in una lista gia' definita a partire dal file 'input.txt'\n");
	
	// Dichiarazione delle variabili
	char *nome_file = "input.txt";
	nodo *anchor = crea_lista(nome_file);
	int element_to_delete = 0;
	
	// Lista prima della rimozione
	printf("\nLa lista letta dal file 'input.txt' e':\n");
	stampa(anchor);
	
	// Acquisisco il valore dell'elemento da rimuovere
	printf("\nInserisci il valore che vuoi rimuovere dalla lista ");
	scanf("%d", &element_to_delete);
	
	// Effettuo la rimozione
	anchor = rimuoviElemento(anchor, element_to_delete);
	
	// Stampa dopo la rimozione
	printf("\nLa lista dopo la rimozione e':\n");
	stampa(anchor);
	
	return 0;
}


nodo* crea_lista(char *nome_file){
	
	// Dichiarazione delle variabili
	FILE *my_file = fopen(nome_file, "r");
	nodo *anchor = NULL;
	nodo *new_box = NULL;
	nodo *previous = NULL;
	int number = 0, index = 0;
	
	while(fscanf(my_file, "%d", &number) != EOF){
		// Allocazione
		new_box = (nodo*) calloc(1, sizeof(nodo));
		
		if(new_box == NULL){
			printf("\nErrore nell'allocazione della memoria\n");
			exit(1);
		}
		
		new_box->dato = number;
		new_box->next = NULL;
		
		if(index == 0){
			anchor = new_box;
			previous = anchor;
		}
		else{
			previous->next = new_box;
			previous = new_box;
		}
		index++;
	}
	
	fclose(my_file);
	
	return anchor;
}



nodo* rimuoviElemento(nodo* anchor, int element){
	
	// Dichiarazione delle variabili
	nodo *p_anchor = anchor;
	nodo *previous = anchor;
	
	while(p_anchor != NULL && p_anchor->dato != element){
		previous = p_anchor;
		p_anchor = p_anchor->next;
	}
	
	if(p_anchor != NULL){
		printf("\nElemento Trovato!\n");
		previous->next = p_anchor->next;
	}
	else{
		printf("\nElemento NON Trovato!\n");
	}
	
	
	return anchor;
}



void stampa(nodo *anchor){
	printf("\n");
	while(anchor != NULL){
		printf("|%d| -> ", anchor->dato);
		anchor = anchor->next;
	}
	printf("NULL\n");
}
