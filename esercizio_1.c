#include<stdio.h> 
#include<stdlib.h>

// Dimension of the string
#define N 100


char* consonanti(char *pointer){

	char vocals[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
	char consonants[N];
	char *pconsonants = consonants;
	int k = 0, l = 0;
	
	for(int i = 0; i < N; i++){
		k = 0;
		// The element is in the alphabet
		if(97 <= (int) *(pointer + i) <= 122 || 65 <= (int) *(pointer + i) <= 90){
			for(int j = 0; j < 20; j++){
				if(*(pointer + i) != vocals[j]){
					k++;
				}
				else{
					printf("Ho trovato una vocale, la vocale e' %c\n", *(pointer + i));
				}
			}
			
			if(k == 20){
				*(pconsonants + l) = *(pointer + i);
				l++;
			}
			
		}
	}
	
	return pconsonants;

}



int main(){
	
	char stringa[N];
	char letter;
	char *pstring;
	int index = 0;
	
	pstring = stringa;
	
	printf("Inserisci la stringa\n");
	
	
	
	do{
		letter = getchar();
		*(pstring + index) = letter;
		index ++;
	}
	while(letter != '\n' && index < N);
	
	
	char *consonants = (char*)calloc(N, sizeof(char));
	
	consonants = consonanti(pstring);
	printf("Le consonanti contenute nella stringa in serita sono ");
	printf("%s", consonants);
	printf("\n");

	return 0;
}













