#include<stdio.h>
#include<stdlib.h>


// Prototipi di funzione
int* invertiArray(int*, int);
void stampa(int*, int);


int main(void){
	
	// Scopo del programma
	printf("\nQuesto programma prende in input un array di dimensione N e lo inverte\n");
	
	// Dichiarazione delle variabili
	int N = 0;
	
	printf("\n");
	
	printf("Quanti elementi vuoi inserire? ");
	scanf("%d", &N);
	
	int array[N];
	int *p_array = array;
	
	// Riempio l'array
	
	for(int i = 0; i< N; i++){
		printf("Inserisci il %d elemento: ", i+1);
		scanf("%d", &array[i]);
		fflush(stdin);
	}
	
	// Eseguo l'inversione
	p_array = invertiArray(p_array, N);
	// Stampo
	stampa(p_array, N);
	
	
	return 0;
}


int* invertiArray(int *array, int N){
	// Dichiarazione delle variabili
	int temp = 0;
	
	for(int i = 0; i < N/2; i++){
		temp = *(array + i);
		*(array + i) = *(array + N - i - 1);
		*(array + N - i - 1) = temp;
	}
	return array;
}


void stampa(int *array, int N){
	printf("\n[");
	for(int i = 0; i < N; i++){
		i != (N-1) ? printf("%d, ", *(array + i)) : printf("%d", *(array + i));
	}
	printf("]\n");
}
