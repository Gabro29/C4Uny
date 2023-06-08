#include<stdio.h>
#include<stdlib.h>
#include<time.h>


// Direttive
#define GESTISCI_ERRORE(messaggio) do{printf("\nErrore: %s\n", messaggio); exit(1);}while(0)


// Definisco il nodo
typedef struct nodo{
	int dato;
	struct nodo *next;
}nodo;


// Definisco il container
typedef struct contenitore{
	nodo* p1;
	nodo* p2;
}contenitore;


// Prototipi di Funzione
nodo* menu_principale(char);
nodo* crea_lista_simple(int);
nodo* crea_lista_random(int, int, int);
nodo* crea_lista_keyboard(void);
char* prendi_nome_file(void);
nodo* crea_lista_from_file(char*);
nodo* manipulate_lista(nodo*, char);
void sum_mean(nodo*);
nodo* add_start(nodo*);
nodo* add_end(nodo*);
nodo* remove_duplicates_all(nodo*);
nodo* remove_duplicates_single(nodo*);
contenitore* spezza(nodo*);
nodo* sort_plus(nodo*);
nodo* sort_minus(nodo*);
nodo* remove_element(nodo*);
nodo* remove_element_range(nodo*);
void save_file(nodo*, char);
void stampa(nodo*);
int distruttore(nodo*);


int main(void){
	
	// Scopo del programma
	printf("\nQuesto programma permette di effettuare operazioni tra liste e file\n");
	printf("di seguito vengono elencate tutte le possibili opzioni:\n");
	
	printf("\tOpzione 1: Crea una lista di interi da 0 a N-1;\n");
	printf("\tOpzione 2: Crea una lista di interi random (distribuzione non uniforme) da min a max;\n");
	printf("\tOpzione 3: Crea una lista di interi acquisiti da tastiera;\n");
	printf("\tOpzione 4: Crea una lista di interi acquisiti da file.\n");
	
	// Determino la scelta
	char scelta;
	printf("Digita la tua scelta: ");
	scanf("%c", &scelta);
	
	nodo *anchor = menu_principale(scelta);
	
	if(anchor != NULL){
		printf("\n\nE' possibile adesso manipolare tale lista\n");
		printf("di seguito vengono elencate tutte le possibili opzioni:\n");
		
		printf("\tOpzione 1: Somma tutti gli elementi della lista e determina la media;\n");
		printf("\tOpzione 2: Aggiunta in testa di un elemento;\n");
		printf("\tOpzione 3: Aggiunta in coda di un elemento;\n");
		printf("\tOpzione 4: Rimozione di tutti i duplicati dalla lista;\n");
		printf("\tOpzione 5: Rimozione di tutti i nodi che contengono uno specifico dato;\n");
		printf("\tOpzione 6: Spezzare la lista a meta';\n");	
		printf("\tOpzione 7: Sorting Crescente della lista;\n");	
		printf("\tOpzione 8: Sorting Decrescente della lista;\n");
		printf("\tOpzione 9: Elimina elemento in base alla posizione;\n");
		printf("\tOpzione 0: Elimina elementi per un range di posizioni.\n");
		
		
		// Determino la scelta
		fflush(stdin);
		printf("Digita la tua scelta: ");
		scanf("%c", &scelta);
		
		anchor = manipulate_lista(anchor, scelta);
		
		printf("\nVuoi salvare su file la lista appena visualizzata? (Y/N)\n");
		// Determino la scelta
		fflush(stdin);
		printf("Digita la tua scelta: ");
		scanf("%c", &scelta);
		
		save_file(anchor, scelta);
		
	}
	else{
		printf("Lista VUOTA\n");
	}
	
	if(distruttore(anchor) != 0) GESTISCI_ERRORE("Errore nella distruzione!\n");
	else printf("\nLista Distrutta!\n");
	
	return 0;
}




