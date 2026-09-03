#include <stdio.h>

void dobrar(int *numero)
{
    *numero = *numero * 2;
}

int main()
{
    int numero = 80;

    dobrar(&numero);

    printf("numero dobrado ficou: %d", numero);

    return 0;
}