#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

//nb parfait = la somme de toute ses diviseurs except lui-meme

void message(int n){
	printf("message erreur %d\n",n);
	exit(0);
}

int cpValide(char c[]){
	return strlen(c)==12;
}

int intervalleValide(long min, long max){
	return (min>=0 && max>=0);
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
	int argumentC = 0;

	char fichiertxt[100] = "data.txt";
	
	printf("%s\n",fichiertxt);
	long n1,n2,ntemp;

	FILE *fp;

	printf("%d\n",argc);

	while(argv[i] != NULL){
		switch(argv[i][1]){
			case 'c': case 'C':
				if(argv[i+1] == NULL){
					fprintf(stderr, "Usage: %s <-c CODEpermanent> [-i fichier.in] [-o fichier.out] \n", argv[0]);
					exit(0);
				} else if(!cpValide(argv[i+1])){
					message(2);
				} else {
					argumentC = 1;
				}
			break;

			case 'i': case 'I':
				
				if(argv[i+1] == NULL){
					message(5);
				}
				
				strcpy(fichiertxt,argv[i+1]);
				fp = fopen(fichiertxt,"r");

								
			break;
		}
		i+=2;
	}

	printf("%s\n",fichiertxt);

	if(argc<2 || argumentC==0){
		fprintf(stderr, "Usage: %s <-c CODEpermanent> [-i fichier.in] [-o fichier.out] \n", argv[0]);

	} else {
	
		fp = fopen(fichiertxt,"r");

		if(fp!=NULL && fscanf(fp,"%ld %ld",&n1, &n2) == 2){
			
			if(n1 > n2){
				ntemp = n2;
				n2 = n1;
				n1 = ntemp;
			}
			
			if(intervalleValide(n1,n2)){
				for(long i = n1; i<= n2; i++){
					if(estParfait(i)){
						printf("%ld",i);	
						printf(" nb parfait\n");
					}
				}
			}
			

			fclose(fp);

		} else {
			printf("fichier invalide\n");	
		}	
 	}

        return 0;
}
