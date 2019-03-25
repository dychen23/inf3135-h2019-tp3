
#ifndef STRUCTURE_H
#define STRUCTURE_H
	
	typedef struct vector_t{
	
		int capacite;
		int elements;

        } vector_t;


	typedef enum bool {T=1,F=0} bool_t;
	typedef unsigned __int128 uint128_t;
         
	void inserer(vector_t t, int n);
#endif
