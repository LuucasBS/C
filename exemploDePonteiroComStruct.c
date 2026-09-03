#include <stdio.h>

typedef struct
{

    int idade;
    int fiosDeCabelo;

} Pessoa;

int main()
{

    Pessoa pessoa1;

    Pessoa *ppessoa1 = &pessoa1;

    pessoa1.fiosDeCabelo = 10;
    pessoa1.idade = 2;

    ppessoa1->fiosDeCabelo = 20;
    ppessoa1->idade = 4;

        return 0;
}