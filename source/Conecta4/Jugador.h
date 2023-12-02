
#pragma once
#include <iostream>
#include "Tablero.h"

class Jugador {
public:
    virtual int elegirColumna(Tablero& tablero) = 0;
    virtual ~Jugador() {}
};
