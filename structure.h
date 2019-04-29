
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
	void afficherArbre(noeud *tree);
	void afficherArbreInverse(noeud *tree);
	uint128_t noeudExiste(noeud *tree, uint128_t key); 
	void clearTree(noeud **tree);	

	uint128_t readU128(char const *c);
	void printU128(uint128_t n);


	
#endif

