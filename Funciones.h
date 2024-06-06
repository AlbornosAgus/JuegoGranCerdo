#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

// FUNCIONES DECLARADAS
void resultados (string nombreJ1, string nombreJ2, int acuTrufasJ1, int acuTrufasJ2, int lanzMaxJ1, int lanzMaxJ2, int oinkJ1, int oinkJ2,string *g,int *p);
void cargarTresDados(int* dadosJ1);
void acumuladorTrufas (int trufas, int acuTrufas, bool flag);
void opcionJugar(string *g,int *p);
void graficoDados (int dado);
void modoManual () ;
void cerditos();
void condicionDeDadosDobles (int* dados, int &acutrufas, bool &flag, bool &tercerDado, bool &barro, int &lanz, int &lanzTotal, int &lanzMaxJ1, int &oinkJ1, int &suma);
void comienzaJuego(int dados1[2], int dados2[2], string nombre1, string nombre2,string *g,int *p);
void DefineOrdenDeJugadores(int PuntajeRonda1, int dadosJ1[2], int dadosJ2[2], string Nombrej1, string Nombrej2, bool juegoEnModoAleatorio,string *g,int *p);
void TirarDado(int vecJ1[2],int vecJ2[2], string nombrej1, string nombrej2);
void tirarDadoRondas (int* Dado);
void condicionDeDadosTriples(int* dados, int &acuTrufasJ1, int &acuTrufasJ2, bool &puedeContinuar, bool &barro, int &lanz, int &lanzTotal, int &lanzMaxJ1, int &oinkJ1, int &suma);
void interfaceResultado ( string nombreJ1, string nombreJ2, int acuTrufasJ1, int acuTrufasJ2,int lanzMaxJ1,int  LanzMaxJ2, int pdvLanzamientoJ1,int pdvLanzamientoJ2, int oinkJ1, int oinkJ2,int pdvOinksJ1, int pdvOinksJ2, int pdvCada50TrufasJ1,  int pdvCada50TrufasJ2, int pdvTrufasTotalesJ1, int pdvTrufasTotalesJ2,string *g,int *p);
void dadosManual (int* dadosJ2,int* dadosJ1, string j1, string j2);
int menuPrincipal(string *g, int* p);
void estadistica (string *ganador, int *puntajeFinalGanador);
string ingresarNombre(int n);
int PuntajeInicial(int VecPunto[2]);
int PuntajeMax(int acu1, int acu2, string a, string b);
int MaxNumero ( int vecmax1[2],int vecmax2[2], string a, string b);
void interfaceJuego(int acuTrufasJ1,int acuTrufasJ2,int dadosJ1[2], int dadosJ2[2], string Nombrej1, string Nombrej2,string nombre,int rondas,int lanz,int lanzTotal, int acu, int suma);

int menuPrincipal(string *g, int* p)
{
    srand(time(NULL));

    int opcion , puntos, respuesta;
   /** string ganador="LEO";
    string *ptroG = &ganador;
    int puntajeFinalGanador=0;
    int* ptroP = &puntajeFinalGanador;**/

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
        case 1: opcionJugar(g,p); // MODO ALEATORIO
            break;
        case 2: //modoManual(&ganador,&puntajeFinalGanador); // MODO MANUAL
            break;
        case 3: estadistica (g,p);// ESTADISTICAS
            break;
        case 4: cerditos();//CREDITOS
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
void cerditos()
{
    int eleccion;
    cout <<"------GRUPO 28------ " << endl;
    cout <<"Billordo Miranda Karen Belen NL : 27981"<<endl;
    cout << "Albornos Agustin Mariano NL : 26809"<<endl;
    cout << "Matias Ezequiel Frischeisein NL : 29776"<<endl;
    cout<<endl;
    cout << "Presione 1 para volver al menu "<<endl;
    cin>>eleccion;
    /** if(eleccion == 1)
     {
        menuPrincipal(g,p);
     }**/

}
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
void opcionJugar(string *g,int *p) // guarda nombre de jugadores y define quien comienza a jugar
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
      TirarDado(dadosJ1,dadosJ2,Nombrej1,Nombrej2);// FUNCION QUE TIRA DADOS PARA COMENZAR Y DENTRO LLAMA A FUNCION DE GRAFICO DE DADOS
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
    DefineOrdenDeJugadores(PuntajeRonda1, dadosJ1, dadosJ2, Nombrej1, Nombrej2, juegoEnModoAleatorio,g,p); // llama e inicia el juego

    system("pause");
    system ("cls") ;

}

