#include <iostream>
#include <cstring>
#include "utils.h"
#define DIM 3 // es la dimension del tablero

using namespace std;

void inicializarMatriz(char [][DIM]);
void mostrarMatriz(char [][DIM]);
bool colocarMarcaX(char [][DIM], int, int);
bool colocarMarcaO(char [][DIM], int, int);
bool defineGanador(char [][DIM]);

int contador_jugadas; // ayuda a declarar empates

int main(){
    char tablero[DIM][DIM],resp; // tablero y marcas a usar como tambien respuesta a la continuacion del juego
    int fila, columna;
    bool validarJuego = false, jugadorX = true, jugadorO = true, hayGanador = false; // banderas tanto del juego como los jugadores

    cout<<"Juego del gato v1.1\n\n"<<endl;

    inicializarMatriz(tablero);
    mostrarMatriz(tablero);

    do{
        while(jugadorX == true && !hayGanador){
            cout<<endl;
            cout<<"Es el turno de jugador X"<<endl;
            cout<<"Digite una fila (0/2) "; cin>>fila;
            cout<<"Digite una columna (0/2) "; cin>>columna;
            cout<<"\n";
            if(colocarMarcaX(tablero,fila,columna)){
                mostrarMatriz(tablero); // cada que se incerte una marca en el lugar correspondiente se mostrara el tablero al usuario
                cout<<endl;
                if(defineGanador(tablero)){
                    hayGanador = true;
                }
                break;
                cin.get();
            }
            cin.get();
        }

        while(jugadorO == true && !hayGanador){
            cout<<"Es el turno de jugador O"<<endl;
            cout<<"Digite una fila (0/2) "; cin>>fila;
            cout<<"Digite una columna (0/2) "; cin>>columna;
            cout<<"\n";
            if(colocarMarcaO(tablero,fila,columna)){
                mostrarMatriz(tablero);
                cout<<endl;
                if(defineGanador(tablero)){
                    hayGanador = true;
                }
                break;
                cin.get();
            }// en caso de que el espacio este ocupado, se vuelve a repetir el turno
        }

        if(hayGanador){
            mostrarMatriz(tablero);
            cout<<"\n\n"<<endl;
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

void mostrarMatriz(char tablero[DIM][DIM]){ // generacion del tablero
    for(int i=0; i<DIM; i++){
        cout<<" "<<tablero[i][0];
        cout<<" | "<<tablero[i][1];
        cout<<" | "<<tablero[i][2]<<endl; // en cada columna se coloca este caracter

        if(i<2){// en cada fila se coloca este espacio
            cout<<"------------"<<endl;
        }
    }
}

bool colocarMarcaX(char tablero[DIM][DIM], int fila, int columna){
    char marcaX = 'X';

    if((fila<0 || fila>2) || (columna < 0 || columna > 2)){ // validadion que evita desbordamiento
        cout<<"Error, jugada no valida"<<endl;
        return false;
    }

    if(tablero[fila][columna] != '-'){ // validacion que verifica los espacios vacios
        cout<<"El espacio esta ocupado"<<endl;
        return false;
    }

    tablero[fila][columna] = marcaX;
    contador_jugadas++;
    // en caso de que pase las validaciones, el juego prosigue
    return true;
}

bool colocarMarcaO(char tablero[DIM][DIM], int fila, int columna){
    char marcaO = 'O';

    if((fila<0 || fila>2) || (columna < 0 || columna > 2)){ // validacion que evita desbordamiento
        cout<<"Error, jugada no valida"<<endl;
        return false;
    }

    if(tablero[fila][columna] != '-'){ // validacion que verifica los espacios vacios
        cout<<"El espacio esta ocupado"<<endl;
        return false;
    }

    tablero[fila][columna] = marcaO;
    contador_jugadas++;
    // en caso de que pase las validaciones, el juego prosigue
    return true;
}
bool defineGanador(char tablero[DIM][DIM]){
    char marcaX = 'X';
    char marcaO = 'O';
    if(
        // comprobacion de filas jugador X
        (tablero[0][0] == marcaX && tablero[0][1] == marcaX && tablero[0][2] == marcaX) ||
        (tablero[1][0] == marcaX && tablero[1][1] == marcaX && tablero[1][2] == marcaX) ||
        (tablero[2][0] == marcaX && tablero[2][1] == marcaX && tablero[2][2] == marcaX) ||
        // comprobacion de columnas jugador X
        (tablero[0][0] == marcaX && tablero[1][0] == marcaX && tablero[2][0] == marcaX) ||
        (tablero[0][1] == marcaX && tablero[1][1] == marcaX && tablero[2][1] == marcaX) ||
        (tablero[0][2] == marcaX && tablero[1][2] == marcaX && tablero[2][2] == marcaX) ||
        //comrpobacion de diagonales jugador X
        (tablero[0][0] == marcaX && tablero[1][1] == marcaX && tablero[2][2] == marcaX) ||
        (tablero[0][2] == marcaX && tablero[1][1] == marcaX && tablero[2][0] == marcaX)
    ){
        cout<<"Has ganado Jugador X  !!!"<<endl;
        cout<<endl;
        return true;
    }

    if(
    // comprobacion de filas jugador O
        (tablero[0][0] == marcaO && tablero[0][1] == marcaO && tablero[0][2] == marcaO) ||
        (tablero[1][0] == marcaO && tablero[1][1] == marcaO && tablero[1][2] == marcaO) ||
        (tablero[2][0] == marcaO && tablero[2][1] == marcaO && tablero[2][2] == marcaO) ||
        // comprobacion de columnas jugador O
        (tablero[0][0] == marcaO && tablero[1][0] == marcaO && tablero[2][0] == marcaO) ||
        (tablero[0][1] == marcaO && tablero[1][1] == marcaO && tablero[2][1] == marcaO) ||
        (tablero[0][2] == marcaO && tablero[1][2] == marcaO && tablero[2][2] == marcaO) ||
        //comprobacion de diagonales jugador O
        (tablero[0][0] == marcaO && tablero[1][1] == marcaO && tablero[2][2] == marcaO) ||
        (tablero[0][2] == marcaO && tablero[1][1] == marcaO && tablero[2][0] == marcaO)
    ){
        cout<<"Has ganado Jugador O  !!!"<<endl;
        cout<<"\n";
        return true;
    }

    //empates
    if(contador_jugadas == 9){
        cout<<"Es un empate!!!!"<<endl;
        cout<<endl;
        return true;
    }

    return false;
}

