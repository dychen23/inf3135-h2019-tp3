#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//nb parfait = la somme de toute ses diviseurs except lui-meme

int argumentValide(char c[]){

	int faux = 0;
	if(strcmp(c,"-c") == 0 || strcmp(c,"-i") == 0 || strcmp(c,"-o") == 0){
		faux = 1;
	}

	//ne peut pas retourner la comparaison directement car strcmp retourne 0 si egale
	return faux;
}

int estCodePermanent(char c[]){
	return strlen(c)==12;
}

long estParfait(long n){

	long parfait = 0;
	long somme = 1;

	//on commence a 2 car sert a rien de tester 1, vu qu’on ne peut pas ajouter lui-meme
	for(long i = 2; i*i<=n; i++){	
		if(n%i==0){
			if(i*i!=n){
				somme+= i + (n/i);
			} else {
				somme+=i ;
			}
		}
	}
	return (somme == n && n!=1); 
}

int main(int argc, char *argv[]) {
	
	int i = 1;
	char a[10] = "";
	
	while(argv[i] != NULL){
	
		strcpy(a,argv[i]);
		printf("%s\n",a);
		i+=2;

		switch((*argv)[i])
		
		case 'c': case 'C'
		
		break;
	}

	

	if(argc<2 || (strcmp(argv[1],"-c") && strcmp(argv[1],"-C")) != 0){
		fprintf(stderr, "Usage: %s <-c CODEpermanent> [-i fichier.in] [-o fichier.out] \n", argv[0]);

	} else {

		long n1,n2,ntemp;
		FILE *fp = fopen(argv[4],"r");

		if(fp!=NULL && fscanf(fp,"%ld %ld",&n1, &n2) == 2){
			
			if(n1 > n2){
				ntemp = n2;
				n2 = n1;
				n1 = ntemp;
			}
			
			for(long i = n1; i<= n2; i++){
				if(estParfait(i)){
					printf("%ld",i);	
					printf(" nb parfait\n");
				}

				//printf("%ld\n",i);	
			}

		fclose(fp);

		} else {
			printf("fichier invalide\n");	
		}	
 	}

        return 0;
}
