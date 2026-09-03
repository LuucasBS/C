#include <stdio.h>

// int retornarvalor(int *numero)
// {
//     int novo;

//     novo = *numero * 2;

//     return novo;
// }

int main()
{

    int teste1 = 10;
    int *pteste1 = &teste1;

    printf("%d\n", teste1);
    printf("%p\n", &teste1); // printf("%p", pteste1);
    printf("%p\n", pteste1);

    printf("%d\n", *pteste1);

    return 0;
}