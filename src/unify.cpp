#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>


using namespace std;


void lectura();


int main()
{
  lectura();
  system("pause");
  return 0;
}

void lectura()
{

  ifstream archivo;
  string texto;
  int acum = 0; 
  int aux = 0;
  archivo.open("prueba1.txt",ios::in); // Abrimos el archivo en modo lectura
   if(archivo.fail())
    {
      cout << "No se pudo abrir el archivo";
      exit(1);
    }

    while(!archivo.eof())  // Mientras no sea final de fichero
      {
      	acum++;
        getline(archivo,texto);
        string numeros[acum];
        numeros[aux] = texto;
        cout << numeros[aux] << endl;
        aux++;
        
      }
          
    archivo.close(); // Cerramos el archivo

}

