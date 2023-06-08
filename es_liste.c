#include<stdio.h>
#include<stdlib.h>

// Definisco il nodo
typedef struct nodo{
	int dato;
	struct nodo* next;
}nodo;


// Prototipi di funzione
nodo* crea_lista_cascata(int);
nodo* cancella_range(nodo*, int, int); // Includendo gli estremi
nodo* cancella_single(nodo*, int);
void stampa(nodo*);


int main(void){
	
	nodo* anchor = crea_lista_cascata(10);
//	anchor = cancella_range(anchor, 6, 8);
	stampa(anchor);
	anchor = cancella_single(anchor, 10);
	stampa(anchor);
	
	
	return 0;
}



nodo* crea_lista_cascata(int N){
	nodo* anchor = NULL;
	nodo* new_box;
	
	for(int i = 0; i < N; i++){
		// Allocazione
		new_box = (nodo*) malloc(sizeof(nodo));
		if (new_box == NULL) {
            printf("Errore di allocazione della memoria.\n");
            exit(1);
        }
		// Assegnazione
		new_box->dato = i;
		// Indirizzamento
		new_box->next = anchor;
		anchor = new_box;
		
	}
	return anchor;
}


nodo* cancella_range(nodo* anchor, int from, int to){
	int index = 0;
	nodo* p_anchor = anchor;
	nodo* p_from = NULL;
	nodo* temp;
	
	while(p_anchor != NULL && index <= to){
		
		// Memorizzo il primo brealpoint
		if(index == from - 1){
			p_from = p_anchor; 
			printf("Nodi rimossi da %d a ", from);
		}
		// Cancello la memoria per la celle
		// nel range inserito
		if (index >= from && index <= to){
            temp = p_anchor;
            p_anchor = p_anchor->next;
            free(temp);
        }
		else{
            p_anchor = p_anchor->next;
        }
		
		index ++;
	}
	
	// Collego i breakpoints trovati
	if (p_from != NULL){
        p_from->next = p_anchor;
    }
	else{
        anchor = p_anchor;
    }
    printf("%d\n", to);
	return anchor;
}


nodo* cancella_single(nodo* anchor, int position){
	
	nodo* p_anchor = anchor;
	nodo* p_pos;
	nodo* temp;
	int index = 1;
	
	
	if(position == 1){
        temp = anchor;
        anchor = anchor->next;
        free(temp);
        return anchor;
    }
	
	while(p_anchor != NULL && index != position){
		if(index == position - 1) p_pos = p_anchor;
		
		p_anchor = p_anchor->next;
		index ++;
	}
	
	temp = p_anchor;
	p_anchor = p_anchor->next;
	free(temp);
	
	if(p_pos != NULL){
		p_pos->next = p_anchor;
	}
	else{
		anchor = p_anchor;
	}
	
	return anchor;
}

void stampa(nodo* anchor){
	printf("\n");
	while(anchor != NULL){
		printf("|%d| -", anchor->dato);
		anchor = anchor->next;
	}
	printf(" NULL\n");
}







