#include "Palabra.h"
#include <iostream>
using namespace std;
Palabra::Palabra()
{
    //ctor
}
Palabra::Palabra(string dato, int numero)
{
    this->letra=dato;
    this->punteo=numero;
}
Palabra::~Palabra()
{
    //dtor
}
