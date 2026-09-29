// Exercício 5 - Leia uma palavra e substitua todas as ocorrências da letra a por @.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAMANHO_PALAVRA 100

int main() {
    char palavra[TAMANHO_PALAVRA] = {0};
    int quantidade = 0;

    printf("Escreva uma palavra de ate 100 caracteres: ");
    scanf("%99s", &palavra);

    for (int i = 0; i < strlen(palavra); i++) {
        palavra[i] = toupper(palavra[i]);
        if (palavra[i] == 'A') palavra[i] = '@';
    }

    printf("Nova palavra: %s", palavra);

    return 0;
}
