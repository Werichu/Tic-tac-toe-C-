#include <iostream>
#include <cstring>
#include "utils.h"
#define DIM 3

using namespace std;

void inicializarMatriz(char [][DIM]);
void mostrarMatriz(char [][DIM]);
bool colocarMarca(char [][DIM], int, int, char);
bool defineGanador(char [][DIM], char);

int main(){
    char tablero[DIM][DIM], marca,resp; // tablero y marcas a usar como tambien respuesta a la continuacion del juego
    int fila, columna;
    bool validarJuego = false, jugadorX = true, jugadorO = true, hayGanador = false; // banderas tanto del juego como los jugadores

    cout<<"Juego del gato v1.0\n\n"<<endl;

    inicializarMatriz(tablero);
    mostrarMatriz(tablero);

    do{
        while(jugadorX == true && !hayGanador){
            cout<<endl;
            cout<<"Es el turno de jugador X"<<endl;
            cout<<"Digite una fila (0/2) "; cin>>fila;
            cout<<"Digite una columna (0/2) "; cin>>columna;
            cout<<"Digite su marca: "; cin>>marca;
            if(marca == 'X' || marca == 'x'){
                if(colocarMarca(tablero,fila,columna,marca)){
                    if(defineGanador(tablero,marca)){
                        hayGanador = true;
                    }
                    break; // pasa el turno
                }
            }else{
                cout<<"No es la marca correspondiente"<<endl;
                cin.get();
            }
        }

        mostrarMatriz(tablero);
        cin.get();

        while(jugadorO == true && !hayGanador){
            cout<<"Es el turno de jugador O"<<endl;
            cout<<"Digite una fila (0/2) "; cin>>fila;
            cout<<"Digite una columna (0/2) "; cin>>columna;
            cout<<"Digite su marca: "; cin>>marca;
            if(marca == 'O' || marca == 'o'){// validacion de la marca corresponsiente
                if(colocarMarca(tablero,fila,columna,marca)){
                    if(defineGanador(tablero,marca)){
                        hayGanador = true;
                    }
                    break;
                }
            }else{
                cout<<" No es su marca corresponsiente"<<endl;
                cin.get();
            }
        }

        mostrarMatriz(tablero);
        cin.get();

        if(hayGanador){
            mostrarMatriz(tablero);

            cout<<"hay un ganador!!!"<<endl;
            cout<<"desea comenzar una nueva partida? (S/n): ";
            cin>>resp;

            if(resp == 's' || resp == 'S'){
                cout<<"\n\n";
                inicializarMatriz(tablero); // se vacia la matriz
                hayGanador = false;
                jugadorX = true;
                jugadorO = true;
                limpiar_pantalla();
                cin.get();
                continue; // se repite el ciclo do while
            }else{
                validarJuego = true; // termina el juego
            }
        }

    }while(validarJuego == false);

    return 0;
}

void inicializarMatriz(char tablero[DIM][DIM]){
    memset(tablero,'-',9); // esta funcion llena la matriz tablero con caracteres nulos
}

void mostrarMatriz(char tablero[DIM][DIM]){
    for(int i=0; i<DIM; i++){
        cout<<" "<<tablero[i][0];
        cout<<" | "<<tablero[i][1];
        cout<<" | "<<tablero[i][2]<<endl; // en cada columna se coloca este caracter

        if(i<2){// en cada fila se comoca este espacio
            cout<<"------------"<<endl;
        }
    }
}

bool colocarMarca(char tablero[DIM][DIM], int fila, int columna, char marca){
    if((fila<0 || fila>2) || (columna < 0 || columna > 2)){ // validadion que evita desbordamiento
        cout<<"Error, jugada no valida"<<endl;
        return false;
    }

    if(tablero[fila][columna] != '-'){ // validacion que verifica los espacios vacios
        cout<<"El espacio esta ocupado"<<endl;
        return false;
    }

    tablero[fila][columna] = marca;
    // en caso de que pase las validaciones, el juego prosigue
    return true;
}

bool defineGanador(char tablero[DIM][DIM], char marca){
    if(
        // comprobacion de filas
        (tablero[0][0] == marca && tablero[0][1] == marca && tablero[0][2] == marca) ||
        (tablero[1][0] == marca && tablero[1][1] == marca && tablero[1][2] == marca) ||
        (tablero[2][0] == marca && tablero[2][1] == marca && tablero[2][2] == marca) ||
        // comprobacion de columnas
        (tablero[0][0] == marca && tablero[1][0] == marca && tablero[2][0] == marca) ||
        (tablero[0][1] == marca && tablero[1][1] == marca && tablero[2][1] == marca) ||
        (tablero[0][2] == marca && tablero[1][2] == marca && tablero[2][2] == marca) ||
        //comrpobacion de diagonales
        (tablero[0][0] == marca && tablero[1][1] == marca && tablero[2][2] == marca) ||
        (tablero[0][2] == marca && tablero[1][1] == marca && tablero[2][0] == marca)
    ){
        cout<<"Has ganado!!!"<<endl;
        return true;
    }

    return false;
}

