#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED
template<class T>
class ListaSimple
{
    class Nodo
    {
        Nodo *siguiente;
        T dato;
    public:
        Nodo(T x)
        {
            dato=x;
            siguiente=0;
        }
        void setSiguiente(Nodo *n)
        {
            siguiente=n;
        }
        Nodo *getSiguiente()
        {
            return siguiente;
        }
        T getDato()
        {
            return dato;
        }
    };
    Nodo *inicio;
    Nodo *fin;
    int tamanio;
    bool estaVacia();
    public:
        ListaSimple<T>()
        {
            inicio=0;
            tamanio=0;
        }
        int getTamanio()
        {
            return tamanio;
        }
        void insertar_final(T dato);
        void insertar(T dato,int index);
        T remover(int index);
        void buscar(T dato);
        T get_element_at(int index);
};

template<class T>
bool ListaSimple<T>::estaVacia()
{
    return this->tamanio==0;
}

template<class T>
T ListaSimple<T>::get_element_at(int index)
{
    if(index>=0 && index<= tamanio)
    { Nodo *iterador = this->inicio;
        int x = 0;
        while(iterador!=0)
        {
            if(index == x){return iterador->getDato();}
            iterador = iterador->getSiguiente();
            x++;
        }
    }
    return 0;
}

template<class T>
void ListaSimple<T>::insertar_final(T dato)
{
    Nodo *nuevo= new Nodo(dato);
    if(estaVacia())
    {
        inicio=fin=nuevo;
        tamanio++;
    }
    else
    {
        fin->setSiguiente(nuevo);
        fin= nuevo;
        tamanio++;
    }
}

template<class T>
void ListaSimple<T>::insertar(T dato,int index)
{
    Nodo *nuevo= new Nodo(dato);
    if(estaVacia())
    {
        inicio=fin=nuevo;
        tamanio++;
    }
    else if(index==tamanio)
    {
        insertar_final(dato);
    }
    else if(index==0)
    {
        nuevo->setSiguiente(inicio);
        inicio=nuevo;
        tamanio++;
    }
    else{
            Nodo *aux=this->inicio;
            int x=0;
        while(aux!=0)
        {
            if(x==index){break;}
            aux=aux->getSiguiente();
        }
        Nodo* sig= aux->getSiguiente();
        aux->setSiguiente(nuevo);
        nuevo->setSiguiente(sig);
        tamanio++;
    }
}

template<class T>
T ListaSimple<T>::remover(int index)
{
    T informacion;
    if(index==0)
    {
        informacion=this->inicio->getDato();
        inicio=inicio->getSiguiente();
        this->tamanio--;
    }
    else
    {
        Nodo *aux= this->inicio;
        Nodo *anterior=0;
        int x=0;
        while(aux!=0)
        {
            if(x==index)
            {
                informacion=aux->getDato();
                break;
            }
            anterior=aux;
            aux=aux->getSiguiente();
            x++;
        }
        anterior->setSiguiente(aux->getSiguiente());
        aux->setSiguiente(0);
        this->tamanio--;
    }
    return informacion;
}


#endif // LISTASIMPLE_H_INCLUDED
