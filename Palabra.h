#ifndef PALABRA_H
#define PALABRA_H
#include <iostream>
using namespace std;


class Palabra
{
    public:
        Palabra();
        Palabra(string, int);
        virtual ~Palabra();
        void setLetra(string);
        void setPunteo(int);
        string getLetra();
        int getPunteo();
    protected:

    private:
        string letra="";
        int punteo=0;
};

#endif // PALABRA_H
