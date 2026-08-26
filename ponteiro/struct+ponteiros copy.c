

#include <stdio.h>

typedef struct
{
    int hora;
    int minuto;
    int segundo;

} Horario;

int main()
{

    Horario agora, *depois;

    depois = &agora;

    depois->hora = 20;
    depois->minuto = 23;
    depois->segundo = 10;

    printf("%i:%i:%i", agora.hora, agora.minuto, agora.segundo);

    return 0;
}