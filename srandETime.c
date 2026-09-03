#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    srand(time(NULL));

    float numerosAleatorios;

    numerosAleatorios = rand() % 11;

    printf("numero aleatorio gerado: %.1f", numerosAleatorios);

    return 0;
}