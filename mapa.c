#include <stdio.h>
#define LINHAS 20
#define COLUNAS 40

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

    /* Desenha uma estrada horizontal no meio do mapa */
    for (j = 0; j < COLUNAS; j++) {
        mapa[9][j] = '-';
        mapa[10][j] = '-';
    }

    /* Indicadores de sentido da estrada */
    mapa[9][0] = '>';
    mapa[10][COLUNAS - 1] = '<';
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

int main(void)
{
    inicializa_mapa();
    while (1) {
        clear_screen();
        imprime_mapa();
        sleep(1);
    }
    return 0;
}
