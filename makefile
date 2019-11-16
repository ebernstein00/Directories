all: directories.o linkedlist.o
	gcc -o program directories.c linkedlist.c
directories.o: listfuncs.h directories.c linkedlist.c
	gcc -c -g directories.c
linkedlist.o: linkedlist.c
	gcc -c -g linkedlist.c
run:
	./program
clean:
	rm *.o
	rm *~
