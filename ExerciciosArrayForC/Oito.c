// OITO - Leia 10 números reais. Mostre todos os números positivos armazenados e informe a quantidade de números negativos.

#include <stdio.h>
#define TAM_MAX 10

int numeros[TAM_MAX];

int descobrirQuantidadeNegativos() {
    int contadorNegativos = 0;
    
    for (int i = 0; i < TAM_MAX; i++) {
        if (numeros[i] < 0) {
            contadorNegativos = contadorNegativos + 1;
        }
    }

    return contadorNegativos;
}

void mostrarNumeroPositivo() {
    for (int i = 0; i < TAM_MAX; i++) {
        if (numeros[i] >= 0) {
            printf("Numero positivo da lista na posicao %d: %d \n", i, numeros[i]);    
        }
    }
}

int main() {
    for (int i = 0; i < TAM_MAX; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    mostrarNumeroPositivo();

    int quantidadeNegativos = descobrirQuantidadeNegativos();
    printf("Quantidade de negativos da lista: %d \n", quantidadeNegativos);

    return 0;
}