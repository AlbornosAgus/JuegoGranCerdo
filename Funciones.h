#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

// FUNCIONES DECLARADAS
void comienzaJuegoManual(int dadosJ1[2], int dadosJ2[2], string Nombrej1, string Nombrej2,string *g,int *p);
void resultados (string nombreJ1, string nombreJ2, int acuTrufasJ1, int acuTrufasJ2, int lanzMaxJ1, int lanzMaxJ2, int oinkJ1, int oinkJ2,string *g,int *p);
void cargarTresDados(int* dadosJ1);
void acumuladorTrufas (int trufas, int acuTrufas, bool flag);
void opcionJugar(string *g,int *p,bool modalidad);
void graficoDados (int dado);
void modoManual (string *g, int *p) ;
void cerditos(string *g, int *p);
void condicionDeDadosDobles (int* dados, int &acutrufas, bool &flag, bool &tercerDado, bool &barro, int &lanz, int &lanzTotal, int &lanzMaxJ1, int &oinkJ1, int &suma);
void comienzaJuego(int dados1[2], int dados2[2], string nombre1, string nombre2,string *g,int *p,bool modalidad);
void DefineOrdenDeJugadores(int PuntajeRonda1, int dadosJ1[2], int dadosJ2[2], string Nombrej1, string Nombrej2, bool juegoEnModoAleatorio,string *g,int *p,bool modalidad);
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
void interfaceJuego(int acuTrufasJ1,int acuTrufasJ2,int dadosJ1[2], int dadosJ2[2], string Nombrej1, string Nombrej2,string nombre,int rondas,int lanz,int lanzTotal, int acu);
void TirarDadoManual(int vecJ1[2],int vecJ2[2], string j1, string j2);
void cargarTresDadosManual(int dadosJ1[3]);
void tirarDadoRondasManual(int dadosJ1[2]);

#endif // FUNCIONES_H_INCLUDED
