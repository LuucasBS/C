#include <stdio.h>
#include <string.h>

struct Pessoa
{
    char nome[50];
    int idade;
};

int main()
{
    struct Pessoa pessoa1;
    struct Pessoa *ponteiro = &pessoa1;

    strcpy(ponteiro->nome, "Lucas");
    ponteiro->idade = 25;

    printf("Nome: %s\n", pessoa1.nome);
    printf("Idade: %d\n", pessoa1.idade);

    return 0;
}