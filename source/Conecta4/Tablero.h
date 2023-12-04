#pragma once
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int FILAS = 6;
const int COLUMNAS = 7;
const char VACIO = ' ';
const char JUGADOR1 = 'X';
const char JUGADOR2 = 'O';

class Tablero{
    private:
    vector<vector<char>> board;
    int jugadorActual;
    int PROFUNDIDAD;
    public:
    Tablero(int profundidad){
        board = vector<vector<char>>(FILAS, vector<char>(COLUMNAS, VACIO));
        jugadorActual = 1;
        this -> PROFUNDIDAD = profundidad;
    };
    ~Tablero(){
        cout << "Destructor" << endl;
    };

    void printBoard(){
        for (int i = 0; i < FILAS; ++i) {
            for (int j = 0; j < COLUMNAS; ++j) {
                cout << "| " << board[i][j] << " ";
            }
            cout << "|" << endl;
        }
        cout << "-----------------------------" << endl;
    };

    //pone la ficha en la columna indicada, si esta vacia o es un numero invalido, retorna false
    bool ponerFicha(int col){        
        if (col < 0 || col >= COLUMNAS) {
            cout << "Columna fuera de rango. Introduce un número válido (0-" << COLUMNAS - 1 << ")." << endl;
            return false;
        }

        for (int i = FILAS - 1; i >= 0; --i) {
            if (board[i][col] == VACIO) {
                if(jugadorActual == 1){
                    board[i][col] = JUGADOR1;
                }else{
                    board[i][col] = JUGADOR2;
                }
                return true;
            }
        }

        cout << "Columna llena. Elige otra columna." << endl;
        return false;
    
    };

    //Verifica si hay un ganador revisando las posibles combinaciones
    bool verificarGanador(){

        for (int i = 0; i < FILAS; ++i) {
            for (int j = 0; j < COLUMNAS - 3; ++j) {
                if (board[i][j] != VACIO &&
                    board[i][j] == board[i][j + 1] &&
                    board[i][j] == board[i][j + 2] &&
                    board[i][j] == board[i][j + 3]) {
                    return true;
                }
            }
        }

        for (int i = 0; i < FILAS - 3; ++i) {
            for (int j = 0; j < COLUMNAS; ++j) {
                if (board[i][j] != VACIO &&
                    board[i][j] == board[i + 1][j] &&
                    board[i][j] == board[i + 2][j] &&
                    board[i][j] == board[i + 3][j]) {
                    return true;
                }
            }
        }

        for (int i = 3; i < FILAS; ++i) {
            for (int j = 0; j < COLUMNAS - 3; ++j) {
                if (board[i][j] != VACIO &&
                    board[i][j] == board[i - 1][j + 1] &&
                    board[i][j] == board[i - 2][j + 2] &&
                    board[i][j] == board[i - 3][j + 3]) {
                    return true;
                }
            }
        }

        for (int i = 3; i < FILAS; ++i) {
            for (int j = 3; j < COLUMNAS; ++j) {
                if (board[i][j] != VACIO &&
                    board[i][j] == board[i - 1][j - 1] &&
                    board[i][j] == board[i - 2][j - 2] &&
                    board[i][j] == board[i - 3][j - 3]) {
                    return true;
                }
            }
        }

        return false;
    };

    bool movimientoValido(int col) {
        if (col >= 0 && col < COLUMNAS && board[0][col] == VACIO) {
            return true;
        } else {
            return false;
        }
    }

    int obtenerFilaVacia(int col) {
        for (int i = FILAS - 1; i >= 0; --i) {
            if (board[i][col] == VACIO) {
                return i;
            }
        }
        return -1;
    }

