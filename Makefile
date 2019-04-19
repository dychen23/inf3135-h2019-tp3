OPTIONS = -Wall -pedantic -std=c99 -lm -O1 

FILE=cp.txt
VARIABLE=$(shell cat $(FILE))

default :tp3

outils.o: outils.h outils.c
	gcc $(OPTIONS) -c outils.h outils.c 

structure.o: structure.h structure.c
	 gcc $(OPTIONS) -c structure.h structure.c

tp3:outils.o structure.o tp3.c
	gcc $(OPTIONS) outils.o structure.o tp3.c -o tp3

test:
	./tp3 -c $(VARIABLE) -i ./data/data.txt -d asc 

1:
	./tp3 -c $(VARIABLE) -i ./data/data.txt -d ASC
2:
	./tp3 -c $(VARIABLE) -i ./data/data.txt -d des
3:
	./tp3 -c $(VARIABLE) -i ./data/data.txt -d DES

.PHONY: clean
clean :
	rm -f *.o 
	rm -f tp3 
	
	rm -f code.txt 
	rm -rf data.zip.*
	rm -rf data
	rm -f *.h.gch
	rm -f res.out
	rm -f *.guy

data :
	wget -q  https://www.github.com/guyfrancoeur/INF3135_H2019/raw/master/tp1/data.zip
	unzip data.zip -d ./data
	rm data.zip

resultat :
	git add resultat.txt
	git commit -m "ajoute resultat.txt"
	git push

push :
	git pull
	git add .
	git commit -m "."
	git push

