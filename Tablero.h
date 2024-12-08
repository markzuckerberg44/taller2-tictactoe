//
// Created by julih on 07-12-2024.
//

#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include <iostream>

const char JUGADOR = 'X';
const char IA = 'O';
const char VACIO = ' ';

class Tablero {
private:
    char tablero[3][3];

public:
    Tablero();
    void mostrar() const;
    bool hayMovimientos() const;
    int evaluar() const;
    bool realizarMovimiento(int fila, int columna, char jugador);
    void deshacerMovimiento(int fila, int columna);
    char obtenerCelda(int fila, int columna) const;
};

#endif
