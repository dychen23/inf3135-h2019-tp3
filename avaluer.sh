#!/bin/bash
 
if [ ! -f inf3135-h2019-tp2.correction ]; then
wget -q https://raw.githubusercontent.com/guyfrancoeur/INF3135_H2019_TP2/master/inf3135-h2019-tp2.correction
fi

C=0
nbPoints=0
NC='\033[0m'
utilisateur=$(cat cp.txt)
sub=`sed "s/'/\'/g" inf3135-h2019-tp2.correction`

make

/*
make data
test -f ./data/data.txt
make test
make clean ; make clean
grep -c -e 'resultat:' -e 'resultat :' Makefile
test -f README.md
gcc -Wall -pedantic -std=c99 -lm -O2 -o tp2 tp2.c outils.c
./tp2 -c $(cat cp.txt) -i ~/depot/data0.in ; test -f code.txt
./tp2
./tp2 -c FRAG
./tp2 -c FRAG12345678 -u
./tp2 -c $(cat cp.txt) < ~/depot/data4.err
./tp2 -c $(cat cp.txt) -i ok.txt
./tp2 -c $(cat cp.txt) -o ./ok/ok.txt < ~/depot/data1.in
./tp2 -c $(cat cp.txt) -i ~/depot/data5.in -o res.out
diff --brief -b res.out ~/depot/data5.res
gtimeout 5s ./tp2 -c $(cat cp.txt) -o res.out < ~/depot/data1.in
diff --brief -b res.out ~/depot/data1.res
gtimeout 5s ./tp2 -c $(cat cp.txt) -i ~/depot/data2.in > res.out
diff --brief -b res.out ~/depot/data2.res
gtimeout 5s ./tp2 -c $(cat cp.txt) < ~/depot/data3.in > res.out
diff --brief -b res.out ~/depot/data3.res	
*/
	     
	echo "";

	echo "Note (total) pour $utilisateur dans inf3135-h2019-tp2: $nbPoints";
	echo "FIN."
	echo ${tabR[14]};	


