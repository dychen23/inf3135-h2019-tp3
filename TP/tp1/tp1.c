#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

//nb parfait = la somme de toute ses diviseurs except lui-meme

void message(int n){
	printf("%d\n",n);
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
	char a[10] = "";

	while(argv[i] != NULL){
	
		if(argc<2){
			fprintf(stderr, "Usage: %s <-c CODEpermanent> [-i fichier.in] [-o fichier.out] \n", argv[0]);
		}

		switch(argv[i][1]){

			case 'c': case 'C':
				if(argv[i+1] == NULL){
					fprintf(stderr, "Usage: %s <-c CODEpermanent> [-i fichier.in] [-o fichier.out] \n", argv[0]);
					exit(0);
				} else if(!cpValide(argv[i+1])){
					message(2);
				} 
			break;

			case 'i': case 'I':
				
			break;
		}
		i+=2;
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