nodo* menu_principale(char scelta){
	
	// Dichiarazione delle variabili
	int N = 0, min = 0, max =0;
	nodo *anchor = NULL;
	char *filename;
	
	while(scelta != 's')
		switch(scelta){
			// Lista di interi da 0 a N-1
			case '1':;
				printf("Inserisci il numero N: ");
				scanf("%d", &N);
				anchor = crea_lista_simple(N);
				printf("La lista ottenuta e':\n");
				stampa(anchor);
				scelta = 's';
				break;
			// Crea una lista di interi random
			case '2':
				printf("Inserisci il primo estremo min: ");
				scanf("%d", &min);
				printf("Inserisci il secondo estremo max: ");
				scanf("%d", &max);
				printf("Quanti elementi vuoi?: ");
				scanf("%d", &N);
				anchor = crea_lista_random(min, max, N);
				printf("La lista ottenuta e':\n");
				stampa(anchor);
				scelta = 's';
				break;
			// Crea una lista di interi acquisiti da tastiera
			case '3':
				anchor = crea_lista_keyboard();
				printf("La lista ottenuta e':\n");
				stampa(anchor);
				scelta = 's';
				break;
			// Crea una lista di interi acquisiti da file
			case '4':
				printf("Inserisci il nome del file da leggere, si prega di usare 'txt' oppure 'dat': ");
				anchor = crea_lista_from_file(prendi_nome_file());
				printf("La lista ottenuta e':\n");
				stampa(anchor);
				scelta = 's';
				break;
				
			default:
				printf("Scelta non valida!\n");
				printf("\nDigita la tua scelta: ");
				fflush(stdin);
				scanf("%c", &scelta);
				break;
		}
	return anchor;
}



nodo* crea_lista_simple(int N){
	
	// Dichiarazione delle variabili
	nodo *anchor = NULL;
	nodo *new_box = NULL;
	nodo  *previous = NULL;
	
	for(int i = 0; i < N; i++){
		// Allocazione
		new_box = (nodo*) calloc(1, sizeof(nodo));
		if(new_box == NULL) GESTISCI_ERRORE("Allocazione Nodo!\n");
		
		// Assegnazione
		new_box->dato = i;
		new_box->next = NULL;
		
		if(anchor == NULL){
			anchor = new_box;
			previous = anchor;
		}
		else{
			previous->next = new_box;
			previous = new_box;
		}
	}

	return anchor;
}



nodo* crea_lista_random(int min, int max, int N){
	
	// Dichiarazione delle variabili
	nodo *anchor = NULL;
	nodo *new_box = NULL;
	nodo  *previous = NULL;
	
	// Setto il seme
	srand(time(NULL));

	for(int i = 0; i < N; i++){
		// Allocazione
		new_box = (nodo*) calloc(1, sizeof(nodo));
		if(new_box == NULL) GESTISCI_ERRORE("Allocazione Nodo!\n");
		
		// Assegnazione
		new_box->dato = (rand() % (max - min + 1)) + min;
		new_box->next = NULL;
		
		if(anchor == NULL){
			anchor = new_box;
			previous = anchor;
		}
		else{
			previous->next = new_box;
			previous = new_box;
		}
	}

	return anchor;
}



nodo *crea_lista_keyboard(void){
	
	// Dichiarazione delle variabili
	int number = -1, index = 1;
	nodo *anchor = NULL;
	nodo *new_box = NULL;
	nodo  *previous = NULL;

	while(number != 0){
		printf("Inserisci il %d valore da inserire: ", index);
		scanf("%d", &number);
		if(number != 0){
			// Allocazione
			new_box = (nodo*) calloc(1, sizeof(nodo));
			if(new_box == NULL) GESTISCI_ERRORE("Allocazione Nodo!\n");
			
			// Assegnazione
			new_box->dato = number;
			new_box->next = NULL;
			
			if(anchor == NULL){
				anchor = new_box;
				previous = anchor;
			}
			else{
				previous->next = new_box;
				previous = new_box;
			}
		}
		index++;
	}

	return anchor;
}



char* prendi_nome_file(void){
	
	// Dichiarazione delle variabili
	int index = 0;
	char letter;
	char *filename = (char*) calloc(1, sizeof(char));
	
	// Prendo in input altri valori dopo l'immissione precedente
	fflush(stdin);
	
	// Acquisisco il nome del file
	do{
		letter = getchar();
		if(letter != '\n'){
			if(index != 0) filename = (char*) realloc(filename, index * sizeof(char));
			filename[index] = letter;
			index++;
		}
	}while(letter != '\n');
	
	return filename;
}



