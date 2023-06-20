#include <stdio.h>

// Função recursiva de busca binária
int busca_binaria(int vetor[], int esquerda, int direita    , int x) {
    if (direita >= esquerda)
    {
        // Encontra o ponto médio
        int meio = esquerda + (direita - esquerda) / 2;

        // Se o elemento estiver no meio
        if (vetor[meio] == x)
            return meio;

        // Se o elemento for menor que o ponto médio, pesquisa na metade esquerda
        if (vetor[meio] > x)
            return busca_binaria(vetor, esquerda, meio - 1, x);

        // Caso contrário, pesquisa na metade direita
        return busca_binaria(vetor, meio + 1, direita, x);
    }

    // Elemento não está presente no vetor
    return -1;
}

int main(int argc, char** argv)
{
    int vetor[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int x = 11; // Elemento para buscar
    
    // Chama a função de busca binária
    int resultado = busca_binaria(vetor, 0, n - 1, x);

    // Imprime o resultado
    if (resultado == -1)
        printf("O elemento não está presente no vetor\n");
    else
        printf("O elemento está presente no índice %d\n", resultado);
    
    return 0;
}
