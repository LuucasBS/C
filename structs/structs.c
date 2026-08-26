#include <stdio.h>

int main()
{

    struct horario
    {
        int horas;
        int minutos;
        int segundos;
        double teste;
    };

    typedef struct
    {
        char nome[50];
        int idade;

    } Pessoa;

    Pessoa lucas;

    lucas.nome = "lucas";
    lucas.idade = 25;

    struct horario agora;

    agora.horas = 10;
    agora.minutos = 34;
    agora.segundos = 22;

    printf("%i, %i, %i", agora.horas, agora.minutos, agora.segundos);

    struct horario depois;

    depois.horas = agora.horas + 10;

    return 0;
}