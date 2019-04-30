#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

#include "structure.h"

uint128_t exposant(uint128_t a, uint128_t b){

	uint128_t n = 1;
	uint128_t m = 1;

	while(m <= b){
		n *= a;
		m++;		
	}
	return n;
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

int verifierasc(char *c){
	
	return strcmp(c,"asc") == 0 ;
}


//==============================================================================

uint128_t estPremier(uint128_t n){

    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    uint128_t nb_racine = sqrt(n);
    
for (uint128_t i=3; i <= nb_racine; i+=2) {
        if (n % i == 0 ) return 0;
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

void verificationNombre(uint128_t *min, uint128_t *max,noeud **arbre){

	uint128_t total = 0;

	for(uint128_t p = 2; p<=65 && total < *max; ++p){
		if(estPremier(p)){
			uint128_t MersennePrime = exposant(2,p)-1;
			uint128_t a = exposant(2,p-1)*MersennePrime;

			if(estPremier(MersennePrime)){
		
				if(*min > *max){
					swap(min,max);
				}
				
				if(a <= *max && a>= *min){
					if(!(noeudExiste(*arbre,a))){
						ajoutNoeud(arbre,a);
					}		
				}

				total = a;
			}
		}
	}
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

/*
//validation de l’intervalle 
int intervalleValide(uint128_t min ){
	return (min >= 0 );
}
*/
