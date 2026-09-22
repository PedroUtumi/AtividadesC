// CINCO - Leia 10 números inteiros e determine qual é o maior valor armazenado no vetor.

#include <stdio.h>

int descobrirMaiorValor(const int tamMax, int numeros[tamMax]) {
    int maior = 0;
    
    for (int i = 0; i < tamMax; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
    }

    return maior;
}

int main() {
    const int tamMax = 10;
    int numeros[tamMax];

    for (int i = 0; i < tamMax; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    int maiorValor = descobrirMaiorValor(tamMax, numeros);
    printf("Maior valor da lista: %d", maiorValor);

    return 0;
}