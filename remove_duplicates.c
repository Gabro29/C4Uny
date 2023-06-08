#include<stdio.h>
#include<stdlib.h>


// Definisco il nodo
typedef struct nodo{
	struct nodo* prev;
	int dato;
	struct nodo *next;
}nodo;


// Prototipi di Funzione
nodo* listabi_da_file(char*);
nodo* rimuoviDuplicati(nodo*);
nodo* remove_node(nodo*, int);
void stampa(nodo*);



int main(void){
	
	// Scopo del programma
	printf("\nQuesto programma rimuove i duplicati da una lista, che viene generata a aprtire dal file 'input.txt'\n");
	
	// Dichiarazione delle variabili
	char *filename = "input.txt";
	nodo *anchor = listabi_da_file(filename); // Lista bidirezionale
	
	// Visualizzo a schermo prima della rimozione
	printf("\n------La lista prima della rimozione------\n");
	stampa(anchor);
	
	// Effettuo la rimozione degli elementi duplicati e tengo solo le prime occorrenze
	anchor = rimuoviDuplicati(anchor);
	
	// Visualizzo a schermo dopo la rimozione
	printf("\n------La lista dopo la rimozione------\n");
	stampa(anchor);
	
	
	return 0;
}



nodo* listabi_da_file(char *filename){
	
	// Dichiarazione delle varaibili
	FILE *my_file = fopen(filename, "r");
	int number = 0, index = 0;
	nodo *anchor = NULL;
	nodo *new_box = NULL;
	nodo *previous = NULL;
	
	while(fscanf(my_file, "%d", &number) != EOF){
		// Allocazione
		new_box = (nodo*) calloc(1, sizeof(nodo));
		
		if(new_box == NULL){
			printf("\nErrore nell'allocazione della memoria.\n");
			exit(1);
		}
		
		// Assegnazione
		new_box->dato = number;
		new_box->next = NULL;
		
		// Collegamento
		if(index == 0){
			new_box->prev = NULL;
			anchor = new_box;
			previous = anchor;
		}
		else{
			new_box->prev = previous;
			previous->next = new_box;
			previous = new_box;
		}
		index++;
	}
	return anchor;
}



nodo* rimuoviDuplicati(nodo* anchor){
    nodo *ANCHOR = anchor;
    nodo *temp = NULL;
    nodo *p_cfr = NULL;
    nodo *previous = NULL;

    while (anchor != NULL) {
        p_cfr = anchor->next;
        previous = anchor;
        
        while (p_cfr != NULL) {
            if(anchor->dato == p_cfr->dato) {
                temp = p_cfr;
                p_cfr = p_cfr->next;
                previous->next = p_cfr;
                free(temp);
            } 
			else {
                previous = p_cfr;
                p_cfr = p_cfr->next;
            }
        }

        anchor = anchor->next;
    }

    return ANCHOR;
}


nodo* remove_node(nodo* anchor, int pos) {
    if (anchor == NULL) {
        // La lista è vuota, restituisci NULL
        return NULL;
    }

    if (pos == 1) {
        // Rimuovi il primo nodo dalla lista
        nodo* temp = anchor;
        anchor = anchor->next;
        if (anchor != NULL) {
            anchor->prev = NULL;
        }
        free(temp);
        return anchor;
    }

    nodo* current = anchor;
    nodo* previous = NULL;
    int index = 1;

    while (current != NULL && index != pos) {
        previous = current;
        current = current->next;
        index++;
    }

    if (current == NULL) {
        // La posizione non esiste nella lista, restituisci l'ancora senza modifiche
        return anchor;
    }

    // Rimuovi il nodo corrente dalla lista
    previous->next = current->next;
    if (current->next != NULL) {
        current->next->prev = previous;
    }
    free(current);

    return anchor;
}



void stampa(nodo *anchor){
	printf("\nLa lista e':\n");
	while(anchor != NULL){
		printf("|%d| -> ", anchor->dato);
		anchor = anchor->next;
	}	
	printf("NULL\n");
}
