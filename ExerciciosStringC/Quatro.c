// Exercício 4 - Leia uma palavra e uma letra. Informe quantas vezes essa letra aparece na palavra.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAMANHO_PALAVRA 100

int main() {
    char palavra[TAMANHO_PALAVRA] = {0};
    char letra;
    int quantidade = 0;

    printf("Escreva uma palavra de ate 100 caracteres: ");
    scanf("%99s", &palavra);
    
    printf("Escreva uma letra para procurar: ");
    scanf(" %c", &letra);

    letra = toupper(letra);

    for (int i = 0; i < strlen(palavra); i++) {
        palavra[i] = toupper(palavra[i]);
        if (palavra[i] == letra) quantidade++;
    }

    printf("A palavra %s tem %d letra(s) %c", palavra, quantidade, letra);

    return 0;
}