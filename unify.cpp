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
  archivo.open("Pruebas.txt",ios::in); // Abrimos el archivo en modo lectura

  if(archivo.fail())
    {
      cout << "No se pudo abrir el archivo";
      exit(1);
    }

    while(!archivo.eof())  // Mientras no sea final de fichero
      {
	getline(archivo,texto);
	cout << texto << endl;
      }

    archivo.close(); // Cerramos el archivo
    
}
