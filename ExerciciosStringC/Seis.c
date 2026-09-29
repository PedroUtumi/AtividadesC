// Exercício 6 - Leia uma palavra e apresente seus caracteres na ordem inversa.
#include <stdio.h>
#include <string.h>
#define TAMANHO_MAXIMO_PALAVRA 100

int main() {
    char palavra[TAMANHO_MAXIMO_PALAVRA];

    printf("Escreva uma palavra de ate 100 caracteres: ");
    scanf("%99s", &palavra);

    int tamanhoReal = strlen(palavra);

    for (int i = tamanhoReal - 1; i >= 0; i--) {
        printf("%c \n", palavra[i]);
    }

    return 0;
}