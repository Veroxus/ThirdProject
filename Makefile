all: babyQuery.o removeCommas.o
	gcc -ansi -Wall -o babyQuery babyQuery.o removeCommas.o

babyQuery: babyQuery.o removeCommas.o
	gcc -ansi -Wall -o babyQuery babyQuery.o removeCommas.o

babyQuery.o: babyQuery.c
	gcc -ansi -Wall -c babyQuery.c

removeCommas.o: removeCommas.c
	gcc -ansi -Wall -c removeCommas.c

clean:
	rm babyQuery removeCommas.o babyQuery.o
