/*
	Jucimar Junior
	jucimar.jr@gmail.com

	Gerador de numeros
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( int argc, char *argv[])
{
	int n,i,p,x;
	char c;

	n = atoi(argv[2]);
	c = *argv[1];

	switch ( c )
	{
		case 'a':
			srand( time( NULL ) );
			x = 10 * n;

			for( i = 0; i < n; i++ )
			{
				p = rand() % x;
				printf( "%d\n", p );
			}
			break;

		case 'c':
			for( i = 0; i < n; i++ )
				printf( "%d\n", i );
			break;
		
		case 'd':
			for( i = n; i > 0; i-- )
				printf( "%d\n", i );
			break;
		
		case 'i':
			p = rand() % n;

			for( i = 0; i < n; i++ )
				printf( "%d\n", p );
			break;
	}

	return 0;
}	
