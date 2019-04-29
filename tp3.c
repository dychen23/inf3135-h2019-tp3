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

int main(int argc, char *argv[]) {

	noeud *arbre = NULL;
	
	#ifdef testarbre
		noeud *arbre = NULL;
	
		ajoutNoeud(&arbre,5);
		ajoutNoeud(&arbre,30);

		printTree(arbre);
		printf("=========\n");
		printReverseTree(arbre);

		if(noeudExiste(arbre,5)){

		printf("existe deja\n");		
		}	

	#endif

	#ifdef testu128t
		char *a = "123456789098765432123456789098765432123";

		uint128_t n = readU128(a);
	
		printU128(n);

		printf("%lu de longeur\n",strlen(a));

		
		uint128_t b = 19 ;
		uint128_t c = 28 ;

		if(c<b) printf(" 19 < 28 ");
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

			int erreur4 = 4;

			while(!feof(fp)){
				
				if(fscanf(fp,"%s %s",s1,s2)==2){
					
					erreur4 = 0;

					min = readU128(s1);
					max = readU128(s2);

					verificationNombre(&min,&max,&arbre);
				} 			
			}	

			if(erreur4==4) exit(erreur4);
		
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

	#ifdef testajout
	if(min > max){
		swap(&min,&max);
	} 

	//afficherArbre(arbre);
	//afficherArbreInverse(arbre);

	#endif	
	
	tri == asc ? afficherArbre(arbre,fw): afficherArbreInverse(arbre,fw);

	

	fclose(fp);
	fclose(fw);

	clearTree(&arbre);

        return 0;
}
