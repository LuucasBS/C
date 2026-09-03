#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_VEICULOS 10

typedef struct
{

    char marca[50];
    int ano;
    bool temRevisao;

} Veiculo;

void adicionarVeiculos(Veiculo *veiculo, int quantidadeDeVeiculosPatio)
{

    for (int i = 0; i < quantidadeDeVeiculosPatio; i++)
    {

        printf("digite o ano do veiculo %i:  ", i + 1);
        scanf("%i", &veiculo[i].ano);

        printf("\n Digite a marca do veiculo %i: ", i + 1);
        scanf("%s", &veiculo[i].marca);

        printf("\n Digite se o carro fez a revisão anual (S/N): ");
        bool resposta = scanf("%i", &veiculo[i].temRevisao);

        if (resposta == 1)
        {
            veiculo->temRevisao = true;
        }
        else if (resposta == 0)
        {
            veiculo->temRevisao = false;
        }
        else
        {
            printf("Resposta invalida!\n");
        }
    }
}

int main()
{

    int quantidadeVeiculosNoPatio;
    Veiculo patio[MAX_VEICULOS];

    printf("quantos veiculos terão no patio? ");
    scanf("%d", &quantidadeVeiculosNoPatio);

    if (quantidadeVeiculosNoPatio > MAX_VEICULOS || quantidadeVeiculosNoPatio < 0)
    {
        printf("quantidade Invalida");
        return -1;
    }

    adicionarVeiculos(patio, quantidadeVeiculosNoPatio);

    return 0;
}