#include <stdio.h>

int fatorial(int num1)
{

    int resultado;

    if (num1 == 0)
    {
        resultado = 1;
    }
    else
    {
        resultado = num1 * fatorial(num1 - 1);
    }

    return resultado;
}

int main()
{
    int numero, resultado;

    printf("digite um numero inteiro");

    scanf("%i", &numero);

    resultado = fatorial(numero);

    printf("o fatorial do numero é: %i\n", resultado);

    return 0;
}
