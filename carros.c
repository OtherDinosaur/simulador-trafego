#include "estado.h"
#include "carros.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define LINHAS 20
#define COLUNAS 70

void *threadCarro(void *arg) {
    Carro *carro = (Carro *) arg;
    Estado *estado = carro->estado;
    int ultimoTick = 0;
    while (1) {
        pthread_mutex_lock(&estado->mutexTick);

        while (ultimoTick == estado->tick) {
            pthread_cond_wait(&estado->condTick, &estado->mutexTick);

        }

        ultimoTick = estado->tick;
        pthread_mutex_unlock(&estado->mutexTick);
        
        if (estado->tick % carro->velocidade == 0) {    
            pthread_mutex_lock(&estado->mutexMapa);       
            anda_carro(carro);
            pthread_mutex_unlock(&estado->mutexMapa);
        }
    }

    return NULL;
    
}

void anda_carro(Carro *carro) {
    if (carro->id == -1) {
        return;
    }
    if (carro->direcao == 11) {
        carro->col++;
    } else if (carro->direcao == 12) {
        carro->col--;
    } else if (carro->direcao == 21) {
        carro->lin--;
    } else if (carro->direcao == 22) {
        carro->lin++;
    }
    if (carro->lin >= LINHAS - 1 || carro->col >= COLUNAS - 1 || carro->lin <= 1 || carro->col <= 1) {
        printf("Carro %d saiu do mapa!\n", carro->id);
        carro->id = -1; // Marca o carro como removido
        
    }
}