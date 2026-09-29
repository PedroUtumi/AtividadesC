// Exercício 3 -  Leia uma palavra e informe a quantidade de vogais existentes.

#include <stdio.h>
#include <ctype.h>
#define TAMANHO_PALAVRA 100

int main() {
    char palavra[TAMANHO_PALAVRA] = {0};
    int quantidadeVogais = 0;

    printf("Escreva uma palavra de ate 100 caracteres: ");
    scanf("%99s", palavra);

    for (int i = 0; i < TAMANHO_PALAVRA; i++) {
        if (palavra[i] != 0) {
            palavra[i] = toupper(palavra[i]);
            switch (palavra[i])
            {
            case 'A':
                quantidadeVogais++;
                break;
            case 'E':
                quantidadeVogais++;
                break;
            case 'I':
                quantidadeVogais++;
                break;
            case 'O':
                quantidadeVogais++;
                break;
            case 'U':
                quantidadeVogais++;
                break;
            }
        }
        else break;
    }

    printf("A palavra %s tem %d vogais", palavra, quantidadeVogais);

    return 0;
}