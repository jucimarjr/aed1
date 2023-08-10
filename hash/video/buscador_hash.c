/*------------------------------------------------------------------
-------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO 25000


/* definição da estrutura de dados */
typedef struct no No;
struct no {
	char info[15];
	No *prox;
};

No *tabela[TAMANHO];

/*--------------------------------------------------------------------------*/
No *inserir_adjacente( No *lista, char info[] )
{
	No *novo;
	novo = (No *)malloc( sizeof( No ) );

	strcpy( novo->info, info );

	novo->prox = lista;
	
	return novo;
}


/*--------------------------------------------------------------------------*/
int faz_hash( char info[] )
{
	int indice = 0;
	int i;

	for (i = 0; i < 11; i++)
		indice += info[i] * i * i;
	
	indice -= 20000;

	return indice;
}

/*--------------------------------------------------------------------------*/
void inserir( char info[] )
{
	int funcao_hash;
	
	funcao_hash = faz_hash( info );

	//printf("hash = %d info= %s \n", funcao_hash, info );

	tabela[funcao_hash] = inserir_adjacente( tabela[funcao_hash], info);
}


/*--------------------------------------------------------------------------*/
void imprimir( No *g[] )
{
	int i;
	No *atual;

	for ( i = 0; i < TAMANHO; i++ )
	{
		if ( g[i] == NULL )
			printf( "%d -> .\n", i );
		else
		{

			atual = g[i];
			
			printf( "%d ->", i );
	
			while( atual != NULL )
			{
				printf( " %s ", atual->info );
				atual = atual->prox;
			}
	
			printf("\n");
		}
	}
}

/*--------------------------------------------------------------------------*/
int busca_lista( No *lista, char chave[] )
{
	No *c;
	int achou = -1;
	int i = 0;

	c = lista;

	while( c != NULL && achou == -1 )
	{
		if ( !strcmp(c->info,chave ) )
		{
			achou = i;
		}
		else
		{
			i++;
			c = c->prox;
		}
	}

	return achou;
}

/*--------------------------------------------------------------------------*/
int busca_hash( char chave[] )
{
	int achou;
	int indice;

	indice = faz_hash( chave );

	achou = busca_lista( tabela[indice],chave );

	return achou;
}

/*--------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	char busca[3000][15];
	int i;
	int achou;
	double start,stop,elapsed;
	char chave[15];
	int min,seg,visualizacao,qualidade;
	float opiniao;
	char arq1[50];
	char arq2[50];

	strcpy(arq1, argv[1] );
	strcpy(arq2, argv[2] );

	// inicializa a tabela hash
	for ( i = 0; i < TAMANHO; i++ )
		tabela[i] = NULL;

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
		inserir(chave);
		i++;
	}	
	
	fclose(arquivo);
	
	// abre o arquivo texto dos videos para procurar
 	FILE *arquivo2 = fopen(arq2, "r");

	i = 0;

	while ( !feof( arquivo2 ) && i < 3000 )
 	{
		fscanf(	arquivo2 ,"%s", chave );
		strcpy( busca[i], chave );
		i++;
	}	
	
	fclose( arquivo2 );

	// imprime a tabela hash
	printf("\nTabela Hash\n");
	imprimir( tabela );
	printf("\n");
	
	//-----------------------------------------------------------------------------
	printf( "busca hash:\n" );

	start = (double) clock() / CLOCKS_PER_SEC;
	
	achou = -1;
	
	for ( i = 0; i<3000; i++)
	{
		achou = busca_hash(busca[i]);

		if ( achou >= 0 )
			printf("[%d] %s encontrado ^_^\n ",i, busca[i] );
		else
			printf("%s nao encontrado =(\n",busca[i]);
	}
	
	stop = (double) clock() / CLOCKS_PER_SEC;
	
	elapsed = (double) stop - start;

	printf("em %f segundos\n", elapsed );
	
	return 0;
}