nodo* crea_lista_from_file(char *filename){
	
	// Dichiarazione delle variabili
	int number = 0;
	nodo *anchor = NULL;
	nodo *new_box = NULL;
	nodo  *previous = NULL;
	FILE *my_file = fopen(filename, "r");
	
	if(my_file == NULL) GESTISCI_ERRORE("File non trovato!\n");

	while(fscanf(my_file, "%d", &number) != EOF){
		// Allocazione
		new_box = (nodo*) calloc(1, sizeof(nodo));
		if(new_box == NULL) GESTISCI_ERRORE("Allocazione Nodo!\n");
		
		// Assegnazione
		new_box->dato = number;
		new_box->next = NULL;
		
		if(anchor == NULL){
			anchor = new_box;
			previous = anchor;
		}
		else{
			previous->next = new_box;
			previous = new_box;
		}
	}
	fclose(my_file);
	return anchor;
}



nodo* manipulate_lista(nodo *anchor, char scelta){
	
	// Dichiarazione delle variabili
	contenitore *my_container;
	
	while(scelta != 's')
		switch(scelta){
			
			// Somma tutti gli elementi della lista e determina la media
			case '1':;
				sum_mean(anchor);
				scelta = 's';
				break;
				
			// Aggiunta in testa di un elemento
			case '2':
				anchor = add_start(anchor);
				printf("La lista ottenuta e':\n");
				stampa(anchor);
				scelta = 's';
				break;
				
			// Aggiunta in coda di un elemento
			case '3':
				anchor = add_end(anchor);
				printf("La lista ottenuta e':\n");
				stampa(anchor);
				scelta = 's';
				break;
				
			// Rimozione di tutti i duplicati dalla lista
			case '4':
				anchor = remove_duplicates_all(anchor);
				printf("La lista ottenuta e':\n");
				stampa(anchor);
				scelta = 's';
				break;
				
			// Rimozione di tutti i nodi che contengono uno specifico dato
			case '5':
				anchor = remove_duplicates_single(anchor);
				printf("La lista ottenuta e':\n");
				stampa(anchor);
				scelta = 's';
				break;
				
			// Spezzare la lista a meta'
			case '6':
				my_container = spezza(anchor);
				printf("La prima parte e':\n");
				stampa(my_container->p1);
				printf("La seconda parte e':\n");
				stampa(my_container->p2);
				scelta = 's';
				anchor = NULL;
				break;
				
			// Sorting Crescente della lista
			case '7':
				anchor = sort_plus(anchor);
				printf("La lista ottenuta e':\n");
				stampa(anchor);
				scelta = 's';
				break;
				
			// Sorting Decrescente della lista
			case '8':
				anchor = sort_minus(anchor);
				printf("La lista ottenuta e':\n");
				stampa(anchor);
				scelta = 's';
				break;

			// Elimina elemento in base alla posizione
			case '9':
				anchor = remove_element(anchor);
				printf("La lista ottenuta e':\n");
				stampa(anchor);
				scelta = 's';
				break;
				
			// Elimina elementi per un range di posizioni
			case '0':
				anchor = remove_element_range(anchor);
				printf("La lista ottenuta e':\n");
				stampa(anchor);
				scelta = 's';
				break;
				
			default:
				printf("Scelta non valida!\n");
				printf("\nDigita la tua scelta: ");
				fflush(stdin);
				scanf("%c", &scelta);
				break;
		}
	return anchor;
}



void sum_mean(nodo *anchor){
	
	// Dichiarazione delle variabili
	int somma = 0, index = 1;
	
	while(anchor != NULL){
		somma = somma + anchor->dato;
		anchor = anchor->next;
		index++;
	}
	
	printf("La somma degli elementi della lista e' %d, la media e' %f\n", somma, somma / (float) index);
	
}



nodo* add_start(nodo *anchor){
	
	// Dichiarazione delle variabili
	int dato = 0;
	nodo *new_box = NULL;
	
	// Prendo il dato da inserire
	printf("Inserisci il dato che vorresti aggiungere: ");
	fflush(stdin);
	scanf("%d", &dato);
	
	new_box = (nodo*) calloc(1, sizeof(nodo));
	new_box->dato = dato;
	new_box->next = anchor;
	
	return new_box;
}



