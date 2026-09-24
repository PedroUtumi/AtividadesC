// CINCO - Leia 10 números inteiros e determine qual é o maior valor armazenado no vetor.

#include <stdio.h>
#define TAM_MAX 10

int numeros[TAM_MAX];

int descobrirMaiorValor() {
    int maior = numeros[0];
    
    for (int i = 0; i < TAM_MAX; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
    }

    return maior;
}

int main() {
    for (int i = 0; i < TAM_MAX; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    int maiorValor = descobrirMaiorValor();
    printf("Maior valor da lista: %d", maiorValor);

    return 0;
}