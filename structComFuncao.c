#include <stdio.h>

#define NUMERO_PESSOAS 2

typedef struct
{
    char nome[50];
    int idade;
    int documento;
} Pessoa;

int verificarQuantidadePessoas(
    Pessoa pessoas[],
    int tamanhoArray)
{
    return tamanhoArray;
}

void trazerAsPessoasDaMinhaListaComSeusDados(
    Pessoa pessoas[],
    int quantidadeDePessoas)
{
    for (int i = 0; i < quantidadeDePessoas; i++)
    {
        printf("\n-----------------------------\n");
        printf("Dados da pessoa %i\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %i\n", pessoas[i].idade);
        printf("Documento: %i\n", pessoas[i].documento);
        printf("-----------------------------\n");
    }
}

Pessoa *buscarPessoaPeloDocumento(Pessoa vetor[], int quantidadeItens, int documentoPessoa)
{

    for (int i = 0; i < quantidadeItens; i++)
    {

        if (vetor[i].documento == documentoPessoa)
        {

            return &vetor[i];
        }

        return NULL;
    }
}

int main(void)
{
    Pessoa vetorPessoas[NUMERO_PESSOAS];
    int documentoPessoa;

    for (int i = 0; i < NUMERO_PESSOAS; i++)
    {
        printf("\nDigite o nome da pessoa %i: ", i + 1);
        scanf("%49s", vetorPessoas[i].nome);

        printf("Digite a idade da pessoa %i: ", i + 1);
        scanf("%i", &vetorPessoas[i].idade);

        printf("Digite o documento da pessoa %i: ", i + 1);
        scanf("%i", &vetorPessoas[i].documento);
    }

    int numeroPessoasNaLista =
        verificarQuantidadePessoas(
            vetorPessoas,
            NUMERO_PESSOAS);

    printf(
        "\nA quantidade de pessoas é: %i\n",
        numeroPessoasNaLista);

    trazerAsPessoasDaMinhaListaComSeusDados(
        vetorPessoas,
        numeroPessoasNaLista);

    printf("Digite o documento para buscar uma pessoa: ");

    scanf("%i", &documentoPessoa);

    Pessoa *pessoaEncontrada = buscarPessoaPeloDocumento(vetorPessoas, numeroPessoasNaLista, documentoPessoa);

    if (pessoaEncontrada != NULL)
    {

        printf("a pessoa encontrada foi: %s\n", pessoaEncontrada->nome);
    }
    else
    {

        printf("Pessoa não encontrada.\n");
    }

    return 0;
}