#include <stdio.h>
#include <string.h>

typedef struct
{
    int idade;
    char nome[50];
    char sexo;
} Pessoa;

void adicionarPessoasNaLista(
    Pessoa listaDePessoas[],
    int quantidadePessoasLista)
{
    for (int i = 0; i < quantidadePessoasLista; i++)
    {
        printf("\n------------------------------------------\n");

        printf("Digite a idade da pessoa %i: ", i + 1);
        scanf("%i", &listaDePessoas[i].idade);

        printf("Digite o nome da pessoa %i: ", i + 1);
        scanf("%49s", listaDePessoas[i].nome);

        printf("Digite o sexo da pessoa %i (M/F): ", i + 1);
        scanf(" %c", &listaDePessoas[i].sexo);

        printf("------------------------------------------\n");
    }
}

void pessoasCadastradas(
    Pessoa listaDePessoas[],
    int quantidadePessoasLista)
{
    printf("\nAs pessoas cadastradas são:\n");

    for (int i = 0; i < quantidadePessoasLista; i++)
    {
        printf("\n---------------------------------------\n");
        printf("Idade: %i\n", listaDePessoas[i].idade);
        printf("Nome: %s\n", listaDePessoas[i].nome);
        printf("Sexo: %c\n", listaDePessoas[i].sexo);
        printf("---------------------------------------\n");
    }
}

Pessoa *buscarPessoaNaLista(
    Pessoa listaPessoas[],
    int quantidadePessoas,
    const char nomeProcurado[])
{
    for (int i = 0; i < quantidadePessoas; i++)
    {
        if (strcmp(nomeProcurado, listaPessoas[i].nome) == 0)
        {
            return &listaPessoas[i];
        }
    }

    return NULL;
}

int main(void)
{
    int numeroPessoasLista;
    char nomeProcurado[50];

    printf("Digite a quantidade de pessoas da lista: ");
    scanf("%i", &numeroPessoasLista);

    if (numeroPessoasLista <= 0)
    {
        printf("A quantidade precisa ser maior que zero.\n");
        return 1;
    }

    /*
     * O vetor deve ser criado somente depois que seu tamanho
     * tiver sido informado.
     */
    Pessoa listaPessoas[numeroPessoasLista];

    adicionarPessoasNaLista(
        listaPessoas,
        numeroPessoasLista);

    pessoasCadastradas(
        listaPessoas,
        numeroPessoasLista);

    printf("\nDigite o nome da pessoa que deseja encontrar: ");
    scanf("%49s", nomeProcurado);

    Pessoa *pessoaLocalizada = buscarPessoaNaLista(
        listaPessoas,
        numeroPessoasLista,
        nomeProcurado);

    if (pessoaLocalizada != NULL)
    {
        printf("\nPessoa localizada:\n");
        printf("Nome: %s\n", pessoaLocalizada->nome);
        printf("Idade: %i\n", pessoaLocalizada->idade);
        printf("Sexo: %c\n", pessoaLocalizada->sexo);
    }
    else
    {
        printf("\nPessoa não encontrada.\n");
    }

    return 0;
}