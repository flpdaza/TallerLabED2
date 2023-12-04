#pragma once
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int ROWS = 6;
const int COLS = 7;
const char EMPTY = ' ';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
const int DEPTH = 6; // Profundidad máxima de búsqueda para el algoritmo minimax

class Tablero{
    private:
    vector<vector<char>> board;
    int currentPlayer;
    public:
    Tablero(){
        board = vector<vector<char>>(ROWS, vector<char>(COLS, EMPTY));
        currentPlayer = 1;
    };
    ~Tablero(){
        cout << "Destructor" << endl;
    };

    void printBoard(){
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                cout << "| " << board[i][j] << " ";
            }
            cout << "|" << endl;
        }
        cout << "-----------------------------" << endl;
    };

    bool encontrarFilaVacia(int){        
        if (col < 0 || col >= COLS) {
            cout << "Columna fuera de rango. Introduce un número válido (0-" << COLS - 1 << ")." << endl;
            return false;
        }

        for (int i = ROWS - 1; i >= 0; --i) {
            if (board[i][col] == EMPTY) {
                board[i][col] = (currentPlayer == 1) ? PLAYER1 : PLAYER2;
                return true;
            }
        }

        cout << "Columna llena. Elige otra columna." << endl;
        return false;
    
    };
    bool verificarGanador(){// Verificación horizontal
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS - 3; ++j) {
                if (board[i][j] != EMPTY &&
                    board[i][j] == board[i][j + 1] &&
                    board[i][j] == board[i][j + 2] &&
                    board[i][j] == board[i][j + 3]) {
                    return true;
                }
            }
        }

        // Verificación vertical
        for (int i = 0; i < ROWS - 3; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (board[i][j] != EMPTY &&
                    board[i][j] == board[i + 1][j] &&
                    board[i][j] == board[i + 2][j] &&
                    board[i][j] == board[i + 3][j]) {
                    return true;
                }
            }
        }

        // Verificación diagonal ascendente
        for (int i = 3; i < ROWS; ++i) {
            for (int j = 0; j < COLS - 3; ++j) {
                if (board[i][j] != EMPTY &&
                    board[i][j] == board[i - 1][j + 1] &&
                    board[i][j] == board[i - 2][j + 2] &&
                    board[i][j] == board[i - 3][j + 3]) {
                    return true;
                }
            }
        }

        // Verificación diagonal descendente
        for (int i = 3; i < ROWS; ++i) {
            for (int j = 3; j < COLS; ++j) {
                if (board[i][j] != EMPTY &&
                    board[i][j] == board[i - 1][j - 1] &&
                    board[i][j] == board[i - 2][j - 2] &&
                    board[i][j] == board[i - 3][j - 3]) {
                    return true;
                }
            }
        }

        return false;
    };
    bool isValidMove(int col) {
        return col >= 0 && col < COLS && board[0][col] == EMPTY;
    }

    int getLastEmptyRow(int col) {
        for (int i = ROWS - 1; i >= 0; --i) {
            if (board[i][col] == EMPTY) {
                return i;
            }
        }
        return -1;
    }

    int scorePosition(vector<vector<char>>& board) {
        int score = 0;

        // Horizontal
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS - 3; ++j) {
                int countPlayer1 = 0;
                int countPlayer2 = 0;
                for (int k = 0; k < 4; ++k) {
                    if (board[i][j + k] == PLAYER1) {
                        countPlayer1++;
                    } else if (board[i][j + k] == PLAYER2) {
                        countPlayer2++;
                    }
                }
                if (countPlayer1 > 0 && countPlayer2 == 0) {
                    score += countPlayer1 * countPlayer1 * countPlayer1;
                } else if (countPlayer2 > 0 && countPlayer1 == 0) {
                    score -= countPlayer2 * countPlayer2 * countPlayer2;
                }
            }
        }

        // Vertical
        for (int i = 0; i < ROWS - 3; ++i) {
            for (int j = 0; j < COLS; ++j) {
                int countPlayer1 = 0;
                int countPlayer2 = 0;
                for (int k = 0; k < 4; ++k) {
                    if (board[i + k][j] == PLAYER1) {
                        countPlayer1++;
                    } else if (board[i + k][j] == PLAYER2) {
                        countPlayer2++;
                    }
                }
                if (countPlayer1 > 0 && countPlayer2 == 0) {
                    score += countPlayer1 * countPlayer1 * countPlayer1;
                } else if (countPlayer2 > 0 && countPlayer1 == 0) {
                    score -= countPlayer2 * countPlayer2 * countPlayer2;
                }
            }
        }

        // Diagonal ascendente
        for (int i = 3; i < ROWS; ++i) {
            for (int j = 0; j < COLS - 3; ++j) {
                int countPlayer1 = 0;
                int countPlayer2 = 0;
                for (int k = 0; k < 4; ++k) {
                    if (board[i - k][j + k] == PLAYER1) {
                        countPlayer1++;
                    } else if (board[i - k][j + k] == PLAYER2) {
                        countPlayer2++;
                    }
                }
                if (countPlayer1 > 0 && countPlayer2 == 0) {
                    score += countPlayer1 * countPlayer1 * countPlayer1;
                } else if (countPlayer2 > 0 && countPlayer1 == 0) {
                    score -= countPlayer2 * countPlayer2 * countPlayer2;
                }
            }
        }

        // Diagonal descendente
        for (int i = 3; i < ROWS; ++i) {
            for (int j = 3; j < COLS; ++j) {
                int countPlayer1 = 0;
                int countPlayer2 = 0;
                for (int k = 0; k < 4; ++k) {
                    if (board[i - k][j - k] == PLAYER1) {
                        countPlayer1++;
                    } else if (board[i - k][j - k] == PLAYER2) {
                        countPlayer2++;
                    }
                }
                if (countPlayer1 > 0 && countPlayer2 == 0) {
                    score += countPlayer1 * countPlayer1 * countPlayer1;
                } else if (countPlayer2 > 0 && countPlayer1 == 0) {
                    score -= countPlayer2 * countPlayer2 * countPlayer2;
                }
            }
        }

        return score;
    }
    int minimax(int depth, int alpha, int beta, bool maximizingPlayer) {
        if (depth == 0 || checkWin()) {
            return scorePosition(board);
        }

        if (maximizingPlayer) {
            int maxScore = INT_MIN;
            for (int col = 0; col < COLS; ++col) {
                if (isValidMove(col)) {
                    int row = getLastEmptyRow(col);
                    board[row][col] = PLAYER1;
                    int score = minimax(depth - 1, alpha, beta, false);
                    board[row][col] = EMPTY;
                    maxScore = max(maxScore, score);
                    alpha = max(alpha, score);
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
            return maxScore;
        } else {
            int minScore = INT_MAX;
            for (int col = 0; col < COLS; ++col) {
                if (isValidMove(col)) {
                    int row = getLastEmptyRow(col);
                    board[row][col] = PLAYER2;
                    int score = minimax(depth - 1, alpha, beta, true);
                    board[row][col] = EMPTY;
                    minScore = min(minScore, score);
                    beta = min(beta, score);
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
            return minScore;
        }
    }

    int getBestMove() {
        int bestMove = -1;
        int bestScore = INT_MIN;

        for (int col = 0; col < COLS; ++col) {
            if (isValidMove(col)) {
                int row = getLastEmptyRow(col);
                board[row][col] = PLAYER1;
                int score = minimax(DEPTH, INT_MIN, INT_MAX, false);
                board[row][col] = EMPTY;
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = col;
                }
            }
        }

        return bestMove;
    }
    void playAgainstAI() {
        bool gameover = false;

        while (!gameover) {
            printBoard();

            if (currentPlayer == 1) {
                cout << "Turno del jugador " << currentPlayer << ". Elige una columna (0-" << COLS - 1 << "): ";
                int col;
                cin >> col;

                if (isValidMove(col)) {
                    dropPiece(col);
                    if (checkWin()) {
                        printBoard();
                        cout << "¡Jugador " << currentPlayer << " ha ganado!" << endl;
                        gameover = true;
                    } else {
                        currentPlayer = 2;
                    }
                }
            } else {
                int aiMove = getBestMove();
                if (isValidMove(aiMove)) {
                    dropPiece(aiMove);
                    if (checkWin()) {
                        printBoard();
                        cout << "¡IA ha ganado!" << endl;
                        gameover = true;
                    } else {
                        currentPlayer = 1;
                    }
                }
            }
        }
    }
};


