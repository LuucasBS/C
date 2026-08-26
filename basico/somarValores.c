#include <stdio.h>
#include <stdbool.h>

int main()
{

    int primeiroValor;
    int segundoValor;
    int soma;

    printf("digite o primeiro valor");

    scanf("%i", &primeiroValor);

    printf("digite o segundo valor");

    scanf("%i", &segundoValor);

    soma = primeiroValor + segundoValor;

    printf("a soma dos valores deu: %i", soma);
}