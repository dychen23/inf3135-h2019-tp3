#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//nb parfait = la somme de toute ses diviseurs except lui-meme

long min,max;

//affiche les messages erreurs
void message(int n){
	if(n != 0){
		printf("message erreur %d\n",n);
		exit(0);
	}

	printf("%d\n",n);
}

//validation du fichier
int fichierValide(FILE *fp){
	return fp && fscanf(fp,"%ld %ld",&min, &max) == 2;
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

	int num;
	int i = 1;
	int argumentC = 1;
	int argumentI = 1;
	int argumentO = 1;
	int avecO = 0;
	int avecI = 0;

	char input[100];
	char output[100];

	//char *codePermanent = NULL;

	long ntemp;

	FILE *fp = NULL;
	FILE *fw = NULL;

	//on vérifie tous les arguments
	while(i < argc){
		
		//strcomp retourne 0 si egale		
		if(strcmp(argv[i],"-c") == 0 || strcmp(argv[i],"-C") == 0){
			if(argv[i+1] == NULL || argv[i+1][0] == '-' ){
				argumentC =0;
			} else if(!cpValide(argv[i+1])){
				message(2);
			} else {
				fw = fopen("code.txt","w");	
				fprintf(fw,"%s\n",argv[i+1]);	
			}

		} else if(strcmp(argv[i],"-i") == 0 || strcmp(argv[i],"-I") == 0){
			
			avecI = 1;
			
			if(argv[i+1] == NULL){
				argumentI=0;
			} else {
				strcpy(input,argv[i+1]);

				fp=fopen(input,"r");

				if(!fichierValide(fp)){
					printf("fichier invalide\n");
					message(5);
				}
			}

		} else if(strcmp(argv[i],"-o") == 0 || strcmp(argv[i],"-O") == 0){

			avecO = 1;

			if(argv[i+1]==NULL || argv[i+1][0] == '-'){
				argumentO=0;
			} else {
				strcpy(output,argv[i+1]);
				fw = fopen(output,"w");
			}
 
		} else {
			message(3);
		}

		i+=2;
	}

	if(argc<2 || !argumentC){
		fprintf(stderr, "Usage: %s <-c CODEpermanent> [-i fichier.in] [-o fichier.out] \n", argv[0]);
		exit(0);
	} else if(!argumentI){
		message(5);
	} else if(!intervalleValide(min,max)){
		message(4);
	} else if(!argumentO){
		message(6);
	} 

	if(!avecI){

		fseek (stdin, 0, SEEK_END);
		num = ftell (stdin);
		
		// < redirection
		if(num > 0){
			printf("not empty \n");

	
		//sinon on demande input
		} else {
			printf("fichier entree: \n");
			if(fgets(input,20,stdin)){
				strtok(input, "\n");
				fp=fopen(input,"r");

				if(!fichierValide(fp)){
					printf("fichier invalide\n");
					message(5);
				}
			}
		}
	}	

	if(!avecO){

		fseek (stdout, 0, SEEK_END);
		num = ftell (stdout);
		
		// redirection >
		if(num > 0){
			printf("num \n");

		} else {
	
			printf("fichier sortie:\n");
			fgets(output,20,stdin);
			strtok(output, "\n");
			
			printf("%s\n",output);
			//puts("sasdasdasd\n");
			fw = fopen(output,"w");	
		} 
	} 


	if(min > max){
		ntemp = max;
		max = min;
		min = ntemp;
	}
	printf("\ninput:%s\n",input);
	printf("output:%s\n\n",output);
	for(long i = min; i<= max; i++){
		if(estParfait(i)){
			printf("%ld\n",i);
			fprintf(fw,"%ld\n",i);
		} 
	}

	fclose(fp);
	fclose(fw);

        return 0;
}
