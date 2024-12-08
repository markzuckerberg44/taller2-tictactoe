#include "Tablero.h"
#include "IA_Minimax.h"
#include <iostream>
using namespace std;

int main() {
    Tablero tablero;
    IA_Minimax ia;

    int turno = 0; // 0: Humano, 1: IA
    cout << "Juego del Gato: Humano vs Maquina\n";

    while (tablero.hayMovimientos() && tablero.evaluar() == 0) {
        tablero.mostrar();
        if (turno == 0) {
            int fila, columna;
            cout << "Tu turno. Ingresa fila y columna (ejemplo: 1 1): ";
            cin >> fila >> columna;
            if (!tablero.realizarMovimiento(fila, columna, JUGADOR)) {
                cout << "Movimiento invalido. Intenta de nuevo.\n";
            } else {
                turno = 1;
            }
        } else {
            cout << "Turno de la maquina...\n";
            pair<int, int> movimiento = ia.mejorMovimiento(tablero);
            tablero.realizarMovimiento(movimiento.first, movimiento.second, IA);
            turno = 0;
        }
    }

    tablero.mostrar();
    int resultado = tablero.evaluar();
    if (resultado == 10) cout << "La maquina gano.\n";
    else if (resultado == -10) cout << "Ganaste!\n";
    else cout << "Es un empate.\n";

    return 0;
}

