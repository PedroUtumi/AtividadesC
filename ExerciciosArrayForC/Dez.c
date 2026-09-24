// DEZ - Leia dois vetores, A e B, contendo 10 números inteiros cada. Crie um terceiro vetor C, no qual cada posição seja a soma dos elementos correspondentes de A e B. Exemplo: C[0] = A[0] + B[0].

#include <stdio.h>
#define TAM_MAX 10

int numerosA[TAM_MAX];
int numerosB[TAM_MAX];

int multiplicar(int index) {    
    return numerosA[index] * numerosB[index];
}

int main() {
    int numerosC[TAM_MAX];
    for (int i = 0; i < TAM_MAX; i++) {
        printf("Digite o valor %d do vetor A: ", i + 1);
        scanf("%d", &numerosA[i]);
    }

    for (int i = 0; i < TAM_MAX; i++) {
        printf("Digite o valor %d do vetor B: ", i + 1);
        scanf("%d", &numerosB[i]);
    }

    for (int i = 0; i < TAM_MAX; i++) {
        int valor = multiplicar(i);
        numerosC[i] = valor; 
    }

    for (int i = 0; i < TAM_MAX; i++) {
        printf("Valores vetor C(A x B): %d \n", numerosC[i]);
    }

    return 0;
}