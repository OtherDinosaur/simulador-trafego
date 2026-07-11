#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mapa.h"
#include "carros.h"
#include "relogio.h"
#include "estado.h"
#include "inicializador.h"


char tela[LINHAS][COLUNAS];

int main(void)
{
    Estado estado;
    Carro carros[NUM_CARROS];
    estado.tick = 0;

    pthread_mutex_init(&estado.mutexTick, NULL);
    pthread_cond_init(&estado.condTick, NULL);
    pthread_mutex_init(&estado.mutexMapa, NULL);
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            pthread_mutex_init(&estado.ocupacao[i][j], NULL);
        }
    }
    pthread_t relogio;
    pthread_t veiculos[15]; // para threads dos carros

    inicializa_mapa();
    inicializaSemaforos(&estado);
    inicializaVeiculos(carros, &estado);
    pthread_create(&relogio, NULL, threadRelogio, &estado);

    //pthread_create(&veiculos[0], NULL, threadCarro, &carros[0]);
    for (int i = 0; i < NUM_CARROS; i++) {
        pthread_mutex_lock(&estado.ocupacao[carros[i].lin][carros[i].col]);
        pthread_create(&veiculos[i], NULL, threadCarro, &carros[i]);
        pthread_mutex_unlock(&estado.ocupacao[carros[i].lin][carros[i].col]);
    }
    

    /*pthread_join(relogio, NULL);

    for (int i = 0; i < 15; i++) {
        pthread_join(veiculos[i], NULL);
    }*/


    
    while (1) {
        printf("\033[H");
        pthread_mutex_lock(&estado.mutexMapa);
        imprime_tela(tela, carros, NUM_CARROS);
        pthread_mutex_unlock(&estado.mutexMapa);
        usleep(REFRESH_US);
    }
    return 0;
}
