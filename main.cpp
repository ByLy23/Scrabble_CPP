#include <iostream>
#include "json/json.h"
#include "EDD/CuboDisperso.h"
#include <fstream>
#include <stdlib.h>
#include <clocale>
#include "EDD/ListaDoble.h"
#include "EDD/ArbolBinBusqueda.h"
#include "json/jsoncpp.cpp"
#include <time.h>
#include "EDD/Cola.h"
#include "EDD/ListaDobleCircular.h"
#include "EDD/ListaSimple.h"
#include <string>
#include <windows.h>
//#include "Coordenada.h"
#include "Palabra.h"
using namespace std;

//Aca van a ir todas las declaraciones importantes
void leerJSON();
void graficarReportes(string, string);
void mostrarReportes(ArbolBusqueda*);
void imprimirCola();
void agregarCola();
void asignarFichas(bool,bool);
void iniciarJuego();
void imprimirFichas(ListaDoble<Palabra*> *lista);
bool verificarUsuario(string);
    string cuerpoCola="";
    string enlacesCola="";
    string cuerpoLista="";
    string enlaceLista="";
    static int punteojug1=0;
    static int punteojug2=0;
    string usuario1="";
    string usuario2="";
void hacerCiclo(string, int, int);
NodoABB *raizs;
    static int DimensionTablero=0;
    int contadorAux=0;
   // Aca van a ir las listas que se utilizaran en todo el programa
   ListaDobleCircular<string> *DiccionarioPalabras= new ListaDobleCircular<string>();
   ListaDoble<Palabra*> *fichaJug1= new ListaDoble<Palabra*>();
   ListaDoble<Palabra*> *fichaJug2= new ListaDoble<Palabra*>();
   Cola<Palabra*> *colaPalabras= new Cola<Palabra*>();
   CuboDisperso* tablero= new CuboDisperso();
   Cola<Palabra*> *auxLista= new Cola<Palabra*>();
   Cola<Palabra*> *auxMatriz= new Cola<Palabra*>();
   ListaSimple<Palabra*> *AuxPalabra= new ListaSimple<Palabra*>();
   ArbolBusqueda *arbolUsuarios= new ArbolBusqueda();
