/*
    Nome:   Jucimar Maia da Silva Jr
    Mat:    7389217389123
    
    Bubblesort
*/

#include <stdio.h>
#include <time.h>

void bubblesort(int vetor[], int n)
{
    int i, j, temp;
    int contador1 = 0;
    int contador2 = 0;

    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            contador1++;

            if (vetor[j] > vetor[j+1])
            {
                contador2++;

                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
            /*
            for (int i = 0; i < n; i++)
                printf("%d ", vetor[i]);
            
            printf("\n");*/
        }
    }
    //printf("Bubblesort\n");
    //printf("Loop: %d\n",contador1);
    //printf("Comparações: %d\n",contador2);
}

int main(int argc, char *argv[])
{
    //int vetor[] = {64, 34, 25, 12, 22, 11, 90, 87, 100, 01};
    //int vetor[] = {01, 11, 12, 22, 25, 34, 64, 87, 90, 100};
    //int vetor[] = {100, 90, 87, 64, 34, 25, 22, 12, 11, 01};
    
    int vetor[100000];
    int n = 100000;
    double start, finish, elapsed;

    // ler o vetor
    for (int i = 0; i < n; i++)
        scanf("%d", &vetor[i]);
    
    // inicia o cronometro
    start = (double) clock() / CLOCKS_PER_SEC;

    bubblesort(vetor, n);
    
    // finaliza o cronometro
    finish = (double) clock() / CLOCKS_PER_SEC;
	
	// calcula o tempo
    elapsed = (double) finish - start;

	printf( "%f s \n", elapsed);
    /*
    printf("vetor ordenado: ");

    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);

    printf("\n");
   */
    return 0;
}