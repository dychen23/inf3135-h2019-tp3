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
//#define testajout
//#define max

int main(int argc, char *argv[]) {

	noeud *arbre = NULL;
	
	//int num;
	int i = 1;
	int erreur4 = 4;
	
	bool avecC = 1;
	bool avecI = 0;

	char output[100];
	//char temp[100];
	
	char s1[40]; //(char *)malloc();
	char s2[40]; //(char *)malloc();

	uint128_t min = 0;
	uint128_t max = 0;

	char *err = "340282366920938463463374607431768211455";
	uint128_t uint128_err = readU128(err);
	
	#ifdef max
		printU128(uint128_err,stdout);
	#endif

	FILE * fp = stdin;
	FILE * fw = stdout;
	FILE * fww = stdout;

	int tri = des;

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

			while(fscanf(fp,"%s %s",s1,s2) != EOF) {

				min = readU128(s1);
				max = readU128(s2);

				if(min != uint128_err && max != uint128_err) {
					verificationNombre(&min,&max,&arbre);	
					erreur4 = 0;
				} 	
			}	

			if(erreur4==4) exit(erreur4);
		
		} else if(strcmp(argv[i],"-o") == 0 || strcmp(argv[i],"-O") == 0){

			if(argv[i+1]==NULL || argv[i+1][0] == '-'){
				exit(6);
			} 
			
			strcpy(output,argv[i+1]);
			fww = fopen(output,"w");

			if(fww == NULL) exit(6);

		} else if(strcmp(argv[i],"-d") == 0 || strcmp(argv[i],"-D") == 0){

			char *argumentD = argv[i+1];
			
			if(argv[i+1]== NULL || !ASCorDES(argumentD)) {
				exit(7);
			}
			
			if(strcmp(argumentD,"asc") == 0 || strcmp(argumentD,"ASC") == 0){
				tri=asc;
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

		while(fscanf(fp,"%s %s",s1,s2) != EOF) {				

			min = readU128(s1);
			max = readU128(s2);

			if(min != uint128_err && max != uint128_err) {
				verificationNombre(&min,&max,&arbre);
				erreur4 = 0;	
			}
		}	
						
	}

	if(erreur4==4) exit(erreur4);	
	
	tri == asc ? afficherArbre(arbre, fww): afficherArbreInverse(arbre, fww);

	fclose(fp);
	fclose(fw);

	if(arbre != NULL)clearTree(&arbre);

        return 0;
}
