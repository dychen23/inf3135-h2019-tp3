#!/bin/bash

if [ ! -f inf3135-h2019-tp2.correction ]; then
wget -q https://raw.githubusercontent.com/guyfrancoeur/INF3135_H2019_TP2/master/inf3135-h2019-tp2.correction
fi

COUNTER=1

while read line; do 
	echo "$COUNTER :" ${line:6:6};
	COUNTER=$[$COUNTER +1];
done < inf3135-h2019-tp2.correction
