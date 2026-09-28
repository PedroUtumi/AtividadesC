// QUINZE - Leia 10 números inteiros. Depois, utilizando laços for, apresente cada valor apenas uma vez, mesmo que ele tenha sido digitado várias vezes

#include <stdio.h>
#define TAM_MAX 10

int numeros[TAM_MAX];

int main() {
    for (int i = 0; i < TAM_MAX; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("Valores sem repeticao: \n");

    for (int i = 0; i < TAM_MAX; i++) {
        int apareceu = 0;
        for (int j = 0; j < i; j++) {
            if (numeros[i] == numeros[j]) {
                apareceu = 1;
                break;
            }
        }
        if (!apareceu) {
            printf("Valor: %d \n", numeros[i]);
        }
    }

    return 0;
}