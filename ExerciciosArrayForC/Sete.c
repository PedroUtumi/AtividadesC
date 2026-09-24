// SETE - Leia 15 números inteiros e armazene-os em um vetor. Ao final, informe quantos números são pares e quantos são ímpares.

#include <stdio.h>
#define TAM_MAX 15

int numeros[TAM_MAX];

int descobrirParesImpares(int index) {
    int par = 0;
    int impar = 1;
    return numeros[index] % 2 == 0 ? par : impar;
}

int main() {
    for (int i = 0; i < TAM_MAX; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    for (int i = 0; i < TAM_MAX; i++) {
        int parImpar = descobrirParesImpares(i);
        if (parImpar == 0) {
            printf("Valor %d eh par \n", numeros[i]);
        } else {
            printf("Valor %d eh impar \n", numeros[i]);
        }
    }


    return 0;
}