all: directories.o
	gcc -o program directories.c
directories.o: directories.c
	gcc -c -g directories.c
run:
	./program
clean:
	rm *.o
	rm *~
