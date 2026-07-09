#include "semaforo.h"
#include "estado.h"
#include "mapa.h"

void troca_cor(Semaforo *semaforo) {
    semaforo->cor = 1 - semaforo->cor; // Alterna entre 0 e 1
}

Semaforo *buscaSemaforo(Estado *estado, int lin, int col) {
    for (int i = 0; i < NUM_SEMAFOROS; i++) {
        if (estado->semaforo[i].lin == lin && estado->semaforo[i].col == col) {
            return &estado->semaforo[i];
        }
    }
    return NULL;
}

void inicializaSemaforos(Estado *estado) {
    int sem = 0;
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (mapa[i][j] == '+') {
                estado->semaforo[sem] = (Semaforo){.lin = i, .col = j, .cor = 0, .periodo = 20};
                sem++;
            }
        }
    }
}