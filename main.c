#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mapa.h"
#include "carros.h"
#include "relogio.h"
#include "estado.h"


char tela[LINHAS][COLUNAS];

int main(void)
{
    Estado estado;
    Carro carros[15];
    estado.tick = 0;


    carros[0].id = 1;
    carros[0].lin = 4;
    carros[0].col = 4;
    carros[0].direcao = 11;
    carros[0].velocidade = 2;
    carros[0].Ambulancia = 0;
    carros[0].thread = 0;
    carros[0].estado = &estado;

    carros[1].id = 2;
    carros[1].lin = 5;
    carros[1].col = 65;
    carros[1].direcao = 12;
    carros[1].velocidade = 1;
    carros[1].Ambulancia = 0;
    carros[1].thread = 0;
    carros[1].estado = &estado;

    carros[2].id = 3;
    carros[2].lin = 1;
    carros[2].col = 20;
    carros[2].direcao = 22;
    carros[2].velocidade = 4;
    carros[2].Ambulancia = 0;
    carros[2].thread = 0;
    carros[2].estado = &estado;

    pthread_mutex_init(&estado.mutexTick, NULL);
    pthread_cond_init(&estado.condTick, NULL);
    pthread_mutex_init(&estado.mutexMapa, NULL);
    pthread_t relogio;
    pthread_t veiculos[15]; // para threads dos carros

    inicializa_mapa();
    
    pthread_create(&relogio, NULL, threadRelogio, &estado);

    //pthread_create(&veiculos[0], NULL, threadCarro, &carros[0]);
    for (int i = 0; i < 3; i++) {
        pthread_create(&veiculos[i], NULL, threadCarro, &carros[i]);
    }
    

    /*pthread_join(relogio, NULL);

    for (int i = 0; i < 15; i++) {
        pthread_join(veiculos[i], NULL);
    }*/


    
    while (1) {
        printf("\033[H");
        pthread_mutex_lock(&estado.mutexMapa);
        imprime_tela(tela, carros, 3);
        pthread_mutex_unlock(&estado.mutexMapa);
        usleep(REFRESH_US);
    }
    return 0;
}
