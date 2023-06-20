#include <stdio.h>

// Função para realizar busca binária
int busca_binaria(int vetor[], int tamanho, int elemento)
{
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita)
    {
        int meio = (esquerda + direita) / 2;

        // Se o elemento estiver no meio
        if (vetor[meio] == elemento)
            return meio;

        // Se o elemento for maior que o meio, procure à direita
        if (vetor[meio] < elemento)
            esquerda = meio + 1;

        // Se o elemento for menor que o meio, procure à esquerda
        else
            direita = meio - 1;
    }

    // Se chegamos aqui, o elemento não foi encontrado
    return -1;
}

int main(int argc, char** argv)
{
    // Vetor de 10 posições ordenado
    int vetor[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    // Elemento que queremos encontrar
    int elemento = 15;

    // Tamanho do vetor
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    // Chamar a função de busca binária
    int resultado = busca_binaria(vetor, tamanho, elemento);

    // Exibir o resultado
    if (resultado != -1)
        printf("Elemento encontrado na posição %d\n", resultado);
    else 
        printf("Elemento não encontrado no vetor\n");

    return 0;
}
