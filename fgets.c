#include <stdio.h>
#include <string.h>

void mudarNomeDoUsuario(char *nome)
{
    char novoNome[50];
    printf("digite um novo nome");

    fgets(novoNome, sizeof(novoNome), stdin);

    strcpy(nome, novoNome);

    printf("o novo nome foi:  %s", novoNome);
}

int main()
{

    char nomeDigitado[50];
    printf("digite um nome: ");

    fgets(nomeDigitado, sizeof(nomeDigitado), stdin);

    printf(" o nome digitado foi: %s", nomeDigitado);

    mudarNomeDoUsuario(nomeDigitado);

    return 0;
}