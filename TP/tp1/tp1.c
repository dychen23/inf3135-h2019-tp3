#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

//nb parfait = la somme de toute ses diviseurs except lui-meme

long n1,n2;

//affiche les messages erreurs
void message(int n){
	printf("message erreur %d\n",n);
	exit(0);
}


//validation des characteres d’entree
int charValide(char *c1){

	return strcmp(c1,"-c")==0 || strcmp(c1,"-C") ||
	       strcmp(c1,"-i")==0 || strcmp(c1,"-I") ||
	       strcmp(c1,"-o")==0 || strcmp(c1,"-O");
}


//validation du fichier
int fichierValide(FILE *fp){
	return fp && fscanf(fp,"%ld %ld",&n1, &n2) == 2;
}

//validation du code permanent
int cpValide(char c[]){
	return strlen(c)==12;
}

//validation de l’intervalle 
int intervalleValide(long min, long max){
	return (min>=0 && max>=0);
}

//verifie si un nombre est parfait
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
	int argumentC = 1;
	int argumentI = 1;

	char fichiertxt[100] = "data.txt";
	char charactere;
	
	printf("%s\n",fichiertxt);
	long ntemp;

	FILE *fp=fopen(fichiertxt,"r");
	fichierValide(fp)? : message(5);

	//on vérifie tous les arguments
	while(i < argc){
		
		//strcomp retourne 0 si egale		
		if(strcmp(argv[i],"-c") == 0 || strcmp(argv[i],"-C") == 0){
			if(argv[i+1] == NULL || argv[i+1][0] == '-' ){
				argumentC =0;
			} else if(!cpValide(argv[i+1])){
				message(2);
			} 
		}
			
		 else if(strcmp(argv[i],"-i") == 0 || strcmp(argv[i],"-I") == 0){
			if(argv[i+1] == NULL){
				message(5);
			}

			strcpy(fichiertxt,argv[i+1]);
			fp = fopen(fichiertxt,"r");

			if(!fichierValide(fp)){
				argumentI = 0;
			} 	
		} else if(strcmp(argv[i],"-o") == 0 || strcmp(argv[i],"-O") == 0){
			
		} else {
			message(3);
		}
			
		i+=2;

		/*
		switch(argv[i][1]){
			case 'c': case 'C':
				if(argv[i+1] == NULL || argv[i+1][0] == '-' ){
					argumentC =0;
				} else if(!cpValide(argv[i+1])){
					message(2);
				} 
			break;

			case 'i': case 'I':	
				if(argv[i+1] == NULL){
					message(5);
				}

				strcpy(fichiertxt,argv[i+1]);
				fp = fopen(fichiertxt,"r");

				if(!fichierValide(fp)){
					argumentI = 0;
				} 								
			break;

			case 'o': case 'O':
			break;

			default:
				message(3);
			break;
			
		}
		//printf("%s\n",argv[i]);
		i+=2;
		*/
	}

	//printf("%s\n",fichiertxt);

	if(argc<2 || !argumentC){
		fprintf(stderr, "Usage: %s <-c CODEpermanent> [-i fichier.in] [-o fichier.out] \n", argv[0]);
	} else if(!argumentI){
		message(5);
	} else if(!intervalleValide(n1,n2)){
		message(4);
	} else {
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
		}

		fclose(fp);
 	}

        return 0;
}
