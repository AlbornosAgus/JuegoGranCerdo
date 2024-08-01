#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;
#include "funciones.h"


void opcionJugar(string *g,int *p, bool modalidad) // guarda nombre de jugadores y define quien comienza a jugar
{

    string Nombrej1, Nombrej2;
    int acuPuntosj1 = 0 , acuPuntosj2 = 0;
    int PuntajeRonda1;
    int dadosJ1[2]={} ,dadosJ2[2]={};
    int DadoMasAlto;
    bool juegoEnModoAleatorio=true;

    // LLAMADA A LAS FUNCIONES

    Nombrej1= ingresarNombre(1);
    Nombrej2= ingresarNombre(2);
    system("cls");

    do //DO WHILE DONDE SE VUELVE A INICIALIZAR TODAS LAS FUNCIONES SI DA UN DOBLE EMPATE
    {
        cout << "Comienza quien obtenga el mayor puntaje de dados " << endl;
        system ("pause");
        if(modalidad == true)
        {
            TirarDado(dadosJ1,dadosJ2,Nombrej1,Nombrej2);// FUNCION QUE TIRA DADOS PARA COMENZAR Y DENTRO LLAMA A FUNCION DE GRAFICO DE DADOS

        }
        else
        {
            TirarDadoManual(dadosJ1,dadosJ2,Nombrej1,Nombrej2);
        }
        acuPuntosj1= PuntajeInicial(dadosJ1);
        acuPuntosj2= PuntajeInicial(dadosJ2);
        PuntajeRonda1 = PuntajeMax(acuPuntosj1,acuPuntosj2,Nombrej1, Nombrej2); // TOMA LA SUMA DE DADOS

        if(PuntajeRonda1 == 0)// SI EMPATE
        {
            DadoMasAlto = MaxNumero (dadosJ1 , dadosJ2 , Nombrej1, Nombrej2); // TOMA VALOR DE DADO MAS ALTO Y DEFINE
        }
        else
        {
            DadoMasAlto = 1 ;
        }

    }while(DadoMasAlto == 0 ) ; // SI EMPATE NUEVAMENTE
    DefineOrdenDeJugadores(PuntajeRonda1, dadosJ1, dadosJ2, Nombrej1, Nombrej2, juegoEnModoAleatorio,g,p,modalidad); // llama e inicia el juego

    system("pause");
    system ("cls") ;

}

void DefineOrdenDeJugadores(int PuntajeRonda1, int dadosJ1[2], int dadosJ2[2], string Nombrej1, string Nombrej2, bool juegoEnModoAleatorio,string *g,int *p,bool modalidad)
{

   // if (juegoEnModoAleatorio)
    //{
        if (PuntajeRonda1 == 1)
        {
            comienzaJuego(dadosJ1, dadosJ2, Nombrej1, Nombrej2,g,p,modalidad);
        }
        else
        {
            comienzaJuego(dadosJ2, dadosJ1, Nombrej2, Nombrej1,g,p,modalidad);
        }
    //}

}


