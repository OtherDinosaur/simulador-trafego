#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mapa.h"
#include "carros.h"


pthread_mutex_t mutexTick;
pthread_cond_t condTick;

int tick = 0;



int main(void)
{
    carros[0].id = 1;
    carros[0].lin = 4;
    carros[0].col = 4;
    carros[0].direcao = 11;
    carros[0].velocidade = 1;
    carros[0].Ambulancia = 0;
    carros[0].thread = 0;
    carros[0].anterior = '>';

    inicializa_mapa();
    
    while (1) {
        system("clear");
        imprime_mapa();
        anda_carro(&carros[0]);
        sleep(1);
    }
    return 0;
}
