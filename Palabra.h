#ifndef PALABRA_H
#define PALABRA_H
#include <iostream>
using namespace std;


class Palabra
{
    public:
        Palabra();
        Palabra(string, int);
        string getLetra(){
            return letra;
        }
        int getPunteo()
        {
            return punteo;
        }
        void setPunteo(int puntos)
        {
            this->punteo=puntos;
        }
        void setLetra(string letra)
        {
            this->letra=letra;
        }
        virtual ~Palabra();

    protected:

    private:
        string letra="";
        int punteo=0;
};

#endif // PALABRA_H
