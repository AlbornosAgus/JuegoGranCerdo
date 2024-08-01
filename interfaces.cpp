#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;
#include "funciones.h"

void interfaceJuego(int acuTrufasJ1,int acuTrufasJ2,int dadosJ1[2], int dadosJ2[2], string Nombrej1, string Nombrej2,string nombre,int rondas,int lanz, int lanzTotal, int trufasDeLaRonda)
{
system ("cls");
    cout<<"GRAN CERDO"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<Nombrej1<<": "<<acuTrufasJ1<<" Trufas acumuladas"<<"         "<<Nombrej2<<": "<<acuTrufasJ2<<" Trufas acumuladas"<<endl;
    cout<<endl;
    cout << endl;
    cout<<"TURNO DE "<<nombre<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"+--------------------------+"<<endl;
    cout<<"| RONDAS #"<<rondas<<"                |"<<endl;
    cout<<"| TRUFAS DE LA RONDA: "<<trufasDeLaRonda<<"    |"<<endl;
    cout<<"| LANZAMIENTOS: "<<lanzTotal<<"          |"<<endl;
    cout<<"+--------------------------+"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"LANZAMIENTO # "<<lanz<<endl;
    cout<<endl;

}

void interfaceResultado ( string nombreJ1, string nombreJ2, int acuTrufasJ1, int acuTrufasJ2,int lanzMaxJ1,int  LanzMaxJ2, int pdvLanzamientoJ1,int pdvLanzamientoJ2, int oinkJ1, int oinkJ2,int pdvOinksJ1, int pdvOinksJ2,int  pdvTrufasTotalesJ1,int  pdvTrufasTotalesJ2, int pdvCada50TrufasJ1,  int pdvCada50TrufasJ2,string *g,int *p)
{

    int puntajeFinalJ1 = pdvTrufasTotalesJ1 + pdvCada50TrufasJ1 + pdvOinksJ1 + pdvLanzamientoJ1;
    int puntajeFinalJ2 = pdvTrufasTotalesJ2 + pdvCada50TrufasJ2 + pdvOinksJ2 + pdvLanzamientoJ2;
    int cada50TrufasJ1 = pdvCada50TrufasJ1*50;
    int cada50TrufasJ2 = pdvCada50TrufasJ2*50;
    string ganador;
    string continuar;
    int puntajeFinalGanador, eleccion;

    cout << "GRAN CERDO " << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "HITO" << "                       " << nombreJ1 << "                 " << nombreJ2 << "          " << endl;
    cout << "Mas trufas en total" << "        " << pdvTrufasTotalesJ1 <<"PDV   ("<<acuTrufasJ1<<")"<<"         "<<pdvTrufasTotalesJ2<<"PDV  ("<<acuTrufasJ2<<")"<<endl;
    cout << "Cada 50 trufas" << "             " << pdvCada50TrufasJ1 <<"PDV   ("<<cada50TrufasJ1<<")"<<"        "<<pdvCada50TrufasJ2<<"PDV   ("<<cada50TrufasJ2<<")"<<endl;
    cout << "Oinks" << "                      " << pdvOinksJ1 <<"PDV   ("<<oinkJ1<<")"<< "          "<<pdvOinksJ2<<"PDV   ("<<oinkJ2<<")"<<endl;
    cout << "Cerdo codicioso" << "            " <<pdvLanzamientoJ1<<"PDV   ("<<lanzMaxJ1<<")"<<"          "<< pdvLanzamientoJ2<<"PDV   ("<<LanzMaxJ2<<")"<< endl;
    cout <<"------------------------------------------------------------------------------------"<<endl;
    cout <<" TOTAL: "<<"                         "<<puntajeFinalJ1<<"                     "<<puntajeFinalJ2<<endl;
    cout <<endl;
    if (puntajeFinalJ1>puntajeFinalJ2)
    {
        ganador = nombreJ1;
        puntajeFinalGanador = puntajeFinalJ1;
    }
    else
    {
        ganador = nombreJ2;
        puntajeFinalGanador = puntajeFinalJ2;
    }
    cout << "GANA: " <<ganador<< " con " << puntajeFinalGanador << " de PDV. " << endl;
    *g = ganador;
    *p = puntajeFinalGanador;

    cout << "Presione 1 para volver al menu " << endl;
    cin >> eleccion;
    if (eleccion == 1)
    {
        menuPrincipal(g,p);
    }


}

void graficoDados( int dado)
{

    if(dado == 1)
    {
        cout << "*-----*" << endl << "|     |" << endl << "|  x  |" << endl << "|     |" << endl << "*-----*" << endl;
    }
    if(dado == 2)
    {
        cout << "*-----*" << endl << "|x    |" << endl << "|     |" << endl << "|    x|" << endl << "*-----*" << endl;
    }
    if(dado == 3)
    {
        cout << "*-----*" << endl << "|x    |" << endl << "|  x  |" << endl << "|    x|" << endl << "*-----*" << endl;
    }
    if(dado == 4)
    {
        cout << "*-----*" << endl << "|x   x|" << endl << "|     |" << endl << "|x   x|" << endl << "*-----*" << endl;
    }
    if(dado == 5)
    {
        cout << "*-----*" << endl << "|x   x|" << endl << "|  x  |" << endl << "|x   x|" << endl << "*-----*" << endl;
    }
    if(dado == 6)
    {
            cout << "*-----*" << endl << "|x x x|" << endl << "|     |" << endl << "|x x x|" << endl << "*-----*" << endl;
    }

}
