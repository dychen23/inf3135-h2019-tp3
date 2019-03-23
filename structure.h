
#ifndef STRUCTURE_H
#define STRUCTURE_H
	
	typedef struct vector_t{
	
		char content;
        } vector_t;

	typedef enum bool {T=0,F=1} bool_t;
	typedef unsigned __int128 uint128_t;
        
	void inserer(vector_t t, int n);
#endif
