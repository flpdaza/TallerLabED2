#pragma once
#include <iostream>

using namespace std;

const int FILAS = 6;
const int COLUMNAS = 7;
const char ESPACIO_VACIO = ' ';
const char JUGADOR_HUMANO = 'X';
const char JUGADOR_CPU = 'O';

class Tablero{
    public:
    char board[FILAS][COLUMNAS] = {{' ', ' ', ' ', ' ',' ', ' ', ' '},
                                   {' ', ' ', ' ', ' ',' ', ' ', ' '},
                                   {' ', ' ', ' ', ' ',' ', ' ', ' '},
                                   {' ', ' ', ' ', ' ',' ', ' ', ' '},
                                   {' ', ' ', ' ', ' ',' ', ' ', ' '},
                                   {' ', ' ', ' ', ' ',' ', ' ', ' '}};
    Tablero();
    ~Tablero();
    void printBoard();
    void jugarHumano();
    int encontrarFilaVaciaH(int);
    int verificarGanador();
    int minimax(int, bool, int, int);
};
Tablero::Tablero(){}
Tablero::~Tablero(){}
void Tablero::printBoard(){
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

int Tablero::encontrarFilaVaciaH(int columna){
    
    if(columna >= 0 && columna < COLUMNAS){
        for(int i = FILAS-1;i>=0; i--){
            if(board[i][columna] == ESPACIO_VACIO){
                board[i][columna] = JUGADOR_HUMANO;
                return 1;
            }
        }
        cout<<"columna llena"<<endl;
    }else{
        cout<<"columna invalida"<<endl;
    }
    return -1;
}

void Tablero::jugarHumano(){
    int columna;
    cout << "En que columna desea jugar? (0-6): ";
    cin >> columna;
    encontrarFilaVaciaH(columna);
}

// verificar ganador
int Tablero::verificarGanador(){
    //verificar ganador horizontal humano o cpu
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS-3; j++){
            if(board[i][j] == JUGADOR_HUMANO && board[i][j+1] == JUGADOR_HUMANO && board[i][j+2] == JUGADOR_HUMANO && board[i][j+3] == JUGADOR_HUMANO){
                cout<<"Ganaste"<<endl;
                return 1;
            }else if(board[i][j] == JUGADOR_CPU && board[i][j+1] == JUGADOR_CPU && board[i][j+2] == JUGADOR_CPU && board[i][j+3] == JUGADOR_CPU){
                cout<<"Gano la maquina"<<endl;
                return -1;
            }
        }
    }
};

//implementa el algoritmo minimax con poda alfa beta
int Tablero::minimax(int depth, bool isMaximizingPlayer, int alpha, int beta){
    int score = verificarGanador();
    if(score == 1){
        return score;
    }
    if(score == -1){
        return score;
    }
    if(isMaximizingPlayer){
        int best = -1000;
        for(int i = 0; i < FILAS; i++){
            for(int j = 0; j < COLUMNAS; j++){
                if(board[i][j] == ESPACIO_VACIO){
                    board[i][j] = JUGADOR_CPU;
                    int val = minimax(depth - 1, false, alpha, beta);
                    best = max(best, val);
                    alpha = max(alpha, best);
                    board[i][j] = ESPACIO_VACIO;
                    if(beta <= alpha){
                        break;
                    }
                }
            }
        }
        return best;
    }else{
        int best = 1000;
        for(int i = 0; i < FILAS; i++){
            for(int j = 0; j < COLUMNAS; j++){
                if(board[i][j] == ESPACIO_VACIO){
                    board[i][j] = JUGADOR_HUMANO;
                    int val = minimax(depth - 1, true, alpha, beta);
                    best = min(best, val);
                    beta = min(beta, best);
                    board[i][j] = ESPACIO_VACIO;
                    if(beta <= alpha){
                        break;
                    }
                }
            }
        }
        return best;
    }
}