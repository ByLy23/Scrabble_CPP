#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
template<class T>
class Cola
{
    class Nodo
    {

        Nodo *siguiente;
        T dato;
    public:
         Nodo(T dato){
        siguiente=0;
        dato=0;
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
        Cola<T>()
        {
            inicio=0;
            tamanio=0;
        }
        int getTamanio()
        {
            return tamanio;
        }
        void Enqueue(T dato);
        T Dequeue();
};

template<class T>
bool Cola<T>::estaVacia()
{
    return this->tamanio==0;
}

template<class T>
void Cola<T>::Enqueue(T dato)
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
T Cola<T>::Dequeue()
{
    T info= this->inicio->getDato();
    if(inicio=fin)
    {
        inicio=fin=0;
        tamanio--;
    }
    else
    {
        inicio= inicio->getSiguiente();
        tamanio--;
    }
    return info;
}
#endif // COLA_H_INCLUDED
