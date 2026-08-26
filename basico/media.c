#include <stdio.h>

int main()
{

    float nota1;
    float nota2;
    float media;

    printf("digite a nota 1: ");

    scanf("%f", &nota1);

    printf("digite a nota 2: ");

    scanf("%f", &nota2);

    media = (nota1 + nota2) / 2;

    printf("a média das notas foi:  %2.f", media);
}