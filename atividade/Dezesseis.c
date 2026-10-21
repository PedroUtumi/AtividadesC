#include <stdio.h>

float calcularMedia(float nota1, float nota2, float nota3) {
    return (nota1 + nota2 + nota3) / 3;
}

void exibirSituacao(float media) {
    const int APROVADO = 6;
    if (media >= APROVADO) {
        printf("Aluno foi aprovado\n");
    } else {
        printf("Aluno foi reprovado\n");
    }
}

int main() {
    float nota1, nota2, nota3;
    
    printf("Digite a primeira nota: ");
    scanf("%d", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%d", &nota2);
    printf("Digite a terceira nota: ");
    scanf("%d", &nota3);

    int media = calcularMedia(nota1, nota2, nota3);
    exibirSituacao(media);

    return 0;
}
