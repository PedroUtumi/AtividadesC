#include <stdio.h>

#define QUANTIDADE_LINHAS 5
#define QUANTIDADE_COLUNAS 4

#define CADASTRAR_TEMPERATURAS 1
#define EXIBIR_TEMPERATURAS 2
#define BUSCAR_TEMPERATURAS 3
#define CALCULAR_MEDIAS 4
#define MAIOR_MENOR_DIFERENCA 5
#define ATUALIZAR_TEMPERATURAS 6
#define EXIBIR_ALERTAS 7
#define EXIBIR_SIMULACAO 8

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
            return -1;
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

void buscarMaiorTemperatura(float temperaturas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS]) {
    float maior = temperaturas[0][0];
    int pc = 1;
    int horario = 0;
    for (int i = 0; i < QUANTIDADE_LINHAS; i++) {
        for (int j = 0; j < QUANTIDADE_COLUNAS; j++) {
            if (temperaturas[i][j] > maior) {
                maior = temperaturas[i][j];
                pc = i + 1;
                horario = j;
            } 
        }
    }
    printf("Maior valor encontrado no PC %d as %dh \n", pc, acharHorario(horario));
}

void buscarMenorTemperatura(float temperaturas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS]) {
    float menor = temperaturas[0][0];
    int pc = 1;
    int horario = 0;
    for (int i = 0; i < QUANTIDADE_LINHAS; i++) {
        for (int j = 0; j < QUANTIDADE_COLUNAS; j++) {
            if (temperaturas[i][j] < menor) {
                menor = temperaturas[i][j];
                pc = i + 1;
                horario = j;
            } 
        }
    }
    printf("Menor valor encontrado no PC %d as %dh \n", pc, acharHorario(horario));
}

void mostrarComputadorMaiorMedia(float mediaComputador[QUANTIDADE_LINHAS]) {
    float maior = mediaComputador[0];
    for (int i = 0; i < QUANTIDADE_LINHAS; i++) {
        if (mediaComputador[i] > maior) maior = mediaComputador[i]; 
    }
    printf("Maior media: %.2f\n", maior);
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
    mostrarComputadorMaiorMedia(mediaComputador);
}

void calcularMediaHorario(float temperaturas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS]) {
    float mediaHorario[QUANTIDADE_COLUNAS] = {0};
    
    for (int i = 0; i < QUANTIDADE_COLUNAS; i++) {
        for (int j = 0; j < QUANTIDADE_LINHAS; j++) {
            mediaHorario[i] = mediaHorario[i] + temperaturas[j][i];
        }
        mediaHorario[i] = mediaHorario[i] / QUANTIDADE_LINHAS;
        printf("Media do horario %dh: %.2f\n", acharHorario(i), mediaHorario[i]);
    }
}

void calcularMediaGeral(float temperaturas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS]) {
    float mediaGeral = 0;
    
    for (int i = 0; i < QUANTIDADE_LINHAS; i++) {
        for (int j = 0; j < QUANTIDADE_COLUNAS; j++) {
            mediaGeral = mediaGeral + temperaturas[i][j];
        }
    }
    mediaGeral = mediaGeral / (QUANTIDADE_COLUNAS * QUANTIDADE_LINHAS);
    printf("Media geral: %.2f\n", mediaGeral);
}

void contarMedicoesAcima70Graus(float temperaturas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS]) {
    int contador = 0;
    
    for (int i = 0; i < QUANTIDADE_LINHAS; i++) {
        for (int j = 0; j < QUANTIDADE_COLUNAS; j++) {
            if (temperaturas[i][j] > 70.0) contador++;
        }
    }

    printf("Quantas temperaturas acima de 70 C existem: %d\n", contador);
}

void alterarMatrizTemperaturas(float temperaturas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS], int pc, int horario, float novaTemperatura) {
    if (pc < 1 || pc > QUANTIDADE_LINHAS || horario < 0 || horario >= QUANTIDADE_COLUNAS) {
        printf("PC ou horario invalido!\n");
        return;
    }
    temperaturas[pc - 1][horario] = novaTemperatura;
    
};

void lerTemperaturasCriticas(float temperaturas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS], int matrizTemperaturasCriticas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS]) {
    for (int i = 0; i < QUANTIDADE_LINHAS; i++) {
        for (int j = 0; j < QUANTIDADE_COLUNAS; j++) {
            if (temperaturas[i][j] > 70) matrizTemperaturasCriticas[i][j] = 1;
            else matrizTemperaturasCriticas[i][j] = 0;
        }
    }
}