nodo* add_end(nodo *anchor){
	
	// Dichiarazione delle variabili
	int dato = 0;
	nodo *new_box = NULL;
	nodo *p_anchor = anchor;
	
	// Prendo il dato da inserire
	printf("Inserisci il dato che vorresti aggiungere: ");
	fflush(stdin);
	scanf("%d", &dato);
	
	new_box = (nodo*) calloc(1, sizeof(nodo));
	new_box->dato = dato;
	new_box->next = NULL;
	while(p_anchor->next != NULL){p_anchor = p_anchor->next;}
	p_anchor->next = new_box;
	
	return anchor;
}



nodo* remove_duplicates_all(nodo *anchor){
	
	// Dichiarazione delle variabili
	nodo *ANCHOR = anchor;
	nodo *temp = NULL;
	nodo *p_cfr = NULL;
	nodo *previous = NULL;
	
	while(anchor != NULL){
		p_cfr = anchor->next;
		previous = anchor;
		
		while(p_cfr != NULL){
			if(anchor->dato == p_cfr->dato){
				temp = p_cfr;
				p_cfr = p_cfr->next;
				previous->next = p_cfr;
				free(temp);
			}
			else{
				previous = p_cfr;
				p_cfr = p_cfr->next;
			}
		}		
		anchor = anchor->next;
	}
	
	
	return ANCHOR;
}



nodo* remove_duplicates_single(nodo *anchor){
	
	// Dichiarazione delle variabili
	int dato = 0;
	nodo *ANCHOR = anchor;
	nodo *temp = NULL;
	nodo *p_cfr = NULL;
	nodo *previous = NULL;
	
	// Acquisisco il valore da eliminare
	printf("Inserisci il dato che vuoi rimuovere dalla lista: ");
	fflush(stdin);
	scanf("%d", &dato);
	
	while(anchor != NULL){
		if(dato == anchor->dato){
			temp = anchor;
			ANCHOR = anchor->next;
			free(temp);
		}
		else{
			p_cfr = anchor->next;
			previous = anchor;
			
			while(p_cfr != NULL){
				if(dato == p_cfr->dato){
					temp = p_cfr;
					p_cfr = p_cfr->next;
					previous->next = p_cfr;
					free(temp);
				}
				else{
					previous = p_cfr;
					p_cfr = p_cfr->next;
				}
			}
		}	
		anchor = anchor->next;
	}
	
	return ANCHOR;
}



contenitore* spezza(nodo *anchor){
	
	// Dichiarazione delle variabili
	int index = 0, N = 0;
	nodo *p_anchor = anchor;
	contenitore *container = (contenitore*) calloc(1, sizeof(contenitore));
	
	// Determino quanti elementi ho nella lista
	while(p_anchor != NULL){
		p_anchor = p_anchor->next;
		N++;
	}
		
	// Metto da parte il primo puntatore
	container->p1 = anchor;
	
	p_anchor = anchor;
	
	while(index < (N/2)-1){
		p_anchor = p_anchor->next;
		index++;
	}
	// Metto da parte il secondo puntatore
	container->p2 = p_anchor->next;
	
	// Scollego le lista
	p_anchor->next = NULL;
	
	return container;
}



nodo* sort_plus(nodo *anchor){
	
	// Dicharazione delle variabili
	int N = 0, temp = 0;
	nodo *p_anchor = anchor;
	nodo *support = anchor;
	
	// Determino la lunghezza della lista
	while(p_anchor != NULL){
		p_anchor = p_anchor->next;
		N++;
	}
	
	p_anchor = anchor;
	// Effettuo il BubbleSort
	for(int i = 0; i < N; i++){
		support = anchor;
		for(int j = 0; j < N - i - 1; j++){
			if(support->dato > (support->next)->dato){
				temp = support->dato;
				support->dato = (support->next)->dato;
				(support->next)->dato = temp;
			}
			support = support->next;
		}
		p_anchor = p_anchor->next;
	}
	
	return anchor;
}



