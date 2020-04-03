#include "Palabra.h"
#include <iostream>
using namespace std;
Palabra::Palabra()
{
    this->letra="";
    this->punteo=0;
    //ctor
}
Palabra::Palabra(string letra, int punteo)
{
    this->letra=letra;
    this->punteo=punteo;
}
Palabra::~Palabra()
{
    //dtor
}
string Palabra::getLetra(){
            return letra;
        }
        int Palabra::getPunteo()
        {
            return punteo;
        }
        void Palabra::setPunteo(int puntos)
        {
            this->punteo=puntos;
        }
        void Palabra::setLetra(string letra)
        {
            this->letra=letra;
        }
