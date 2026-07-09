#ifndef ESTADO_H
#define ESTADO_H

#include <pthread.h>

typedef struct Estado {
    pthread_mutex_t mutexTick;
    pthread_cond_t condTick;
    pthread_mutex_t mutexMapa;

    int tick;

} Estado;

#endif