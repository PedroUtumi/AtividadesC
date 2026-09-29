// Exercício 1 - Leia uma palavra e imprima cada caractere em uma linha.
#include <stdio.h>
#include <string.h>

int main() {
    char palavra[100];

    printf("Escreva uma palavra de ate 100 caracteres: ");
    scanf("%99s", &palavra);

    for (int i = 0; i < strlen(palavra); i++) {
        printf("%c \n", palavra[i]);
    }

    return 0;
}