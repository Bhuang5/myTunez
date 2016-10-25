GCC = gcc -g

tunez: list.o playlist.o main.o
	$(GCC) list.o playlist.o main.o -o tunez

list.o: list.c list.h
	$(GCC) -c list.c

playlist.o: playlist.c playlist.h
	$(GCC) -c playlist.c

main.o: main.c playlist.h
	$(GCC) -c main.c

clean:
	rm tunez
	rm *.o
	rm *~

run: tunez
	./tunez
