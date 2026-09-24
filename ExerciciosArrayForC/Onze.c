// ONZE - Leia 10 números inteiros para um vetor. Depois, mostre primeiro todos os números pares e, em seguida, todos os números ímpares.

#include <stdio.h>
#define TAM_MAX 10

int numeros[TAM_MAX];

void mostrarPares() {
    for (int i = 0; i < TAM_MAX; i++) {
        if (numeros[i] % 2 == 0) {
            printf("Numero Par: %d \n", numeros[i]);
        }
    }
}

void mostrarImpares() {
    for (int i = 0; i < TAM_MAX; i++) {
        if (numeros[i] % 2 != 0) {
            printf("Numero Impar: %d \n", numeros[i]);
        }
    }
}

int main() {

    for (int i = 0; i < TAM_MAX; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    mostrarPares();
    mostrarImpares();

    return 0;
}