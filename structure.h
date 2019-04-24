
#ifndef STRUCTURE_H
#define STRUCTURE_H
	
	__extension__ typedef unsigned __int128 uint128_t;

	enum ordonne{asc,ASC,des,DES};

	typedef struct noeud
	{
   	 	unsigned int key;
   		struct noeud *left;
   	 	struct noeud *right;

	} noeud ;
	         
	void ajoutNoeud(noeud **noeud, unsigned int n);
	void printTree(noeud *tree);
	void printReverseTree(noeud *tree);
	int rechercheNoeud(noeud *tree, unsigned int key); 
	
#endif

