#include <stdio.h>
#include <stdlib.h>

float calcularMaior(float *medicoes, int qtdeMedicoes) {
    float maiorMedicao = medicoes[0];
    for (int i = 0; i < qtdeMedicoes; i++) {
        if (maiorMedicao < medicoes[i]) maiorMedicao = medicoes[i]; 
    }
    return maiorMedicao;
}

int main() {
    int quantidadeMedicoes;

    do {
        printf("Digite a quantidade de medicoes: ");
        scanf("%d", &quantidadeMedicoes);
    } while (quantidadeMedicoes <= 0);
    
    float *medicoes = malloc(quantidadeMedicoes * sizeof(float));

    if (medicoes == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    for (int i = 0; i < quantidadeMedicoes; i++) {
        printf("Digite o %d valor medido: ", i + 1);
        scanf("%f", &medicoes[i]);        
    }

    float maiorMedicao = calcularMaior(medicoes, quantidadeMedicoes);
    printf("Maior medicao realizada: %.2f\n", maiorMedicao);

    free(medicoes);

    return 0;
}