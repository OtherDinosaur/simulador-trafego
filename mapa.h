#ifndef MAPA_H
#define MAPA_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "carros.h"

#define LINHAS 20
#define COLUNAS 70
extern char mapa[LINHAS][COLUNAS];

void inicializa_mapa();

void imprime_tela();


#endif