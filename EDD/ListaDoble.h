#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED
template<class T>
class ListaDoble
{
    class Nodo
    {
    public:
    Nodo(T x){
        dato=x;
        siguiente=anterior=0;
    }
    void setSiguiente(Nodo *n)
    {
        siguiente=n;
    }
    Nodo *getSiguiente()
    {
        return siguiente;
    }
    void setAnterior(Nodo *n)
    {
        anterior=n;
    }
    Nodo *getAnterior()
    {
        return anterior;
    }
    T getDato()
    {
        return dato;
    }
private:
    T dato;
    Nodo *siguiente;
    Nodo *anterior;
    };
public:

    ListaDoble<T>()
    {
     inicio=fin=0;
     size=0;
    }
    int getSize(){return size;}
    T eliminar(int index);
    void agregar_inicio(T dato);
    void agregar_fin(T dato);
    void agregar_entre(T dato,int index);
    T obtener_at(int index);
    int size;
private:
    bool estaVacia(){return size==0;}
    Nodo *inicio;
    Nodo *fin;
};
template<class T>
T ListaDoble<T>::obtener_at(int index)
{
     if(index >= 0 && index < size)
    {
        Nodo *iterador = this->inicio;
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
void ListaDoble<T>::agregar_entre(T dato, int index)
{
    if(index >= 0 && index <= this->size)
    {
        if(index == 0){ this->agregar_inicio(dato) ; return;}
        if(index == this->size) {this->agregar_fin(dato); return;}
        Nodo *aux = this->inicio;
        int x = 0;
        while(aux!=0)
        {
            if(x == index){break;}
            aux = aux->getSiguiente();
            x++;
        }
        Nodo *n = new Nodo(dato);
        aux->getAnterior()->setAnterior(n);
        n->setAnterior(aux->getAnterior());
        n->setSiguiente(aux);
        aux->setAnterior(n);
        this->size++;
    }
}
template<class T>
void ListaDoble<T>::agregar_fin(T dato)
{
     Nodo *nuevo= new Nodo(dato);
    if(estaVacia())
    {
        this->inicio=this->fin=nuevo;
        this->size++;
    }
    else
    {
        this->fin->setSiguiente(nuevo);
        nuevo->setAnterior(fin);
        this->fin= nuevo;
        this->size++;
    }
}

template<class T>
void ListaDoble<T>::agregar_inicio(T dato)
{
    Nodo *nuevo= new Nodo(dato);
    if(estaVacia())
    {
        this->inicio=this->fin=nuevo;
        this->size++;
    }
    else
    {
        nuevo->setSiguiente(this->inicio);
        this->inicio->setAnterior(nuevo);
        this->inicio= nuevo;
        this->size++;
    }
}

template<class T>
T ListaDoble<T>::eliminar(int index)
{
    T informacion;
 if(index>=0 && index<size)
    {
        if(index==0){
                informacion=this->inicio->getDato();
            this->inicio=this->inicio->getSiguiente();
            this->inicio->getAnterior()->setSiguiente(0);
            this->inicio->setAnterior(0);
            this->size--;
        }
        else if(index==this->size-1){
            informacion=this->fin->getDato();
            fin=fin->getAnterior();
            fin->getSiguiente()->setAnterior(0);
            fin->setSiguiente(0);
            this->size--;
        }
        else{

        int x=0;
        Nodo *actual=this->inicio;
        Nodo *anterior= 0;
        while(actual!=0)
        {
            if(x==index){informacion=actual->getDato();break;}
            anterior=actual;
            actual=actual->getSiguiente();
            x++;
        }
        actual->getSiguiente()->setAnterior(anterior);
        anterior->setSiguiente(actual->getSiguiente());
        actual->setSiguiente(0);
        actual->setAnterior(0);
        this->size--;
        }
    }
    return informacion;
}
#endif // LISTADOBLE_H_INCLUDED
