//
// Created by julih on 07-12-2024.
//

#include "Tablero.h"
using namespace std;

Tablero::Tablero() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            tablero[i][j] = VACIO;
}

void Tablero::mostrar() const {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << tablero[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  -+-+-\n";
    }
}

bool Tablero::hayMovimientos() const {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (tablero[i][j] == VACIO)
                return true;
    return false;
}

int Tablero::evaluar() const {
    // Revisar filas y columnas
    for (int i = 0; i < 3; ++i) {
        if (tablero[i][0] != VACIO && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2])
            return (tablero[i][0] == IA) ? 10 : -10;
        if (tablero[0][i] != VACIO && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i])
            return (tablero[0][i] == IA) ? 10 : -10;
    }
    // Revisar diagonales
    if (tablero[0][0] != VACIO && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])
        return (tablero[0][0] == IA) ? 10 : -10;
    if (tablero[0][2] != VACIO && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
        return (tablero[0][2] == IA) ? 10 : -10;

    return 0;
}

bool Tablero::realizarMovimiento(int fila, int columna, char jugador) {
    if (fila >= 0 && fila < 3 && columna >= 0 && columna < 3 && tablero[fila][columna] == VACIO) {
        tablero[fila][columna] = jugador;
        return true;
    }
    return false;
}

void Tablero::deshacerMovimiento(int fila, int columna) {
    tablero[fila][columna] = VACIO;
}

char Tablero::obtenerCelda(int fila, int columna) const {
    return tablero[fila][columna];
}