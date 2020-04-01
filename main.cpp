#include <iostream>
#include "json/json.h"
//#include "EDD/CuboDisperso.h"
#include "json/jsoncpp.cpp"
using namespace std;

int main()
{
    int contadorMenu=0;
    do{
        system("cls");
        cout<<"1. Iniciar Juego"<<endl;
        cout<<"2. Leer archivo"<<endl;
        cout<<"3. Agregar usuario"<<endl;
        cout<<"4. Mostrar reportes"<<endl;
        cout<<"5. Salir"<<endl;
        cin>>contadorMenu;
        switch(contadorMenu)
        {
        case 1:
            //inicioJuego();
            break;
        case 2:
            //leerJson();
            break;
        case 3:
            //agregarUsuario();
            break;
        case 4:
            //mostrarReportes();
            break;
        }
    }while(contadorMenu!=5);
}
