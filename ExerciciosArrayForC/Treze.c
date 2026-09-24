// TREZE - Leia 10 números inteiros. Substitua todos os valores negativos armazenados no vetor pelo número 0. Ao final, apresente o vetor modificado.

#include <stdio.h>
#define TAM_MAX 10

int numeros[TAM_MAX];

int SubstituirValorNegativo() {
    for (int i = 0; i < TAM_MAX; i++) {
        if (numeros[i] < 0) {
            numeros[i] = 0;
        }
    }
}

void mostrarVetor() {
    for (int i = 0; i < TAM_MAX; i++) {
        printf("Novo vetor posicao %d: %d \n", i, numeros[i]);
    }
}

int main() {
    for (int i = 0; i < TAM_MAX; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    SubstituirValorNegativo();
    mostrarVetor();

    return 0;
}