void comienzaJuego(int dadosJ1[2], int dadosJ2[2], string Nombrej1, string Nombrej2,string *g,int *p,bool modalidad)
{
    string nombre;
    int acu;
    int opcion, acuTrufasJ1 = 0, acuTrufasJ2 = 0;
    int lanzMaxJ1 = 0, lanzMaxJ2 = 0;
    int tercerDadoJ1[3] = {}, tercerDadoJ2[3] = {};
    bool puedeContinuar = true;
    bool supera50TrufasJ1 = false;
    bool supera50TrufasJ2 = false;
    bool barro = false;
    int oinkJ1 = 0, oinkJ2 = 0;
    system ("cls");

        for (int ronda = 1; ronda <= 5; ronda++)//FOR DE 5 RONDAS
        {
            // se inicializa int de lanzamientos para el jugador 1
            int lanz = 1;
            int lanzTotal = 0;
            int trufasDeLaRonda = 0;

                do
                {
                    nombre = Nombrej1;

                    interfaceJuego(acuTrufasJ1,acuTrufasJ2,dadosJ1,dadosJ2,Nombrej1,Nombrej2,nombre,ronda,lanz, lanzTotal,trufasDeLaRonda);
                    puedeContinuar = true;

                    if ((supera50TrufasJ1 && supera50TrufasJ2) || barro)
                    {
                        if(modalidad == true)
                        {
                            cargarTresDados(tercerDadoJ1);
                            condicionDeDadosTriples(tercerDadoJ1, acuTrufasJ1, acuTrufasJ2, puedeContinuar, barro,lanz, lanzTotal, lanzMaxJ1, oinkJ1,trufasDeLaRonda);
                        }
                        else
                        {
                            cargarTresDadosManual(tercerDadoJ1);
                            condicionDeDadosTriples(tercerDadoJ1, acuTrufasJ1, acuTrufasJ2, puedeContinuar, barro,lanz, lanzTotal, lanzMaxJ1, oinkJ1,trufasDeLaRonda);
                        }
                    }
                    else
                    {
                        if(modalidad == true)
                        {
                            tirarDadoRondas(dadosJ1);
                            condicionDeDadosDobles(dadosJ1, acuTrufasJ1, puedeContinuar, supera50TrufasJ1, barro, lanz, lanzTotal, lanzMaxJ1, oinkJ1, trufasDeLaRonda);

                        }
                        else
                        {
                            tirarDadoRondasManual(dadosJ1);
                            condicionDeDadosDobles(dadosJ1, acuTrufasJ1, puedeContinuar, supera50TrufasJ1, barro, lanz, lanzTotal, lanzMaxJ1, oinkJ1, trufasDeLaRonda);
                        }
                        if (acuTrufasJ1 > 50)
                        {
                            supera50TrufasJ1 = true;

                        }

                    }

                }while (puedeContinuar);
                system("cls");


            //se inicializa int de lanzamientos para el jugador 2

            lanz= 1;
            lanzTotal = 0;
            trufasDeLaRonda=0;

                do
                {
                    acu=acuTrufasJ2;
                    nombre = Nombrej2;
                    interfaceJuego(acuTrufasJ1,acuTrufasJ2,dadosJ1,dadosJ2,Nombrej1,Nombrej2,nombre,ronda,lanz, lanzTotal,trufasDeLaRonda);
                    puedeContinuar = true;


                    if((supera50TrufasJ1 && supera50TrufasJ2) || barro)
                    {
                        // Tirar tres dados para el jugador 1
                        // Procesar los resultados de los tres dados
                        if(modalidad == true)
                        {
                            cargarTresDados(tercerDadoJ2);
                            condicionDeDadosTriples(tercerDadoJ2, acuTrufasJ2, acuTrufasJ1, puedeContinuar, barro, lanz, lanzTotal, lanzMaxJ2, oinkJ2, trufasDeLaRonda);

                        }
                        else
                        {
                            cargarTresDadosManual(tercerDadoJ2);
                            condicionDeDadosTriples(tercerDadoJ2, acuTrufasJ2, acuTrufasJ1, puedeContinuar, barro, lanz, lanzTotal, lanzMaxJ2, oinkJ2, trufasDeLaRonda);

                        }
                        system("cls");

                    }

                    else
                    {
                        if(modalidad == true)
                        {
                            tirarDadoRondas(dadosJ2);
                            condicionDeDadosDobles(dadosJ2, acuTrufasJ2, puedeContinuar, supera50TrufasJ2, barro, lanz, lanzTotal, lanzMaxJ2, oinkJ2, trufasDeLaRonda);

                        }
                        else
                        {
                            tirarDadoRondasManual(dadosJ2);
                            condicionDeDadosDobles(dadosJ2, acuTrufasJ2, puedeContinuar, supera50TrufasJ2, barro, lanz, lanzTotal, lanzMaxJ2, oinkJ2, trufasDeLaRonda);
                        }
                        if (acuTrufasJ2 > 50)
                        {
                            supera50TrufasJ2 = true;

                        }
                        system("cls");
                    }
                }while(puedeContinuar);
        }

        system ("pause") ;
        system ("cls");
        resultados (Nombrej1, Nombrej2, acuTrufasJ1 , acuTrufasJ2, lanzMaxJ1, lanzMaxJ2, oinkJ1, oinkJ2,g,p );

}
// FUNCION QUE PIDE NOMBRE DE JUGADORES
string ingresarNombre(int n)
{
    string nombre;
    cout << "Ingresar nombre del jugador numero " << n << endl;
    cin >> nombre;
    return nombre;
}
