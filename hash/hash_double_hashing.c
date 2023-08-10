/*------------------------------------------------------------------
	Universidade Federal de Minas Gerais
	Escola de Engenharia
	Programa de Pós-Graduação em Engenharia Elétrica
	Estrutura de Dados e Algoritmos para Eng da Computação
	Prof: Diogenes Cecilio
	Aluno: Jucimar Junior ( jucimar.jr@gmail.com )

	Tabela Hash Double Hashing

	Questão 2b

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
void inserir_hash_double_hashing( int info )
{
	int funcao_hash;
	int double_hashing;

	// 99991 é o maior primo antes de 10^5
	funcao_hash = info % 99991;

	// insere usando a funcao hash
	// se a posicao nao for nulo
	// faz o double hashing
	if ( tabela[funcao_hash] == NULL )
		tabela[funcao_hash] = inserir_adjacente( tabela[funcao_hash], info);
	else
	{
		
		// funcao double hashing
		double_hashing = info % 89989;

		tabela[double_hashing] = 
			inserir_adjacente( tabela[double_hashing], info);
	}
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
		inserir_double_hashing( valor );
	}

	printf("\nTabela Hash\n");
	imprimir( tabela );
	printf("\n");
	
	return 0;
}
