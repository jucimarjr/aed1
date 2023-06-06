/*
	Jucimar Junior
	jucimar.jr@gmail.com

	Gerador de numeros aleatorios

	Uso
	-----
	
	Ex: gerar 10x numeros aleatorios entre 0 e 1000 e grava no arquivo 1000.txt
	
	./gerar-rand 1000 > 1000.txt

1000  - 10x
2500  - 10x
5000  - 15x
10000 - 20x


*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( int argc, char *argv[])
{
	long int n,i,p;
	
	n = atoi(argv[1]);

	srand( time( NULL ) );

	for( i = 0; i < 20*n; i++ )
	{
		if ( i < 32000*n ) 
			p = rand() % n;
		else
			p = ( rand() % n/2 ) + ( rand() % n/2 );

		printf( "%li\n", p );
	}

	return( 0 );
}	
