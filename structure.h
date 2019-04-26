
#ifndef STRUCTURE_H
#define STRUCTURE_H
	
	__extension__ typedef unsigned __int128 uint128_t;

	enum ordonne{asc,ASC,des,DES};

	typedef struct noeud
	{
   	 	uint128_t key;
   		struct noeud *left;
   	 	struct noeud *right;

	} noeud ;
	         
	void ajoutNoeud(noeud **noeud, uint128_t n);
	void printTree(noeud *tree);
	void printReverseTree(noeud *tree);
	uint128_t rechercheNoeud(noeud *tree, uint128_t key); 
	void clearTree(noeud **tree);

	
#endif

