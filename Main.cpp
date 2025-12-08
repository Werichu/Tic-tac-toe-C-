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
        cin>>opc;
        limpiar_pantalla();

        switch(opc){
            case JUGAR: juego(); break;
            case ESTADISTICAS: break;
            case BORRAR: break;
        }

    }while(opc !=0);

    return 0;
}



