// DOZE - Leia 10 números inteiros e armazene-os em um vetor. Depois, solicite ao usuário um número para pesquisa. Informe quantas vezes esse número aparece no vetor.

#include <stdio.h>
#define TAM_MAX 10

int numeros[TAM_MAX];

int descobrirPosicao(int numeroPesquisa, int index) {    
    return numeros[index] == numeroPesquisa ? index : TAM_MAX + 1;
}

int main() {
    int numeroPesquisa;
    int contador = 0;
    for (int i = 0; i < TAM_MAX; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("Digite o valor a ser pesquisado: ");
    scanf("%d", &numeroPesquisa);
    
    for (int i = 0; i < TAM_MAX; i++) {
        int posicao = descobrirPosicao(numeroPesquisa, i);
        if (posicao < TAM_MAX + 1) {
            contador = contador + 1;
        }
    }

    printf("Valor pesquisado aparece %d vezes", contador);


    return 0;
}