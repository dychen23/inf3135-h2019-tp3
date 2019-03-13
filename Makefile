OPTIONS = -Wall -pedantic -std=c99 -lm -O1 

FILE=cp.txt
VARIABLE=$(shell cat $(FILE))

default :tp2

outils.o: outils.h outils.c
	gcc $(OPTIONS) -c outils.h outils.c 

tp2:outils.o tp2.c
	gcc $(OPTIONS) outils.o tp2.c -o tp2

test:
	./tp2 -c $(VARIABLE) -i ./data/data.txt 
	
.PHONY: clean
clean :
	rm -f *.o 
	rm -f tp2 
	rm -f code.txt 
	rm -rf data 
	rm -f *.h.gch


data :
	wget -q  https://www.github.com/guyfrancoeur/INF3135_H2019/raw/master/tp1/data.zip
	unzip data.zip -d ./data
	rm data.zip

resultat :
	git add resultat.txt
	git commit -m "ajoute resultat.txt"
	git push

push :
	git add .
	git commit -m "."
	git push

