#include <stdio.h>

int main()
{

    int x = 10;
    double y = 20.50;
    char z = 'a';

    int *pX = &x;
    double *pY = &y;
    char *pZ = &z;

    double soma = *pX + *pY;

    printf("%i %i\n", x, y);

    printf("%f", soma);

    return 0;
}