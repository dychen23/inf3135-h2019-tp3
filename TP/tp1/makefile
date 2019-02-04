OPTIONS = -Wall -pedantic -std=c99

FILE=cp.txt
CODE = `cat $(cp.txt)`
		
tp1:tp1.c
	gcc $(OPTIONS) -o tp1 tp1.c

test:
	./tp1 -c ABCD12345678 -i data.txt -o pot.txt

clean :
	rm -f *.o
	rm -f tp1

data :
	wget https://www.github.com/guyfrancoeur/INF3135_H2019/raw/master/tp1/data.zip 
	unzip data.zip
      
resultat :
	git add .
	git commit -m "."
	git push

