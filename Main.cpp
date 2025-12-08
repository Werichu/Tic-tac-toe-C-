#include <iostream>
#include <cstring>
#include "utils.h"
#include "Logica.h"

using namespace std;

int main(){
    int opc;

    do{
        cout<<"---------- Juego del gato v1.2 ----------\n"<<endl;
        cout<<"[1] Iniciar juego"<<endl;
        cout<<"[2] Mostrar estadisticas"<<endl;
        cout<<"[3] Borrar estadisticas"<<endl;
        cout<<"[0] Salir"<<endl;
        cout<<"opcion: "; cin>>opc;
        limpiar_pantalla();

        switch(opc){
            case JUGAR:        juego(); break;
            case ESTADISTICAS: Estadisticas(); break;
            case BORRAR: break;
            case SALIR: cout<<"Byteees!!!!!"<<endl; break;
            default: cout<<"Opcion no valida"<<endl;
        }

    }while(opc != SALIR);

    return 0;
}



