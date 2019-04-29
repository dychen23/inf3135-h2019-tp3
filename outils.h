#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>

#include "structure.h"

void verificationNombre(uint128_t *min, uint128_t *max, noeud **arbre);

uint128_t estParfait(uint128_t n);
uint128_t estPremier(uint128_t n);

uint128_t exposant(uint128_t a, uint128_t b);

int cpValide(char *c);

//int intervalleValide(uint128_t min);

int ASCorDES(char *c);
int verifierasc (char *c);

void swap(uint128_t *min, uint128_t *max);


