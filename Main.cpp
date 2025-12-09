#include <iostream>
#include <cstring>
#include "utils.h"
#include "Logica.h"

using namespace std;

int contador_jugadas; // ayuda a declarar empates
int victorias_jugadorX; // estas variables cuantas las victorias de cada jugador como los empates
int victorias_jugadorO;
int empates;

int main(){
    int opc;

    do{
        cout<<"---------- Tic-Tac-Toe ----------\n"<<endl;
        cout<<"[1] Iniciar juego"<<endl;
        cout<<"[2] Mostrar estadisticas"<<endl;
        cout<<"[3] Guardar datos"<<endl;
        cout<<"[4] Cargar datos"<<endl;
        cout<<"[5] Borrar datos"<<endl;
        cout<<"[0] Salir"<<endl;
        cout<<"opcion: "; cin>>opc;
        limpiar_pantalla();

        switch(opc){
            case JUGAR:        juego(); break;
            case ESTADISTICAS: Estadisticas(); break;
            case GUARDAR: guardarDatos(); break;
            case CARGAR: cargarDatos(); break;
            case BORRAR: cout<< "proximamente!!!!!!!!" <<endl;break;
            case SALIR: cout<<"Byteees!!!!!"<<endl; break;
            default: cout<<"Opcion no valida"<<endl;
        }

    }while(opc != SALIR);

    return 0;
}



