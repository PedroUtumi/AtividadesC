// QUATORZE - Leia 10 números inteiros e determine o maior e o menor valor armazenados. Em seguida, apresente a diferença entre o maior e o menor.     

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

int descobrirMenorValor() {
    int menor = numeros[0];
    
    for (int i = 0; i < TAM_MAX; i++) {
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }

    return menor;
}

int main() {
    for (int i = 0; i < TAM_MAX; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    int maior = descobrirMaiorValor(); 
    int menor = descobrirMenorValor();

    int diferenca = maior - menor;

    printf("Maior valor: %d | Menor valor: %d | Diferenca: %d \n", maior, menor, diferenca);
    return 0;
}
