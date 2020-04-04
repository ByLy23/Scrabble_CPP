#ifndef CUBODISPERSO_H_INCLUDED
#define CUBODISPERSO_H_INCLUDED
#include <iostream>

using namespace std;
//arreglos matriz
class CuboDisperso
{
    class Nodo
    {
        Nodo *siguiente;
        Nodo *anterior;
        Nodo *arriba;
        Nodo *abajo;
        int fila;
        int columna;
        int multiplicador;
        string letra;
        int tamanio;
    public:
        //crear cabeceras de filas y columnas

        Nodo(string letra, int fila, int columna, int multi)
        {//anio es filas, mes es columnas
            this->fila=fila;
            this->columna=columna;
            this->letra=letra;
            this->multiplicador=multi;
            siguiente=anterior=arriba=abajo=0;
        }
         Nodo(int dato, bool esFila)
        {
            if(esFila)
            {
            this->fila=dato;
            this->columna=-1;
            this->letra="";
            this->multiplicador=0;
            siguiente=anterior=arriba=abajo=0;
            }else{
            this->fila=-1;
            this->columna=dato;
            this->letra="";
            this->multiplicador=0;
            siguiente=anterior=arriba=abajo=0;
            }
        }
        int getColumna()
        {
            return columna;
        }
        int getFila()
        {
            return fila;
        }
        int getMuti()
        {
            return multiplicador;
        }
        string getLetra()
        {
            return letra;
        }
        void setColumna(int f)
        {
            columna=f;
        }void setFila(int f)
        {
            fila=f;
        }void setMulti(int f)
        {
           multiplicador=f;
        }
        void setLetra(string letra)
        {
            this->letra=letra;
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
        void setSiguiente(Nodo *siguiente)
        {
            this->siguiente=siguiente;
        }
        void setAnterior(Nodo *anterior)
        {
            this->anterior=anterior;
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
        raiz= new Nodo("raiz",-1,-1,0);
    }
    Nodo *busquedaNodo(int columna, int fila)
{
    bool bandera=false;
        Nodo *retorno=0;
    Nodo *aux= raiz;
    while(aux!=0)
    {
        Nodo *aux2=raiz;
        while(aux2!=0){
            if(aux2->getColumna()==columna && aux2->getFila()==fila)
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
    Nodo *col_insertada= insertarColumna(new Nodo(columna,false), cabeza_col);
    return col_insertada;
}
Nodo *crearFila(int fila)
{
    Nodo *cabezaFila= raiz;
    Nodo *filaInsertada= insertarFila(new Nodo(fila,true),cabezaFila);
    return filaInsertada;
}
/*void imprimir()
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
}*/
void crearNodo(string nombre, int multi, int fila, int columna)
{
    Nodo *nuevo= new Nodo(nombre,fila,columna,multi);
    Nodo *NodoColumna= buscarColumna(columna);
    Nodo *NodoFila= buscarFila(fila);
    if(NodoColumna==0 && NodoFila==0){
        //ninguno esta creado
        NodoColumna= crearColumna(columna);
        NodoFila= crearFila(fila);
        nuevo= insertarColumna(nuevo,NodoFila);
        nuevo= insertarFila(nuevo,NodoColumna);
    }
    else if(NodoColumna==0 && NodoFila!=0)
    {
        NodoColumna= crearColumna(columna);
        nuevo= insertarColumna(nuevo,NodoFila);
        nuevo= insertarFila(nuevo,NodoColumna);
        //solo esta creada la fila
    }
    else if(NodoColumna!=0 && NodoFila==0)
    {
        //solo esta creada la columna
        NodoFila= crearFila(fila);
        nuevo= insertarColumna(nuevo,NodoFila);
        nuevo= insertarFila(nuevo,NodoColumna);
    }
    else if(NodoColumna!=0 && NodoFila!=0)
    {
        //estan creados los dos
        nuevo= insertarColumna(nuevo,NodoFila);
        nuevo= insertarFila(nuevo,NodoColumna);
    }
}
Nodo *insertarFila(Nodo *nuevo,Nodo *nodoFila)
{
    Nodo *aux= nodoFila;
    bool Flag= false;
     while(true)
    {
        if(aux->getColumna() ==nuevo->getColumna())
        {
            aux->setFila(nuevo->getFila());
            aux->setLetra(nuevo->getLetra());
            aux->setMulti(nuevo->getMuti());
            return aux;
        }
        else if(aux->getColumna()>nuevo->getColumna())
        {
            Flag= true;
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
        if(aux->getFila() ==nuevo->getFila())
        {
            aux->setColumna(nuevo->getColumna());
            aux->setLetra(nuevo->getLetra());
            aux->setMulti(nuevo->getMuti());
            return aux;
        }
        else if(aux->getFila()>nuevo->getFila())
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
Nodo *buscarFila(int fila)
{
    Nodo *aux= raiz;
    if(raiz->getAbajo()!=0)
    {
        while(aux!=0)
        {
            if(aux->getFila()==fila)
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
            if(aux->getColumna()==columna)
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
