#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

long estParfait(long n);
long estPremier(long n);
int cpValide(char *c);
int intervalleValide(long min, long max);

void swap(unsigned long *min, unsigned long *max);
