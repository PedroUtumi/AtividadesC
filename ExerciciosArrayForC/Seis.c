// SEIS - Leia 10 números inteiros. Informe o menor valor encontrado e a posição em que ele aparece no vetor.

#include <stdio.h>

int descobrirMenorValor(const int tamMax, int numeros[tamMax]) {
    int menor = 0;
    
    for (int i = 0; i < tamMax; i++) {
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }

    return menor;
}

int descobrirPosicaoMenorValor(const int tamMax, int numeros[tamMax], int menorValor, int index) {    
    return numeros[index] == menorValor ? index : 255;
}

int main() {
    const int tamMax = 10;
    int numeros[tamMax];

    for (int i = 0; i < tamMax; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    int menorValor = descobrirMenorValor(tamMax, numeros);
    printf("Menor valor da lista: %d \n", menorValor);
    
    int j = 1;
    for (int i = 0; i < tamMax; i++) {
        int posicao = descobrirPosicaoMenorValor(tamMax, numeros, menorValor, i);
        if (posicao < 255) {
            printf("%d Posicao menor valor da lista: %d \n", j, posicao);
            j++;
        }
    }

    return 0;
}