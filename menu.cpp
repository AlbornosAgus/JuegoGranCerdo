#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;
#include "funciones.h"


int menuPrincipal(string *g, int* p)
{
    srand(time(NULL));

    int opcion , puntos, respuesta;
    bool static inicioJuego = false;
    bool modalidad = false;

    system ("cls");
    // MENU
    cout<<"GRAN CERDO"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"1 - JUGAR ALEATORIO"<<endl;
    cout<<"2 - JUGAR MANUALMENTE"<<endl;
    cout<<"3 - ESTADISTICA"<<endl;
    cout<<"4 - CERDITOS"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"0 - SALIR"<<endl;
    cin >> opcion;
    system("cls");
    switch (opcion) {
        case 1: inicioJuego = true;
            modalidad = true;
            opcionJugar(g,p,modalidad); // MODO ALEATORIO
            break;
        case 2:
            inicioJuego = true;
            modalidad = false;
            opcionJugar(g,p,modalidad); // MODO MANUAL
            break;
        case 3: if (inicioJuego == true)
               {
                estadistica (g,p);// ESTADISTICAS
               }
               else
               {
                   cout << "Aun no hay estadisticas guardadas. " << endl;
               } system ("pause");
               menuPrincipal(g,p);

            break;
        case 4: cerditos(g,p);//CREDITOS
            break;
        case 0:
             cout << "Seguro que desea salir ?? " << " 1- Si    2- No" << endl;
             cin >> respuesta;
             if (respuesta == 1)
             {
                return 0;
             }
             else
             {
                return menuPrincipal(g,p);
             }
             break;
        default:
            system("cls");
            cout << " |-----------------------------------------| " << endl;
            cout << " | ERROR!!! OPCION INGRESADA NO ES VALIDA  | " << endl;
            cout << " |-----------------------------------------| " << endl;
            system("pause");
            return menuPrincipal(g,p);
            break;
    }


}
void cerditos(string *g , int *p)
{
    int eleccion;
    cout <<"------GRUPO 28------ " << endl;
    cout <<"Billordo Miranda Karen Belen NL : 27981"<<endl;
    cout << "Albornos Agustin Mariano NL : 26809"<<endl;
    cout << "Matias Ezequiel Frischeisein NL : 29776"<<endl;
    cout<<endl;
    cout << "Presione 1 para volver al menu "<<endl;
    cin>>eleccion;
    if(eleccion == 1)
     {
        menuPrincipal(g,p);
     }

}


void estadistica (string *ganador, int *puntajeFinalGanador ) {

int eleccion;
cout << "El ultimo ganador fue " << *ganador << " con " << *puntajeFinalGanador << " PDV" << endl;
cout << endl;
cout << "Presione 1 para volver al menu " << endl;
cin >> eleccion;
if (eleccion == 1)
{
     menuPrincipal(ganador,puntajeFinalGanador);
}


}

