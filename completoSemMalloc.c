#include <stdio.h>
#include <string.h>

#define MAX_PESSOAS 100

typedef struct
{
    int id;
    char nome[50];
    int idade;

} Pessoa;

// Adiciona as pessoas no vetor
void adicionarPessoas(Pessoa pessoas[], int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        printf("\n--- Pessoa %d ---\n", i + 1);

        printf("ID: ");
        scanf("%d", &pessoas[i].id);

        printf("Nome: ");
        scanf(" %49[^\n]", pessoas[i].nome);

        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);
    }
}

// Busca uma pessoa pelo ID
Pessoa *buscarPessoaPorId(Pessoa pessoas[], int quantidade, int id)
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

// Altera o nome de uma pessoa pelo ID
int alterarNomePorId(
    Pessoa pessoas[],
    int quantidade,
    int id,
    char novoNome[])
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

// Remove uma pessoa pelo ID
int removerPessoaPorId(
    Pessoa pessoas[],
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

    // Desloca os elementos para a esquerda
    for (int i = indiceEncontrado; i < *quantidade - 1; i++)
    {
        pessoas[i] = pessoas[i + 1];
    }

    (*quantidade)--;

    return 1;
}

// Mostra todas as pessoas
void mostrarPessoas(Pessoa pessoas[], int quantidade)
{
    printf("\n--- LISTA DE PESSOAS ---\n");

    for (int i = 0; i < quantidade; i++)
    {
        printf("\nID: %d\n", pessoas[i].id);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
    }
}

int main()
{
    Pessoa pessoas[MAX_PESSOAS];

    int quantidade;

    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &quantidade);

    if (quantidade > MAX_PESSOAS || quantidade <= 0)
    {
        printf("Quantidade invalida.\n");
        return 1;
    }

    // ADICIONAR
    adicionarPessoas(pessoas, quantidade);

    // MOSTRAR
    mostrarPessoas(pessoas, quantidade);

    // BUSCAR
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

    // ALTERAR NOME
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
        printf("Nome alterado com sucesso!\n");
    }
    else
    {
        printf("Pessoa nao encontrada.\n");
    }

    // REMOVER
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
        printf("Pessoa removida com sucesso!\n");
    }
    else
    {
        printf("Pessoa nao encontrada.\n");
    }

    mostrarPessoas(pessoas, quantidade);

    return 0;
}