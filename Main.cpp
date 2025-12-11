#include <iostream>
#include <cstring>
#include "utils.h"
#include "Logica.h"

using namespace std;

int main(){
    int opc;

    do{
        cout<<"---------- Tic-Tac-Toe ----------\n"<<endl;
        cout<<"[1] Iniciar juego"<<endl;
        cout<<"[2] Mostrar estadisticas"<<endl;
        cout<<"[3] Guardar puntuacion"<<endl;
        cout<<"[4] Cargar puntuacion"<<endl;
        cout<<"[5] Borrar puntuacion"<<endl;
        cout<<"[0] Salir"<<endl;
        cout<<"opcion: "; cin>>opc;
        limpiar_pantalla();

        switch(opc){
            case JUGAR:        juego(); break;
            case ESTADISTICAS: estadisticas(); break;
            case GUARDAR:      guardarDatos(); break;
            case CARGAR:       cargarDatos(); break;
            case BORRAR:       borrarDatos(); break;
            case SALIR: cout<<"Byteees!!!!!"<<endl; break;
            default: cout<<"Opcion no valida"<<endl;
        }

    }while(opc != SALIR);

    return 0;
}



