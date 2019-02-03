OPTIONS = -Wall -pedantic -std=c99

FILE=cp.txt
CODE = `cat $(cp.txt)`
		
tp1:tp1.c
	gcc $(OPTIONS) -o tp1 tp1.c

clean :
	rm -f *.o
	rm -f tp1

data :
	wget https://github.com/guyfrancoeur/INF3135_H2019/blob/master/tp1/data.zip
      
resultat :
	git add .
	git commit -m "."
	git push

