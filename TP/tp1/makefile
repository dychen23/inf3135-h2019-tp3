OPTIONS = -Wall -pedantic -std=c99

tp1:tp1.c
	gcc -o tp1 tp1.c
	
clean :
	rm -f *.o
	rm -f tp1

data :
	wget https://www.github.com/guyfrancoeur/INF3135_H2019/raw/master/tp1/data.zip

resultat :
	git add .
	git commit -m "."
	git push
