#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

void menuPrincipal();
void comenzarJuego();
void jugar();
void estadisticas(string ganador, int puntos);
void cerditos();
string ingresarNombre(int n);

int main()
{
    comenzarJuego();
    return 0;
}
void menuPrincipal()
{
    cout<<"GRAN CERDO"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"1 - JUGAR"<<endl;
    cout<<"2 - ESTADISTICA"<<endl;
    cout<<"3 - CERDITOS"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"0 - SALIR"<<endl;
}
void comenzarJuego()
{
   menuPrincipal();
   int opcion;
   cin >> opcion;
   system("cls");
   switch(opcion)
   {
       case 1: jugar();
       break;
       case 2: estadisticas("WALTER",3);
       break;
       case 3: cerditos();
       break;
       case 0: ExitProcess(0);
       break;
       default:
        cout<<"Eleccion invalida"<<endl;
        cout<<endl;
        comenzarJuego();
        break;
   }
}
void jugar()
{
    string j1, j2;
    j1=ingresarNombre(1);
    j2=ingresarNombre(2);
    cout<<"es el turno de "+j1<<endl;

}
void estadisticas(string ganador, int puntos)
{
    cout<<"El ganador es "<< ganador<<" con "<<puntos<<" PDV"<<endl;

}
void cerditos()
{
    cout << "Albornos Agustin Legajo 26809 "<<endl;


}
string ingresarNombre(int n)
{
    string nombre;
    cout<<"Ingresar nombre del jugador numero "<<n<<endl;
    cin>>nombre;
    return nombre;
}