void detectarSuperaquecimento(int matrizTemperaturasCriticas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS]) {
    int computadoresSuperaquecidos[QUANTIDADE_LINHAS] = {0};
    for (int i = 0; i < QUANTIDADE_LINHAS; i++) {
        int contador = 0;
        for (int j = 0; j < QUANTIDADE_COLUNAS; j++) {
            if (matrizTemperaturasCriticas[i][j] == 1) {
                contador++;
                if (contador == 2) printf("PC %d superaquecido\n", i + 1);
            }
        }
    }
}

void calcularDiferencaTemperaturaComputador(float temperaturas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS]) {
    for (int i = 0; i < QUANTIDADE_LINHAS; i++) {
        float maior = temperaturas[i][0];
        float menor = temperaturas[i][0];
        
        for (int j = 0; j < QUANTIDADE_COLUNAS; j++) {
            if (temperaturas[i][j] > maior) maior = temperaturas[i][j];
            else if (temperaturas[i][j] < menor) menor = temperaturas[i][j];
        }
        printf("Diferenca entre o maior e o menor valor do PC %d: %.2f\n", i + 1, maior - menor);
    }
}

void simulacaoResfriamento(float temperaturas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS]) {
    float resfriamento[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS];
    for (int i = 0; i < QUANTIDADE_LINHAS; i++) {
        for (int j = 0; j < QUANTIDADE_COLUNAS; j++) resfriamento[i][j] = 0.9 * temperaturas[i][j];
    }
    exibirTemperaturas(resfriamento);
}

void menuInterativo(float temperaturas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS], int opcao) {
    switch (opcao) {
        case CADASTRAR_TEMPERATURAS: {
            lerTemperaturas(temperaturas);
            break;
        }
    
        case EXIBIR_TEMPERATURAS: {
            exibirTemperaturas(temperaturas);
            break;
        }

        case BUSCAR_TEMPERATURAS: {
            float valorBusca;
            printf("Digite um valor para buscar: ");
            scanf("%f", &valorBusca);
            buscarTemperaturas(temperaturas, valorBusca);
            break;
        }

        case CALCULAR_MEDIAS: {
            calcularMediaComputador(temperaturas);
            calcularMediaGeral(temperaturas);
            calcularMediaHorario(temperaturas);
            break;
        }

        case MAIOR_MENOR_DIFERENCA: {
            buscarMaiorTemperatura(temperaturas);
            buscarMenorTemperatura(temperaturas);
            calcularDiferencaTemperaturaComputador(temperaturas);
            break;
        }

        case ATUALIZAR_TEMPERATURAS: {
            int pc;
            printf("Digite um numero do pc para alterar valor: ");
            scanf("%d", &pc);
            
            int horario;
            printf("Digite o horario que vc quer alterar(0 = 8h | 1 = 11h | 2 = 14h | 3 = 17h): ");
            scanf("%d", &horario);
            
            float novaTemperatura;
            printf("Digite a nova temperatura: ");
            scanf("%f", &novaTemperatura);
            
            alterarMatrizTemperaturas(temperaturas, pc, horario, novaTemperatura);
            exibirTemperaturas(temperaturas);
            break;
        }

        case EXIBIR_ALERTAS: {
            contarMedicoesAcima70Graus(temperaturas);
            int matrizTemperaturasCriticas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS];
            lerTemperaturasCriticas(temperaturas, matrizTemperaturasCriticas);
            detectarSuperaquecimento(matrizTemperaturasCriticas);
            break;
        }

        case EXIBIR_SIMULACAO: {
            simulacaoResfriamento(temperaturas);
            break;
        }

        default:
            printf("Fechando programa...");
            break;
    }
}

int main() {
    float temperaturas[QUANTIDADE_LINHAS][QUANTIDADE_COLUNAS];
    int opcao;
    do {
        printf("1 - Cadastrar temperaturas\n");
        printf("2 - Exibir temperaturas\n");
        printf("3 - Buscar temperaturas\n");
        printf("4 - Calcular medias\n");
        printf("5 - Encontrar maior, menor e sua diferenca\n");
        printf("6 - Atualizar temperatura\n");
        printf("7 - Exibir alertas\n");
        printf("8 - Exibir simulacao de resfriamento\n");
        printf("0 - Sair\n");
        
        printf("Escolha sua opcao: ");
        scanf("%d", &opcao);
        
        printf("\n");

        menuInterativo(temperaturas, opcao);
    } while (opcao != 0);
    
    return 0;
}