#include<stdio.h>
#include<stdlib.h>


// Direttive
#define ERROR_EXIT() printf("\nErrore nell'allocazione della memoria\n"); exit(1);

// Prototipi di Funzione
int* riempi_array(void);
int* ordinamentoCrescente(int*);
void stampa(int*);
void distruggi(int*);


int main(void){
	
	// Scopo del programma
	printf("\nQuesto programma prende in input dei valori interi e li ordina in senso crescente\n");
	
	// Popolo l'array
	printf("\nInserisci i valori nell'array (digita 0 per interrompere):\n");
	int *array = riempi_array(); 
	// Da notare che l'array returnato ha come ultimo elemento 0 in modo da determinare la lunghezza dell'array in un secondo momento
	
	// Ordinamento mediante BubbleSort
	array = ordinamentoCrescente(array);
	
	// Visualizzo a schermo
	stampa(array);
	
	// Pulisco la Memoria
	distruggi(array);
	
	return 0;
}



int* riempi_array(void){
	
	// Dichiarazione delle variabili
	int number = 0, index = 1;
	int *array = (int*) calloc(index, sizeof(int));
	
	if (array == NULL) {
	    printf("Errore nell'allocazione della memoria\n");
	    exit(EXIT_FAILURE);
	}

	while(1){
		printf("\tValore %d: ", index);
		scanf("%d", &number);
		
		if(number == 0) break;
		
		if(number != 0){
			
			array = (int*) realloc(array, index * sizeof(int));
			if (array == NULL) {
			    printf("Errore nell'allocazione della memoria\n");
			    exit(EXIT_FAILURE);
			}
			
			*(array + index - 1) = number;
		
		}
		
		
		index++;
	}
	
	return array;
}



int* ordinamentoCrescente(int *array){
	// Dichiarazione delle variabili
    int temp, flag = 0, LEN = 1;
    
    // Determino la lunghezza dell'array sfruttando la posizione dell'ultimo elemento
    while (array[LEN] != 0) {
        LEN++;
    }

    for(int i = 0; i < LEN; i++) {
        for(int j = 0; j < LEN - i - 1; j++) {
            if(array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = 1;
            }
        }
        // Se l'array è già ordinato
        if(flag == 0) break;
    }
	return array;
}


void stampa(int *array){
	printf("\nL'array ordinato e':\n[");
	for(int i = 0; array[i] != 0; i++){
		array[i+1] != 0 ? printf("%d, ", array[i]) : printf("%d", array[i]);
	}
	printf("]\n");
}



void distruggi(int *array){
	free(array);
}
