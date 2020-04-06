#ifndef LISTADOBLECIRCULAR_H_INCLUDED
#define LISTADOBLECIRCULAR_H_INCLUDED
template<class T>
class ListaDobleCircular
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
    string grupo;
    string getEnlaces(){
        return enlaces;
    }
    string getCuerpo()
    {
        return cuerpo;
    }
    void setEnlaces(string enlaces)
    {
        this->enlaces=enlaces;
    }
    void setCuerpo(string cuerpo)
    {
        this->cuerpo=cuerpo;
    }
    ListaDobleCircular<T>()
    {
     inicio=fin=0;
     size=0;
    }
    int getSize(){return size;}
    void eliminar(int index);
    void agregar_inicio(T dato);
    void agregar_fin(T dato);
    void agregar_entre(T dato,int index);
    T obtener_at(int index);
    void imprimirLista();
    int size;
private:
    bool estaVacia(){return size==0;}
    Nodo *inicio;
    Nodo *fin;
    string cuerpo="";
    string enlaces="";
};

template<class T>
T ListaDobleCircular<T>::obtener_at(int index)
{
        Nodo *iterador = this->inicio;
     if(index >= 0 && index < size)
    {
        int x = 0;
        do
        {
            if(index == x){return iterador->getDato();}
            iterador = iterador->getSiguiente();
            x++;
        }while(iterador!=fin);
    }
    return iterador->getDato();
}

template<class T>
void ListaDobleCircular<T>::agregar_entre(T dato, int index)
{
    if(index >= 0 && index <= this->size)
    {
        if(index == 0){ this->agregar_inicio(dato) ; return;}
        if(index == this->size) {this->agregar_fin(dato); return;}
        Nodo *aux = this->inicio;
        int x = 0;
        do
        {
            if(x == index){break;}
            aux = aux->getSiguiente();
            x++;
        }while(aux==fin);
        Nodo *n = new Nodo(dato);
        aux->getAnterior()->setAnterior(n);
        n->setAnterior(aux->getAnterior());
        n->setSiguiente(aux);
        aux->setAnterior(n);
        this->size++;
    }
}

template<class T>
void ListaDobleCircular<T>::agregar_fin(T dato)
{
     Nodo *nuevo= new Nodo(dato);
    if(estaVacia())
    {
        this->inicio=this->fin=nuevo;
        nuevo->setAnterior(nuevo);
        nuevo->setSiguiente(nuevo);
        this->size++;
    }
    else
    {
        this->fin->setSiguiente(nuevo);
        nuevo->setAnterior(this->fin);
        nuevo->setSiguiente(this->inicio);
        this->inicio->setAnterior(nuevo);
        this->fin= nuevo;
        this->size++;
    }
}

template<class T>
void ListaDobleCircular<T>::agregar_inicio(T dato)
{
    Nodo *nuevo= new Nodo(dato);
    if(estaVacia())
    {
        this->inicio=this->fin=nuevo;
        nuevo->setAnterior(nuevo);
        nuevo->setSiguiente(nuevo);
        this->size++;
    }
    else
    {
        nuevo->setSiguiente(this->inicio);
        this->inicio->setAnterior(nuevo);
        nuevo->setAnterior(fin);
        fin->setSiguiente(nuevo);
        this->inicio= nuevo;
        this->size++;
    }
}

template<class T>
void ListaDobleCircular<T>::eliminar(int index)
{
 if(index>=0 && index<=size)
    {
        if(index==0){
            this->inicio=this->inicio->getSiguiente();
            this->inicio->getAnterior()->setSiguiente(0);
            this->inicio->setAnterior(0);
            this->size--;
        }
        else if(index==this->size){
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
            if(x==index){break;}
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
}

template<class T>
void ListaDobleCircular<T>::imprimirLista()
{
    int x=0;
    Nodo *aux= this->inicio;
    if(!estaVacia()){
    while(x!=size)
    {
        cuerpo+=aux->getDato()+"[shape= record label=\""+aux->getDato()+"\"];\n";
        enlaces+= aux->getDato()+"->"+aux->getAnterior()->getDato()+"\n"+aux->getDato()+"->"+aux->getSiguiente()->getDato()+"\n";
        grupo+=aux->getDato()+"; ";
        x++;
        aux=aux->getSiguiente();
    }
    }
}


#endif // LISTADOBLECIRCULAR_H_INCLUDED
