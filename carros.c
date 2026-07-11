#include "estado.h"
#include "carros.h"
#include "mapa.h"
#include "semaforo.h"
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
        
        if (ultimoTick % carro->velocidade == 0) {
            
            pthread_mutex_lock(&estado->mutexMapa);
            anda_carro(carro);
            pthread_mutex_unlock(&estado->mutexMapa);
        }
    }

    return NULL;
    
}

void anda_carro(Carro *carro) {
    
    Estado *estado = carro->estado;
    int novaLin = carro->lin;
    int novaCol = carro->col;

    if (carro->id == -1) {
        return;
    }


    if (carro->direcao == 11) {
        novaCol++;
    } else if (carro->direcao == 12) {
        novaCol--;
    } else if (carro->direcao == 21) {
        novaLin--;
    } else if (carro->direcao == 22) {
        novaLin++;
    }

    if (novaLin >= LINHAS - 1 || novaCol >= COLUNAS - 1 || novaLin <= 1 || novaCol <= 1) {
        printf("Carro %d saiu do mapa!\n", carro->id);
        carro->id = -1; // Marca o carro como removido
        pthread_mutex_unlock(&estado->ocupacao[carro->lin][carro->col]);
    }
    Semaforo *sem = buscaSemaforo(estado, novaLin, novaCol);

    int horizontal = (carro->direcao / 10 == 1);

    if (!carro->ambulancia){
        if (sem != NULL && sem->cor == 1 && horizontal) {
            return;
        } else if (sem != NULL && sem->cor == 0 && !horizontal) {
            return;
        }
    }

 
    if (pthread_mutex_trylock(&estado->ocupacao[novaLin][novaCol]) == 0) {
        pthread_mutex_unlock(&estado->ocupacao[carro->lin][carro->col]);
        carro->lin = novaLin;
        carro->col = novaCol;
    }
}