#include <stdio.h>

int main()
{

    int numeros[5] = {10, 20, 30, 40, 50};

    printf("%d\n", numeros[0]);
    printf("%d\n", numeros[1]);
    printf("%d\n", numeros[2]);
    printf("%d\n", numeros[3]);
    printf("%d\n", numeros[4]);

    int *pnumeros = numeros;

    pnumeros[2] = 100;

    printf("------------------------------------\n");
    printf("%d\n", numeros[0]);
    printf("%d\n", numeros[1]);
    printf("%d\n", numeros[2]);
    printf("%d\n", numeros[3]);
    printf("%d\n", numeros[4]);

    return 0;
}