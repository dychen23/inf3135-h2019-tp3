
#ifndef STRUCTURE_H
#define STRUCTURE_H
	
	typedef struct node
	{
   	 	unsigned int key;
   		struct node *left;
   	 	struct node *right;

	} node ;

	typedef unsigned __int128 uint128_t;
         
	void inserer(noeud_t** noeud, int n);
	void imprimer(noeud_t* n);
	
#endif

