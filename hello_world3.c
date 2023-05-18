/*
    Nome:   Jucimar Maia da Silva Jr
    Mat:    7389217389123

    Meu 3o  programa =)

*/

#include <stdio.h>
#include "processamento.c"

int main(int argc, char** argv)
{
    int i;
    int notas[10];
    float media;

    // entrada de dados
    for (i = 0; i < 10; i++) 
        scanf("%d", &notas[i]);

    // processamento dos dados
    media = calcular_media(10,notas);

    // saida
    printf("%f\n", media);

	return 0;
}
