// QUATRO - Leia as notas de 10 alunos e armazene-as em um vetor. Calcule e apresente a média da turma. Depois, mostre quais notas são maiores ou iguais à média.

#include <stdio.h>
#define TAM_MAX 10

float listaNotas[TAM_MAX];

float calcularMediaGeral() {
    float mediaGeral = 0;

    for (int i = 0; i < TAM_MAX; i++) {
        mediaGeral = mediaGeral + listaNotas[i];
    }
    mediaGeral = mediaGeral / TAM_MAX;
    
    return mediaGeral;    
}

int calcularQuantidadeMaiorIgualMedia(float mediaGeral) {
    int quantidade = 0;

    for (int i = 0; i < TAM_MAX; i++) {
        if (listaNotas[i] >= mediaGeral) {
            quantidade++;    
        }
    }
    
    return quantidade;
}

float calcularNotaMaiorIgualMedia(float mediaGeral, int index) {
    return listaNotas[index] >= mediaGeral ? listaNotas[index] : -1;
}

int main() {
    for (int i = 0; i < TAM_MAX; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &listaNotas[i]);
    }

    float mediaGeral = calcularMediaGeral();
    int quantidade = calcularQuantidadeMaiorIgualMedia(mediaGeral);
    float notasMaioresIguaisMedia[quantidade];

    int j = 0;
    for (int i = 0; i < TAM_MAX; i++) {
        float nota = calcularNotaMaiorIgualMedia(mediaGeral, i);
        if (nota >= 0) {
            notasMaioresIguaisMedia[j] = nota;
            j++; 
        } 
    }
    
    printf("Media da Turma: %.2f \n", mediaGeral);

    for (int i = 0; i < quantidade; i++) {
        printf("Notas iguais ou maiores que a media: %.2f \n", notasMaioresIguaisMedia[i]);
    }

    return 0;
}