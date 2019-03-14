#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "outils.h"
#include <math.h>

//#define TRACE
//#define valeur

int main(int argc, char *argv[]) {

	int num;
	int i = 1;
	int argumentC = 1;
	int avecO = 0;
	int avecI = 0;

	char output[100];
	char temp[100];

	unsigned long min,max;

	FILE *fp = stdin;
	FILE *fw = stdout;

	#ifdef valeur
	printf("%lu\n",sizeof(unsigned long));
	#endif

	//on vérifie tous les arguments
	while(i < argc){
		
		#ifdef TRACE
		if(argv[i][0]=='-'){
			
			switch(argv[i][1]){
				case 'c' : printf("c\n"); break;
						
			
				case 'i' : printf("i\n"); break;
				case 'o' : printf("o\n"); break;
	
				default: exit(3); break;
			}
		}
		#endif

		//strcomp retourne 0 si egale		
		if(strcmp(argv[i],"-c") == 0 || strcmp(argv[i],"-C") == 0){
			if(argv[i+1] == NULL || argv[i+1][0] == '-' ){
				argumentC =0;
			} else if(!cpValide(argv[i+1])){
				exit(2);	
			} 

			fw = fopen("code.txt","w");	
			fprintf(fw,"%s\n",argv[i+1]);	
	

		} else if(strcmp(argv[i],"-i") == 0 || strcmp(argv[i],"-I") == 0){
			
			avecI = 1;
			
			if(argv[i+1] == NULL){
				exit(5);
			} 

			fp=fopen(argv[i+1],"r");

			if(!(fp && fscanf(fp,"%lu %lu",&min, &max) == 2)){
					exit(5);
			}

		} else if(strcmp(argv[i],"-o") == 0 || strcmp(argv[i],"-O") == 0){

			avecO = 1;

			if(argv[i+1]==NULL || argv[i+1][0] == '-'){
				exit(6);
			} 
			
				strcpy(output,argv[i+1]);
				fw = fopen(output,"w");

				if(fw == NULL) exit(6);

		} else {
			exit(3);
		}

		i+=2;
	}

	if(argc<2 || !argumentC){
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
			
			fp=stdin;
			
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
		unsigned long a = pow(2,p-1)*MersennePrime;

		if(estPremier(MersennePrime) && a<=max && a >= min){
			if(estParfait(a)){
				if(avecO){
					fprintf(fw,"%ld\n",a);		
				} else {
					printf("%ld\n",a);
				}
			} 
		}
	}

	fclose(fp);
	fclose(fw);

        return 0;
}
