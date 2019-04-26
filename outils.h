#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include "structure.h"

uint128_t estParfait(uint128_t n);
uint128_t estPremier(uint128_t n);

int cpValide(char *c);
//int intervalleValide(uint128_t min);

int ASCorDES(char *c);

void swap(uint128_t *min, uint128_t *max);

uint128_t readU128(char const *c);
void printU128(uint128_t n);


