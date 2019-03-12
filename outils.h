#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int estParfait(unsigned long n);
int estPremier(unsigned long n);

int cpValide(char *c);
int intervalleValide(unsigned long min,unsigned long max);

void swap(unsigned long *min, unsigned long *max);
