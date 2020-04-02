#include "Usuario.h"
#include <iostream>
using namespace std;
Usuario::Usuario()
{
    //ctor
}
Usuario::Usuario(string nombre, int punteo)
{
    this->nombre=nombre;
    this->punteo=punteo;
}
void Usuario::setNombre(string nomgre)
{
    this->nombre=nomgre;
}
void Usuario::setPunteo(int punteo)
{
    this->punteo=punteo;
}
string Usuario::getNombre()
{
    return nombre;
}
int Usuario::getPunteo()
{
    return punteo;
}
Usuario::~Usuario()
{
    //dtor
}
