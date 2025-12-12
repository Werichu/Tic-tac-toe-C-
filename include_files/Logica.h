#ifndef LOGICA_H_INCLUDED
#define LOGICA_H_INCLUDED
#include <iostream>
#include <fstream>
#include "utils.h"
#include "Estructura.h"
#define DIM 3 // es la dimension del tablero

using std::cout;
using std::cin;
using std::endl;

//prototipos
bool colocarMarcaX(char tablero[DIM][DIM], int fila, int columna);
bool colocarMarcaO(char tablero[DIM][DIM], int fila, int columna);
bool defineGanador(char tablero[DIM][DIM]);

// estructura
    Puntos p;

void inicializarMatriz(char tablero[DIM][DIM]){ // se inicializa el tablero con un caracter nulo
    for(int i=0; i<DIM; i++){
        for(int j=0; j<DIM; j++){
            tablero[i][j] = '-';
        }
    }
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

void juego(){
    int fila, columna;
    char tablero[DIM][DIM]; // tablero y marcas a usar como tambien respuesta a la continuacion del juego
    char resp;
    bool validarJuego = false, jugadorX = true, jugadorO = true, hayGanador = false; // banderas tanto del juego como los jugadores

    cout<<endl;
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
            p.contador_jugadas = 0; // se reinicia el contador de movimientos
            limpiar_pantalla();
            cin.get();
            continue; // se repite el ciclo do while
        }else{
            validarJuego = true; // termina el juego
            p.contador_jugadas = 0;
            limpiar_pantalla();
        }
    }

    }while(validarJuego == false);
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
    p.contador_jugadas++;
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
    p.contador_jugadas++;
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
        p.victorias_jugadorX++;
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
        p.victorias_jugadorO++;
        cout<<"\n";
        return true;
    }

    //empates
    if(p.contador_jugadas == 9){
        cout<<"Es un empate!!!!"<<endl;
        p.empates++;
        cout<<endl;
        return true;
    }

    return false;
}

void estadisticas (){// muestra tablero de victorias
    cout<<"-----------------ESTADISTICAS---------------"<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"|                 VICTORIAS                |"<<endl;
    cout<<"|------------------------------------------|"<<endl;
    cout<<"|     JUGADOR X      |      JUGADOR O      |"<<endl;
    cout<<"|------------------------------------------|"<<endl;
    cout<<"|"<<"         "<<p.victorias_jugadorX<<"          "<<"|"<<
    "          "<<p.victorias_jugadorO<<"          "<<"|"<<endl;
    cout<<"|------------------------------------------|"<<endl;
    cout<<"|      EMPATES      "<<" |          "<<p.empates<<
    "          |"<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"\n\n"<<endl;
}

void guardarDatos(){
    std::ofstream miArchivo ("Puntuaciones.txt");
    miArchivo<<"Victorias X: "<<p.victorias_jugadorX<<"\n"<<"Victorias O: "<<
    p.victorias_jugadorO<<"\n"<<"Empates: "<<p.empates;
    miArchivo.close();

    cout<<"-> Archivo generado como: Puntuaciones.txt"<<endl;
    cout<<endl;

}

void cargarDatos(){
    std::string texto;
    std::ifstream Archivo ("Puntuaciones.txt");
    if(Archivo.is_open()){
        Archivo>>texto>>texto>>p.victorias_jugadorX;
        Archivo>>texto>>texto>>p.victorias_jugadorO;
        Archivo>>texto>>p.empates;
        Archivo.close();
        cout<<"Se han cargado los datos"<<endl;
    }else{
    cout<<"Error al cargar los datos"<<endl;
    }
}

void borrarDatos(){
    p.victorias_jugadorX = 0;
    p.victorias_jugadorO = 0;
    p.empates = 0;

    std::ofstream miArchivo ("Puntuaciones.txt");
    miArchivo<<"Victorias X: "<<p.victorias_jugadorX<<"\n"<<"Victorias O: "<<
    p.victorias_jugadorO<<"\n"<<"Empates: "<<p.empates;
    miArchivo.close();
    cout<<"Datos borrados con exito"<<endl;
}

#endif // LOGICA_H_INCLUDED
