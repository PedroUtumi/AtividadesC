// SEIS - Leia 10 números inteiros. Informe o menor valor encontrado e a posição em que ele aparece no vetor.

#include <stdio.h>
#define TAM_MAX 10

int numeros[TAM_MAX];

int descobrirMenorValor() {
    int menor = numeros[0];
    
    for (int i = 0; i < TAM_MAX; i++) {
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }

    return menor;
}

int descobrirPosicaoMenorValor(int menorValor, int index) {    
    return numeros[index] == menorValor ? index : TAM_MAX + 1;
}

int main() {
    for (int i = 0; i < TAM_MAX; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    int menorValor = descobrirMenorValor();
    printf("Menor valor da lista: %d \n", menorValor);
    
    int j = 1;
    for (int i = 0; i < TAM_MAX; i++) {
        int posicao = descobrirPosicaoMenorValor(menorValor, i);
        if (posicao < TAM_MAX + 1) {
            printf("%d Posicao menor valor da lista: %d \n", j, posicao);
            j++;
        }
    }

    return 0;
}