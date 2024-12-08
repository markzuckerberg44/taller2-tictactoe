//
// Created by julih on 07-12-2024.
//

#include "IA_Minimax.h"
#include <limits>
using namespace std;

int IA_Minimax::minimax(Tablero& tablero, int profundidad, bool esMaximizador, int alfa, int beta) {
    int puntuacion = tablero.evaluar();

    if (puntuacion == 10 || puntuacion == -10 || !tablero.hayMovimientos())
        return puntuacion;

    if (esMaximizador) {
        int mejor = numeric_limits<int>::min();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (tablero.obtenerCelda(i, j) == VACIO) {
                    tablero.realizarMovimiento(i, j, IA);
                    mejor = max(mejor, minimax(tablero, profundidad + 1, false, alfa, beta));
                    tablero.deshacerMovimiento(i, j);
                    alfa = max(alfa, mejor);
                    if (beta <= alfa) break;
                }
            }
        }
        return mejor;
    } else {
        int peor = numeric_limits<int>::max();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (tablero.obtenerCelda(i, j) == VACIO) {
                    tablero.realizarMovimiento(i, j, JUGADOR);
                    peor = min(peor, minimax(tablero, profundidad + 1, true, alfa, beta));
                    tablero.deshacerMovimiento(i, j);
                    beta = min(beta, peor);
                    if (beta <= alfa) break;
                }
            }
        }
        return peor;
    }
}

pair<int, int> IA_Minimax::mejorMovimiento(Tablero& tablero) {
    int mejorValor = numeric_limits<int>::min();
    pair<int, int> mejorMovimiento = {-1, -1};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tablero.obtenerCelda(i, j) == VACIO) {
                tablero.realizarMovimiento(i, j, IA);
                int valorMovimiento = minimax(tablero, 0, false, numeric_limits<int>::min(), numeric_limits<int>::max());
                tablero.deshacerMovimiento(i, j);

                if (valorMovimiento > mejorValor) {
                    mejorValor = valorMovimiento;
                    mejorMovimiento = {i, j};
                }
            }
        }
    }
    return mejorMovimiento;
}

