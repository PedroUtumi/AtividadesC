// QUATRO - Leia as notas de 10 alunos e armazene-as em um vetor. Calcule e apresente a média da turma. Depois, mostre quais notas são maiores ou iguais à média.

#include <stdio.h>

float calcularMediaGeral(const int tamMax, float listaNotas[tamMax]) {
    float mediaGeral = 0;

    for (int i = 0; i < tamMax; i++) {
        mediaGeral = mediaGeral + listaNotas[i];
    }
    mediaGeral = mediaGeral / tamMax;
    
    return mediaGeral;    
}

int calcularQuantidadeMaiorIgualMedia(const int tamMax, float listaNotas[tamMax], float mediaGeral) {
    int quantidade = 0;

    for (int i = 0; i < tamMax; i++) {
        if (listaNotas[i] >= mediaGeral) {
            quantidade++;    
        }
    }
    
    return quantidade;
}

float calcularNotaMaiorIgualMedia(const int tamMax, float listaNotas[tamMax], float mediaGeral, int index) {
    return listaNotas[index] >= mediaGeral ? listaNotas[index] : -1;
}

int main() {
    const int tamMax = 10;
    float listaNotas[tamMax];

    for (int i = 0; i < tamMax; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &listaNotas[i]);
    }

    float mediaGeral = calcularMediaGeral(tamMax, listaNotas);
    int quantidade = calcularQuantidadeMaiorIgualMedia(tamMax, listaNotas, mediaGeral);
    float notasMaioresIguaisMedia[quantidade];

    int j = 0;
    for (int i = 0; i < tamMax; i++) {
        float nota = calcularNotaMaiorIgualMedia(tamMax, listaNotas, mediaGeral, i);
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