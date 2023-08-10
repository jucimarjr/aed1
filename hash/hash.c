/*------------------------------------------------------------------
	Universidade Federal de Minas Gerais
	Escola de Engenharia
	Programa de Pós-Graduação em Engenharia Elétrica
	Estrutura de Dados e Algoritmos para Eng da Computação
	Prof: Diogenes Cecilio
	Aluno: Jucimar Junior ( jucimar.jr@gmail.com )

	Tabela Hash 

	Questão 2a

-------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/* definição da estrutura de dados */
typedef struct no No;

struct no
{
	int info;
	No* prox;
};

No *tabela[100000];

/*--------------------------------------------------------------------------*/
No *inserir_adjacente( No *lista, int info )
{
	No *novo;
	novo = (No *)malloc( sizeof( No ) );
	novo->info = info;
	novo->prox = lista;
	
	return novo;
}

/*--------------------------------------------------------------------------*/
void inserir( int info )
{
	int funcao_hash;

	// 99991 é o maior primo antes de 10^5
	funcao_hash = info % 99991;

	printf("hash = %d info= %d \n", funcao_hash, info );

	tabela[funcao_hash] = inserir_adjacente( tabela[funcao_hash], info);
}


/*--------------------------------------------------------------------------*/
void imprimir( No *g[] )
{
	int i;
	No *atual;

	for ( i = 0; i < 100000; i++ )
	{
		if ( g[i] == NULL )
			printf( "%d -> .\n", i );
		else
		{

			atual = g[i];
			
			printf( "%d ->", i );
	
			while( atual != NULL )
			{
				printf( " %d ", atual->info );
				atual = atual->prox;
			}
	
			printf("\n");
		}
	}
}

/*--------------------------------------------------------------------------*/
int main()
{
	int i;
	int valor;

	for ( i = 0; i < 100000; i++ )
		tabela[i] = NULL;
	
	for ( i = 0; i < 100000; i++ )
	{
		scanf("%d", &valor );
		inserir( valor );
	}

	printf("\nTabela Hash\n");
	imprimir( tabela );
	printf("\n");
	
	return 0;
}
