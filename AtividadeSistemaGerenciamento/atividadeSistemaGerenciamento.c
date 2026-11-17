#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

typedef struct Sensor {
    int codigo;
    float temperatura;
    struct Sensor *proximo;
} Sensor;

Sensor *inserirInicio(Sensor *inicio, float valorTemperatura, int codigo) {
    Sensor *novo = malloc(sizeof(Sensor));
    if (novo == NULL) {
        printf("Erro de alocação\n");
        return inicio;
    }
    novo->codigo = codigo;
    novo->temperatura = valorTemperatura;
    novo->proximo = inicio;
    return novo;
}

Sensor *inserirFinal(Sensor *inicio, float valorTemperatura, int codigo) {
    Sensor *novo = malloc(sizeof(Sensor));
    if (novo == NULL) {
        printf("Erro de alocação.\n");
        return inicio;
    }
    novo->codigo = codigo;
    novo->temperatura = valorTemperatura;
    novo->proximo = NULL;
    if (inicio == NULL) {
        return novo;
    }
    Sensor *atual = inicio;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    return inicio;
}

void mostrarLista(Sensor *inicio) {
    Sensor *atual = inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->temperatura);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

Sensor *buscar(Sensor *inicio, int codigo) {
    Sensor *atual = inicio;
    while (atual != NULL) {
        if (atual->codigo == codigo) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

Sensor *remover(Sensor *inicio, int codigo) {
    Sensor *atual = inicio;
    Sensor *anterior = NULL;
    while (atual != NULL && atual->codigo != codigo) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == NULL) return inicio;
    if (anterior == NULL) inicio = atual->proximo;
    else anterior->proximo = atual->proximo;
    free(atual);
    return inicio;
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