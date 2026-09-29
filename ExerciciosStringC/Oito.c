// Exercício 8 -  Leia duas palavras e informe: qual possui maior quantidade de caracteres; e o tamanho de cada uma.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAMANHO_PALAVRA 100

int main() {
    char palavra1[TAMANHO_PALAVRA] = {0};
    char palavra2[TAMANHO_PALAVRA] = {0};
    int quantidadeCaractere1 = 0;
    int quantidadeCaractere2 = 0;

    printf("Escreva uma palavra de ate 100 caracteres: ");
    scanf("%99s", &palavra1);
    int tamanhoPalavra1 = strlen(palavra1);
    
    printf("Escreva outra palavra de ate 100 caracteres: ");
    scanf("%99s", &palavra2);
    int tamanhoPalavra2 = strlen(palavra2);

    if (tamanhoPalavra1 > tamanhoPalavra2) {
        printf("A palavra %s eh maior | Tamanho 1: %d | Tamanho 2: %d", palavra1, tamanhoPalavra1, tamanhoPalavra2);
    } else if (tamanhoPalavra1 == tamanhoPalavra2) {
        printf("As palavras sao iguais | Tamanho 1: %d | Tamanho 2: %d", palavra1, tamanhoPalavra1, tamanhoPalavra2);
    } else printf("A palavra %s eh maior | Tamanho 1: %d | Tamanho 2: %d", palavra2, tamanhoPalavra1, tamanhoPalavra2); 

    return 0;
}
