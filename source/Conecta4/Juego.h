#pragma once
#include <iostream>
#include "Tablero.h"

using namespace std;
const int depth = 42;

class Juego{
    Tablero *tablero = new Tablero();
    public:
    Juego();
    ~Juego();
    void ejecutar();
};
Juego::Juego(){}
Juego::~Juego(){}

//genera el metodo ejecutar para el juego y que termine cuando haya un ganador
void Juego::ejecutar(){
    int columna;
    int turno = 0;
    bool seguir = true;
    while(seguir){
        tablero->printBoard();
        if(turno == 0){
            cout<<"Turno del jugador humano"<<endl;
            cout<<"Ingrese la columna: ";
            cin>>columna;
            tablero->encontrarFilaVaciaH(columna);
            turno = 1;
        }else{
            cout<<"Turno del jugador CPU"<<endl;
            tablero->minimax(depth, false, -1000, 1000);
            turno = 0;
        }
        if(tablero->verificarGanador() == 1 || tablero->verificarGanador() == -1){
            seguir = false;
        };
    }
}

