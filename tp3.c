#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include "outils.h"
#include "structure.h"
#include <math.h>
#include <stdbool.h>

//#define TRACE
//#define testarbre
//#define testu128t
 
int main(int argc, char *argv[]) {

	#ifdef testarbre
		noeud *arbre = NULL;
	
		ajoutNoeud(&arbre,5);
		ajoutNoeud(&arbre,30);

		printTree(arbre);
		printf("=========\n");
		printReverseTree(arbre);

		if(rechercheNoeud(arbre,5)){

		printf("existe deja\n");		
		}	

	#endif

	#ifdef testu128t
		char *a = "123456789123456789123456789012345111111";

		uint128_t n = readU128(a);
	
		printU128(n);

		printf("%lu de longeur\n",strlen(a));
	#endif

	int num;
	int i = 1;
	
	bool avecC = 1;
	bool avecI = 0;
	bool avecO = 0;

	char output[100];
	char temp[100];
	
	char s1[40]; //(char *)malloc();
	char s2[40]; //(char *)malloc();

	uint128_t min = 0;
	uint128_t max = 0;
	
	FILE *fp = stdin;
	FILE *fw = stdout;

	//on vérifie tous les arguments
	while(i < argc){
	
		if(strcmp(argv[i],"-c") == 0 || strcmp(argv[i],"-C") == 0){
			if(argv[i+1] == NULL || argv[i+1][0] == '-' ){
				avecC = 0;
			} else if(!cpValide(argv[i+1])){
				exit(2);	
			} 

			fw = fopen("code.txt","w");	
			fprintf(fw,"%s\n",argv[i+1]);	
	

		} else if(strcmp(argv[i],"-i") == 0 || strcmp(argv[i],"-I") == 0){
			
			avecI = 1;
			
			fp=fopen(argv[i+1],"r");

			if(argv[i+1] == NULL || !(fp)){
				exit(5);
			} 

			int erreur4 = 4;

			while(!feof(fp)){
				
				if(fscanf(fp,"%s %s",s1,s2)==2){
					
					erreur4 = 0;

					min = readU128(s1);
					max = readU128(s2);

					if(min == -1 || max == -1){
						exit(4);
					}
				} 				
			}		
		
		} else if(strcmp(argv[i],"-o") == 0 || strcmp(argv[i],"-O") == 0){

			avecO = 1;

			if(argv[i+1]==NULL || argv[i+1][0] == '-'){
				exit(6);
			} 
			
			strcpy(output,argv[i+1]);
			fw = fopen(output,"w");

			if(fw == NULL) exit(6);

		} else if(strcmp(argv[i],"-d") == 0 || strcmp(argv[i],"-D") == 0){

			char *argumentD = argv[i+1];
			
			if(argv[i+1]== NULL || !ASCorDES(argumentD)) {
				exit(7);
			} 
			
		} else {
			exit(3);
		}

		i+=2;
	}

	if(argc<2 || !avecC){
		fprintf(stderr, "Usage: %s <-c CODEpermanent> [-i fichier.in] [-o fichier.out] \n", argv[0]);
		exit(1);
	} 
	
	if(!avecI){
 
		//scanf("%lu %lu",&min, &max);

		fseek (stdin, 0, SEEK_END);
		num = ftell (stdin);
		
		rewind(stdin);

		// < data.txt
		if(num > 0){
			
			//fp=stdin;
			
			if(!fp) exit(5);
				
			fgets(temp,100,stdin);
			strtok(temp, "\n");

			char *r;
			char *ptr;
				
			r = strtok(temp," ");
			min = strtol(r,&ptr,10);
			
			r = strtok(NULL," "),
			max= strtol(r,&ptr,10);
			
		} 
	}	
		
	if(min > max){
		swap(&min,&max);
	} 

	for(uint128_t p = 2; p<=65; ++p){
	
		uint128_t MersennePrime = pow(2,p)-1;
		uint128_t a = pow(2,p-1)*MersennePrime;

		if(estPremier(MersennePrime) && a<=max && a >= min){
			
			if(estParfait(a)){
				if(avecO){
					//fprintf(fw,"%llu\n",a);		
				} else {
					printU128(a);
					//printf("%llu\n",a);
				}
			} 
		}
	}

	fclose(fp);
	fclose(fw);

	#ifdef testarbre
		clearTree(&arbre);
	#endif

        return 0;
}
