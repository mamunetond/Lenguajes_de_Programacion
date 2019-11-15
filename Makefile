all: Lenguajes_de_Programacion

Lenguajes_de_Programacion: unify.o
 $(CXX) -o $@ $^
 
unify.o: unify.cpp scanner.h token.h

scanner.o: scanner.cpp scanner.h token.h

token.o: token.cpp token.h

ast.o: ast.h ast.cpp

parser.o: parser.h parser.cpp

clean:
        rm -f *.o
        rm -f Lenguajes_de_Programacion


