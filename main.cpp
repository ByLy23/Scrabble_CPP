#include <iostream>
#include "json/json.h"
//#include "EDD/CuboDisperso.h"
#include <fstream>
#include <stdlib.h>
#include "EDD/ArbolBinBusqueda.h"
#include "json/jsoncpp.cpp"
#include "EDD/ListaDobleCircular.h"
#include <windows.h>
#include "Coordenada.h"
using namespace std;

//Aca van a ir todas las declaraciones importantes
void leerJSON();
void graficarReportes(string, string);
void mostrarReportes(ArbolBusqueda*);
NodoABB *raiz;
    int contadorAux=0;
int main()
{
    //Aca van a ir todas las variables necesarias
    static int DimensionTablero=0;
    int contadorMenu=0;
    string nombreUser="";
    raiz=new NodoABB();
   // Aca van a ir las listas que se utilizaran en todo el programa
   ListaDobleCircular<string> *DiccionarioPalabras= new ListaDobleCircular<string>();
   ArbolBusqueda *arbolUsuarios= new ArbolBusqueda();

    //Aca va a ir el menu
    do{
        //system("cls");
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
            cout<<"Inicio paso"<<endl;
            cin>>nombreUser;
            arbolUsuarios->insertarNodoABB(raiz, nombreUser);
            cout<<"Ingresado"<<endl;
            break;
        case 2:
            leerJSON();
            break;
        case 3:
            //agregarUsuario();
            break;
        case 4:
            mostrarReportes(arbolUsuarios);
            break;
        }
    }while(contadorMenu!=5);
}
void mostrarReportes(ArbolBusqueda *arbolUsuarios)
{
    string todoArbolito="";
    int lectura=0;
    do
    {
        cout<<"1. "<<endl;
        cout<<"2. "<<endl;
        cout<<"3. Mostrar Arbol binario de usuarios"<<endl;
        cout<<"4. Recorrido preorden"<<endl;
        cout<<"5. Recorrido inorden"<<endl;
        cout<<"6. Recorrido postorden"<<endl;
        cout<<"7. "<<endl;
        cin>>lectura;
        switch(lectura)
        {
        case 1:
            //lista de palabras en diccionario
            break;
        case 2:
            //cola de letras en forma desordenada
            break;
        case 3:
            arbolUsuarios->imprimirNodo(raiz,contadorAux);
            todoArbolito="digraph graficaArbolito{ \n linkdir=LR \n"+arbolUsuarios->getCuerpo()+"\n"+arbolUsuarios->getEnlaces()+"}";
            //cout<<todoArbolito<<endl;
            graficarReportes(todoArbolito,"ArbolBinBusqueda");
            arbolUsuarios->setCuerpo("");
            arbolUsuarios->setEnlaces("");
            todoArbolito="";
            //arbol binario de usuarios
            break;
        case 4:
            arbolUsuarios->preorden(raiz);
            todoArbolito="digraph graficaPreorden{ \n linkdir=LR \n arreglo[shape= record label= \"{"+arbolUsuarios->getCuerpo()+"}\"];\n}";
            graficarReportes(todoArbolito,"preOrden");
            arbolUsuarios->setCuerpo("");
            arbolUsuarios->setEnlaces("");
            todoArbolito="";
            //recorrido PREORDEN del arbol
            break;
        case 5:
            arbolUsuarios->inorden(raiz);
            todoArbolito="digraph graficaInorden{ \n linkdir=LR \n arreglo[shape= record label= \"{"+arbolUsuarios->getCuerpo()+"}\"];\n}";
            graficarReportes(todoArbolito,"Inorden");
            arbolUsuarios->setCuerpo("");
            arbolUsuarios->setEnlaces("");
            todoArbolito="";
            //recorrido INORDEN del arbol
            break;
        case 6:
            arbolUsuarios->postOrden(raiz);
            todoArbolito="digraph graficaPostrden{ \n linkdir=LR \n arreglo[shape= record label= \"{"+arbolUsuarios->getCuerpo()+"}\"];\n}";
            graficarReportes(todoArbolito,"postOrden");
            arbolUsuarios->setCuerpo("");
            arbolUsuarios->setEnlaces("");
            todoArbolito="";
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

void graficarReportes(string archivo,string nombre)
{
    string nombreArchivo=nombre+".dot";
    ofstream datos(nombreArchivo);
    datos<<archivo<<endl;
    datos.close();
    string inicio="start dot -Tpng "+nombre+".dot -o "+nombre+".png";
    string ejecucion= "start "+nombre+".png";
    system((inicio).c_str());
    system((ejecucion).c_str());
}
