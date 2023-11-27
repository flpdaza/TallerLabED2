#pragma once
#include <iostream>

using namespace std;
const int FILAS = 6;
const int COLUMNAS = 7;
class Juego{
    private:
    public:
    Juego();
    ~Juego();
    void ejecutar();
    void printBoard(char[FILAS][COLUMNAS]);
    void jugadorHumano(char [FILAS][COLUMNAS]);
    void encontrarFilaVacia(char [FILAS][COLUMNAS], int);
    bool columnaLlena(char [FILAS][COLUMNAS], int);
};

Juego::Juego(){}

void Juego::ejecutar(){
    char board[FILAS][COLUMNAS] = {{' ', ' ', ' ', ' ',' ', ' ', ' '},
                                   {' ', ' ', ' ', ' ',' ', ' ', ' '},
                                   {' ', ' ', ' ', ' ',' ', ' ', ' '},
                                   {' ', ' ', ' ', ' ',' ', ' ', ' '},
                                   {' ', ' ', ' ', ' ',' ', ' ', ' '},
                                   {' ', ' ', ' ', ' ',' ', ' ', ' '}};

    string salir;
    printBoard(board);
    while(!columnaLlena(board, 0)){
        jugadorHumano(board);
        printBoard(board);
    }
    cout<<"presiones cualquier boton para salir"<<endl;
    cin>>salir;
}

void Juego::printBoard(char board[FILAS][COLUMNAS])
{
    cout << "" << endl;
    cout << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << "|" << board[0][3] << "|" << board[0][4] << "|" << board[0][5] << "|" << board[0][6] << endl;
    cout << "-+-+-+-+-+-+-" << endl;
    cout << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << "|" << board[1][3] << "|" << board[1][4] << "|" << board[1][5] << "|" << board[1][6] << endl;
    cout << "-+-+-+-+-+-+-" << endl;
    cout << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << "|" << board[2][3] << "|" << board[2][4] << "|" << board[2][5] << "|" << board[2][6] << endl;
    cout << "-+-+-+-+-+-+-" << endl;
    cout << board[3][0] << "|" << board[3][1] << "|" << board[3][2] << "|" << board[3][3] << "|" << board[3][4] << "|" << board[3][5] << "|" << board[3][6] << endl;
    cout << "-+-+-+-+-+-+-" << endl;
    cout << board[4][0] << "|" << board[4][1] << "|" << board[4][2] << "|" << board[4][3] << "|" << board[4][4] << "|" << board[4][5] << "|" << board[4][6] << endl;
    cout << "-+-+-+-+-+-+-" << endl;
    cout << board[5][0] << "|" << board[5][1] << "|" << board[5][2] << "|" << board[5][3] << "|" << board[5][4] << "|" << board[5][5] << "|" << board[5][6] << endl;
    cout << "0 1 2 3 4 5 6" << endl;
    cout << "" << endl;
}

void Juego::jugadorHumano(char board[FILAS][COLUMNAS])
{
    int columna;
    cout << "En que columna desea jugar? (0-6): " << endl;
    cin >> columna;

    encontrarFilaVacia(board, columna);
    
}

void Juego::encontrarFilaVacia(char board[FILAS][COLUMNAS], int columna){
    
        if(columna >= 0 && columna < COLUMNAS){
        for(int i = FILAS-1;i>=0; i--){
            if(board[i][columna] == ' '){
                board[i][columna] = 'x';
                return;
            }

        }
        cout<<"columna llena"<<endl;
    }else{
        cout<<"columna invalida"<<endl;
    }
    
    
    
   

}

bool Juego::columnaLlena(char board[FILAS][COLUMNAS], int columna){
    if(board[0][columna] != ' '){
        return true;
    }
    return false;
}