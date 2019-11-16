/*
   Autores:
   
   - Mario Alejandro Muñetón Durango
   - Johan Esteban Mesa
   
   Profesor:  Andres Sicard Ramirez
   
   Asignatura: Lenguajes de Programación 
   
   Descripción: Implementación del algoritmo de Unificación
   
   Universidad EAFIT
   Medellín
   2019 
*/

/*
   Bibliotecas usadas:
*/

#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <map>


using namespace std; // Un namespace, no es más que una forma de crear un bloque, y que todas las funciones que estén dentro del mismo, estén asociadas a ese namespace (o espacio de nombres), al cual se le asigna un nombre para identificarlo.

/*
    Definición de cada uno de los procedimientos
*/

void lectura();
void fallo();
void unificar(string C[100]);
void VariablesLibres();
void composicion(string o, string t);
void unifica();


/*
   Función main que retorna 0
*/
int main()
{
  lectura();
  system("pause");
  return 0;
}

/*
    Lectura del arcgivo, que luego se guarda en una estructura para luego usarlo y realizar los respectivos procedimientos
*/

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
        unifica();
        aux++;
        
      }
          
    archivo.close(); // Cerramos el archivo


}

/*
   Este procedimeinto imprime en que casos el algortimo no es posible unificar
*/
void falla()
{
	cout << "No se puede unificar" << endl;
}

/*
    Este algoritmo imprime en que casos  el algoritmo se unifica
*/

void unifica()
{

	cout << "Si se puede unificar" << endl;
}

/*
    LA sustitución es el mapeo de las sustituciones de cada restricción
*/

string sustitucion(string source, std::map<string,string>strMap, int offset=0, int times=0)
{
  int total = 0;
  string::size_type pos;

  for (std::map<string, string>::iterator i=strMap.begin(); i!=strMap.end(); ++i)
    {
      string fromStr = i->first;
      string toStr = i->second;
      pos=offset;
      while ( (pos = source.find(fromStr, pos)) < string::npos)
    {
      if ( (times!=0) && (total++>=times) )
        return source;  

      source.replace(pos, fromStr.length(), toStr);
      pos+=toStr.size();
    }
    }
  return source;
}

/*
    Este procedieminto va a colocar en un arreglo las variables que son libres
*/

void VariablesLibres()
{
	string TipoVariable[100];
	
}

/*
   Se hace llamado a unificar, y va a recorrer el conjunto de las restricciones
*/

void unificar(string C[100])
{

	
}

/*
   recibe dos parametros y retorna la composición entre dos sustituciones
*/
void composicion(string o, string t)
{
	
	
}
















