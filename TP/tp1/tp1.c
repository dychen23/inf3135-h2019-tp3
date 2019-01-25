#include <stdio.h>

//nb parfait = la somme de toute ses diviseurs except lui-meme

long estParfait(long n){

	long parfait = 0;
	long somme = 1;

	//peut-on conclure qu’il n’y a pas de nombre parfait impair?
	if(n%2!=0){
		//printf(“bye\n");
		return parfait;
	}

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
	
	return somme == n; 
}

int main(int argc, char *argv[]) {
	
	for(long i = 0; i<= 9000; i++){

		if(estParfait(i)){
			printf("%ld",i);	
			printf(" nb parfait\n");
		}

		else {
			//printf("%ld\n",i);
		}

	}
		

        return 0;
}
