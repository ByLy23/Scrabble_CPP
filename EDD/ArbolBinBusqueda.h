#ifndef ARBOLBINBUSQUEDA_H_INCLUDED
#define ARBOLBINBUSQUEDA_H_INCLUDED
#include "Playlist.h"
#include <iostream>
using namespace std;
class NodoABB
    {
        string nombreNodoABB;
        Playlist *listaPla;
        public:
        NodoABB *derecho;
        NodoABB *izquierdo;
        NodoABB(string nombre)
        {
            nombreNodoABB=nombre;
            listaPla=lista;
        }
        void setNombre(string nombre)
        {
            nombreNodoABB= nombre;
        }
        void setLista(Playlist *lista)
        {
            listaPla=lista;
        }
        void setIzquierdo(NodoABB *izq)
        {
            this->izquierdo=izq;
        }
        void setDerecho(NodoABB *der)
        {
            this->derecho=der;
        }
        Playlist *getPlaylist()
        {
            return listaPla;
        }
        NodoABB *getIzquierdo()
        {
            return izquierdo;
        }
        NodoABB *getDerecho()
        {
            return derecho;
        }
        string getNombre()
        {
            return nombreNodoABB;
        }
    };
class ArbolBusqueda{
    public:
    ArbolBusqueda(){
    }
    NodoABB *crearNodoABB(string nombre, Playlist *lista)
    {
        NodoABB *nuevo= new NodoABB(nombre,lista);
        nuevo->setNombre(nombre);
        nuevo->setLista(lista);
        nuevo->setIzquierdo(0);
        nuevo->setDerecho(0);
        return nuevo;
    }
    void insertarNodoABB(NodoABB *&arbol, string nombre, Playlist *lista)
    {
        if(arbol==0)
        {
            NodoABB *nuevo= crearNodoABB(nombre, lista);
            arbol=nuevo;
            arbol->getIzquierdo();
        }
        else{
                string nombreComparar= arbol->getNombre();
                if(nombre.compare(nombreComparar)<0)
                {
                    insertarNodoABB(arbol->izquierdo,nombre,lista);
                }
                else{
                    insertarNodoABB(arbol->derecho,nombre,lista);
                }
        }
    }
    void imprimirNodo(NodoABB *arbol, int contador)
    {
        if(arbol==0)
        {
            return;
        }
        else{
            imprimirNodo(arbol->derecho,contador+1);
            for(int i=0; i<contador;i++);
            {
                cout<<"         "<<endl;
            }
            cout<<arbol->getNombre()<<endl;
            imprimirNodo(arbol->izquierdo,contador+1);
        }
    }
};



#endif // ARBOLBINBUSQUEDA_H_INCLUDED
