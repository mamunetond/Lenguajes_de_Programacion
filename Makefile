all: Lenguajes_de_Programacion

Lenguajes_de_Programacion: unify.o
 $(CXX) -o $@ $^
 
unify.o: unify.cpp unify.h

clean:
        rm -f *.o
        rm -f Lenguajes_de_Programacion