void DefineOrdenDeJugadores(int PuntajeRonda1, int dadosJ1[2], int dadosJ2[2], string Nombrej1, string Nombrej2, bool juegoEnModoAleatorio,string *g,int *p)
{

    if (juegoEnModoAleatorio)
    {
        if (PuntajeRonda1 == 1)
        {
            comienzaJuego (dadosJ1, dadosJ2, Nombrej1, Nombrej2,g,p);
        }
        else
        {
            comienzaJuego (dadosJ2, dadosJ1, Nombrej2, Nombrej1,g,p);
        }
    }
    else
    {
        if (PuntajeRonda1 == 1)
        {
            dadosManual (dadosJ1, dadosJ2, Nombrej1, Nombrej2);
        }
        else
        {
        dadosManual (dadosJ2, dadosJ1, Nombrej2, Nombrej1);
        }
    }

}


void comienzaJuego(int dadosJ1[2], int dadosJ2[2], string Nombrej1, string Nombrej2,string *g,int *p)
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
        int lanz= 1;
        int lanzTotal = 0;
        int trufasDeLaRonda =0;




            do
            {
                nombre = Nombrej1;

                interfaceJuego(acuTrufasJ1,acuTrufasJ2,dadosJ1,dadosJ2,Nombrej1,Nombrej2,nombre,ronda,lanz, lanzTotal,trufasDeLaRonda);
                // Si ambos jugadores no superan las 50 trufas o ninguno ha caído en el barro
                if ((supera50TrufasJ1 && supera50TrufasJ2) || barro)
                {
                    cargarTresDados(tercerDadoJ1);
                    condicionDeDadosTriples(tercerDadoJ1, acuTrufasJ1, acuTrufasJ2, puedeContinuar, barro,lanz, lanzTotal, lanzMaxJ1, oinkJ1,trufasDeLaRonda);
                }
                else
                {

                    tirarDadoRondas(dadosJ1);
                    condicionDeDadosDobles(dadosJ1, acuTrufasJ1, puedeContinuar, supera50TrufasJ1, barro, lanz, lanzTotal, lanzMaxJ1, oinkJ1, trufasDeLaRonda);

                }

            }while (puedeContinuar);
            system("cls");


    // se inicializa int de lanzamientos para el jugador 2

        lanz= 1;
        lanzTotal = 0;
        trufasDeLaRonda=0;

            do
            {
                acu=acuTrufasJ2;
                nombre = Nombrej2;
                interfaceJuego(acuTrufasJ1,acuTrufasJ2,dadosJ1,dadosJ2,Nombrej1,Nombrej2,nombre,ronda,lanz, lanzTotal,trufasDeLaRonda);
                puedeContinuar = true;

                // Si ambos jugadores no superan las 50 trufas o ninguno ha caído en el barro
                if((supera50TrufasJ1 && supera50TrufasJ2) || barro)
                {
                    // Tirar tres dados para el jugador 1
                    cargarTresDados(tercerDadoJ2);
                    // Procesar los resultados de los tres dados
                    condicionDeDadosTriples(tercerDadoJ2, acuTrufasJ2, acuTrufasJ1, puedeContinuar, barro, lanz, lanzTotal, lanzMaxJ2, oinkJ2, trufasDeLaRonda);
                    system("cls");

                }

                else
                {

                    tirarDadoRondas(dadosJ2);
                    condicionDeDadosDobles(dadosJ2, acuTrufasJ2, puedeContinuar, supera50TrufasJ2, barro, lanz, lanzTotal, lanzMaxJ2, oinkJ2, trufasDeLaRonda);
                    system("cls");
                }
            }while (puedeContinuar);
        }

        system ("pause") ;
        system ("cls");
        resultados (Nombrej1, Nombrej2, acuTrufasJ1 , acuTrufasJ2, lanzMaxJ1, lanzMaxJ2, oinkJ1, oinkJ2,g,p );

}


