OPTIONS = -Wall -pedantic -std=c99

FILE = cp.txt
VARIABLE= $(shell cat $(FILE))

all:tp1

tp1:tp1.c
	gcc $(OPTIONS) -o tp1 tp1.c
		
1:
	./tp1 -c $(VARIABLE) -i data.txt -o pot.txt
2:
	./tp1 -c $(VARIABLE) -i data.txt
3:
	./tp1 -c $(VARIABLE) -o pot.txt
4:
	./tp1 -c abcd12345678 < data.txt 
5:
	./tp1 -c abcd12345678 > pot.txt
6: 
	./tp1 -c abcd12345678 

clean :
	rm -f *.o
	rm -f tp1
	rm code.txt	
data :
	wget https://www.github.com/guyfrancoeur/INF3135_H2019/raw/master/tp1/data.zip 
	unzip data.zip
	rm data.zip
      
resultat:
	git add resultat.txt
	git commit -m "ajoute resultat.txt"
	git push
push :
	git add .
	git commit -m "."
	git push

