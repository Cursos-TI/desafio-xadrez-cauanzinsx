#include <stdio.h>

// Constantes de movimento
const int BISPO_PASSOS = 5;
const int TORRE_PASSOS = 5;
const int RAINHA_PASSOS = 8;

// Direções (ÁREA LIMPA DE CARACTERES INVISÍVEIS)
void cima() { printf("Cima\n"); }
void baixo() { printf("Baixo\n"); }
void esquerda() { printf("Esquerda\n"); }
void direita() { printf("Direita\n"); }

void linha(const char *titulo) { printf("\n--- %s ---\n", titulo); }

// Nível Novato
void nivelNovato() {
    linha("Nível Novato");

    printf("Bispo - Diagonal superior direita\n");
    for (int i = 0; i < BISPO_PASSOS; i++) {
        cima();
        direita();
    }

    printf("\nTorre - Direita\n");
    for (int i = 0; i < TORRE_PASSOS; i++) direita();

    printf("\nRainha - Esquerda\n");
    for (int i = 0; i < RAINHA_PASSOS; i++) esquerda();
}

// Nível Aventureiro
void nivelAventureiro() {
    linha("Nível Aventureiro");

    printf("Cavalo - Movimento em L (baixo e esquerda)\n");
    for (int i = 0; i < 2; i++) baixo();

    int j = 0;
    while (j < 1) {
        esquerda();
        j++;
    }
}

// Funções Recursivas (Nível Mestre)
void torreRecursiva(int n) {
    if (n == 0) return;
    direita();
    torreRecursiva(n - 1);
}

void rainhaRecursiva(int n) {
    if (n == 0) return;
    esquerda();
    rainhaRecursiva(n - 1);
}

void bispoRecursivo(int n) {
    if (n == 0) return;
    cima();
    direita();
    bispoRecursivo(n - 1);
}

void nivelMestre() {
    linha("Nível Mestre");

    printf("Bispo - Diagonal direita para cima\n");
    bispoRecursivo(BISPO_PASSOS);

    printf("\nTorre - Direita\n");
    torreRecursiva(TORRE_PASSOS);

    printf("\nRainha - Esquerda\n");
    rainhaRecursiva(RAINHA_PASSOS);

    printf("\nCavalo - Movimento em L (cima e direita)\n");
    for (int i = 0, k = 0; i < 2; i++, k++) {
        if (k == 1) continue;
        cima();
    }
    int c = 0;
    while (c < 1) {
        direita();
        c++;
    }
}

int main() {
    printf("MateCheck - Desafio de Xadrez\n");

    nivelNovato();
    nivelAventureiro();
    nivelMestre();

    printf("\nDesafio concluído.\n");
    return 0;
}