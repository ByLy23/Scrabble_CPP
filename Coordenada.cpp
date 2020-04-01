#include "Coordenada.h"
#include <iostream>
Coordenada::Coordenada()
{

    //ctor
}

Coordenada::~Coordenada()
{
    //dtor
}

Coordenada::Coordenada(std::string atributo, int x, int y)
{
    this->x=x;
    this->y=y;
    this->nombre=atributo;
}
std::string Coordenada::getNombre()
{
    return nombre;
}
int Coordenada::getX()
{
    return x;
}
int Coordenada::getY()
{
    return y;
}
void Coordenada::setNombre(std::string nombre)
{
    this->nombre=nombre;
}
void Coordenada::setX(int x)
{
    this->x=x;
}
void Coordenada::setY(int y)
{
    this->y=y;
}
