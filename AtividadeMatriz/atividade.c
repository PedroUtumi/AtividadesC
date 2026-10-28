
#include <stdio.h>
#define QUANTIDADE_LINHAS 5
#define QUANTIDADE_COLUNAS 4

void lerTemperaturas(float temperaturas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS]) {
    for (int i = 0; i < QUANTIDADE_LINHAS; i++) {
        for (int j = 0; j < QUANTIDADE_COLUNAS; j++) {
            do {
                printf("Digite o valor da temperatura[%d][%d]: ", i, j);
                scanf("%f", &temperaturas[i][j]);
            } while (temperaturas[i][j] < 0 || temperaturas[i][j] > 100);
        }
    }
}

void exibirTemperaturas(float temperaturas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS]) {
    printf("Computador\t08h\t11h\t14h\t17h\n");
    for (int i = 0; i < QUANTIDADE_LINHAS; i++) {
        printf("PC %d\t\t", i + 1);
        for (int j = 0; j < QUANTIDADE_COLUNAS; j++) {
            printf("%.2f\t", temperaturas[i][j]);
        }
    printf("\n");
    }
}

int acharHorario(int coluna) {
    int horario = 0;
    switch (coluna)
    {
        case 0:
            return horario = 8;
        case 1:
            return horario = 11;
        case 2:
            return horario = 14;
        case 3:
            return horario = 17;
        default:
            break;
    }
}

void buscarTemperaturas(float temperaturas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS], float valorBusca) {
    int contador = 0;
    for (int i = 0; i < QUANTIDADE_LINHAS; i++) {
        for (int j = 0; j < QUANTIDADE_COLUNAS; j++) {
            if (temperaturas[i][j] == valorBusca) {
                printf("Valor encontrado no PC %d as %dh \n", i + 1, acharHorario(j));
                contador++;
            }
        }
    }
    if (contador == 0) printf("Temperatura nao encontrada");
}

void calcularMediaComputador(float temperaturas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS]) {
    float mediaComputador[QUANTIDADE_LINHAS] = {0};
    
    for (int i = 0; i < QUANTIDADE_LINHAS; i++) {
        for (int j = 0; j < QUANTIDADE_COLUNAS; j++) {
            mediaComputador[i] = mediaComputador[i] + temperaturas[i][j];
        }
        mediaComputador[i] = mediaComputador[i] / QUANTIDADE_COLUNAS;
        printf("Media do PC %d: %.2f\n", i + 1, mediaComputador[i]);
    }

}

int main() {
    float temperaturas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS];
    float valorBusca;

    lerTemperaturas(temperaturas);
    exibirTemperaturas(temperaturas);

    printf("Digite um valor para buscar: ");
    scanf("%f", &valorBusca);

    buscarTemperaturas(temperaturas, valorBusca);

    return 0;
}