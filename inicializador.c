#include "inicializador.h"

void inicializaVeiculos(Carro carros[], Estado *estado)
{
    carros[0] = (Carro){
        .id = 1,
        .lin = 5,
        .col = 4,
        .direcao = 11,
        .velocidade = 2,
        .ambulancia = 0,
        .thread = 0,
        .estado = estado
    };
    carros[1] = (Carro){
        .id = 2,
        .lin = 4,
        .col = 65,
        .direcao = 12,
        .velocidade = 1,
        .ambulancia = 0,
        .thread = 0,
        .estado = estado
    };
    carros[2] = (Carro){
        .id = 3,
        .lin = 4,
        .col = 50,
        .direcao = 12,
        .velocidade = 4,
        .ambulancia = 0,
        .thread = 0,
        .estado = estado
    };

    carros[3] = (Carro){
        .id = 4,
        .lin = 19,
        .col = 36,
        .direcao = 21,
        .velocidade = 4,
        .ambulancia = 0,
        .thread = 0,
        .estado = estado
    };
    carros[4] = (Carro){
        .id = 5,
        .lin = 9,
        .col = 52,
        .direcao = 12,
        .velocidade = 1,
        .ambulancia = 1,
        .thread = 0,
        .estado = estado
    };
    carros[5] = (Carro){
        .id = 6,
        .lin = 1,
        .col = 50,
        .direcao = 22,
        .velocidade = 2,
        .ambulancia = 0,
        .thread = 0,
        .estado = estado
    };
    carros[6] = (Carro){
        .id = 7,
        .lin = 3,
        .col = 50,
        .direcao = 22,
        .velocidade = 2,
        .ambulancia = 1,
        .thread = 0,
        .estado = estado
    };
    carros[7] = (Carro){
        .id = 8,
        .lin = 18,
        .col = 20,
        .direcao = 21,
        .velocidade = 2,
        .ambulancia = 0,
        .thread = 0,
        .estado = estado
    };
    carros[8] = (Carro){
        .id = 9,
        .lin = 18,
        .col = 21,
        .direcao = 21,
        .velocidade = 2,
        .ambulancia = 1,
        .thread = 0,
        .estado = estado
    };
    carros[9] = (Carro){
        .id = 10,
        .lin = 14,
        .col = 30,
        .direcao = 12,
        .velocidade = 4,
        .ambulancia = 0,
        .thread = 0,
        .estado = estado
    };
    carros[10] = (Carro){
        .id = 11,
        .lin = 15,
        .col = 4,
        .direcao = 11,
        .velocidade = 1,
        .ambulancia = 0,
        .thread = 0,
        .estado = estado
    };
}