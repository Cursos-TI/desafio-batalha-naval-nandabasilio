#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < TAM; i++)
        for (j = 0; j < TAM; j++)
            tabuleiro[i][j] = AGUA;

    // Posiciona o navio 1 (horizontal) em (1,1)
    int l1 = 1, c1 = 1;
    for (i = 0; i < TAM_NAVIO; i++)
        tabuleiro[l1][c1 + i] = NAVIO;

    // Posiciona o navio 2 (vertical) em (4,5)
    int l2 = 4, c2 = 5;
    for (i = 0; i < TAM_NAVIO; i++)
        tabuleiro[l2 + i][c2] = NAVIO;

    // Exibe cabeçalho das colunas (letras)
    printf("   ");
    for (j = 0; j < TAM; j++)
        printf(" %c", 'A' + j);
    printf("\n");

    // Exibe o tabuleiro com números nas linhas e valores 0 e 3
    for (i = 0; i < TAM; i++) {
        printf("%2d ", i + 1);  // Número da linha (1 a 10)
        for (j = 0; j < TAM; j++) {
            printf(" %d", tabuleiro[i][j]);  // Mostra 0 (água) ou 3 (navio)
        }
        printf("\n");
    }

    return 0;
}
