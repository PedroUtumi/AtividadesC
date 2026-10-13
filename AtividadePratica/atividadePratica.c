/*
Atividade prática (laboratório) - Desenvolva um programa para armazenar dinamicamente as
temperaturas coletadas por sensores. O programa deverá:
    1. solicitar a quantidade de sensores; V
    2. criar dinamicamente um vetor para armazenar as temperaturas; V
    3. verificar se a memória foi alocada corretamente; V
    4. realizar a leitura das temperaturas; V
    5. apresentar todas as temperaturas; V
    6. calcular a média; V
    7. apresentar a maior temperatura; V
    8. apresentar a menor temperatura; V
    9. perguntar se novos sensores serão adicionados; V
    10. caso necessário, utilizar realloc; V
    11. cadastrar as novas temperaturas; V
    12. apresentar novamente os resultados; V
    13. liberar toda a memória utilizada antes de encerrar o programa. V
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

struct Sensor {
    int codigo;
    float temperatura;
};

void cadastrarTemperaturas(struct Sensor *sensor, int inicio, int fim) {
    for (int i = inicio; i < fim; i++) {
        printf("Escreva o valor da temperatura %d: ", i + 1);
        scanf("%f", &sensor[i].temperatura);
    }
}

void mostrarTemperaturas(struct Sensor *sensor, int quantidadeSensores) {
    for (int i = 0; i < quantidadeSensores; i++) printf("Valor da temperatura %d: %.2f \n", i + 1, sensor[i].temperatura);
}

/*
Nestes blocos, as operações de calcular e apresentar a média, a maior e a menor temperatura estão separadas em funções distintas, 
cada uma com uma responsabilidade específica. Essa abordagem facilita a compreensão, a manutenção e a reutilização do código. 
Entretanto, cada função percorre o vetor separadamente, repetindo o laço for.
*/
/*
void mostrarMedia(struct Sensor *sensor, int quantidadeSensores) {
    float media = 0;

    for (int i = 0; i < quantidadeSensores; i++) {
        media = media + sensor[i].temperatura;
    }

    media = media / quantidadeSensores;
    printf("Media: %.2f \n", media);
}

void mostrarMaiorTemperatura(struct Sensor *sensor, int quantidadeSensores) {
    float maiorTemp = sensor[0].temperatura;

    for (int i = 0; i < quantidadeSensores; i++) {
        if (sensor[i].temperatura > maiorTemp) maiorTemp = sensor[i].temperatura;
    }

    printf("Maior temperatura registrada é: %.2f \n", maiorTemp);
}

void mostrarMenorTemperatura(struct Sensor *sensor, int quantidadeSensores) {
    float menorTemp = sensor[0].temperatura;

    for (int i = 0; i < quantidadeSensores; i++) {
        if (sensor[i].temperatura < menorTemp) menorTemp = sensor[i].temperatura;
    }

    printf("Menor temperatura registrada é: %.2f \n", menorTemp);
}
*/

/*
Neste bloco, as operações de calcular e apresentar a média, a maior e a menor temperatura estão reunidas em uma única função. 
Essa organização pode respeitar o princípio da responsabilidade única, pois todas essas operações estão relacionadas a um mesmo 
propósito: apresentar as estatísticas das temperaturas registradas. A função também percorre o vetor apenas uma vez para realizar 
os três cálculos, evitando a repetição dos laços for.  
*/
void mostrarEstatisticas(struct Sensor *sensor, int quantidadeSensores) {
    float media = 0;
    float maiorTemp = sensor[0].temperatura;
    float menorTemp = sensor[0].temperatura;

    for (int i = 0; i < quantidadeSensores; i++) {
        float temperaturaAtual = sensor[i].temperatura;
        media = media + temperaturaAtual;
        if (temperaturaAtual > maiorTemp) maiorTemp = temperaturaAtual;
        if (temperaturaAtual < menorTemp) menorTemp = temperaturaAtual;
    }

    media = media / quantidadeSensores;

    printf("Media: %.2f\n", media);
    printf("Maior temperatura registrada: %.2f\n", maiorTemp);
    printf("Menor temperatura registrada: %.2f\n", menorTemp);
}

char atribuirMaisSensores() {
    char maisSensores;
    printf("Serão adicionados mais sensores?(S/n): ");
    scanf(" %c", &maisSensores);
    maisSensores = toupper(maisSensores);
    return maisSensores;
}

void atualizarSensores(struct Sensor *sensor, int quantidadeSensores) {
    char maisSensores = atribuirMaisSensores();
    while (maisSensores == 'S') {
        int quantidadeSensoresAdicionados;
        
        struct Sensor *novo;
        
        printf("Escreva a quantidade de sensores adicionados(Para remover sensores, digite um número negativo.): ");
        scanf("%d", &quantidadeSensoresAdicionados);
        
        int novaQuantidadeSensores = quantidadeSensores + quantidadeSensoresAdicionados;
        
        novo = realloc(sensor, novaQuantidadeSensores * sizeof(struct Sensor));
        if (novo != NULL) {
            sensor = novo;
        } else {
            printf("Erro ao realocar memoria.\n");
            return;
        }
        
        cadastrarTemperaturas(sensor, quantidadeSensores, novaQuantidadeSensores);
        quantidadeSensores = novaQuantidadeSensores;

        mostrarTemperaturas(sensor, novaQuantidadeSensores);
        mostrarEstatisticas(sensor, novaQuantidadeSensores);

        maisSensores = atribuirMaisSensores();
    } 
    printf("Não serão adicionados mais sensores");
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int quantidadeSensores;

    printf("Escreva a quantidade de sensores: ");
    scanf("%d", &quantidadeSensores);
    if (quantidadeSensores <= 0) {
        printf("A quantidade deve ser maior que zero.\n");
        return 1;
    }

    struct Sensor *sensor;
    sensor = malloc(quantidadeSensores * sizeof(struct Sensor));

    if (sensor == NULL) {
        printf("erro ao alocar na memoria\n");
        return 1;
    }

    cadastrarTemperaturas(sensor, 0, quantidadeSensores);
    mostrarTemperaturas(sensor, quantidadeSensores);
    mostrarEstatisticas(sensor, quantidadeSensores);
    atualizarSensores(sensor, quantidadeSensores);

    free(sensor);
    sensor = NULL;
    return 0;
}
