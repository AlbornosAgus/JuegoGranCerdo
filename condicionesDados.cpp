
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;
#include "funciones.h"


void tirarDadoRondas(int dadosJ1[2])
{
    for (int i = 0; i < 2; i++)
    {
        dadosJ1[i] = (rand() % 6 + 1);
    }

    graficoDados(dadosJ1[0]), graficoDados(dadosJ1[1]);
}
void tirarDadoRondasManual(int dadosJ1[2])
{
    for (int i = 0 ; i < 2 ; i ++)
    {
        cout << "Ingrese el elemento del dado numero " << i + 1 << endl;
        cin >> dadosJ1 [i];
    }
    graficoDados(dadosJ1[0]), graficoDados(dadosJ1[1]);

}

void cargarTresDados(int dadosJ1[3])
{
    for(int i = 0; i < 3; i++)
    {
        dadosJ1[i] = (rand() % 6 + 1);
    }

    graficoDados(dadosJ1[0]), graficoDados(dadosJ1[1]) , graficoDados (dadosJ1 [2]);
}
void cargarTresDadosManual(int dadosJ1[3])
{
     for (int i = 0 ; i < 3 ; i ++)
    {
        cout << "Ingrese el elemento del dado numero " << i + 1 << endl;
        cin >> dadosJ1 [i];
    }


    graficoDados(dadosJ1[0]), graficoDados(dadosJ1[1]) , graficoDados (dadosJ1 [2]);
}

// FUNCION TIRADA DE DADOS PARA GUARDAR EN VECTOR
void TirarDado(int vecJ1[2],int vecJ2[2], string j1, string j2)
{

    for ( int i = 0; i < 2; i++)
    {
        vecJ1[i] = (rand()%6+1);
        vecJ2[i] = (rand()%6+1);
    }

    cout << "TURNO DE: " << j1 << endl;
    graficoDados(vecJ1[0]), graficoDados(vecJ1[1]);
    system ("pause");
    cout << "TURNO DE: " << j2 << endl;
    graficoDados(vecJ2[0]),graficoDados(vecJ2[1]);
    system ("pause");
    system ("cls");
    system ("pause");


}
void TirarDadoManual(int vecJ1[2],int vecJ2[2], string j1, string j2)
{
    for (int i = 0 ; i < 2 ; i ++)
    {
        cout << "Ingrese el elemento del dado numero " << i + 1 << " de " <<  j1 << " entre en 1 y el 6 " << endl;
        cin >> vecJ1 [i];
    }
    for (int i = 0 ; i < 2 ; i ++ )
    {
        cout << "Ingrese el elemento del dado " << i + 1 << " de  " <<  j2 << " entre el 1 y el 6 " << endl;
        cin >> vecJ2 [i];
    }
}

void condicionDeDadosDobles(int* dadosJ1, int &acuTrufasJ1, bool &puedeContinuar, bool &supera50TrufasJ1, bool &barro , int &lanz, int &lanzTotal, int &lanzMaxJ1, int &oinkJ1, int &trufasDeLaRonda)
{
    int opcion;
    int suma;
    if (lanz > lanzMaxJ1)
    {
        lanzMaxJ1 = lanz;
    }

    // si los dados son iguales y NO son 1
    if((dadosJ1[0] == dadosJ1[1]) && dadosJ1[0] != 1)
    {
        suma = (dadosJ1[0] + dadosJ1[1]) * 2;
        trufasDeLaRonda += suma;
        lanz++;
        lanzTotal++;
        oinkJ1 ++;

       /* if (acuTrufasJ1 > 50)
        {
            supera50TrufasJ1 = true;
        }*/

        cout << "FELICIDADES! Acumulaste el doble de TRUFAS!" << endl;
        cout << "Debes volver a lanzar los dados" << endl;

        system("pause");


    }//si ambos dados son diferentes entre si y no son 1
    else if((dadosJ1[0] != dadosJ1[1] )&&(dadosJ1[0] != 1) && (dadosJ1[1] != 1))
    {
        suma = dadosJ1[0] + dadosJ1[1];
        trufasDeLaRonda += suma;




        cout << "ACUMULASTE " << suma << " TRUFAS! " << endl;
        cout << " Puedes decidir si seguir jugando o ceder tu turno. ";
        cout << " 1 - Seguir jugando    2 - Ceder el turno ";
        cin >> opcion;

        if (opcion == 1)
        {
            lanz ++;
            lanzTotal++;
        }
        else if (opcion == 2)
        {
            acuTrufasJ1 += trufasDeLaRonda;
            puedeContinuar = false;
        }

        // uno de los dados es 1
    }
    else if(dadosJ1[0] == 1 || dadosJ1[1] == 1)
    {
        if(dadosJ1[0] == 1 && dadosJ1[1] == 1) //Si sale un doble 1
        {
            acuTrufasJ1 = 0;
            cout << "CAISTE AL BARRO" << endl;
            cout << "SE COMIENZA A JUGAR CON TRES DADOS! " << endl;
            cout << "Pierdes todas las trufas! Continúa el siguiente jugador" << endl;
            puedeContinuar = false;
            barro = true;
            system("pause");
        }
        else
        {
            trufasDeLaRonda = 0;
            cout << "Uno de tus dados es un 1, no sumas trufas, pierdes el turno y sigue el siguiente jugador" << endl;
            puedeContinuar = false;
            system("pause");

        }

    }

}


