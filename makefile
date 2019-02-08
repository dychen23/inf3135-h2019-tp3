OPTIONS = -Wall -pedantic -std=c99

FILE = cp.txt
VARIABLE= $(shell cat $(FILE))

all:tp1

tp1:tp1.c
	gcc $(OPTIONS) -o tp1 tp1.c
		
1:
	./tp1 -c $(VARIABLE) -i ./data/data.txt -o p
2:
	./tp1 -c $(VARIABLE) -i ./data/data.txt
3:
	./tp1 -c $(VARIABLE) -o p
4:
	./tp1 -c abcd12345678 < ./data/data.txt
5:
	./tp1 -c abcd12345678 > p
6: 
	./tp1 -c abcd12345678 
7:
	./tp1 -c $(VARIABLE) < ./data/data.txt > pot.txt
clean :
	rm -f *.o
	rm -f tp1
	rm code.txt	
	rm -f -r data
data :
	wget https://www.github.com/guyfrancoeur/INF3135_H2019/raw/master/tp1/data.zip 
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

