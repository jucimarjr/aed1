
// calcula a media de um vetor de inteiros
float calcular_media(int n, int *notas)
{
    int i;
    float media = 0;
    int soma = 0;

    for (i = 0; i < n; i++)
        soma = soma + notas[i];

    media = soma / n;

    return media;
}
