#include <stdio.h>

int total = 10;

void atualizar(int *valor) {
    total = total + *valor;
    *valor = *valor * 2;
    printf("A: %d %d\n", total, *valor);
}
     
int main() {
    int numero = 3;
    atualizar(&numero);
    printf("B: %d %d\n", total, numero);
    return 0;
}
/*
    a) Qual será a saída completa do programa?
    b) Identifique a variável global e as variáveis locais.
    c) Explique por que o valor da variável global total não é modificado pela função atualizar.
    d) Modifique a função atualizar para que ela também consiga alterar a variável numero, declarada em main, utilizando um ponteiro. Apresente a chamada correspondente.
*/

/*
    a) A: 8 6 \n B: 10 3
    b) total = 10 é global | total = 5, valor e numero = 3 são locais
    c) porque a variável total global é diferente da que está sendo modificada. Podem ter os mesmos nomes, mas não são as mesmas coisas.
    d)
 
void atualizar(int *valor) {
    total = total + *valor;
    *valor = *valor * 2;
    printf("A: %d %d\n", total, *valor);
}

int main() {
    int numero = 3;
    atualizar(&numero);
    printf("B: %d %d\n", total, numero);
    return 0;
}  
*/