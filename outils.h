#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef OUTILS_H
#define OUTILS_H

#endif

int estParfait(unsigned long n);
int estPremier(unsigned long n);

int cpValide(char *c);
int intervalleValide(unsigned long min,unsigned long max);

void swap(unsigned long *min, unsigned long *max);

