#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>

class Usuario
{
    public:
        Usuario();
        Usuario(std::string nombre, int punteo);
        std::string getNombre();
        int getPunteo();
        void setNombre(std::string);
        void setPunteo(int);
        virtual ~Usuario();

    protected:

    private:
        std::string nombre;
        int punteo;
};

#endif // USUARIO_H
