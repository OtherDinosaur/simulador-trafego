#include "relogio.h"
#include "estado.h"
#include <pthread.h>

void *threadRelogio(void *arg) {
    Estado *estado = (Estado *)arg;
    while (1) {
        
        usleep(TICK_US);

        pthread_mutex_lock(&estado->mutexTick);

        estado->tick++;

        pthread_cond_broadcast(&estado->condTick);

        pthread_mutex_unlock(&estado->mutexTick);

    }
}