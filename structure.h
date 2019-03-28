
#ifndef STRUCTURE_H
#define STRUCTURE_H
	
	typedef struct Noeud{
	
		int element;

		struct Noeud* suivant;
		struct Noeud* precedent;

        } noeud_t;


	typedef enum bool {T=1,F=0} bool_t;
	typedef unsigned __int128 uint128_t;
         
	void inserer(noeud_t** noeud, int n);
	void imprimer(noeud_t* n);
	
#endif

