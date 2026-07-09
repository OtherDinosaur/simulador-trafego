#ifndef CARROS_H
#define CARROS_H

#include <pthread.h>
#include "estado.h"

typedef struct Carro {
    int id;
    int lin;
    int col;
    int direcao; // 1X -> horizontal, 2X -> vertical, X1 -> direita/cima, X2 -> esquerda/baixo
    int velocidade; // 1, 2 ou 4 ticks
    int Ambulancia;
    pthread_t thread;
    Estado *estado;
} Carro;


void *threadCarro(void *arg);

void anda_carro(Carro *carro);


#endif