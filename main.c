#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mapa.h"
#include "carros.h"




int main(void)
{
    inicializa_mapa();
    while (1) {
        system("clear");
        imprime_mapa();
        sleep(1);
    }
    return 0;
}