nodo* sort_minus(nodo *anchor){
	
	// Dicharazione delle variabili
	int N = 0, temp = 0;
	nodo *p_anchor = anchor;
	nodo *support = anchor;
	
	// Determino la lunghezza della lista
	while(p_anchor != NULL){
		p_anchor = p_anchor->next;
		N++;
	}
	
	p_anchor = anchor;
	// Effettuo il BubbleSort
	for(int i = 0; i < N; i++){
		support = anchor;
		for(int j = 0; j < N - i - 1; j++){
			if(support->dato < (support->next)->dato){
				temp = support->dato;
				support->dato = (support->next)->dato;
				(support->next)->dato = temp;
			}
			support = support->next;
		}
		p_anchor = p_anchor->next;
	}
	
	return anchor;
}



nodo* remove_element(nodo *anchor){
	
	// Se la lista è vuota
	if(anchor == NULL){
		return NULL;
	}
	
	// Dichiarazione delle variabili
	int position = 0, index = 1;
	nodo *p_pos = NULL;
	nodo *temp = NULL;
	nodo *p_anchor = anchor;
	
	printf("Inserisci la posizione dell'elemento che vuoi rimuovere, (conta 1): ");
	fflush(stdin);
	scanf("%d", &position);
	
	// Se devo togliere il primo nodo
	if(position == 1){
		temp = anchor;
		anchor = anchor->next;
		free(temp);
		return anchor;
	}
	
	// Tutto il resto
	while(p_anchor != NULL && index != position){
		p_pos = p_anchor;	
		p_anchor = p_anchor->next;
		index++;
	}
	
	// Se sono alla fine 
	if(p_anchor == NULL){
		printf("Hai inserito una posizione che va oltre gli elementi della lista!\n");
		return anchor;
	}
	
	p_pos->next = p_anchor->next;
	free(p_anchor);
	
	
	return anchor;
}



nodo* remove_element_range(nodo *anchor){
	
	// Se la lista è vuota
	if(anchor == NULL){
		return NULL;
	}
	
	// Dichiarazione delle variabili
	int from = 0, to = 0, index = 0;
	nodo *p_from = NULL;
	nodo *temp = NULL;
	nodo *p_anchor = anchor;
	
	printf("Inserisci la posizione da cui partire per effettuare la rimozione, (conta 1): ");
	fflush(stdin);
	scanf("%d", &from);
	
	printf("Inserisci la posizione in cui arrivare, (conta 1): ");
	fflush(stdin);
	scanf("%d", &to);
	
	
	// Controllo
	if(!(from < to)){
		printf("Non hai inserito correttamente gli estremi!\n");
		return anchor;
	}
	
	
	while(p_anchor != NULL && index <= to){
		
		if(index == from - 1) p_from = p_anchor;
		
		if(index >= from && index <= to){
			temp = p_anchor;
			p_anchor = p_anchor->next;
			free(temp);
		}
		else{
			p_anchor = p_anchor->next;
		}
		index++;
	}
	
	if(p_from != NULL){
		p_from->next = p_anchor;
	}
	else{
		anchor = p_anchor;
	}
	
	return anchor;
}



void save_file(nodo *anchor, char scelta){
	
	if(scelta == 'Y'){
		
		// Dichiarazione delle variabili
		int N = 0;
		nodo *p_anchor = anchor;
		
		printf("Scegli il nome del file e aggiungi un estensione, esempio: lista.txt:   ");
		char *filename = prendi_nome_file();
		FILE *my_file = fopen(filename, "w");
		
		// Determino la lunghezza della lista
		while(p_anchor != NULL){
			p_anchor = p_anchor->next;
			N++;
		}
		
		for(int i = 0; i < N; i++){
			fprintf(my_file, "%d\n", anchor->dato);
			anchor = anchor->next;
		}
		
		fclose(my_file);
	}
	
}



void stampa(nodo *anchor){
	printf("\n");
	while(anchor != NULL){
		printf("|%d| -> ", anchor->dato);
		anchor = anchor->next;
	}
	printf("NULL\n");
}



int distruttore(nodo *anchor){
	nodo *temp = NULL;
	while(anchor != NULL){
		temp = anchor;
		anchor = anchor->next;
		free(temp);
	}
	
	return 0;
}
