#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nome[50];
    int idade;

} Pessoa;

// ----------------------------------------------------
// ADICIONAR PESSOAS AO VETOR
// ----------------------------------------------------

void adicionarPessoas(Pessoa *pessoas, int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        printf("\nPessoa %d\n", i + 1);

        printf("Digite o id: ");
        scanf("%d", &pessoas[i].id);

        printf("Digite o nome: ");
        scanf(" %49[^\n]", pessoas[i].nome);

        printf("Digite a idade: ");
        scanf("%d", &pessoas[i].idade);
    }
}

// ----------------------------------------------------
// MOSTRAR TODAS AS PESSOAS
// ----------------------------------------------------

void mostrarPessoas(Pessoa *pessoas, int quantidade)
{
    printf("\n--- LISTA DE PESSOAS ---\n");

    for (int i = 0; i < quantidade; i++)
    {
        printf("\nID: %d\n", pessoas[i].id);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
    }
}

// ----------------------------------------------------
// BUSCAR PESSOA PELO ID
// ----------------------------------------------------

Pessoa *buscarPessoaPorId(Pessoa *pessoas, int quantidade, int id)
{
    for (int i = 0; i < quantidade; i++)
    {
        if (pessoas[i].id == id)
        {
            return &pessoas[i];
        }
    }

    return NULL;
}

// ----------------------------------------------------
// ALTERAR NOME PELO ID
// ----------------------------------------------------

int alterarNomePorId(
    Pessoa *pessoas,
    int quantidade,
    int id,
    char *novoNome)
{
    Pessoa *pessoaEncontrada =
        buscarPessoaPorId(pessoas, quantidade, id);

    if (pessoaEncontrada == NULL)
    {
        return 0;
    }

    strcpy(pessoaEncontrada->nome, novoNome);

    return 1;
}

// ----------------------------------------------------
// REMOVER PESSOA PELO ID
// ----------------------------------------------------

int removerPessoaPorId(
    Pessoa *pessoas,
    int *quantidade,
    int id)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < *quantidade; i++)
    {
        if (pessoas[i].id == id)
        {
            indiceEncontrado = i;
            break;
        }
    }

    if (indiceEncontrado == -1)
    {
        return 0;
    }

    // Move todo mundo depois da pessoa
    // uma posição para trás

    for (int i = indiceEncontrado; i < *quantidade - 1; i++)
    {
        pessoas[i] = pessoas[i + 1];
    }

    (*quantidade)--;

    return 1;
}

// ----------------------------------------------------
// MAIN
// ----------------------------------------------------

int main()
{
    int quantidade;

    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &quantidade);

    // Criando vetor dinamicamente
    Pessoa *pessoas = malloc(quantidade * sizeof(Pessoa));

    if (pessoas == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    adicionarPessoas(pessoas, quantidade);

    mostrarPessoas(pessoas, quantidade);

    // ------------------------------------------------
    // BUSCAR
    // ------------------------------------------------

    int idBusca;

    printf("\nDigite um ID para buscar: ");
    scanf("%d", &idBusca);

    Pessoa *pessoaEncontrada =
        buscarPessoaPorId(pessoas, quantidade, idBusca);

    if (pessoaEncontrada != NULL)
    {
        printf("\nPessoa encontrada!\n");

        printf("ID: %d\n", pessoaEncontrada->id);
        printf("Nome: %s\n", pessoaEncontrada->nome);
        printf("Idade: %d\n", pessoaEncontrada->idade);
    }
    else
    {
        printf("\nPessoa nao encontrada.\n");
    }

    // ------------------------------------------------
    // ALTERAR NOME
    // ------------------------------------------------

    int idAlterar;
    char novoNome[50];

    printf("\nDigite o ID da pessoa que deseja alterar: ");
    scanf("%d", &idAlterar);

    printf("Digite o novo nome: ");
    scanf(" %49[^\n]", novoNome);

    int alterou =
        alterarNomePorId(
            pessoas,
            quantidade,
            idAlterar,
            novoNome);

    if (alterou == 1)
    {
        printf("\nNome alterado com sucesso!\n");
    }
    else
    {
        printf("\nPessoa nao encontrada.\n");
    }

    mostrarPessoas(pessoas, quantidade);

    // ------------------------------------------------
    // REMOVER
    // ------------------------------------------------

    int idRemover;

    printf("\nDigite o ID da pessoa que deseja remover: ");
    scanf("%d", &idRemover);

    int removeu =
        removerPessoaPorId(
            pessoas,
            &quantidade,
            idRemover);

    if (removeu == 1)
    {
        printf("\nPessoa removida com sucesso!\n");
    }
    else
    {
        printf("\nPessoa nao encontrada.\n");
    }

    mostrarPessoas(pessoas, quantidade);

    free(pessoas);

    pessoas = NULL;

    return 0;
}