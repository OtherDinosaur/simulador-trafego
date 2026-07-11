#include "relogio.h"
#include "estado.h"
#include "semaforo.h"
#include "mapa.h"
#include <unistd.h>
#include <pthread.h>

void *threadRelogio(void *arg) {
    Estado *estado = (Estado *)arg;
    while (1) {
        
        usleep(TICK_US);

        pthread_mutex_lock(&estado->mutexTick);

        estado->tick++;

        pthread_cond_broadcast(&estado->condTick);

        pthread_mutex_unlock(&estado->mutexTick);

        if (estado->tick % 20 == 0) {
            pthread_mutex_lock(&estado->mutexMapa);
            for (int i = 0; i < NUM_SEMAFOROS; i++) {
                troca_cor(&estado->semaforo[i]);
            }
            pthread_mutex_unlock(&estado->mutexMapa);
        }
        char *mensagem;
        if (estado->semaforo[0].cor == 0) {
            mensagem = "semaforos agora estão verdes para horizontal <->\n";
        } else {
            mensagem = "semaforos agora estão verdes para vertical ^v   \n";
        }
        printf("%s", mensagem);
        
    }
}