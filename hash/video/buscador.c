/*
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/*---------------------------------------------------------------------------*/
int busca_sequencial( int inicio, int fim, char chave[], char v[100000][15] )
{
	int i;
	int achou;

	i = inicio;
	achou = -1;

	while( achou == -1 && i <= fim )
		if ( !strcmp(v[i],chave ) )
			achou = i;
		else
			i++;
	
	return achou;
}

/*---------------------------------------------------------------------------*/
int busca_binaria( int inicio, int fim, char chave[], char v[100000][15] )
{
	int meio;
	int achou;

	achou = -1;

	while ( achou == -1 && inicio <= fim )
	{
		meio = ( inicio + fim ) / 2;
		
//		printf("i=%d f=%d m=%d v[%d]=%s %s %d\n",inicio,fim,meio,meio,v[meio],chave, strcmp(v[meio],chave));
		
		if ( !strcmp(v[meio],chave) )
			achou = meio;
		else
			if ( strcasecmp( v[meio],chave ) < 0 ) // chave > v[meio]
				inicio = meio + 1;
			else
				fim = meio - 1;
	}

	return achou;
}

/*---------------------------------------------------------------------------*/
int main( int argc, char *argv[] )
{
	char videos[100000][15];
	char busca[3000][15];
	
	char arq1[50];
	char arq2[50];

	int i;
	int achou;
	double start,stop,elapsed;

	char chave[15];
	int min,seg,visualizacao,qualidade;
	float opiniao;
	
	strcpy(arq1, argv[1] );
	strcpy(arq2, argv[2] );
	
	// abre o arquivo texto dos videos linhas
 	FILE *arquivo = fopen(arq1, "r");

	i = 0;

	while ( !feof( arquivo) && i < 100000 )
 	{
		fscanf(
			arquivo,
			"%s %d %d %d %d %f",
			chave,
			&min,
			&seg,
			&visualizacao,
			&qualidade,
			&opiniao
		);
		strcpy(videos[i],chave);
		i++;
	}	
	
	fclose(arquivo);
	
	// abre o arquivo texto dos videos linhas
 	FILE *arquivo2 = fopen(arq2, "r");

	i = 0;

	while ( !feof( arquivo2 ) && i < 3000 )
 	{
		fscanf(	arquivo2 ,"%s", chave );
		strcpy( busca[i], chave );
		i++;
	}	
	
	fclose( arquivo2 );
	
	//-----------------------------------------------------------------------------
	printf( "busca sequencial:\n" );

	start = (double) clock() / CLOCKS_PER_SEC;
	
	achou = -1;
	
	for ( i = 0; i < 3000; i++ )
	{
		achou = busca_sequencial(0,99999,busca[i],videos);
		if ( achou > 0 )
			printf("[%d] %s encontrado na posicao %d ^_^\n ",i, busca[i], achou );
		else
			printf("%s nao encontrado =(\n",busca[i]);
	}
	
	stop = (double) clock() / CLOCKS_PER_SEC;
	
	elapsed = (double) stop - start;

	printf("em %f segundos\n", elapsed );
	
	//-----------------------------------------------------------------------------
	printf( "busca binaria:\n" );

	start = (double) clock() / CLOCKS_PER_SEC;
	
	achou = -1;
	
	for ( i = 0; i < 3000; i++ )
	{
		achou = busca_binaria(0,99999,busca[i],videos);
		if ( achou > 0 )
			printf("[%d] %s encontrado na posicao %d ^_^\n ",i, busca[i], achou );
		else
			printf("%s nao encontrado =(\n",busca[i]);
	}
	
	stop = (double) clock() / CLOCKS_PER_SEC;
	
	elapsed = (double) stop - start;

	printf("em %f segundos\n", elapsed );

	//-----------------------------------------------------------------------------
	
	return 0;
}
