#ifndef COORDENADA_H
#define COORDENADA_H
#include <iostream>

class Coordenada
{
    public:
        Coordenada();
        virtual ~Coordenada();
        Coordenada(std::string , int , int );
        std::string getNombre();
        int getX();
        int getY();
        void setNombre(std::string);
        void setX(int);
        void setY(int);
    protected:

    private:
        std::string nombre;
        int x;
        int y;
};

#endif // COORDENADA_H
