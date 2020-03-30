#ifndef CUBODISPERSO_H_INCLUDED
#define CUBODISPERSO_H_INCLUDED
#include "Cancion.h"
#include "EDD/ListaSimple.h"
#include <iostream>

using namespace std;

class CuboDisperso
{
    class Nodo
    {
        Nodo *siguiente;
        Nodo *anterior;
        Nodo *atras;
        Nodo *adelante;
        Nodo *arriba;
        Nodo *abajo;
        int fila;
        int columna;
        int tamanio;
        string nombreAlbum;
        ListaSimple<Cancion*> *listaCancion;
    public:
        Nodo(string nombre, int fila, int columna, ListaSimple<Cancion*> *canciones)
        {
            this->nombreAlbum=nombre;
            this->fila=fila;
            this->columna=columna;
            this->listaCancion=canciones;
            siguiente=anterior=arriba=abajo=atras=adelante=0;
        }
        Nodo(int fila)//nodo de cabecera de filas
        {
            this->anio=fila;
            nombreAlbum="";
            mes="";
            listaCancion=0;
            siguiente=anterior=arriba=abajo=atras=adelante=0;
        }
        Nodo(string columna)//nodo cabecera de columnas
        {

           anio=-1;
            nombreAlbum="";
            this->mes=columna;
            listaCancion=0;
            siguiente=anterior=arriba=abajo=atras=adelante=0;
        }
        int getAnio()
        {
            return anio;
        }
        string getMes()
        {
            return mes;
        }
        string getNombreAlbum()
        {
            return nombreAlbum;
        }
        ListaSimple<Cancion*> *getCanciones()
        {
            return listaCancion;
        }
        void setAnio(int anio)
        {
            this->anio=anio;
        }
        void setMes(string mes)
        {
            this->mes=mes;
        }
        void setNombreAlbum(string nombreAlbum)
        {
            this->nombreAlbum=nombreAlbum;
        }
        void setListaCanciones(ListaSimple<Cancion*> *listaCanciones)
        {
            this->listaCancion=listaCanciones;
        }
        Nodo *getSiguiente()
        {
            return siguiente;
        }
        Nodo *getAnterior()
        {
            return anterior;
        }
        Nodo *getArriba()
        {
            return arriba;
        }
        Nodo *getAbajo()
        {
            return abajo;
        }
        Nodo *getAtras()
        {
            return atras;
        }
        Nodo *getAdelante()
        {
            return adelante;
        }
        void setSiguiente(Nodo *siguiente)
        {
            this->siguiente=siguiente;
        }
        void setAnterior(Nodo *anterior)
        {
            this->anterior=anterior;
        }
        void setAtras(Nodo *atras)
        {
            this->atras=atras;
        }
        void setAdelante(Nodo *adelante)
        {
            this->adelante=adelante;
        }
        void setArriba(Nodo *arriba)
        {
            this->arriba=arriba;
        }
        void setAbajo(Nodo *abajo)
        {

            this->abajo=abajo;
        }
    };
    Nodo *raiz;
    public:
    CuboDisperso()
    {
        raiz= new Nodo("raiz", -1, "raiz",NULL);
    }
    Nodo *busquedaNodo(int columna, string fila)
{
    bool bandera=false;
        Nodo *retorno=0;
    Nodo *aux= raiz;
    while(aux!=0)
    {
        Nodo *aux2=raiz;
        while(aux2!=0){
            if(aux2->getAnio()==columna && aux2->getMes().compare(fila))
                {
                    retorno=aux2;
                    bandera=true;
                    break;
                }
                aux2=aux2->getSiguiente();
        }
        if (bandera)
            break;
        aux= aux->getAbajo();
    }
    return retorno;
}
Nodo *crearColumna(int columna)
{
    Nodo *cabeza_col= raiz;
    Nodo *col_insertada= insertarColumna(new Nodo(columna), cabeza_col);
    return col_insertada;
}
Nodo *crearFila(string fila)
{
    Nodo *cabezaFila= raiz;
    Nodo *filaInsertada= insertarFila(new Nodo(fila),cabezaFila);
    return filaInsertada;
}
void imprimir()
{
    Nodo *aux= raiz;
    while(aux!=0){
            Nodo *aux2=aux;
            while(aux2!=0)
            {
                if(aux2->getCanciones()!=0)
                {
                    ListaSimple<Cancion*> *canciones= aux2->getCanciones();
                    for(int i=0; i<canciones->getTamanio(); i++)
                    {
                        cout<<canciones->get_element_at(i)->getCancion()<<"Funciona"<<endl;
                    }
                }
                cout<<"Canbio album"<<endl;
                 aux2=aux2->getSiguiente();
            }
            cout<<endl;
            aux=aux->getAbajo();
    }
}
void crearNodo(string nombre, int anio, string mes, ListaSimple<Cancion*> *canciones)
{
    Nodo *nuevo= new Nodo(nombre,anio,mes,canciones);
    Nodo *NodoColumna= buscarColumna(anio);
    Nodo *NodoFila= buscarFila(mes);
    if(NodoColumna==0 && NodoFila==0){
        //ninguno esta creado
        NodoColumna= crearColumna(anio);
        NodoFila= crearFila(mes);
        nuevo= insertarColumna(nuevo,NodoFila);
        nuevo= insertarFila(nuevo,NodoColumna);
    }
    else if(NodoColumna==0 && NodoFila!=0)
    {
        NodoColumna= crearColumna(anio);
        nuevo= insertarColumna(nuevo,NodoFila);
        nuevo= insertarFila(nuevo,NodoColumna);
        //solo esta creada la fila
    }
    else if(NodoColumna!=0 && NodoFila==0)
    {
        //solo esta creada la columna
        NodoFila= crearFila(mes);
        nuevo= insertarColumna(nuevo,NodoFila);
        nuevo= insertarFila(nuevo,NodoColumna);
    }
    else if(NodoColumna!=0 && NodoFila!=0)
    {
        //estan creados los dos
        if(NodoColumna->getAnio()==nuevo->getAnio() && NodoFila->getMes()==nuevo->getMes())
        {
            Nodo *busqueda= busquedaNodo(anio,mes);
            busqueda->setAdelante(nuevo);
            nuevo->setAtras(busqueda);
        }
        else
        {
        nuevo= insertarColumna(nuevo,NodoFila);
        nuevo= insertarFila(nuevo,NodoColumna);
        }
    }
}
Nodo *insertarFila(Nodo *nuevo,Nodo *nodoFila)
{
    Nodo *aux= nodoFila;
    bool Flag= false;
    while(true)
    {
        if(aux->getMes().compare(nuevo->getMes())==0)
        {
            aux->setAnio(nuevo->getAnio());
            aux->setNombreAlbum(nuevo->getNombreAlbum());
            aux->setListaCanciones(nuevo->getCanciones());
            Flag=true;
            return aux;
            break;
        }
        if(aux->getAbajo()!=0)
        {
            aux=aux->getAbajo();
        }
        else{break;}

    }
    if(Flag)
        {
            nuevo->setAbajo(aux);
            aux->getArriba()->setAbajo(nuevo);
            nuevo->setArriba(aux->getArriba());
            aux->setArriba(nuevo);
        }
        else{
            aux->setAbajo(nuevo);
            nuevo->setArriba(aux);
        }
    return nuevo;

}
Nodo *insertarColumna(Nodo *nuevo,Nodo *nodoColumna)
{
    Nodo *aux= nodoColumna;
    bool Flag= false;
    while(true)
    {
        if(aux->getAnio()==nuevo->getAnio())
        {
            aux->setMes(nuevo->getMes());
            aux->setNombreAlbum(nuevo->getNombreAlbum());
            aux->setListaCanciones(nuevo->getCanciones());
            return aux;
        }
        else if(aux->getAnio()>nuevo->getAnio())
        {
            Flag= true;
            break;
        }
        if(aux->getSiguiente()!=0)
        {
            aux=aux->getSiguiente();
        }
        else{break;}
    }
    if(Flag)
        {
            nuevo->setSiguiente(aux);
            aux->getAnterior()->setSiguiente(nuevo);
            nuevo->setAnterior(aux->getAnterior());
            aux->setAnterior(nuevo);
        }
        else{
            aux->setSiguiente(nuevo);
            nuevo->setAnterior(aux);
        }
    return nuevo;

}
Nodo *buscarFila(string fila)
{
    Nodo *aux= raiz;
    if(raiz->getAbajo()!=0)
    {
        while(aux!=0)
        {
            if(aux->getMes().compare(fila)==0)
                return aux;
            aux=aux->getAbajo();
        }
    }
    return 0;
}
Nodo *buscarColumna(int columna)
{
    Nodo *aux= raiz;
    if(aux->getSiguiente()!=0)
    {
        while(aux!=0)
        {
            if(aux->getAnio()==columna)
                return aux;
            aux= aux->getSiguiente();
        }
    }
    return 0;
}
    /*Nodo *insertarFila(Nodo *nuevo, Nodo *fila);
    Nodo *insertarColumna(Nodo *nuevo, Nodo *nodoColumna);
    Nodo *crearFila(string fila);
    Nodo *crearColumna(int columna);
    Nodo *busquedaNodo(int columna, string fila);
    Nodo *buscarColumna(int columna);//listo
    Nodo *buscarFila(string fila);//listo
    void crearNodo(string nombre, int anio, string mes, ListaSimple<Cancion*> *canciones);*/
};


#endif // CUBODISPERSO_H_INCLUDED
