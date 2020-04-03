#include <iostream>
#include "json/json.h"
//#include "EDD/CuboDisperso.h"
#include <fstream>
#include <stdlib.h>
#include "EDD/ArbolBinBusqueda.h"
#include "json/jsoncpp.cpp"
#include <time.h>
#include "EDD/Cola.h"
#include "EDD/ListaDobleCircular.h"
#include "EDD/ListaSimple.h"
#include <windows.h>
#include "Coordenada.h"
#include "Palabra.h"
using namespace std;

//Aca van a ir todas las declaraciones importantes
void leerJSON();
void graficarReportes(string, string);
void mostrarReportes(ArbolBusqueda*);
void imprimirCola();
void agregarCola();
    string cuerpoCola="";
    string enlacesCola="";
void hacerCiclo(string, int, int);
NodoABB *raiz;
    static int DimensionTablero=0;
    int contadorAux=0;
   // Aca van a ir las listas que se utilizaran en todo el programa
   ListaDobleCircular<string> *DiccionarioPalabras= new ListaDobleCircular<string>();
   Cola<Palabra*> *colaPalabras= new Cola<Palabra*>();
   ListaSimple<Palabra*> *AuxPalabra= new ListaSimple<Palabra*>();
int main()
{
    //Aca van a ir todas las variables necesarias
    int contadorMenu=0;
    string nombreUser="";
    raiz=new NodoABB();
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
            agregarCola();
            break;
        case 2:
            leerJSON();
            break;
        case 3:
            system("cls");
            cout<<"Ingresar Usuario"<<endl;
            cin>>nombreUser;
            arbolUsuarios->insertarNodoABB(raiz, nombreUser);
            break;
        case 4:
            mostrarReportes(arbolUsuarios);
            break;
        }
    }while(contadorMenu!=5);
}
void mostrarReportes(ArbolBusqueda *arbolUsuarios)
{
            system("cls");
    string todoArbolito="";
    int lectura=0;
    do
    {
        cout<<"1. Mostrar Palabras diccionario"<<endl;
        cout<<"2. Cola Palabras"<<endl;
        cout<<"3. Mostrar Arbol binario de usuarios"<<endl;
        cout<<"4. Recorrido preorden"<<endl;
        cout<<"5. Recorrido inorden"<<endl;
        cout<<"6. Recorrido postorden"<<endl;
        cout<<"7. "<<endl;
        cout<<"8. "<<endl;
        cout<<"9. "<<endl;
        cout<<"10. "<<endl;
        cout<<"11. Salir"<<endl;
        cin>>lectura;
        switch(lectura)
        {
        case 1:
            DiccionarioPalabras->imprimirLista();
            todoArbolito="digraph diccionario{ \n "+DiccionarioPalabras->getCuerpo()+"\n"+DiccionarioPalabras->getEnlaces()+"}";
            graficarReportes(todoArbolito,"Diccionario");
            cout<<todoArbolito<<endl;
            DiccionarioPalabras->setCuerpo("");
            DiccionarioPalabras->setEnlaces("");
            todoArbolito="";
            //lista de palabras en diccionario
            break;
        case 2:
            imprimirCola();
            todoArbolito="digraph Colapalabras{ \n linkdir=LR \n"+cuerpoCola+"\n"+enlacesCola+"}";
            //cout<<todoArbolito<<endl;
            graficarReportes(todoArbolito,"ColaPalabras");
            cout<<todoArbolito<<endl;
            cuerpoCola="";
            enlacesCola="";
            todoArbolito="";
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
    }while(lectura!=11);
}

void leerJSON()
{
    system("cls");
    cout<<"INGRESO DE DATOS"<<endl;
    string nombreArchivo="";
    cout<<"Ingrese el nombre del archivo"<<endl;
    cin>>nombreArchivo;
    ifstream archivo(nombreArchivo);
    Json::Reader leer;
    Json::Value valor;
    bool parseSuccess= leer.parse(archivo,valor,false);
    if(parseSuccess)
    {
        const Json::Value dimension= valor["dimension"];
        DimensionTablero=dimension.asInt();
        const Json::Value casillasDobles= valor["casillas"]["dobles"];
        cout<<"Dobles"<<endl;
        for(int i=0; i<casillasDobles.size(); i++){
            cout<<"X: " <<casillasDobles[i]["x"].asString() <<endl;
            cout<<"Y: "<<casillasDobles[i]["y"].asString() <<endl;
        }
        const Json::Value casillasTriples= valor["casillas"]["triples"];
        cout<<"Triples"<<endl;
        for(int i=0; i<casillasTriples.size(); i++){
            cout<<"X: " <<casillasTriples[i]["x"].asString() <<endl;
            cout<<"Y: "<<casillasTriples[i]["y"].asString() <<endl;
        }
        const Json::Value diccionario= valor["diccionario"];
        cout<<"Diccionario"<<endl;
        for(int i=0; i<diccionario.size();i++)
        {
            string palabrita=diccionario[i]["palabra"].asString();
          //  cout<<diccionario[i]["palabra"].asString()<<endl;
            DiccionarioPalabras->agregar_fin(palabrita);
        }
    }
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


void agregarCola()
{
    hacerCiclo("A",12,1);
    hacerCiclo("B",2,3);
    hacerCiclo("C",4,3);
    hacerCiclo("D",5,2);
    hacerCiclo("E",12,1);
    hacerCiclo("F",1,4);
    hacerCiclo("G",2,2);
    hacerCiclo("H",2,4);
    hacerCiclo("I",6,1);
    hacerCiclo("J",1,8);
    hacerCiclo("K",1,1);
    hacerCiclo("L",4,1);
    hacerCiclo("M",2,3);
    hacerCiclo("N",4,1);
    hacerCiclo("O",9,1);
    hacerCiclo("P",2,3);
    hacerCiclo("Q",1,5);
    hacerCiclo("R",5,1);
    hacerCiclo("S",6,1);
    hacerCiclo("T",4,1);
    hacerCiclo("U",5,1);
    hacerCiclo("V",1,4);
    hacerCiclo("Ñ",1,8);
    hacerCiclo("W",1,1);
    hacerCiclo("X",1,8);
    hacerCiclo("Y",1,4);
    hacerCiclo("Z",1,10);
    while(AuxPalabra->getTamanio()!=0){
            srand(time(0));
        int random= rand() % AuxPalabra->getTamanio();
        cout<<random<<endl;

        colaPalabras->Enqueue(AuxPalabra->remover(random));
    }
}
void imprimirCola()
{
    for(int i=0; i<colaPalabras->getTamanio();i++)
    {
        int j=i+1;
        cuerpoCola+="nodo"+to_string(i)+"[shape= record label=\""+colaPalabras->get_element_at(i)->getLetra()+"\"];\n";
        enlacesCola+="nodo"+to_string(i)+" -> nodo"+ to_string(j)+"\n";
    }
}
void hacerCiclo(string letra, int cantidad, int punteo)
{
    for(int i=0; i<cantidad;i++)
    {
        AuxPalabra->insertar_final(new Palabra(letra,punteo));
    }
}
