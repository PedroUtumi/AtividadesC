// NOVE - Leia 10 números inteiros para um vetor. Solicite também um número inteiro ao usuário. Crie um segundo vetor contendo cada elemento do primeiro vetor multiplicado pelo número informado. Apresente o novo vetor.

#include <stdio.h>
#define TAM_MAX 10

int numeros[TAM_MAX];

int multiplicar(int multiplicador, int index) {    
    return numeros[index] * multiplicador;
}

int main() {
    int multiplicador;
    int numerosMultiplicados[TAM_MAX];

    for (int i = 0; i < TAM_MAX; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("Digite o valor multiplicador: ");
    scanf("%d", &multiplicador);

    for (int i = 0; i < TAM_MAX; i++) {
        int valor = multiplicar(multiplicador, i);
        numerosMultiplicados[i] = valor; 
    }

    for (int i = 0; i < TAM_MAX; i++) {
        printf("Valores multiplicados: %d \n", numerosMultiplicados[i]);
    }
    
    return 0;
}