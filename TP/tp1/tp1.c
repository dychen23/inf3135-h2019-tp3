#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//nb parfait = la somme de toute ses diviseurs except lui-meme

long n1,n2;

//affiche les messages erreurs
void message(int n){
	if(n != 0){
		printf("message erreur %d\n",n);
		exit(0);
	}

	printf("%d",n);
}

int nomFichierValide(char *nom){
	return (strcmp(nom,".txt")==0);
}

//validation du fichier
int fichierValide(FILE *fp){
	return fp && fscanf(fp,"%ld %ld",&n1, &n2) == 2;
}

//validation du code permanent
int cpValide(char *c){
	
	if(strlen(c)!=12){
		return 0;
	}
	
	char *cp = c;
	
	for(int i =0; i< strlen(c) ; i++,cp++){
		if((i<4 && !isalpha(*cp)) || (i>4 && !isdigit(*cp))){
			return 0;
		} 	
	}
				
	return 1;
}

//validation de l’intervalle 
int intervalleValide(long min, long max){
	return (min>=0 && max>=0);
}

//verifie si un nombre est parfait
long estParfait(long n){

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
	int argumentO = 1;
	int sansO = 1;

	char input[100] = "data.txt";
	char output[100] = "resultat.txt";
	char *codePermanent = NULL;

	//printf("%s\n",fichiertxt);
	long ntemp;

	FILE *fp=fopen(input,"r");
	FILE *fw;

	if(!fichierValide(fp)){
		message(5);
	}

	//on vérifie tous les arguments
	while(i < argc){
		
		//strcomp retourne 0 si egale		
		if(strcmp(argv[i],"-c") == 0 || strcmp(argv[i],"-C") == 0){
			if(argv[i+1] == NULL || argv[i+1][0] == '-' ){
				argumentC =0;
			} else if(!cpValide(argv[i+1])){
				message(2);
			} else {
				codePermanent = argv[i+1];
				fw = fopen("code.txt","w");
				fwrite(codePermanent,sizeof(codePermanent),4,fw);	
			}
		} else if(strcmp(argv[i],"-i") == 0 || strcmp(argv[i],"-I") == 0){

			printf("%s\n",argv[i+1]);

			fp = fopen(argv[i+1],"r");
		
			if(argv[i+1] == NULL || !fichierValide(fp)){
				argumentI=0;
			}

		} else if(strcmp(argv[i],"-o") == 0 || strcmp(argv[i],"-O") == 0){

			if(argv[i+1]==NULL){
				message(6);
			}
			
			char *r;
			r=strstr(argv[i+1],".txt");

			if(r==NULL){
				argumentO=0;
			} else {
				fw = fopen(argv[i+1],"w+b");
				sansO = 0;
			}

		} else {
			message(3);
		}
		i+=2;
	}

	if(argc<2 || !argumentC){
		fprintf(stderr, "Usage: %s <-c CODEpermanent> [-i fichier.in] [-o fichier.out] \n", argv[0]);
	} else if(!argumentI){
		message(5);
	} else if(!intervalleValide(n1,n2)){
		message(4);
	} else if(!argumentO){
		message(6);
	} else {
	
		printf("%s\n",codePermanent);

		if(n1 > n2){
			ntemp = n2;
			n2 = n1;
			n1 = ntemp;
		}

		for(int32_t i = n1; i<= n2; i++){
			if(estParfait(i)){
				printf("%d\n",i);	
				//printf(" nb parfait\n");
				
				if(sansO){	
					fw = fopen(output,"w+");
				}
				
				fwrite(&i,sizeof(&i),16,fw);
			} 
		}
		
		if(argumentO){
			printf("redirection ok\n");
		}

		//message(0);

		fclose(fp);
		fclose(fw);
 	}

        return 0;
}
