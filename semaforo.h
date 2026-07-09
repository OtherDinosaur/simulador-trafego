#ifndef SEMAFORO_H
#define SEMAFORO_H

#include <pthread.h>

typedef struct Estado Estado;

typedef struct Semaforo {
    int lin;
    int col;
    int cor; // 0 = verde para horizontal, 1 = verde para vertical
    int periodo;     // em ticks

} Semaforo;

void troca_cor(Semaforo *semaforo);
Semaforo *buscaSemaforo(Estado *estado, int lin, int col);
void inicializaSemaforos(Estado *estado);


#endif