    int puntajePosicion(vector<vector<char>>& board) {
        int puntaje = 0;

        for (int i = 0; i < FILAS; ++i) {
            for (int j = 0; j < COLUMNAS - 3; ++j) {
                int contJugador1 = 0;
                int contJUGADOR2 = 0;
                for (int k = 0; k < 4; ++k) {
                    if (board[i][j + k] == JUGADOR1) {
                        contJugador1++;
                    } else if (board[i][j + k] == JUGADOR2) {
                        contJUGADOR2++;
                    }
                }
                if (contJugador1 > 0 && contJUGADOR2 == 0) {
                    puntaje += contJugador1 * contJugador1 * contJugador1;
                } else if (contJUGADOR2 > 0 && contJugador1 == 0) {
                    puntaje -= contJUGADOR2 * contJUGADOR2 * contJUGADOR2;
                }
            }
        }

        for (int i = 0; i < FILAS - 3; ++i) {
            for (int j = 0; j < COLUMNAS; ++j) {
                int contJugador1 = 0;
                int contJUGADOR2 = 0;
                for (int k = 0; k < 4; ++k) {
                    if (board[i + k][j] == JUGADOR1) {
                        contJugador1++;
                    } else if (board[i + k][j] == JUGADOR2) {
                        contJUGADOR2++;
                    }
                }
                if (contJugador1 > 0 && contJUGADOR2 == 0) {
                    puntaje += contJugador1 * contJugador1 * contJugador1;
                } else if (contJUGADOR2 > 0 && contJugador1 == 0) {
                    puntaje -= contJUGADOR2 * contJUGADOR2 * contJUGADOR2;
                }
            }
        }

        for (int i = 3; i < FILAS; ++i) {
            for (int j = 0; j < COLUMNAS - 3; ++j) {
                int contJugador1 = 0;
                int contJUGADOR2 = 0;
                for (int k = 0; k < 4; ++k) {
                    if (board[i - k][j + k] == JUGADOR1) {
                        contJugador1++;
                    } else if (board[i - k][j + k] == JUGADOR2) {
                        contJUGADOR2++;
                    }
                }
                if (contJugador1 > 0 && contJUGADOR2 == 0) {
                    puntaje += contJugador1 * contJugador1 * contJugador1;
                } else if (contJUGADOR2 > 0 && contJugador1 == 0) {
                    puntaje -= contJUGADOR2 * contJUGADOR2 * contJUGADOR2;
                }
            }
        }

        for (int i = 3; i < FILAS; ++i) {
            for (int j = 3; j < COLUMNAS; ++j) {
                int contJugador1 = 0;
                int contJUGADOR2 = 0;
                for (int k = 0; k < 4; ++k) {
                    if (board[i - k][j - k] == JUGADOR1) {
                        contJugador1++;
                    } else if (board[i - k][j - k] == JUGADOR2) {
                        contJUGADOR2++;
                    }
                }
                if (contJugador1 > 0 && contJUGADOR2 == 0) {
                    puntaje += contJugador1 * contJugador1 * contJugador1;
                } else if (contJUGADOR2 > 0 && contJugador1 == 0) {
                    puntaje -= contJUGADOR2 * contJUGADOR2 * contJUGADOR2;
                }
            }
        }

        return puntaje;
    }

    int minimax(int PROFUNDIDAD, int alpha, int beta, bool maximizador) {
        if (PROFUNDIDAD == 0 || verificarGanador()) {
            return puntajePosicion(board);
        }

        if (maximizador) {
            int maxpuntaje = INT_MIN;
            for (int col = 0; col < COLUMNAS; ++col) {
                if (movimientoValido(col)) {
                    int fila = obtenerFilaVacia(col);
                    board[fila][col] = JUGADOR1;
                    int puntaje = minimax(PROFUNDIDAD - 1, alpha, beta, false);
                    board[fila][col] = VACIO;
                    maxpuntaje = max(maxpuntaje, puntaje);
                    alpha = max(alpha, puntaje);
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
            return maxpuntaje;
        } else {
            int minpuntaje = INT_MAX;
            for (int col = 0; col < COLUMNAS; ++col) {
                if (movimientoValido(col)) {
                    int fila = obtenerFilaVacia(col);
                    board[fila][col] = JUGADOR2;
                    int puntaje = minimax(PROFUNDIDAD - 1, alpha, beta, true);
                    board[fila][col] = VACIO;
                    minpuntaje = min(minpuntaje, puntaje);
                    beta = min(beta, puntaje);
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
            return minpuntaje;
        }
    }

    int mejorMovimiento() {
        int mejorMovimiento = -1;
        int mejorPuntaje = INT_MIN;

        for (int col = 0; col < COLUMNAS; ++col) {
            if (movimientoValido(col)) {
                int fila = obtenerFilaVacia(col);
                board[fila][col] = JUGADOR1;
                int puntaje = minimax(PROFUNDIDAD, INT_MIN, INT_MAX, false);
                board[fila][col] = VACIO;
                if (puntaje > mejorPuntaje) {
                    mejorPuntaje = puntaje;
                    mejorMovimiento = col;
                }
            }
        }

        return mejorMovimiento;
    }

    void jugarContraPC() {
        bool fin = false;

        while (!fin) {
            printBoard();

            if (jugadorActual == 1) {
                cout << "Turno del jugador " << jugadorActual << ". Elige una columna (0-" << COLUMNAS - 1 << "): ";
                int col;
                cin >> col;

                if (movimientoValido(col)) {
                    ponerFicha(col);
                    if (verificarGanador()) {
                        printBoard();
                        string s;
                        cout << "¡Jugador " << jugadorActual << " ha ganado!" << endl;
                        cout<<"Cualquier tecla para salir"<<endl;
                        cin>>s;
                        fin = true;
                    } else {
                        jugadorActual = 2;
                    }
                }
            } else {
                int movimientoIA = mejorMovimiento();
                if (movimientoValido(movimientoIA)) {
                    ponerFicha(movimientoIA);
                    if (verificarGanador()) {
                        printBoard();
                        string s;
                        cout << "¡IA ha ganado!" << endl;
                        cout<<"Cualquier tecla para salir"<<endl;
                        cin>>s;
                        fin = true;
                    } else {
                        jugadorActual = 1;
                    }
                }
            }
        }
    }
};


