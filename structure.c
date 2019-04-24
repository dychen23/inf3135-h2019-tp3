#include "structure.h"
#include <stdlib.h>
#include <stdio.h>

void ajoutNoeud(noeud **tree, unsigned int key)
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

void printTree(noeud *tree)
{
    if(!tree) return;

    if(tree->left)  printTree(tree->left);

    printf("Cle = %d\n", tree->key);

    if(tree->right) printTree(tree->right);
}

//===========================================================================


void printReverseTree(noeud *tree)
{
    if(!tree) return;

    if(tree->right) printReverseTree(tree->right);

    printf("Cle = %d\n", tree->key);

    if(tree->left)  printReverseTree(tree->left);
}

//===========================================================================


int rechercheNoeud(noeud *tree, unsigned int key)
{
    while(tree)
    {
        if(key == tree->key) return 1;

        if(key > tree->key ) tree = tree->right;
        else tree = tree->left;
    }
    return 0;
}

