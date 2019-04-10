#include "structure.h"
#include <stdlib.h>
#include <stdio.h>

void inserer(noeud_t** noeud, int element){
	
	noeud_t* nouveauNoeud = (noeud_t*)malloc(sizeof(noeud_t));

	nouveauNoeud->element = element;
	nouveauNoeud->suivant = (*noeud);
	nouveauNoeud->precedent = NULL;

	if((*noeud) != NULL){
		(*noeud)->precedent = nouveauNoeud;
	}

	*noeud = nouveauNoeud;

}

void imprimer(noeud_t* n){
	
	noeud_t* dernier;
	
	while(n != NULL){
	
		printf("%d\n",n->element);
		dernier = n;
		n = n->suivant;
	} 
}

