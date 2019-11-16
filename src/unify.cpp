#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>


using namespace std;


void lectura();
void vacio();
void fallo();
void unificar(string C[100]);
void VariablesLibres();
void composicion();
void sustitucion();


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
  archivo.open("prueba6.txt",ios::in); // Abrimos el archivo en modo lectura
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
        unificar(numeros);
        aux++;
        
      }
          
    archivo.close(); // Cerramos el archivo


}

void vacio()
{
	cout << "El archivo se encuentra vacio" << endl;
}

void falla()
{
	cout << "No se puede unificar" << endl;
}

void unififcar(string C[100])
{
		if(C -> empty())
		{
		   vacio();
		   
		}
}









