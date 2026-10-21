#include <stdio.h>
#include <stdbool.h>
#define QUANTIDADE_SENSOR 5

struct Sensor {
    int codigo;
    float temperatura;
    bool estadoFuncionamento;

};

void apresentarValoresCriticos(struct Sensor sensor[QUANTIDADE_SENSOR]) {
    for (int i = 0; i < QUANTIDADE_SENSOR; i++) {
        if (sensor[i].temperatura > 30 && sensor[i].estadoFuncionamento == true)
        {
            printf("Codigo do sensor: %d\n", sensor[i].codigo);
            printf("Temperatura do sensor: %.2f\n", sensor[i].temperatura);
        }
        
    }
}

int contarSensoresCriticos (struct Sensor sensor[QUANTIDADE_SENSOR]) {
    int contadorCritico = 0;
    for (int i = 0; i < QUANTIDADE_SENSOR; i++) {
        if (sensor[i].temperatura > 30&& sensor[i].estadoFuncionamento == true) contadorCritico++;        
    }
    return contadorCritico;
}

int main() {
    struct Sensor sensor[QUANTIDADE_SENSOR];
    int estado;

    for (int i = 0; i < QUANTIDADE_SENSOR; i++) {
        printf("Digite o codigo do sensor %d: ", i + 1);
        scanf("%d", &sensor[i].codigo);
        
        printf("Digite a temperatura do sensor %d: ", i + 1);
        scanf("%f", &sensor[i].temperatura);

        printf("Digite o estado de funcionamento do sensor %d (Ativo = 1 | Inativo = 0): ", i + 1);
        scanf("%d", &estado);
        sensor[i].estadoFuncionamento = (estado != 0);
    }

    apresentarValoresCriticos(sensor);
    int qtdeCriticos = contarSensoresCriticos(sensor);
    printf("Quantidade de sensores criticos: %d\n", qtdeCriticos); 

    return 0;
}
