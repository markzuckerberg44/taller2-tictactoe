//
// Created by julih on 07-12-2024.
//

#ifndef IA_MINIMAX_H
#define IA_MINIMAX_H

#include "Tablero.h"
#include <utility>

class IA_Minimax {
public:
    std::pair<int, int> mejorMovimiento(Tablero& tablero);
private:
    int minimax(Tablero& tablero, int profundidad, bool esMaximizador, int alfa, int beta);
};

#endif

