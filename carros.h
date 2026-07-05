void anda_carro(int *carroX, int *carroY, int direcao)
{
    mapa[*carroX][*carroY] = '-';
    if (direcao == 11) {
        (*carroY)++;
    } else if (direcao == 12) {
        (*carroY)--;
    } else if (direcao == 21) {
        (*carroX)++;
    } else if (direcao == 22) {
        (*carroX)--;
    }
    mapa[*carroX][*carroY] = 'C';
}