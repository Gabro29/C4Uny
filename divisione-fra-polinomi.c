#include <stdio.h>

int main (){
	float Pdividendo[50], Pdivisore[50], Prisultato[50], Ppassaggio[50];
	int m, q, l, i, j, k, grado_dividendo, grado_divisore, continua;
	do{
	int pass=0;
	
	// Inserimento gradi delle dividendo e divisore
	while(pass==0){
		printf("Inserisci il grado del Polinomio dividendo: ");
		scanf("%i", &grado_dividendo);
		printf("Inserisci il grado del Polinomio divisore: ");
		scanf("%i", &grado_divisore);
		if(grado_dividendo>0 && grado_divisore>0){
			if(grado_dividendo>=grado_divisore){
				pass=1;
			}else if(grado_dividendo<grado_divisore){
				printf("Il grado del dividendo non puo' essere minore del grado del divisore \n\n");
			}
	}else{
		printf("Non puoi utilizzare dei gradi negativi \n \n");
	}
}
	
	//azzeramento vettori
	for(i=0;i<grado_dividendo+1;i++){
    Pdivisore[i]=0;
    Pdividendo[i]=0;
    Ppassaggio[i]=0;
    Prisultato[i]=0;
		}
	printf("\n\n");
	//inserimento coefficenti delle x
	for(i=0;i<grado_dividendo+1;i++){
		if(i==0){
		 printf("Inserisci il termine noto del dividendo: " );
		}else if(i==1){
		printf("Inserisci il Coefficente di x del dividendo: ");	
		}else{
		printf("Inserisci il Coefficente di x^%i del dividendo: ", i);
	    }
		scanf("%f", &Pdividendo[i]);
	}
	
	while(Pdividendo[grado_dividendo]==0){
		printf("Devi inserire un coefficente di grado massimo: ");
		scanf("%f", &Pdividendo[grado_dividendo]);
	}
	
	printf("\n\n");		
	
	
	for(j=0;j<grado_divisore+1;j++){
		if(j==0){
		 printf("Inserisci il termine noto del divisore: " );
		}else if(j==1){
		printf("Inserisci il Coefficente di x del divisore: ");	
		}else{
		printf("Inserisci il Coefficente di x^%i del divisore: ", j);
	    }
		scanf("%f", &Pdivisore[j]);
	}
	
	// Effettuo la divisione
   q=grado_dividendo;
   i=grado_dividendo;
   j=grado_divisore;
   k=i-j;
   
   for(k=i-j;k>-1;k--){
   j=grado_divisore;
   Prisultato[k]=Pdividendo[q]/Pdivisore[j];
   q--;
   for(j=grado_divisore;j>-1;j--){
   	l=k+j;
   Ppassaggio[l]=Prisultato[k]*Pdivisore[j];
   }
   
   for(i=grado_dividendo;i>-1;i--){
   Pdividendo[i]= Pdividendo[i]-Ppassaggio[i];
}
  // azzeramento Polinomio di passaggio
  for(m=0;m<grado_dividendo+1;m++){
  	Ppassaggio[m]=0;
  }

}
   printf("\n\n");
//Mostra Risultato
   i=grado_dividendo;
   j=grado_divisore;
   printf("Il risultato di questa divisione e': ");
for(k=i-j;k>-1;k--){
	if(k==0){
		printf("(%.2f)",Prisultato[k]);
	} else if(k==1){
		printf("(%.2f)x+",Prisultato[k]);
	}else{
	printf("(%.2f)x^%i+",Prisultato[k],k);
}
}
printf("\ncon resto: ");
for(i=grado_dividendo;i>-1;i--){
	if(Pdividendo[i]!=0){
	if(i==0){
		printf("(%.2f)",Pdividendo[i]);
	}else if(i==1){
		printf("(%.2f)x+",Pdividendo[i]);
	} else{
	printf("(%.2f)x^%i+",Pdividendo[i],i);
}
}
}
if(Pdividendo[0]==0){
	printf("(%lf)",Pdividendo[0]);
}

printf("\n\n");
printf("Vuoi eseguire un altra divisione?\n1->Si  2->No: ");
scanf("%i", &continua);
printf("\n\n");	
}while(continua==1);

return 0;
}
