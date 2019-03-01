OPTIONS = -Wall -pedantic -std=c99

FILE = cp.txt
VARIABLE= $(shell cat $(FILE))

default:tp2

tp2:tp2.c
	gcc $(OPTIONS) -o tp2 tp2.c

1:
	./tp2 -c $(VARIABLE) -i ./data/data.txt -o p
2:
	./tp2 -c $(VARIABLE) -i ./data/data.txt
3:
	./tp2 -c $(VARIABLE) -o p
4:
	./tp2 -c $(VARIABLE) < ./data/data.txt
5:
	./tp2 -c $(VARIABLE) > p
6: 
	./tp2 -c $(VARIABLE) 
7:
	./tp2 -c $(VARIABLE) < ./data/data.txt > pot.txt

.PHONY: clean
clean :
	rm -f *.o
	rm -f tp2
	rm -f code.txt	
	rm -rf data

data :
	wget -q  https://www.github.com/guyfrancoeur/INF3135_H2019/raw/master/tp1/data.zip 
	unzip data.zip -d ./data
	rm data.zip
		      
resultat:
	git add resultat.txt
	git commit -m "ajoute resultat.txt"
	git push

push :
	git add .
	git commit -m "."
	git push

