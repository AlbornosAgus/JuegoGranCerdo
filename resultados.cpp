#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;
#include "funciones.h"




void resultados (string nombreJ1, string nombreJ2, int acuTrufasJ1, int acuTrufasJ2, int lanzMaxJ1, int LanzMaxJ2, int oinkJ1, int oinkJ2,string *g,int *p)
{
    int pdvLanzamientoJ1 = 0, pdvLanzamientoJ2=0 ;
    int pdvCada50TrufasJ1 = acuTrufasJ1 / 50;
    int pdvCada50TrufasJ2 = acuTrufasJ2 / 50;

    int pdvOinksJ1 = oinkJ1 *2;
    int pdvOinksJ2 = oinkJ2 *2;
    int pdvTrufasTotalesJ1=0 , pdvTrufasTotalesJ2=0 ;

    if (lanzMaxJ1 > LanzMaxJ2)
    {
        pdvLanzamientoJ1 += 3;
    }
    else
    {
        pdvLanzamientoJ2 += 3;
    }

    //quien obtenga mas trufas
    if (acuTrufasJ1 > acuTrufasJ2)
    {
        pdvTrufasTotalesJ1 += 5;
    }
    else
    {
    pdvTrufasTotalesJ2 += 5;
    }


    interfaceResultado ( nombreJ1, nombreJ2, acuTrufasJ1,  acuTrufasJ2, lanzMaxJ1,  LanzMaxJ2, pdvLanzamientoJ1, pdvLanzamientoJ2,  oinkJ1,  oinkJ2, pdvOinksJ1, pdvOinksJ2, pdvTrufasTotalesJ1,  pdvTrufasTotalesJ2,  pdvCada50TrufasJ1,  pdvCada50TrufasJ2,g,p);

}



int PuntajeInicial(int VecPunto[2])// Guarda la suma de ambos dados por jugador
{
    int acu = 0;
    for (int x = 0; x < 2 ; x++)
    {
        acu += VecPunto[x];
    }
    return acu;
}



int PuntajeMax(int acu1, int acu2, string Nombrej1 , string Nombrej2)// Compara la suma de ambos jugadores para empezar a jugar
{
    int MaximoNumero;

    if (acu1 > acu2)
    {
        cout << "TURNO DE " << Nombrej1 << endl;
        MaximoNumero = 1;
        return MaximoNumero;
    }
    else if(acu2 > acu1)
    {
        cout << " TURNO DE " << Nombrej2 << endl;
        MaximoNumero = 2;
        return MaximoNumero;
    }
    else
    {
        cout << " EMPATE!!! , comenzara el que tenga numero de dado mas alto " << endl;
        MaximoNumero = 0;
        return MaximoNumero;
    }

}



int MaxNumero(int vecmax1[2], int vecmax2[2], string Nombrej1, string Nombrej2)
{

    int mayor1, mayor2, max;


    if (vecmax1[0] >= vecmax1[1])
    {
        mayor1 = vecmax1[0];
    }
    else
    {
        mayor1 = vecmax1[1];
    }

    if(vecmax2[0] >= vecmax2[1])
    {
        mayor2 = vecmax2[0];
    }
    else
    {
        mayor2 = vecmax2[1];
    }

    if(mayor1 > mayor2)
    {
        cout << Nombrej1 << " comienza jugando ";
        max = 1;
        system ("pasue");

    }
    else if(mayor2 > mayor1)
    {
        cout << Nombrej2 << " comienza jugando ";
        max = 2;
        system ("pasue");
    }else
    {
        cout << " No hay dado mayor, nuevamente se tiran los dados. ";
        max = 0;
    }
    system ("pause");
    return max;
}

