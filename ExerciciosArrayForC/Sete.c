// Leia 15 números inteiros e armazene-os em um vetor. Ao final, informe quantos números são pares e quantos são ímpares.

#include <stdio.h>

int descobrirParesImpares(const int tamMax, int numeros[tamMax], int index) {
    int par = 0;
    int impar = 1;
    return numeros[index] % 2 == 0 ? par : impar;
}

int main() {
    const int tamMax = 15;
    int numeros[tamMax];

    for (int i = 0; i < tamMax; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    for (int i = 0; i < tamMax; i++) {
        int parImpar = descobrirParesImpares(tamMax, numeros, i);
        if (parImpar == 0) {
            printf("Valor %d eh par \n", numeros[i]);
        } else {
            printf("Valor %d eh impar \n", numeros[i]);
        }
    }


    return 0;
}