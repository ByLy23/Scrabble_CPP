#ifndef ARBOLBINBUSQUEDA_H_INCLUDED
#define ARBOLBINBUSQUEDA_H_INCLUDED
#include <iostream>
using namespace std;
class NodoABB
    {
        string nombreNodoABB;
        public:
        NodoABB *derecho;
        NodoABB *izquierdo;
        NodoABB()
        {
            nombreNodoABB="";
            izquierdo=derecho=0;
        }
        NodoABB(string nombre)
        {
            nombreNodoABB=nombre;
        }
        void setNombre(string nombre)
        {
            nombreNodoABB= nombre;
        }
        string getNombre()
        {
            return nombreNodoABB;
        }
        void setIzquierdo(NodoABB *izq)
        {
            this->izquierdo=izq;
        }
        void setDerecho(NodoABB *der)
        {
            this->derecho=der;
        }
        NodoABB *getIzquierdo()
        {
            return izquierdo;
        }
        NodoABB *getDerecho()
        {
            return derecho;
        }
    };
class ArbolBusqueda{
private:
    string cuerpo="";
    string enlaces="";

    public:
         string getCuerpo(){
        return cuerpo;
    }
    string getEnlaces(){
        return enlaces;
    }
    void setCuerpo(string cuerpo)
    {
        this->cuerpo=cuerpo;
    }
    void setEnlaces(string enlaces)
    {
        this->enlaces=enlaces;
    }
    ArbolBusqueda(){
    }
        void imprimirNodo(NodoABB*, int);
    NodoABB *crearNodoABB(string nombre)
    {
        NodoABB *nuevo= new NodoABB(nombre);
        nuevo->setNombre(nombre);
        nuevo->setIzquierdo(0);
        nuevo->setDerecho(0);
        return nuevo;
    }
    void inorden(NodoABB *arbol)
    {
        if(arbol!=0)
        {
            inorden(arbol->getDerecho());
            cuerpo+=arbol->getNombre()+"|";
            inorden(arbol->getIzquierdo());
        }
    }
    void preorden(NodoABB *arbol)
    {
        if(arbol!=0)
        {
            cuerpo+=arbol->getNombre()+"|";
            preorden(arbol->getDerecho());
            preorden(arbol->getIzquierdo());
        }
    }
    void postOrden(NodoABB *arbol)
    {
        if(arbol!=0)
        {
            postOrden(arbol->getDerecho());
            postOrden(arbol->getIzquierdo());
            cuerpo+=arbol->getNombre()+"|";
        }
    }
        bool bandera=false;
    bool verificaNombre(NodoABB *&arbol, string nombre)
    {
         if(arbol!=0){
                string nombreComparar= arbol->getNombre();
                if(nombre.compare(nombreComparar)==0)
                {
                    bandera=true;
                }
                else if(nombre.compare(nombreComparar)<0)
                {
                    verificaNombre(arbol->derecho,nombre);
                }
                else{
                    verificaNombre(arbol->izquierdo,nombre);
                }
        }
                return bandera;
    }
    void insertarNodoABB(NodoABB *&arbol, string nombre)
    {
        if(arbol==0)
        {
            NodoABB *nuevo= crearNodoABB(nombre);
            arbol=nuevo;
            arbol->getIzquierdo();
        }
        else{
                string nombreComparar= arbol->getNombre();
                if(nombre.compare(nombreComparar)==0)
                {
                    cout<<"Nombre Repetido"<<endl;
                }
                else if(nombre.compare(nombreComparar)<0)
                {
                    insertarNodoABB(arbol->derecho,nombre);
                }
                else{
                    insertarNodoABB(arbol->izquierdo,nombre);
                }
        }
    }
};

#endif // ARBOLBINBUSQUEDA_H_INCLUDED