void condicionDeDadosTriples(int* tercerDadoJ1, int &acuTrufas, int &acuTrufasJ2, bool &puedeContinuar, bool &barro, int &lanz, int &lanzTotal, int &lanzMaxJ1, int &oinkJ1, int &trufasDeLaRonda)
{
    int opcion, suma;
    bool ningunoEsUno = tercerDadoJ1[0] != 1 && tercerDadoJ1[1] != 1 && tercerDadoJ1[2] != 1;
    bool dosLadosIguales = tercerDadoJ1[0] == tercerDadoJ1[1] || tercerDadoJ1[0] == tercerDadoJ1[2] || tercerDadoJ1[1] == tercerDadoJ1[2];
    bool tresLadosSonUno = tercerDadoJ1[0] == 1 && tercerDadoJ1[1] == 1 && tercerDadoJ1[2] == 1;
    bool unLadoEsUno = tercerDadoJ1[0] == 1 || tercerDadoJ1[1] == 1 || tercerDadoJ1[2] == 1;

    if (lanz > lanzMaxJ1) {
        lanzMaxJ1 = lanz;
    }

    if (ningunoEsUno) {
        if (dosLadosIguales) {
            cout << "Dos de los dados son iguales, no acumulas trufas." << endl;
            cout << "Puedes decidir si continuar jugando: " << endl;
            cout << "1 - continuar jugando     2 - ceder el turno ";
            cin >> opcion;

            if (opcion == 1) {
                trufasDeLaRonda = 0;
                lanz++;
                lanzTotal++;
                puedeContinuar = true;
            } else {
                puedeContinuar = false;
            }
        } else {
            suma = tercerDadoJ1[0] + tercerDadoJ1[1] + tercerDadoJ1[2];
            trufasDeLaRonda += suma;


            cout << "ACUMULASTE " << suma << " TRUFAS! " << endl;
            cout << "Puedes decidir si seguir jugando o ceder tu turno." << endl;
            cout << "1 - Seguir jugando    2 - Ceder el turno" << endl;
            cin >> opcion;

            if (opcion == 1) {

                lanz++;
                lanzTotal++;
                puedeContinuar = true;
            } else {
                acuTrufas += trufasDeLaRonda; // Acumula las trufas de la ronda al total
                trufasDeLaRonda = 0; // Reinicia las trufas de la ronda
                puedeContinuar = false;
            }
        }

    } else if (tresLadosSonUno) {
        acuTrufasJ2 += acuTrufas;
        acuTrufasJ2 += trufasDeLaRonda;
        acuTrufas = 0;
        trufasDeLaRonda = 0; // Reinicia las trufas de la ronda

        cout << "---------------- CAISTE AL BARRO ----------------" << endl;
        cout << "Pierdes todas las trufas y se acumulan al otro cerdo!! " << endl;
        puedeContinuar = false;
        barro = true;
        system("pause");
    } else if (unLadoEsUno) {
        cout << "Hay un uno entre los dados, no acumulas trufas y el turno es del siguiente cerdo." << endl;
        puedeContinuar = false;
        trufasDeLaRonda = 0; // Reinicia las trufas de la ronda
        system("pause");
    }
}

