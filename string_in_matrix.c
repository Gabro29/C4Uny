#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

int main(){
	char stringa1[] = "cosa";
	char stringa2[] = "loro";
	char stringa3[] = "geco";
	char stringa4[] = "oggi";
	char stringa5[] = "luca";
	int dim=4;
	int i, j, k;
	char **mat;
	
	mat = (char**)calloc(dim, sizeof(char*));
	
	for(i=0; i<dim; i++) {
		mat[i] = (char*)calloc(dim, sizeof(char));
	}
	
	// Assign value for each rows
	for(i=0; i<dim; i++){
		for(j=0; j<dim; j++){
			switch(i){
				case 0:
					mat[i][j] = stringa1[j];
					break;
				case 1:
					mat[i][j] = stringa2[j];
					break;
				case 2:
					mat[i][j] = stringa3[j];
					break;
				case 3:
					mat[i][j] = stringa4[j];
					break;
				default:
					printf("Some Error\n");
					break;
			}
		}
	}
	
	for(i=0; i<dim; i++){
		printf("%s", mat[i]);		
		printf("\n");
	}
	
	
	// Creo la trasposta
	
	char **Tmat;
	
	Tmat = (char**)calloc(dim, sizeof(char*));
	for(i=0; i<dim; i++) {
		Tmat[i] = (char*)calloc(dim, sizeof(char));
	}
	char temp[4];
	for(i=0; i<dim; i++){
		for(j=0; j<dim; j++){
			temp[j] = mat[j][i];
			Tmat[i][j] = temp[j];
		}
	}	
	
	printf("\n");
	for(i=0; i<dim; i++){
		printf("%s", Tmat[i]);		
		printf("\n");
	}
	
	
	
	// Aggiungo un altra riga a mat
	mat = (char**)realloc(mat, (dim+1)*sizeof(char*));
	
	mat[dim] = "luca";
	printf("\n");
	for(i=0; i<dim+1; i++){
		printf("%s", mat[i]);		
		printf("\n");
	}
	
	
	// Aggiungo un altra colonna a mat
	mat = (char**)calloc(dim+1, sizeof(char*));
	
	for(i=0; i<dim+1; i++) {
		mat[i] = (char*)calloc(dim+2, sizeof(char));
	}
	
		// Assign value for each rows
	for(i=0; i<dim+1; i++){
		for(j=0; j<dim; j++){
			switch(i){
				case 0:
					mat[i][j] = stringa1[j];
					break;
				case 1:
					mat[i][j] = stringa2[j];
					break;
				case 2:
					mat[i][j] = stringa3[j];
					break;
				case 3:
					mat[i][j] = stringa4[j];
					break;
				case 4:
					mat[i][j] = stringa5[j];
				default:
					printf("Some Error%d\n", i);
					break;
			}
		}
	}



	for(i=0; i<dim+1; i++){
		mat[i][dim] = 'p';
	}
	
	for(i=0; i<dim+1; i++){
		mat[i][dim+1] = 'p';
	}
	
	
	printf("\n");
	for(i=0; i<dim+1; i++){
		for(j=0; j<dim+2; j++){
			printf("%c", mat[i][j]);		
		}
		printf("\n");
	}
	
	for(i=0; i<dim; i++) free(mat[i]);
	free(mat);
	for(i=0; i<dim; i++) free(Tmat[i]);
	free(Tmat);
	printf("MEMORIA PULITA\n");	
	
	
	return 0;
}