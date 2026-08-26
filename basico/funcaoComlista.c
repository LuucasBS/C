#include <stdio.h>

int ordemCrescente(int vetor[], int n)
{
    int i, j, temporaria;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (vetor[i] < vetor[j])
            {
                temporaria = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temporaria;
            }
        }
    }
}

int main()
{

    int vetor[10] = {1, 40, 2, 69, 12, 34, 56, 90, 44, 100};
    int i;

    ordemCrescente(vetor, 10);

    for (i = 0; i < 10; i++)
    {

        printf("%i, ", vetor[i]);
    }

    return 0;
}