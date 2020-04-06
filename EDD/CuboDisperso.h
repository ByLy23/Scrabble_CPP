#ifndef CUBODISPERSO_H_INCLUDED
#define CUBODISPERSO_H_INCLUDED
#include <iostream>

using namespace std;
//arreglos matriz
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
            this->columna=0;
            this->letra="";
            this->multiplicador=0;
            siguiente=anterior=arriba=abajo=0;
            }else{
            this->fila=0;
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
class CuboDisperso
{

    Nodo *raiz;
        string cuerpo="";
        string enlaces="";
        string grupo="";
        string wolrd="";
    public:
        string getWor()
        {
            return wolrd;
        }
        void setWords(string grupo)
        {
            this->wolrd=grupo;
        }
        string getGrupo()
        {
            return grupo;
        }
        void setGrupo(string grupo)
        {
            this->grupo=grupo;
        }
        string getEnlaces()
        {
            return enlaces;
        }
        string getCuerpo()
        {
            return cuerpo;
        }
        void setCuerpo(string cuerpo)
        {
            this->cuerpo=cuerpo;
        }
        void setEnlaces(string enlaces)
        {
            this->enlaces=enlaces;
        }
    CuboDisperso()
    {
        raiz= new Nodo("raiz",0,0,0);
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
void imprimir()
{
    Nodo *aux= raiz;
    while(aux!=0){

            string fil="C"+to_string(aux->getFila());
            string col="F"+to_string(aux->getColumna());
           /* if(aux->getAnterior()!=0){
                string filanterior="C"+to_string(aux->getAnterior()->getFila());
            string colanterior="F"+to_string(aux->getAnterior()->getColumna());
            enlaces+="\""+fil+col+"\" -> \""+filanterior+colanterior+"\"\n";
            }
            if(aux->getSiguiente()!=0){
                string filsiguiente="C"+to_string(aux->getSiguiente()->getFila());
            string colsiguiente="F"+to_string(aux->getSiguiente()->getColumna());
            enlaces+="\""+fil+col+"\" -> \""+filsiguiente+colsiguiente+"\"\n";
            }*/
            //cuerpo+="\""+fil+col+"\""+"[shape= record label=\""+fil+","+col+"\"];\n";

        Nodo *aux2=aux;
        string ranki="";
        while(aux2!=0)
        {
  string fil="C"+to_string(aux2->getFila());
            string col="F"+to_string(aux2->getColumna());
            if(aux2->getArriba()!=0){
                string filanterior="C"+to_string(aux2->getArriba()->getFila());
            string colanterior="F"+to_string(aux2->getArriba()->getColumna());
            enlaces+="\""+fil+col+"\" -> \""+filanterior+colanterior+"\"\n";
            }
            if(aux2->getAbajo()!=0){
                string filsiguiente="C"+to_string(aux2->getAbajo()->getFila());
            string colsiguiente="F"+to_string(aux2->getAbajo()->getColumna());
            enlaces+="\""+fil+col+"\" -> \""+filsiguiente+colsiguiente+"\"\n";
            }
            if(aux2->getAnterior()!=0){
                string filanterior="C"+to_string(aux2->getAnterior()->getFila());
            string colanterior="F"+to_string(aux2->getAnterior()->getColumna());
            enlaces+="\""+fil+col+"\" -> \""+filanterior+colanterior+"\"\n";
            }
            if(aux2->getSiguiente()!=0){
                string filsiguiente="C"+to_string(aux2->getSiguiente()->getFila());
            string colsiguiente="F"+to_string(aux2->getSiguiente()->getColumna());
            enlaces+="\""+fil+col+"\" -> \""+filsiguiente+colsiguiente+"\"\n";
            }
            if(aux2->getMuti()==2)
            {
            cuerpo+="\""+fil+col+"\""+"[shape= record label=\""+aux2->getLetra()+"\" style=filled fillcolor=yellow group="+to_string(aux2->getColumna())+"];\n";
            }
            else if(aux2->getMuti()==3)
            {
               cuerpo+="\""+fil+col+"\""+"[shape= record label=\""+aux2->getLetra()+"\" style=filled fillcolor=green group="+to_string(aux2->getColumna())+"];\n";
            }
            else if(aux2->getMuti()==1){
                cuerpo+="\""+fil+col+"\""+"[shape= record label=\""+aux2->getLetra()+"\" style=filled fillcolor=blue group="+to_string(aux2->getColumna())+"];\n";
            }else{
                if(aux2->getFila()==0 && aux2->getColumna()==0){
                        cuerpo+="\""+fil+col+"\""+"[shape= record label=\"Raiz\" style=filled fillcolor=gray group=1];\n";
                }else{
                    if(aux2->getFila()==0)
                        cuerpo+="\""+fil+col+"\""+"[shape= record label=\""+fil+","+col+"\" style=filled fillcolor=gray group="+to_string(aux2->getColumna())+"];\n";
                    else
                        cuerpo+="\""+fil+col+"\""+"[shape= record label=\""+fil+","+col+"\" style=filled fillcolor=gray group= 1];\n";
                   // cout<<fil<<endl;
                }
                }
                ranki+=fil+col+";";
                //cout<<fil+col<<endl;
            aux2=aux2->getAbajo();
        }
        wolrd+="{rank= same; "+ranki+"}\n";
       // cout<<ranki<<endl;
        //grupo+= fil+col+"; ";
    aux=aux->getSiguiente();
        }
    }
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
Nodo *insertarColumna(Nodo *nuevo,Nodo *nodoFila)
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
Nodo *insertarFila(Nodo *nuevo,Nodo *nodoColumna)
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
Nodo *buscarColumna(int fila)
{
    Nodo *aux= raiz;
    if(raiz->getAbajo()!=0)
    {
        while(aux!=0)
        {
            if(fila==aux->getFila())
                return aux;
            aux=aux->getAbajo();
        }
    }
    return aux;
}
Nodo *buscarFila(int columna)
{
    Nodo *aux= raiz;
    if(aux->getSiguiente()!=0)
    {
        while(aux!=0)
        {
            if(columna==aux->getColumna())
                return aux;
            aux= aux->getSiguiente();
        }
    }
    return aux;
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
