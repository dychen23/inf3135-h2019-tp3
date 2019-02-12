#include <stdio.h>

void afficherMatrice(int *matrice,int n, int m){	

	if(matrice != NULL)
	{
		for(int i=0; i< n; ++i){
			for(int j=0; j<m; ++j){
				printf("%d ",*matrice++);
			}
				printf("\n");
		}
	}
}

void ajouterMatrice(int *matrice1, int *matrice2, int *matriceVide,int n, int m){

	afficherMatrice(matrice1,n,m);	
	printf("+\n");
	afficherMatrice(matrice2,n,m);
	printf("=\n");
	
	for(int i =0; i<n; ++i){
		for(int j =0; j<m; ++j){
			*matriceVide=*matrice1+*matrice2;
			*matrice1++;*matrice2++;

			printf("%d ",*matriceVide);
		}
			printf("\n");
	}		
	
	
}

int main(int argc, char *argv[]) {
	
	int matrice[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int matrice1[3][3] = {{0,2,1},{1,2,3},{1,5,3}};
	int matrice2[3][3] = {{9,2,7},{2,3,4},{3,2,6}};
	int matriceVide[3][3];

       	afficherMatrice(*matrice,3,3);
	printf("\n");
	afficherMatrice(*matrice,3,3);
	printf("\n");
	ajouterMatrice(*matrice1,*matrice2,*matriceVide,3,3);
        return 0;
}
