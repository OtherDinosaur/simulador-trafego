#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LINHAS 20
#define COLUNAS 70
char mapa[LINHAS][COLUNAS];

void inicializa_mapa(void)
{
    int i, j;

    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            mapa[i][j] = ' ';
            if (i == 0 || i == LINHAS - 1 || j == 0 || j == COLUNAS - 1) {
                mapa[i][j] = '#'; /* Desenha as bordas do mapa */
            }
        }
    }

    /* Desenha estradas horizontais no meio do mapa */
    for (j = 1; j < COLUNAS - 1; j++) {
        mapa[4][j] = '>';
        mapa[5][j] = '<';
        mapa[9][j] = '>';
        mapa[10][j] = '<';
        mapa[14][j] = '>';
        mapa[15][j] = '<';
    }

    /* Desenha estradas verticais */
    for (int i = 1; i < LINHAS - 1; i++) {
        mapa[i][20] = '|';
        mapa[i][21] = '|';
        mapa[i][35] = '|';
        mapa[i][36] = '|';
        mapa[i][50] = '|';
        mapa[i][51] = '|';
    }

    /* Marca os cruzamentos com '+' */
    for (int i = 4; i <= 15; i += 5) {
        mapa[i][20] = '+';
        mapa[i][21] = '+';
        mapa[i][35] = '+';
        mapa[i][36] = '+';
        mapa[i][50] = '+';
        mapa[i][51] = '+';
        mapa[i+1][20] = '+';
        mapa[i+1][21] = '+';
        mapa[i+1][35] = '+';
        mapa[i+1][36] = '+';
        mapa[i+1][50] = '+';
        mapa[i+1][51] = '+';
    }

}

void imprime_mapa(void)
{
    int i, j;

    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            putchar(mapa[i][j]);
        }
        putchar('\n');
    }
}