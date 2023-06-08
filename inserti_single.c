#include<stdio.h>
#include<stdlib.h> 


// Definisco il nodo
typedef struct nodo{
	int dato;
	struct nodo *next;
}nodo;


// Prototipi di Funzione
nodo* crea_lista(int);
nodo* inserisciElemento(nodo*, int);
void stampa(nodo*);



int main(void){
	
	// Scopo del programma
	printf("\nQuesto programma prende in input un numero e lo inserisce in testa alla lista semplice\n");
	
	// Dichiarazione delle vatiabili
	int number = 0;
	nodo *anchor = crea_lista(10);
	
	// Stampo prima dell'aggiunta
	stampa(anchor);
	
	// Aggiungo un elemento
	printf("\nInserisci il numero: ");
	scanf("%d", &number);

	anchor = inserisciElemento(anchor, number);
	
	// Visualizzo dopo l'aggiunta
	stampa(anchor);
	
	
	return 0;
}



nodo* crea_lista(int N){
	// Dichiarazione delle variabili
	nodo *anchor = NULL;
	nodo *new_box = NULL;
	int number = 0;
	
	for(int i = 0; i < N; i++){
		// Allocazione
		new_box = (nodo*) calloc(1, sizeof(nodo));
		
		if(new_box == NULL){
			printf("\nErrore nell'allocazione.\n"); 
			exit(1);
		}
		
		// Assegnazione
		new_box->dato = number;
		new_box->next = anchor;
		// Collegamento
		anchor = new_box;
	}	
	return anchor;
}



nodo* inserisciElemento(nodo* anchor, int dato){
	nodo *new_box = (nodo*) calloc(1, sizeof(nodo));
	if(new_box == NULL){
		printf("\nErrore nell'allocazione.\n"); 
		exit(1);
	}
	new_box->dato = dato;
	new_box->next = anchor;
	anchor = new_box;
	return anchor;
}



void stampa(nodo* anchor){
	printf("\nLa lista e':\n");
	while(anchor != NULL){
		printf("|%d| -> ", anchor->dato);
		anchor = anchor->next;
	}
	printf("NULL\n");
}
