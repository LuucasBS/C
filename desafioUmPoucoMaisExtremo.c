#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_VALUE 50

typedef struct
{

    char nome[50];
    int idade;
    char estadoCivil[50];

} Pessoa;

void adicionarPessoaNoMeuVetor(Pessoa *pessoa, int quantidadePessoasLista);
void lerPessoasDaMinhaLista(Pessoa *pessoa, int quantidadePessoasLista);
Pessoa *buscarPessoasDaMinhaListaPeloNome(Pessoa *pessoa, int quantidadePessoasLista, char *nomeQueDesejaProcurar);

int main()
{

    Pessoa pessoas[MAX_VALUE];
    int quantidadePessoasLista = 0;
    char nomequeDesejaProcurar[MAX_VALUE];

    while (1)
    {
        int numeroOperacao;
        printf("\n--------------------------------\n");
        printf("Digite uma operacao para realizar:\n ");
        printf("1. adicionar pessoas na lista\n ");
        printf("2. ler pessoas da lista\n ");
        printf("3. procurar pessoas na lista pelo nome:\n ");
        printf("4. sair\n");
        printf("\n--------------------------------\n");
        scanf("%d", &numeroOperacao);

        switch (numeroOperacao)
        {
        case 1:
            printf("Digite a quantidade de pessoas que vao ter na lista: ");
            if (quantidadePessoasLista > MAX_VALUE)
            {
                printf("Máximo de %d pessoas!\n", MAX_VALUE);
                continue;
            }

            scanf("%d", &quantidadePessoasLista);
            adicionarPessoaNoMeuVetor(pessoas, quantidadePessoasLista);
            break;
        case 2:
            lerPessoasDaMinhaLista(pessoas, quantidadePessoasLista);
            break;
        case 3:
        {
            int caractere;

            while ((caractere = getchar()) != '\n' && caractere != EOF)
            {
            }

            printf("\nDigite o nome da pessoa que você quer procurar na lista: ");

            fgets(
                nomequeDesejaProcurar,
                sizeof nomequeDesejaProcurar,
                stdin);

            nomequeDesejaProcurar[strcspn(nomequeDesejaProcurar, "\n")] = '\0';

            Pessoa *pessoaEncontrada =
                buscarPessoasDaMinhaListaPeloNome(
                    pessoas,
                    quantidadePessoasLista,
                    nomequeDesejaProcurar);

            if (pessoaEncontrada == NULL)
            {
                printf("\nPessoa não encontrada.\n");
            }

            break;
        }
        case 4:
            return 0;

        default:
            printf("\nnumero invalido! digite outro novamente \n");
            break;
        }
    }

    return 0;
}

void adicionarPessoaNoMeuVetor(
    Pessoa *pessoa,
    int quantidadePessoasLista)
{
    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF)
    {
    }

    for (int i = 0; i < quantidadePessoasLista; i++)
    {
        printf("Digite o nome da pessoa %d: ", i + 1);
        fgets(pessoa[i].nome, sizeof pessoa[i].nome, stdin);
        pessoa[i].nome[strcspn(pessoa[i].nome, "\n")] = '\0';

        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &pessoa[i].idade);

        while ((caractere = getchar()) != '\n' && caractere != EOF)
        {
        }

        printf("Digite o estado civil da pessoa %d: ", i + 1);
        fgets(
            pessoa[i].estadoCivil,
            sizeof pessoa[i].estadoCivil,
            stdin);
        pessoa[i].estadoCivil[strcspn(pessoa[i].estadoCivil, "\n")] = '\0';
    }
}

void lerPessoasDaMinhaLista(Pessoa *pessoa, int quantidadePessoasLista)
{

    if (quantidadePessoasLista == 0)
    {

        printf("A lista é vazia.");
    }
    else
    {
        for (int i = 0; i < quantidadePessoasLista; i++)
        {

            printf(" ---------------\n");

            printf("o nome da pessoa %d é: %s\n", i + 1, pessoa[i].nome);

            printf("a idade da pessoa %d é: %d\n", i + 1, pessoa[i].idade);

            printf("o estado civil da pessoa %d é: %s\n", i + 1, pessoa[i].estadoCivil);
        }
    }
}

Pessoa *buscarPessoasDaMinhaListaPeloNome(Pessoa *pessoa, int quantidadePessoaLista, char *nomeQueDesejaProcurar)
{

    for (int i = 0; i < quantidadePessoaLista; i++)
    {

        if (strcmp(pessoa[i].nome, nomeQueDesejaProcurar) == 0)
        {

            printf("pessoa encontrada!\n");

            printf("Nome da pessoa encontrada: %s\n", pessoa[i].nome);
            printf("Idade da pessoa encontrada: %d\n", pessoa[i].idade);
            printf("estado civil da pessoa encontrada: %s\n", pessoa[i].estadoCivil);

            return &pessoa[i];
        }
    }

    return NULL;
}