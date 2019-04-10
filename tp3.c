#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include "outils.h"
#include "structure.h"
#include <math.h>

//#define TRACE
//#define valeur

int main(int argc, char *argv[]) {

	int num;
	int i = 1;
	
	enum bool avecC = T;
	enum bool avecI = F;
	enum bool avecO = F;

	char output[100];
	char temp[100];
	
	unsigned long min = 0;
	unsigned long max = 0 ;

	FILE *fp = stdin;
	FILE *fw = stdout;

	#ifdef valeur
	printf("%lu\n",sizeof(unsigned long));
	#endif

	//on vérifie tous les arguments
	while(i < argc){
	
		if(strcmp(argv[i],"-c") == 0 || strcmp(argv[i],"-C") == 0){
			if(argv[i+1] == NULL || argv[i+1][0] == '-' ){
				avecC = F;
			} else if(!cpValide(argv[i+1])){
				exit(2);	
			} 

			fw = fopen("code.txt","w");	
			fprintf(fw,"%s\n",argv[i+1]);	
	

		} else if(strcmp(argv[i],"-i") == 0 || strcmp(argv[i],"-I") == 0){
			
			avecI = T;
			
			if(argv[i+1] == NULL){
				exit(5);
			} 

			fp=fopen(argv[i+1],"r");

			if(!fp){
				exit(5);
			}
			/*
			if(!(fp && fscanf(fp,"%lu %lu",&min, &max) == 2)){
				exit(5);
			}
			*/

			while(!feof(fp)){
		
				if(fscanf(fp,"%lu %lu",&min, &max)==2){
					//printf("%lu %lu\n",min,max);
				} 
			}		
			
		

		} else if(strcmp(argv[i],"-o") == 0 || strcmp(argv[i],"-O") == 0){

			avecO = T;

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

		scanf("%lu %lu",&min, &max);

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
	
	if(!intervalleValide(min,max)){
		exit(4);
	}

	if(min > max){
		swap(&min,&max);
	}
	
	for(int p = 2; p<=31; ++p){
	
		unsigned long MersennePrime = pow(2,p)-1;
		unsigned long long a = pow(2,p-1)*MersennePrime;

		if(estPremier(MersennePrime) && a<=max && a >= min){
			
			if(estParfait(a)){
				if(avecO){
					fprintf(fw,"%llu\n",a);		
				} else {
					printf("%llu\n",a);
				}
			} 
		}
	}

	fclose(fp);
	fclose(fw);

        return 0;
}
