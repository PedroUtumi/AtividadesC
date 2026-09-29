// Exercício 7 - Uma palavra é um palíndromo quando pode ser lida da mesma forma da esquerda para a direita e da direita para a esquerda. Faça um programa que leia uma palavra e informe se ela é um palíndromo.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAMANHO_MAXIMO_PALAVRA 100

int main() {
    char palavra[TAMANHO_MAXIMO_PALAVRA];
    char palavraReversa[TAMANHO_MAXIMO_PALAVRA];

    printf("Escreva uma palavra de ate 100 caracteres: ");
    scanf("%99s", &palavra);

    int tamanhoReal = strlen(palavra);
    int j = 0;

    for (int i = tamanhoReal - 1; i >= 0; i--) {
        palavra[i] = toupper(palavra[i]);
        palavraReversa[j] = palavra[i];
        j++;
    }
    palavraReversa[j] = '\0';

    if (strcmp(palavraReversa, palavra) == 0) {
        printf("As palavras %s e %s sao palindromos", palavra, palavraReversa);
    } else printf("As palavras %s e %s nao sao palindromos", palavra, palavraReversa);

    return 0;
}
