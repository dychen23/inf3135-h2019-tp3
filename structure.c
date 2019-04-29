#include "structure.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ajoutNoeud(noeud **tree, uint128_t key)
{
    noeud *tmpNode;
    noeud *tmpTree = *tree;

    noeud *elem = malloc(sizeof(noeud));

    elem->key = key;
    elem->left = NULL;
    elem->right = NULL;

    if(tmpTree)
    do
    {
        tmpNode = tmpTree;
        if(key > tmpTree->key )
        {
            tmpTree = tmpTree->right;
            if(!tmpTree) tmpNode->right = elem;
        }
        else
        {
            tmpTree = tmpTree->left;
            if(!tmpTree) tmpNode->left = elem;
        }
    }
    while(tmpTree);

    else  *tree = elem;
}


//===========================================================================

void afficherArbre(noeud *tree, FILE *fw)
{
    if(!tree) return;

    if(tree->left)  afficherArbre(tree->left, fw);

    printU128(tree->key, fw);

    if(tree->right) afficherArbre(tree->right, fw);
}

//===========================================================================


void afficherArbreInverse(noeud *tree, FILE *fw)
{
    if(!tree) return;

    if(tree->right) afficherArbreInverse(tree->right,fw);

    printU128(tree->key,fw);

    if(tree->left)  afficherArbreInverse(tree->left,fw);
}

//===========================================================================


uint128_t noeudExiste(noeud *tree, uint128_t key)
{
    while(tree)
    {
        if(key == tree->key) return 1;

        if(key > tree->key ) tree = tree->right;
        else tree = tree->left;
    }
    return 0;
}


//===========================================================================

void clearTree(noeud **tree)
{
    noeud *tmpTree = *tree;

    if(!tree) return;

    if(tmpTree->left)  clearTree(&tmpTree->left);

    if(tmpTree->right) clearTree(&tmpTree->right);

    free(tmpTree);      

    *tree = NULL;
}

//===========================================================================

uint128_t readU128(char const *string){
	
	int len=strlen(string);

	uint128_t mod=1;
	uint128_t utotal =0;

	for(int i = len-1; i>=0; i--){

		if(string[i] < 48 || string[i] > 57){
			return -1;
		}

		uint128_t temp =(uint128_t) string[i]-48 ; // nombre ascii
		temp *= mod; 
		utotal += temp;
		mod *= 10;
	}
	return utotal;
}

//==============================================================================

void printU128(uint128_t n, FILE *fw){
	
	int string[50];
	short compteur=0;
	uint128_t div=10;

	while(n!=0){
		string[compteur]=(n%div);
		n /= div;
		compteur++;
	}


	for(int i = compteur-1; i>=0; --i){

		
		fprintf(fw,"%d",string[i]);
		printf("%d",string[i]);

	}
		fprintf(fw,"\n");
		printf("\n");
}

