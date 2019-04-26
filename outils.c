#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "structure.h"


uint128_t readU128(char const *string){
	
	int len=strlen(string);

	uint128_t mod=1;
	uint128_t utotal =0;

	for(int i = len-1; i>=0; i--){

		if(string[i] < 48 || string[i] > 57){
			return -1;
		}

		uint128_t temp =(uint128_t) string[i]-48 ; // nombre ascii
		temp *= mod; 
		utotal += temp;
		mod *= 10;
	}
	return utotal;
}

//==============================================================================

void printU128(uint128_t n){
	
	int string[45];
	short compteur=0;
	uint128_t div=10;

	while(n!=0){
		string[compteur]=(n%div);
		n /= div;
		compteur++;
	}


	for(int i = compteur-1; i>=0; i--){
		printf("%d",string[i]);
	}
		printf("\n");
}


//==============================================================================

void swap(uint128_t *min, uint128_t *max){

	uint128_t ntemp;

	ntemp = *max;
	*max = *min;
	*min = ntemp;
}

//==============================================================================

int ASCorDES(char *c){

	return strcmp(c,"asc") == 0 || strcmp(c,"ASC") == 0 || strcmp(c,"des") == 0 || strcmp(c,"DES") == 0 ;
}


//==============================================================================

uint128_t estPremier(uint128_t n){

    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
for (int i=3; (i*i) <= n; i+=2) {
        if (n % i == 0 ) return 0;
    }
    return 1;
}

//==============================================================================

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

//==============================================================================

//verifie si un nombre est parfait
uint128_t estParfait(uint128_t n){

	uint128_t somme = 1;

	for(uint128_t i = 2; i*i<=n; ++i){	
		if(n%i==0){
			if(i*i!=n){
				somme+= i + (n/i);
			} else {
				somme+=i ;
			}
		}
	}
	return (somme == n && n != 1); 
}


//==============================================================================

/*
//validation de l’intervalle 
int intervalleValide(uint128_t min ){
	return (min >= 0 );
}
*/
