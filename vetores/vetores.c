#include <stdio.h>

// 1. Boa prática: Definir o tamanho como uma constante.
// Se amanhã precisarmos mudar para 10 alunos, mudamos só aqui!
#define TOTAL_ALUNOS 2

// Assinaturas das funções (o que elas vão fazer)
void preencherNotas(float notas[], int tamanho);
float calcularMedia(float notas[], int tamanho);
float encontrarMaiorNota(float notas[], int tamanho);
void exibirNotas(float notas[], int tamanho);

int main()
{
    // 2. Declarando e INICIALIZANDO o vetor com zeros.
    // Isso garante que não haja "lixo" na memória.
    float notas[TOTAL_ALUNOS] = {0.0};

    float media, maiorNota;

    printf("--- SISTEMA DE NOTAS DA TURMA ---\n\n");

    // Chama a função para ler as notas do teclado
    preencherNotas(notas, TOTAL_ALUNOS);

    // Chama a função para exibir as notas formatadas
    printf("\n--- RELATÓRIO ---\n");
    exibirNotas(notas, TOTAL_ALUNOS);

    // Calcula e exibe a média
    media = calcularMedia(notas, TOTAL_ALUNOS);
    printf("Media da turma: %.2f\n", media);

    // Encontra e exibe a maior nota
    maiorNota = encontrarMaiorNota(notas, TOTAL_ALUNOS);
    printf("Maior nota da turma: %.2f\n", maiorNota);

    return 0;
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES ---

// Função para ler as notas
void preencherNotas(float notas[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]); // O '&' é obrigatório aqui!
    }
}

// Função para calcular a média
float calcularMedia(float notas[], int tamanho)
{
    float soma = 0.0, media;

    for (int i = 0; i < tamanho; i++)
    {
        soma += notas[i]; // soma = soma + notas[i]
    }

    media = soma / tamanho;

    return media;
}

// Função para encontrar a maior nota
float encontrarMaiorNota(float notas[], int tamanho)
{
    // Assumimos que a primeira nota é a maior inicialmente
    float maior = notas[0];

    // Começamos o loop do índice 1, pois o 0 já está na variável 'maior'
    for (int i = 1; i < tamanho; i++)
    {
        if (notas[i] > maior)
        {
            maior = notas[i]; // Atualiza a maior nota se encontrar uma maior
        }
    }

    return maior;
}

// Função para exibir as notas
void exibirNotas(float notas[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("Nota do aluno %d: %.2f\n", i + 1, notas[i]);
    }
}