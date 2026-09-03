#include <stdio.h>

int main()
{

    int numero = 10;

    int *pnumero = &numero;

    *pnumero = 50;

    printf("o novo valor é de : %d", *pnumero);

    return 0;
}