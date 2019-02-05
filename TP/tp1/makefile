OPTIONS = -Wall -pedantic -std=c99

FILE=cp.txt
CODE = `cat $(cp.txt)`
		
tp1:tp1.c
	gcc $(OPTIONS) -o tp1 tp1.c

test:
	./tp1 -c ABCD12345678 -i data.txt -o pot.txt
test1:
	./tp1 -c abcd12345678 -i dat.txt -o po.txt
test2:
	./tp1 -c abcd12345678 < data.txt > pot.txt
test3: 
	./tp1 -c abcd12345678 

clean :
	rm -f *.o
	rm -f tp1
	rm -f *.txt
	rm -f *.zip
	
data :
	wget https://www.github.com/guyfrancoeur/INF3135_H2019/raw/master/tp1/data.zip 
	unzip data.zip
      
resultat:

push :
	git add .
	git commit -m "."
	git push

