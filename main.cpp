#include <iostream>
#include "json/json.h"
//#include "EDD/CuboDisperso.h"
#include "json/jsoncpp.cpp"
#include "EDD/ListaDobleCircular.h"
#include "Coordenada.h"
using namespace std;

//Aca van a ir todas las declaraciones importantes
void leerJSON();
int main()
{
    //Aca van a ir todas las variables necesarias
    static int DimensionTablero=0;
    int contadorMenu=0;
   // Aca van a ir las listas que se utilizaran en todo el programa
   ListaDobleCircular<string> *DiccionarioPalabras= new ListaDobleCircular<string>();

    //Aca va a ir el menu
    do{
        system("cls");
        cout<<"1. Iniciar Juego"<<endl;
        cout<<"2. Leer archivo"<<endl;
        cout<<"3. Agregar usuario"<<endl;
        cout<<"4. Mostrar reportes"<<endl;
        cout<<"5. Salir"<<endl;
        cin>>contadorMenu;
        switch(contadorMenu)
        {
        case 1:
            //inicioJuego();
            break;
        case 2:
            leerJSON();
            break;
        case 3:
            //agregarUsuario();
            break;
        case 4:
            //mostrarReportes();
            break;
        }
    }while(contadorMenu!=5);
}
void mostrarReportes()
{
    int lectura=0;
    do
    {
        switch(lectura)
        {
        case 1:
            //lista de palabras en diccionario
            break;
        case 2:
            //cola de letras en forma desordenada
            break;
        case 3:
            //arbol binario de usuarios
            break;
        case 4:
            //recorrido PREORDEN del arbol
            break;
        case 5:
            //recorrido INORDEN del arbol
            break;
        case 6:
            //recorrido POSTORDEN del arbol
            break;
        case 7:
            //lista simple enlazada ordenada del historial de puntajes por jugador, recibe un parametro el cual es el nombre del usuario
            break;
        }
    }while(lectura!=19);
}

void leerJSON()
{
    system("cls");
    cout<<"INGRESO DE DATOS"<<endl;
    string nombreArchivo="";
    cout<<"Ingrese el nombre del archivo"<<endl;
    cin>>nombreArchivo;
    cout<<"el archivos es: "<<nombreArchivo<<endl;
}