void tirarDadoRondas(int dadosJ1[2])
{
    for (int i = 0; i < 2; i++)
    {
        dadosJ1[i] = (rand() % 6 + 1);
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

        if (acuTrufasJ1 > 50)
        {
            supera50TrufasJ1 = true;
        }

        cout << "FELICIDADES! Acumulaste el doble de TRUFAS!" << endl;
        cout << "Debes volver a lanzar los dados" << endl;

        system("pause");


    }//si ambos dados son diferentes entre si y no son 1
    else if((dadosJ1[0] != dadosJ1[1] )&&(dadosJ1[0] != 1) && (dadosJ1[1] != 1))
    {
        suma = dadosJ1[0] + dadosJ1[1];
        trufasDeLaRonda += suma;


        if (acuTrufasJ1 > 50)
        {
            supera50TrufasJ1 = true;
        }

        cout << "ACUMULASTE " << suma << " TRUFAS! " << endl << "TOTAL DE TRUFAS ACUMULADAS " << trufasDeLaRonda << endl;
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
    }else if(dadosJ1[0] == 1 || dadosJ1[1] == 1)
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

void condicionDeDadosTriples(int* tercerDadoJ1, int &acuTrufas, int &acuTrufasJ2,  bool &puedeContinuar, bool &barro, int &lanz, int &lanzTotal, int &lanzMaxJ1, int &oinkJ1, int &trufasDeLaRonda)
{
    int opcion, suma;


    if (lanz > lanzMaxJ1)
    {
        lanzMaxJ1 = lanz;
    }

    if((tercerDadoJ1[0] != 1 && tercerDadoJ1[1] != 1) && tercerDadoJ1[2] != 1)// si los dados NO son 1
    {
        // si todas las caras son iguales
        if((tercerDadoJ1 [0] == tercerDadoJ1 [1] ) && (tercerDadoJ1 [0] == tercerDadoJ1 [2]))
        {
            suma=(tercerDadoJ1 [0] + tercerDadoJ1 [1] + tercerDadoJ1 [2]) * 2 ;
            acuTrufas += suma;
            lanz ++;
            lanzTotal++;
            oinkJ1 ++;
            trufasDeLaRonda += suma;

            cout << "-------- OINK!!! --------" << endl;
            cout << "FELICIDADES! Acumulaste el doble de TRUFAS!" << endl;
            cout << "Trufas acumuladas " << acuTrufas << " !!! " << endl;
            cout << "Debes volver a lanzar los dados" << endl;
            system("pause");
        }
        else if((tercerDadoJ1 [0] == tercerDadoJ1 [1] )|| (tercerDadoJ1 [0] == tercerDadoJ1 [2]) )// si dos de los dados son iguales
        {
            acuTrufas += 0;
            cout << "Dos de los dados son iguales, no acumulas trufas." << endl;
            cout << " Puedes decidir si continuar jugando: "<< endl;
            cout << " 1 - continuar jugando     2 - ceder el turno ";
            cin >> opcion;

            if (opcion == 1)
            {
                lanz ++;
                lanzTotal++;
            }
            else
            {
                puedeContinuar = false;
            }

            if(tercerDadoJ1 [1] == tercerDadoJ1 [2])
            {

                acuTrufas += 0;
                cout << "Dos de los dados son iguales, no acumulas trufas." << endl << " Puedes decidir si continuar jugando: "<< endl;
                cout << " 1 - continuar jugando     2 - ceder el turno ";
                cin >> opcion;

                if ( opcion == 1)
                {
                    lanz ++;
                    lanzTotal++;
                }
                else
                {
                    puedeContinuar = false;
                }
            }

        }
    }
    else if(tercerDadoJ1[0] == 1 && tercerDadoJ1[1] == 1 && tercerDadoJ1[2] == 1)// si los tres dados son uno
    {
        acuTrufasJ2 += acuTrufas;
        acuTrufas = 0;

        cout << "---------------- CAISTE AL BARRO ----------------"<< endl;
        cout << "Pierdes todas las trufas y se acumulan al otro cerdo !! " << endl;
        puedeContinuar = false;
        barro = true;
        system("pause");


    }else if(tercerDadoJ1[0] == 1 || tercerDadoJ1[1] == 1 || tercerDadoJ1[2] == 1)// uno de los dados es un uno
    {
        acuTrufas += 0;
        cout << "Hay un uno entre los dados, no acumulas trufas y el turno es del siguiente cerdo";
        puedeContinuar = false;
    }
    else
    {
    // si todas las caras son diferentes

        suma = tercerDadoJ1[0] + tercerDadoJ1[1] + tercerDadoJ1[2];
        trufasDeLaRonda += suma;


        cout << "ACUMULASTE " << suma << " TRUFAS! " << endl << "TOTAL DE TRUFAS ACUMULADAS " << acuTrufas << endl;
        cout << " Puedes decidir si seguir jugando o ceder tu turno. ";
        cout << " 1 - Seguir jugando    2 - Ceder el turno ";
        cin >> opcion;

        if ( opcion == 1)
        {
            lanz ++;
            lanzTotal++;
        }
        else
        {
            acuTrufas=trufasDeLaRonda;
            puedeContinuar=false;
        }
        }
    }




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

void interfaceResultado ( string nombreJ1, string nombreJ2, int acuTrufasJ1, int acuTrufasJ2,int lanzMaxJ1,int  LanzMaxJ2, int pdvLanzamientoJ1,int pdvLanzamientoJ2, int oinkJ1, int oinkJ2,int pdvOinksJ1, int pdvOinksJ2,int  pdvTrufasTotalesJ1,int  pdvTrufasTotalesJ2, int pdvCada50TrufasJ1,  int pdvCada50TrufasJ2,string *g,int *p)
{

    int puntajeFinalJ1 = pdvTrufasTotalesJ1 + pdvCada50TrufasJ1 + pdvOinksJ1 + pdvLanzamientoJ1;
    int puntajeFinalJ2 = pdvTrufasTotalesJ2 + pdvCada50TrufasJ2 + pdvOinksJ2 + pdvLanzamientoJ2;
    int cada50TrufasJ1 = pdvCada50TrufasJ1*50;
    int cada50TrufasJ2 = pdvCada50TrufasJ2*50;
    string ganador;
    string continuar;
    int puntajeFinalGanador;

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
    int eleccion;
    cout << "Presione 1 para volver al menu " << endl;
    cin >> eleccion;
    if (eleccion == 1)
    {
        menuPrincipal(g,p);
    }else if(eleccion ==2)
    {
        estadistica(g, p);
    }
    //estadistica(&ganador, &puntajeFinalGanador);
    cout << "INGRESE OINK PARA CONTINUAR" ;
    cin >> continuar;


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


string ingresarNombre(int n)
{ // FUNCION QUE PIDE NOMBRE DE JUGADORES
    string nombre;
    cout << "Ingresar nombre del jugador numero " << n << endl;
    cin >> nombre;
    return nombre;
}

void TirarDado(int vecJ1[2],int vecJ2[2], string j1, string j2)
{ // FUNCION TIRADA DE DADOS PARA GUARDAR EN VECTOR

    srand(time(NULL));

   for ( int i = 0; i < 2; i++) {

        vecJ1[i] = (rand()%6+1);
        vecJ2[i] = (rand()%6+1);}

   cout << "TURNO DE: " << j1 << endl;
   graficoDados(vecJ1[0]), graficoDados(vecJ1[1]);
   system ("pause");
   cout << "TURNO DE: " << j2 << endl;
   graficoDados(vecJ2[0]),graficoDados(vecJ2[1]);
   system ("pause");
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
    }
    else if(mayor2 > mayor1)
    {
        cout << Nombrej2 << " comienza jugando ";
        max = 2;
    }else
    {
        cout << " No hay dado mayor, nuevamente se tiran los dados. ";
        max = 0;
    }
    system ("pause");
    return max;
}

void modoManual (string* g,int* p)
{

     string Nombrej1, Nombrej2;
    int acuPuntosj1 = 0 , acuPuntosj2 = 0;
    int PuntajeRonda1;
    int dadosJ1[2]={} ,dadosJ2[2]={};
    int DadoMasAlto;
    bool juegoEnModoAleatorio = false;

    // LLAMADA A LAS FUNCIONES

    Nombrej1= ingresarNombre(1);
    Nombrej2= ingresarNombre(2);
    system("cls");

    do //DO WHILE DONDE SE VUELVE A INICIALIZAR TODAS LAS FUNCIONES SI DA UN DOBLE EMPATE
    {
      cout << "Comienza quien obtenga el mayor puntaje de dados " << endl;
      system ("pause");
      dadosManual (dadosJ1, dadosJ2, Nombrej1,Nombrej2) ;
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
    DefineOrdenDeJugadores(PuntajeRonda1, dadosJ1, dadosJ2, Nombrej1, Nombrej2, juegoEnModoAleatorio,g,p ); // llama e inicia el juego

    system("pause");

}

void dadosManual (int* dadosJ1,int* dadosJ2, string j1, string j2)
{

    for (int i = 0 ; i < 2 ; i ++)
    {
        cout << "Ingrese el elemento del dado numero " << i + 1 << " de " <<  j1 << " entre en 1 y el 6 " << endl;
        cin >> dadosJ1 [i];
    }
    for (int i = 0 ; i < 2 ; i ++ )
    {
        cout << "Ingrese el elemento del dado " << i + 1 << " de  " <<  j2 << " entre el 1 y el 6 " << endl;
        cin >> dadosJ2 [i];
    }
    system ("cls");
    system ("pause");

}


#endif // FUNCIONES_H_INCLUDED
