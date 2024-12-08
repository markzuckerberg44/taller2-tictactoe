#include "Tablero.h"
#include "IA_Minimax.h"
#include <iostream>
using namespace std;

void printRules(Tablero table) {
    cout<<"Reglas del juego gato:"<<endl;
    cout<<"1) El juego consta de turnos. El jugador uno siempre sera 'X' y el jugador 2 o la maquina sera 'O'."<<endl;
    cout<<"2) El tablero tendra una dispocicion de filas y columnas, en la que se debera ingresar en orden las posiciones, ejemplo: 1 0"<<endl;
    cout<<"3) El jugador o la IA que complete primero una fila, columna o diagonal de 3 sera quien gane, en caso de no se complete es un empate"<<endl;
    cout<<"A continuacion, se mostrara el tablero:"<<endl;
    table.mostrar();
}


int verificarNumero() {
    int numero;

    while(!(cin>>numero)) {
        cin.ignore(1000,'\n');
        cin.clear();
        cout<<"\rError al ingresar, por favor ingrese una de las opciones\n>";
    }
    return numero;
}

int main() {
    Tablero tablero;
    IA_Minimax ia;
    string spacing = "----------------------------------";
    string menu = "Juego del gato/tictactoe\n1) Reglas del juego del gato\n2) Jugador contra Jugador\n3) Jugador contra maquina";
    int turno = 0; // 0: Jugador 1, 1: IA o jugador 2
    int option = 0;
    bool iaOrPlayer2 = false; //false para jugador y true para ia
    while(option <2 || option>3) {
        cout<<spacing<<endl;
        cout<<menu<<endl;
        cout<<spacing<<endl;
        cout<<"Selecciona una opcion: "<<endl;
        option = verificarNumero();
        cin.ignore(1000,'\n');
        cin.clear();
        switch(option) {
            case 1:
                printRules(tablero);
            break;
            case 2:
                cout<<"Jugador vs jugador"<<endl;
            break;
            case 3:
                cout << "Humano vs Maquina\n";
                iaOrPlayer2 = true;
            break;
            default:
                break;
        }
    }


    while (tablero.hayMovimientos() && tablero.evaluar() == 0) {
        tablero.mostrar();
        if (turno == 0) {
            if(iaOrPlayer2) {
                cout << "Tu turno. Ingresa fila y columna (ejemplo: 1 1): ";
            }else {
                cout << "Turno del jugador 1. Ingrese fila y columna (ejemplo: 1 1): "<<endl;
            }
            int fila, columna;

            cin >> fila >> columna;
            if (!tablero.realizarMovimiento(fila, columna, JUGADOR)) {
                cout << "Movimiento invalido. Intenta de nuevo.\n";
            } else {
                turno = 1;
            }
        } else {
            if(iaOrPlayer2) {
                cout << "Turno de la maquina...\n";
                pair<int, int> movimiento = ia.mejorMovimiento(tablero);
                tablero.realizarMovimiento(movimiento.first, movimiento.second, IA);
                turno = 0;
            }else {
                int fila, columna;
                cout << "Turno del jugador 2. Ingrese fila y columna (ejemplo: 1 1): ";
                cin >> fila >> columna;
                //seguira la misma dispocicón que la IA
                if (!tablero.realizarMovimiento(fila, columna, IA)) {
                    cout << "Movimiento invalido. Intenta de nuevo.\n";
                } else {
                    turno = 0;
                }
            }

        }
    }

    tablero.mostrar();
    int resultado = tablero.evaluar();
    if(iaOrPlayer2) {
        if (resultado == 10) cout << "La maquina gano.\n";
        else if (resultado == -10) cout << "Ganaste!\n";
        else cout << "Es un empate.\n";
    }else {
        if (resultado == 10) cout << "Gano jugador 2!\n";
        else if (resultado == -10) cout << "Gano jugador 1!\n";
        else cout << "Es un empate.\n";
    }


    return 0;
}

