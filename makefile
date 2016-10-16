Tunez: Tunez.c
	gcc Tunez.c -o Tunez

clean: 
	rm *~
	rm ~#

run: Tunez
	./Tunez