#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

#define SAIR 0
#define INSERIR_INICIO 1
#define INSERIR_FINAL 2
#define LISTAR_SENSORES 3
#define BUSCAR_SENSOR 4
#define REMOVER_SENSOR 5
#define CALCULAR_MEDIA 6
#define CONTAR_ACIMA_TEMPERATURA 7

typedef struct Sensor {
    int codigo;
    float temperatura;
    struct Sensor *proximo;
} Sensor;

Sensor *inserirInicio(Sensor *sensor, float valorTemperatura, int codigo) {
    Sensor *novo = malloc(sizeof(Sensor));
    if (novo == NULL) {
        printf("Erro de alocação\n");
        return sensor;
    }
    novo->codigo = codigo;
    novo->temperatura = valorTemperatura;
    novo->proximo = sensor;
    return novo;
}

Sensor *inserirFinal(Sensor *sensor, float valorTemperatura, int codigo) {
    Sensor *novo = malloc(sizeof(Sensor));
    if (novo == NULL) {
        printf("Erro de alocação.\n");
        return sensor;
    }
    novo->codigo = codigo;
    novo->temperatura = valorTemperatura;
    novo->proximo = NULL;
    if (sensor == NULL) {
        return novo;
    }
    Sensor *atual = sensor;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    return sensor;
}

void mostrarLista(Sensor *sensor) {
    Sensor *atual = sensor;
    while (atual != NULL) {
        printf("%.2f | ", atual->temperatura);
        atual = atual->proximo;
    }
    printf("\n");
}

Sensor *buscar(Sensor *sensor, int codigo) {
    Sensor *atual = sensor;
    while (atual != NULL) {
        if (atual->codigo == codigo) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

Sensor *remover(Sensor *sensor, int codigo) {
    Sensor *atual = sensor;
    Sensor *anterior = NULL;
    while (atual != NULL && atual->codigo != codigo) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == NULL) return sensor;
    if (anterior == NULL) sensor = atual->proximo;
    else anterior->proximo = atual->proximo;
    free(atual);
    return sensor;
}

float calcularMedia(Sensor *sensor) {
    Sensor *atual = sensor;
    float media = 0;
    int contador = 0;
    while (atual != NULL) {
        media += atual->temperatura;
        contador++;
        atual = atual->proximo;
    }
    media /= contador;
    return media;
}

int contarSensoresAcimaLimite(Sensor *sensor, float limite) {
    Sensor *atual = sensor;
    int contador = 0;
    while (atual != NULL) {
        if (atual->temperatura > limite) contador++; 
        atual = atual->proximo;
    }
    return contador;
}

Sensor *liberarLista(Sensor *sensor) {
    Sensor *atual = sensor;
    while (atual != NULL) {
        Sensor *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    return NULL;
}

void menuInterativo(Sensor **sensor, int opcao) {
    switch (opcao) {
        case INSERIR_INICIO: {
            float valor;
            int codigo;
            printf("Digite uma temperatura para inserir: ");
            scanf("%f", &valor);
            printf("Digite o codigo dela para inserir: ");
            scanf("%d", &codigo);
            *sensor = inserirInicio(*sensor, valor, codigo);
            break;
        }
    
        case INSERIR_FINAL: {
            float valor;
            int codigo;
            printf("Digite uma temperatura para inserir: ");
            scanf("%f", &valor);
            printf("Digite o codigo dela para inserir: ");
            scanf("%d", &codigo);
            *sensor = inserirFinal(*sensor, valor, codigo);
            break;
        }
        
        case LISTAR_SENSORES: {
            mostrarLista(*sensor);
            break;
        }

        case BUSCAR_SENSOR: {
            int codigo;
            printf("Digite o codigo do sensor para buscar: ");
            scanf("%d", &codigo);
            Sensor *resultado = buscar(*sensor, codigo);
            if (resultado != NULL) {
                printf("Codigo: %d\n", resultado->codigo);
                printf("Temperatura: %.2f\n", resultado->temperatura);
            } else printf("Sensor nao encontrado!\n");
            break;
        }

        case REMOVER_SENSOR: {
            int codigo;
            printf("Digite o codigo do sensor para remover: ");
            scanf("%d", &codigo);
            *sensor = remover(*sensor, codigo);
            break;
        }

        case CALCULAR_MEDIA: {
            float media = calcularMedia(*sensor);
            printf("Média dos sensores: %.2f\n", media);
            break;
        }

        case CONTAR_ACIMA_TEMPERATURA: {
            float valor;
            printf("Digite uma temperatura para ser o limite: ");
            scanf("%f", &valor);
            int contador = contarSensoresAcimaLimite(*sensor, valor);
            printf("Sensores acima do limite: %d\n", contador);
            break;
        }

        case SAIR: {
            *sensor = liberarLista(*sensor);
            printf("Fechando programa...");
            break;
        }

        default:
            printf("Inválido");
            break;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Sensor *sensor = NULL;
    int opcao;
    do {
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no final\n");
        printf("3 - Listar sensores\n");
        printf("4 - Buscar sensor\n");
        printf("5 - Remover sensor\n");
        printf("6 - Calcular média\n");
        printf("7 - Contar sensores acima de uma temperatura\n");
        printf("0 - Sair\n");

        printf("Escolha: ");
        scanf("%d", &opcao);

        menuInterativo(&sensor, opcao);

    } while (opcao != SAIR);
    return 0;
}
