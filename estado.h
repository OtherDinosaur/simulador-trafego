#ifndef ESTADO_H
#define ESTADO_H

#define LINHAS 20
#define COLUNAS 70

#include <pthread.h>



typedef struct Estado {
    pthread_mutex_t mutexTick;
    pthread_cond_t condTick;
    pthread_mutex_t mutexMapa;
    pthread_mutex_t ocupacao[LINHAS][COLUNAS];
    int tick;

} Estado;

#endif