#include <iostream>

int leitura(){

    int valor;

    printf("\nDigite o valor que deseja calcular: ");
    scanf("%d", &valor);

    return valor;
}

int retorno(){

    int leituraValor = leitura();

    printf("O seu valor e: %d", leituraValor);

}