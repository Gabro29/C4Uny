#include<stdio.h>
#include<stdlib.h>

// Definisco il nodo della lista
typedef struct nodo{
	int dato;
	struct nodo* next;
}nodo;

// Definisco il container
typedef struct contenitore{
	nodo* p1;
	nodo* p2;
}contenitore;

// Prototipi di Funzione
nodo* crea_lista(int N);
void stampa(nodo* list);
contenitore* spezza(nodo* anchor);

int main(void){
	
	// Scopo del programma
	printf("Questo programma, dato un intero a piacere N, crea una lista che poi");
	printf("viene divisa a meta'. Quindi [0, (N-1)/2) [(N-1)/2, (N-1)]\n");
	
	// Genero una lista semplice
	printf("Inserisci l'intero\n");
	int N;
	scanf("%d", &N);
	nodo* anchor = crea_lista(N);
	printf("La lista e'\n");
	stampa(anchor);
	
	// Spezzo la lista a meta'
	contenitore* my_container = spezza(anchor);
	printf("La prima lista e'\n");
	stampa(my_container->p1);
	printf("La seconda lista e'\n");
	stampa(my_container->p2);
	return 0;
}




nodo* crea_lista(int N){
	
	nodo* anchor;
	nodo* new_box = NULL;
	nodo* previous = anchor;
	
	for(int i = 0; i < N; i++){
		new_box = malloc(sizeof(nodo));
		new_box->dato = i;
		new_box->next = NULL;
		
		if(i == 0){
			anchor = new_box;
			previous = new_box;
		}else{
			previous->next = new_box;
			previous = new_box;
		}
	}
	
	return anchor;
}


void stampa(nodo* list){
	nodo* p = list;
	if(p == NULL){
		printf("La lista e' vuota\n");
	}else{
	while(p != NULL){
		printf("|%d|", p->dato);
		p = p->next;
		if(p != NULL) 
			printf(" -> ");
	}
	printf("\n");
	}
}


contenitore* spezza(nodo* anchor){
	
	int dim=0, count=0;
	nodo* pcount = anchor;
	nodo* p1;
	nodo* p2;
	contenitore* container = malloc(sizeof(contenitore));
	
	while(pcount != NULL){
		pcount = pcount->next;
		dim++;
	}
	
	printf("\nLa lunghezza della lista originale e' %d\n", dim);
	printf("Adesso la divido in due liste, una di lunghezza %d e  l'altra di %d\n", dim/2, dim - dim/2);
	
	
	p1 = anchor;
	while(count < (dim/2)-1){
		p1 = p1->next;
		count++;
	}
	p2 = p1->next;
	p1->next = NULL;
	container->p1 = anchor;
	container->p2 = p2;
	
	return container;
}





