#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define MAR 0
#define NAVIO 3

// Função para inicializar o tabuleiro com valor 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = MAR;
        }
    }
}

// Função para verificar se é possível posicionar o navio sem sair do tabuleiro e sem sobreposição
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                        int linha, int coluna, char orientacao) {
    if (orientacao == 'H') { // Horizontal
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
            return 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != MAR)
                return 0;
        }
    } else if (orientacao == 'V') { // Vertical
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
            return 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != MAR)
                return 0;
        }
    }
    return 1;
}

// Função para posicionar um navio na matriz do tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                     int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else if (orientacao == 'V') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas e orientações dos navios
    int linhaNavio1 = 2, colunaNavio1 = 3; // Navio 1 - horizontal
    int linhaNavio2 = 5, colunaNavio2 = 7; // Navio 2 - vertical

    // Verifica e posiciona o primeiro navio
    if (podePosicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, 'H')) {
        posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, 'H');
    } else {
        printf("Erro ao posicionar o navio 1.\n");
    }

    // Verifica e posiciona o segundo navio
    if (podePosicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, 'V')) {
        posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, 'V');
    } else {
        printf("Erro ao posicionar o navio 2.\n");
    }

    // Exibe o tabuleiro final com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}
