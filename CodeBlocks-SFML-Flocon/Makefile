Prog: main.o Ligne.o
	g++ main.o Ligne.o -o Prog -Wall

main.o: main.c Ligne.h
	g++ -c main.c -Wall

Ligne.o: Ligne.cpp Ligne.h
	g++ -c Ligne.c -Wall
        
clean:
	rm -rf *.o
        
deepclean:
	rm -rf *.o main
