#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
template<class T>
class Pila
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
    int tamanio;
    bool estaVacia();
    public:
        Pila<T>()
        {
            inicio=0;
            tamanio=0;
        }
        int getTamanio()
        {
            return tamanio;
        }
        void push(T dato);
        T pop();
        T peek();
};

template<class T>
bool Pila<T>::estaVacia()
{
    return this->tamanio==0;
}

template<class T>
void Pila<T>::push(T dato)
{
    Nodo *nuevo= new Nodo(dato);
    if(estaVacia())
    {
        this->inicio=nuevo;
        this->tamanio++;
    }
    else
    {
        nuevo->setSiguiente(this->inicio);
        this->inicio= nuevo;
        this->tamanio++;
    }
}

template<class T>
T Pila<T>::pop()
{
    Nodo aux= inicio;
    if(aux!=0)
    {
        T info= this->inicio->getDato();
        this->inicio= this->inicio->getSiguiente();
        this->tamanio--;
        return info;
    }
    else{
        return 0;
    }
}

template<class T>
T Pila<T>::peek()
{
    T aux= this->inicio->getDato();
    return aux;
}


#endif // PILA_H_INCLUDED
