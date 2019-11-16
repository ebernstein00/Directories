all: directories.o dirlist.o filelist.o
	gcc -o program directories.c dirlist.c filelist.c
directories.o: dirfuncs.h filefuncs.h directories.c dirlist.c filelist.c
	gcc -c -g directories.c
dirlist.o: dirlist.c
	gcc -c -g dirlist.c
filelist.o: filelist.c
	gcc -c -g filelist.c
run:
	./program
clean:
	rm *.o
	rm *~
