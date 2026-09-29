// Exercício 2 -  Leia uma palavra e informe quantos caracteres ela possui. Não utilize strlen().
#include <stdio.h>
#define TAMANHO_PALAVRA 10

int main() {
    char palavra[TAMANHO_PALAVRA] = {0};
    int quantidade = 0;

    printf("Escreva uma palavra de ate 100 caracteres: ");
    scanf("%99s", &palavra);

    for (int i = 0; i < TAMANHO_PALAVRA; i++) {
        if (palavra[i] != 0) quantidade++;
        else break;
    }

    printf("A palavra %s tem %d caracteres", palavra, quantidade);

    return 0;
}