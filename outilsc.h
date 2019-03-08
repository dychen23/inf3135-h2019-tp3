#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>


void swap(unsigned long *min,unsigned long *max){
	unsigned long ntemp;

		ntemp = *max;
		*max = *min;
		*min = ntemp;
}

int estPremier(long n){

	if(n==2) return 1;
/*
	if(n==3) return 1;
	if(n==5) return 1;
        if(n==7) return 1;
	if(n%2==0) return 0;
	if(n%3==0) return 0;
	if(n%5==0) return 0;
        if(n%7==0) return 0;
*/
	for(int i =3;i*i <= n; i+=2){
		if(n%i==0){
			return 0;
		}
	}
	
	return 1;
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

//verifie si un nombre est parfait
int estParfait(long n){

	unsigned long somme = 1;
	
	//on commence a 2 car sert a rien de tester 1, vu qu’on ne peut pas ajouter lui-meme
	for(unsigned long i = 2; i*i<=n; ++i){	

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

int estParfait2(long n){
	
	unsigned long prime;
        unsigned long total;

	for(int i = 2; i*i <= n; ++i){
		
		if(estPremier(i)){
		prime = pow(2,i)-1;

		if(estPremier(prime)){ 
				//printf("i = 2: %lu %lu\n",prime,total);
			total = pow(2,i-1)*prime;

			if(n==total)return 1;	
		}
		}
	}

	return 0;
}

//validation de l’intervalle 
int intervalleValide(long min, long max){
	return (min>=0 && max>=0);
}

