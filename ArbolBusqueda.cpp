#include "EDD/ArbolBinBusqueda.h"
#include <iostream>
using namespace std;
void ArbolBusqueda::imprimirNodo(NodoABB *arbol, int contador)
{
        if(arbol!=NULL)
        {
          if(arbol->getDerecho()){
              if(arbol->getNombre()!=""){
            cuerpo+=arbol->getNombre() + "[shape= circle label=\"" + arbol->getNombre() + "\"];\n";
            enlaces+= arbol->getNombre()+ "->"+ arbol->getDerecho()->getNombre()+"\n";
              }
            imprimirNodo(arbol->getDerecho(),contador+1);
          }
          if(arbol->getIzquierdo()){
                if(arbol->getNombre()!=""){

            cuerpo+=arbol->getNombre() + "[shape= circle label=\"" + arbol->getNombre() + "\"];\n";
            enlaces+= arbol->getNombre()+"->"+arbol->getIzquierdo()->getNombre()+"\n";
                }
            imprimirNodo(arbol->getIzquierdo(),contador+1);
          }
        }
}