int main()
{
    bool user1=false;
    bool user2=false;
    raizs=new NodoABB();
    setlocale(LC_CTYPE, "Spanish");
    //Aca van a ir todas las variables necesarias
    int contadorMenu=0;
    string nombreUser="";
string arbolis="";
    //Aca va a ir el menu
    do{
            int random;
        //system("cls");
        cout<<"1. Iniciar Juego"<<endl;
        cout<<"2. Leer archivo"<<endl;
        cout<<"3. Agregar usuario"<<endl;
        cout<<"4. Mostrar reportes"<<endl;
        cout<<"5. Salir"<<endl;
        cin>>contadorMenu;
        switch(contadorMenu)
        {
        case 99:
            tablero->imprimir();
            arbolis="digraph diccionario{ \n "+tablero->getCuerpo()+"\n"+tablero->getEnlaces()+"}";
            cout<<arbolis<<endl;
            break;
        case 1:
            agregarCola();
            cout<<"Nombre del usuario 1:"<<endl;
            cin>>usuario1;
            if(verificarUsuario(usuario1))
            {
               // cout<<"Continuar Juego"<<endl;
                user1=true;
                arbolUsuarios->bandera=false;

            }
            else{
                cout<<"Usuario no registrado"<<endl;
            }
            cout<<"Nombre del usuario 2:"<<endl;
            cin>>usuario2;
            if(verificarUsuario(usuario2))
            {
                //cout<<"Continuar Juego"<<endl;
                user2=true;
                arbolUsuarios->bandera=false;
            }
            else{
                cout<<"Usuario no registrado"<<endl;
            }
            if(user1 && user2){
            asignarFichas(user1,user2);
            iniciarJuego();
            }else{cout<<"No se puede iniciar ya que faltan jugadores"<<endl;}
            break;
        case 2:
            leerJSON();
            break;
        case 3:
            system("cls");
            cout<<"Ingresar Usuario"<<endl;
            cin>>nombreUser;
            arbolUsuarios->insertarNodoABB(raizs, nombreUser);
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
        system("cls");
        cout<<"1. Mostrar Palabras diccionario"<<endl;
        cout<<"2. Cola Palabras"<<endl;
        cout<<"3. Mostrar Arbol binario de usuarios"<<endl;
        cout<<"4. Recorrido preorden"<<endl;
        cout<<"5. Recorrido inorden"<<endl;
        cout<<"6. Recorrido postorden"<<endl;
        cout<<"7. "<<endl;
        cout<<"8. "<<endl;
        cout<<"9. "<<endl;
        cout<<"10. Lista doblemente enlazada de fichas de jugadores"<<endl;
        cout<<"11. Salir"<<endl;
        cin>>lectura;
        switch(lectura)
        {
        case 1:
            DiccionarioPalabras->imprimirLista();
            todoArbolito="digraph diccionario{ \n "+DiccionarioPalabras->getCuerpo()+"\n"+DiccionarioPalabras->getEnlaces()+"}";
            graficarReportes(todoArbolito,"Diccionario");
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

            cuerpoCola="";
            enlacesCola="";
            todoArbolito="";
            //cola de letras en forma desordenada
            break;
        case 3:
            arbolUsuarios->imprimirNodo(raizs,contadorAux);
            todoArbolito="digraph graficaArbolito{ \n linkdir=LR \n"+arbolUsuarios->getCuerpo()+"\n"+arbolUsuarios->getEnlaces()+"}";
            //cout<<todoArbolito<<endl;
            graficarReportes(todoArbolito,"ArbolBinBusqueda");
            arbolUsuarios->setCuerpo("");
            arbolUsuarios->setEnlaces("");
            todoArbolito="";
            //arbol binario de usuarios
            break;
        case 4:
            arbolUsuarios->preorden(raizs);
            todoArbolito="digraph graficaPreorden{ \n linkdir=LR \n arreglo[shape= record label= \"{"+arbolUsuarios->getCuerpo()+"}\"];\n}";
            graficarReportes(todoArbolito,"preOrden");
            arbolUsuarios->setCuerpo("");
            arbolUsuarios->setEnlaces("");
            todoArbolito="";
            //recorrido PREORDEN del arbol
            break;
        case 5:
            arbolUsuarios->inorden(raizs);
            todoArbolito="digraph graficaInorden{ \n linkdir=LR \n arreglo[shape= record label= \"{"+arbolUsuarios->getCuerpo()+"}\"];\n}";
            graficarReportes(todoArbolito,"Inorden");
            arbolUsuarios->setCuerpo("");
            arbolUsuarios->setEnlaces("");
            todoArbolito="";
            //recorrido INORDEN del arbol
            break;
        case 6:
            arbolUsuarios->postOrden(raizs);
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
            case 8:
                //lista simple que representa el escoreboard
            break;
            case 9:
            //matriz dispersa
            break;
            case 10:
                imprimirFichas(fichaJug1);
                todoArbolito="digraph FichasJug1{ \n linkdir=LR \n"+cuerpoLista+"\n"+enlaceLista+"}";
            //cout<<todoArbolito<<endl;
            graficarReportes(todoArbolito,"FichasJug1");
            cuerpoLista="";
            enlaceLista="";
            todoArbolito="";
            imprimirFichas(fichaJug2);
                todoArbolito="digraph FichasJug2{ \n linkdir=LR \n"+cuerpoLista+"\n"+enlaceLista+"}";
            //cout<<todoArbolito<<endl;
            graficarReportes(todoArbolito,"FichasJug2");
            cuerpoLista="";
            enlaceLista="";
            todoArbolito="";
            //listas de fichas
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
        for(int i=0; i<DimensionTablero;i++)
            {
                tablero->crearFila(i);
                tablero->crearColumna(i);
            }
            int doble=2;
            int trip=3;
        const Json::Value casillasDobles= valor["casillas"]["dobles"];
        //cout<<"Dobles"<<endl;
        for(int i=0; i<casillasDobles.size(); i++){
                int x=casillasDobles[i]["x"].asInt();
                int y=casillasDobles[i]["y"].asInt();
                cout<<to_string(x)+" y "+to_string(y)<<endl;
               // tablero->crearNodo("",doble,x,y);
        //    cout<<"X: " <<casillasDobles[i]["x"].asString() <<endl;
          //  cout<<"Y: "<<casillasDobles[i]["y"].asString() <<endl;
        }
        const Json::Value casillasTriples= valor["casillas"]["triples"];
        //cout<<"Triples"<<endl;
        for(int i=0; i<casillasTriples.size(); i++){
                int x=casillasTriples[i]["x"].asInt();
                int y=casillasTriples[i]["y"].asInt();
                cout<<to_string(x)+" y "+to_string(y)<<endl;
              //  tablero->crearNodo("",trip,x,y);
          //  cout<<"X: " <<casillasTriples[i]["x"].asString() <<endl;
            //cout<<"Y: "<<casillasTriples[i]["y"].asString() <<endl;
        }
        const Json::Value diccionario= valor["diccionario"];
        //cout<<"Diccionario"<<endl;
        for(int i=0; i<diccionario.size();i++)
        {
            string palabrita=diccionario[i]["palabra"].asString();
          //  cout<<diccionario[i]["palabra"].asString()<<endl;
            DiccionarioPalabras->agregar_fin(palabrita);
        }
    }
}
bool verificarUsuario(string user)
{
    return arbolUsuarios->verificaNombre(raizs, user);
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
    hacerCiclo("a",12,1);
    hacerCiclo("b",2,3);
    hacerCiclo("c",4,3);
    hacerCiclo("d",5,2);
    hacerCiclo("e",12,1);
    hacerCiclo("f",1,4);
    hacerCiclo("g",2,2);
    hacerCiclo("h",2,4);
    hacerCiclo("i",6,1);
    hacerCiclo("j",1,8);
    hacerCiclo("k",1,1);
    hacerCiclo("l",4,1);
    hacerCiclo("m",2,3);
    hacerCiclo("n",4,1);
    hacerCiclo("o",9,1);
    hacerCiclo("p",2,3);
    hacerCiclo("q",1,5);
    hacerCiclo("r",5,1);
    hacerCiclo("s",6,1);
    hacerCiclo("t",4,1);
    hacerCiclo("u",5,1);
    hacerCiclo("v",1,4);
    hacerCiclo("ñ",1,8);
    hacerCiclo("w",1,1);
    hacerCiclo("x",1,8);
    hacerCiclo("y",1,4);
    hacerCiclo("z",1,10);
    while(AuxPalabra->getTamanio()!=0){
            srand(time(0));
        int random= rand() % AuxPalabra->getTamanio();
        //cout<<random<<endl;

        colaPalabras->Enqueue(AuxPalabra->remover(random));
    }
}
void imprimirCola()
{
    for(int i=0; i<colaPalabras->getTamanio();i++)
    {
        int j=i+1;
        int dato=colaPalabras->get_element_at(i)->getPunteo();
        string dato1=to_string(dato);
        cuerpoCola+="nodo"+to_string(i)+"[shape= record label=\""+colaPalabras->get_element_at(i)->getLetra()+"\n Punteo: "+dato1+"\"];\n";
        enlacesCola+="nodo"+to_string(i)+" -> nodo"+ to_string(j)+"\n";
    }
}
void imprimirFichas(ListaDoble<Palabra*> *lista)
{
    for(int i=0; i<lista->getSize(); i++)
    {
        int j=i+1;
        int k=i-1;
        int dato= lista->obtener_at(i)->getPunteo();
        string datofin= to_string(dato);
        cuerpoLista+="nodo"+to_string(i)+"[shape= record label=\""+lista->obtener_at(i)->getLetra()+"\n Punteo: "+datofin+"\"];\n";
        if(j<lista->getSize())
        {
        enlaceLista+="nodo"+to_string(i)+" -> nodo"+ to_string(j)+"\n";
        }
        if(k>=0){
        enlaceLista+="nodo"+to_string(i)+" -> nodo"+ to_string(k)+"\n";
        }
    }
}
void hacerCiclo(string letra, int cantidad, int punteo)
{
    for(int i=0; i<cantidad;i++)
    {
        AuxPalabra->insertar_final(new Palabra(letra,punteo));
    }
}
void asignarFichas(bool u1, bool u2)
{
    if(u1 && u2)
    {
        for(int i=0; i<7; i++)
        {

        fichaJug1->agregar_fin(colaPalabras->Dequeue());
        }
        for(int i=0; i<7; i++)
        {

        fichaJug2->agregar_fin(colaPalabras->Dequeue());
        }
    }
}
int turno=0;
bool contadorTurno(int t)
{
    if(t==0)
    {
        turno=1;
        return true;
    }
    else{
        turno=0;
        return false;
    }
}
bool verificarDiccionario(string pal)
{
    bool bandera=false;
    for(int i=0; i<DiccionarioPalabras->getSize(); i++)
    {
        string palabti=DiccionarioPalabras->obtener_at(i);
        if(pal.compare(palabti)==0)
        {
            bandera=true;
            break;
        }
    }
    return bandera;
}
string fichasJug1="";
void imprimirFichasJugador1(){
    fichasJug1="";
    for(int i=0; i<fichaJug1->getSize();i++)
    {
        int va=fichaJug1->obtener_at(i)->getPunteo();
        string da= to_string(va);
        fichasJug1+=fichaJug1->obtener_at(i)->getLetra()+" Punteo: "+da+", ";
    }
}
string fichasJug2="";
void imprimirFichasJugador2(){
    fichasJug2="";
    for(int i=0; i<fichaJug2->getSize();i++)
    {
        int va=fichaJug2->obtener_at(i)->getPunteo();
        string da= to_string(va);
        fichasJug2+=fichaJug2->obtener_at(i)->getLetra()+" Punteo: "+da+", ";
    }
}
bool verificarLetra(string letr,int num)
{
    bool bandera=false;
    if(num==1)
    {
        for(int i=0; i<=fichaJug1->getSize();i++){
            if(letr.compare(fichaJug1->obtener_at(i)->getLetra())==0)
            {
                bandera=true;
                cout<<fichaJug1->getSize()<<endl;
                auxLista->Enqueue(fichaJug1->eliminar(i));
                break;
            }
        }
    }
    else{
        for(int i=0; i<=fichaJug2->getSize();i++){
            if(letr.compare(fichaJug2->obtener_at(i)->getLetra())==0)
            {
                bandera=true;
                cout<<fichaJug2->getSize()<<endl;
                cout<<i<<endl;
                auxLista->Enqueue(fichaJug2->eliminar(i));
                break;
            }
        }
    }
    return bandera;
}
void turnos(int jug)
{
    string palabra="";
    string letra="";
    int fin=0;
    int x=0;
    int verHori=0;
    int y=0;
    do{
            cout<<"Ingrese letra: "<<endl;
            cin>>letra;
            palabra+=letra;
            if(jug==1){
            if(verificarLetra(letra,1)){
                    cout<<"Letra Valida"<<endl;
            }else{
                while(auxLista->getTamanio()!=0)
                {
                    fichaJug1->agregar_fin(auxLista->Dequeue());
                }
                break;}
            }else{
            if(verificarLetra(letra,2))
            {
            }else{
                 while(auxLista->getTamanio()!=0)
                {
                    fichaJug2->agregar_fin(auxLista->Dequeue());
                }
                break;}
            }
            cout<<"1. Salir"<<endl;
            cin>>fin;
            }while(fin!=1);
            if(verificarDiccionario(palabra))
            {
            system("cls");
            cout<<"Ingresa X"<<endl;
            cin>>x;
            cout<<"Ingresa Y"<<endl;
            cin>>y;
            cout<<"1. Ingresar Horizontal"<<endl;
            cout<<"2. Ingresar Vertical"<<endl;
            cin>>verHori;
                int larg;
            switch(verHori)
            {
            case 1:
                larg= x+ palabra.length();
                if(larg>DimensionTablero && y>DimensionTablero){

                }else{
                     cout<<"Vamos bien :3"<<endl;
                }
                break;
            case 2:
                larg=y+ palabra.length();
                if(larg>DimensionTablero && y>DimensionTablero){
                }
                else{
                    cout<<"Vamos bien :3"<<endl;
                }
                break;
            }
            }else{
                cout<<"Palabra no valida"<<endl;
                if(jug==1){

                while(auxLista->getTamanio()!=0)
                {
                    fichaJug1->agregar_fin(auxLista->Dequeue());
                }

            }else{
                 while(auxLista->getTamanio()!=0)
                {
                    fichaJug2->agregar_fin(auxLista->Dequeue());
                }
            }
            }

}
void iniciarJuego()
{
    srand(time(0));
    int random= rand() % 2;
    int finalizarJuego=0;
    int variableTurno=0;
    turno=random;
    int contadorFin=0;
    do{
        if(contadorTurno(turno))
        {
            do{
            cout<<"Turno: "+usuario1<<endl;
            imprimirFichasJugador1();
            cout<<"Palabras disponibles: "<<fichasJug1<<endl;
            turnos(1);
            cout<<"Terminar turno con 2"<<endl;
            cin>>variableTurno;
            }while(variableTurno!=2);
        }
        else{
            int variableTurno=0;
            do{
            cout<<"Turno: "+usuario2<<endl;
            imprimirFichasJugador2();
            cout<<"Palabras disponibles: "<<fichasJug2<<endl;
            turnos(2);
            cout<<"Terminar turno con 2"<<endl;
            cin>>variableTurno;
            }while(variableTurno!=2);

        }
        contadorFin++;
        int muestra= contadorFin %2;
        if(muestra==0)
        {
            cout<<"Desea Finalizar Juego? \n 50. Si \n cualquier numero sino quiere finalizar"<<endl;
            cin>>finalizarJuego;
        }
    }while((finalizarJuego!=50) && (colaPalabras->getTamanio()!=0));
}
