/*
    Nome:   Jucimar Maia da Silva Jr
    Mat:    7389217389123
    
    InsertionSort

*/

#include <stdio.h>

void insertionsort(int vetor[], int n)
{
    int i, key, j;
    int contador1 = 0;
    int contador2 = 0;

    for (i = 1; i < n; i++)
    {
        key = vetor[i];
        j = i - 1;
        
        contador1++;

        while (j >= 0 && vetor[j] > key)
        {
            vetor[j + 1] = vetor[j];
            j = j-1;
            contador2++;
        }
        
        vetor[j + 1] = key;
    }

    printf("insertionsort\n");
    printf("Loop: %d\n",contador1);
    printf("Comparações: %d\n",contador2);
}

int main(int argc, char** argv)
{
    //int vetor[] = {64, 34, 25, 12, 22, 11, 90, 87, 100, 01};
    int vetor[] = {01, 11, 12, 22, 25, 34, 64, 87, 90, 100};
    //int vetor[] = {100, 90, 87, 64, 34, 25, 22, 12, 11, 01};
    int n = 10;
    
    insertionsort(vetor, n);
    
    printf("vetor ordenado: ");

    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);

    printf("\n");
    
    return 0;
}