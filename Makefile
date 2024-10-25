lychrel: lychrel.o
	gcc -g -O0 -o lychrel lychrel.o
 
lychrel.o: lychrel.c
	gcc -g -O0 -c lychrel.c
