# Bem vindo ao simulador de tráfego em C

Simulador de tráfego em C elaborado para a disciplina de Sistemas Operacionais, compreendendo os conhecimentos em threads, mutexes e deadlocks. Maiores informações, vide relatório anexado à entrega do trabalho.

## Para executar:

Para bem executar o programa e visualizar o tráfego sem problemas, siga os seguintes passos:

1. Aumentar o tamanho do terminal, o grid do trânsito possui 20 linhas, fora notificações embaixo, então é recomendado espaço suficiente para pelo menos 25 linhas no terminal;

2. Mantenha todos os arquivos no mesmo diretório, para que os arquivos tenham o respectivo acesso;

3. Execute o comando `gcc carros.c inicializador.c main.c mapa.c relogio.c semaforo.c -pthread -o main` para compilar todos os arquivos do programa;

4. Limpe a tela com `clear` para evitar problemas na visualização da simulação;

5. execute `./main` para iniciar a simulação e visualizar os carros.

- Opcional: utilize ctrl + c para encerrar, pois o sistema foi projetado para execução contínua, mesmo que todos os carros saiam do mapa.