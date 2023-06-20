#include <stdio.h>

long fatorial(int n)
{
    long fat;

    if ((n==1) || (n==0))
        fat = 1;
    else
        for (fat = 1; n > 1; n--)
            fat = fat * n;

    return fat;
}

int main(int argc, char** argv)
{
    int n;
    
    printf("Fatorial iterativo !!!!\n");
    
    scanf("%d",&n);
    printf("fat(%d) = %ld\n", n, fatorial(n));

	return 0;
}