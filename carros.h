

typedef struct {
    int id;
    int lin;
    int col;
    int direcao; // 1X -> horizontal, 2X -> vertical, X1 -> direita/cima, X2 -> esquerda/baixo
    int velocidade; // 1, 2 ou 4 ticks
    int Ambulancia;
    char anterior;
    pthread_t thread;
} Carro;

Carro carros[15];

void anda_carro(Carro *carro) {
    if (carro->id == -1) {
        return;
    }
    mapa[carro->lin][carro->col] = carro->anterior;
    if (carro->direcao == 11) {
        carro->col++;
    } else if (carro->direcao == 12) {
        carro->col--;
    } else if (carro->direcao == 21) {
        carro->lin++;
    } else if (carro->direcao == 22) {
        carro->lin--;
    }
    if (carro->lin >= LINHAS - 1 || carro->col >= COLUNAS - 1 || carro->lin <= 1 || carro->col <= 1) {
        printf("Carro %d saiu do mapa!\n", carro->id);
        carro->id = -1; // Marca o carro como removido
        mapa[carro->lin][carro->col] = carro->anterior;
        exit(1);
        
    }
    carro->anterior = mapa[carro->lin][carro->col];
    mapa[carro->lin][carro->col] = 'C';
}