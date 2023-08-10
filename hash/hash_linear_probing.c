/*------------------------------------------------------------------
	Universidade Federal de Minas Gerais
	Escola de Engenharia
	Programa de Pós-Graduação em Engenharia Elétrica
	Estrutura de Dados e Algoritmos para Eng da Computação
	Prof: Diogenes Cecilio
	Aluno: Jucimar Junior ( jucimar.jr@gmail.com )

	Tabela Hash linear probing

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

long qtde_probs = 0;


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
void inserir_hash_linear_prob( int info )
{
	int funcao_hash;
	int temp;

	// 99991 é o maior primo antes de 10^5
	funcao_hash = info % 99991;

	// faz o linear probing
	// insere se estiver null
	// senão vai procurando 1 null
	if ( tabela[funcao_hash] == NULL )
		tabela[funcao_hash] = inserir_adjacente( tabela[funcao_hash], info);
	else
	{
		temp = funcao_hash;

		while( tabela[temp] != NULL )
		{
			qtde_probs++;
			temp++;
			if ( temp > 99999 )
				temp = 0;
		}
		
		tabela[temp] = inserir_adjacente( tabela[temp], info);
	}
}

/*--------------------------------------------------------------------------*/
void inserir( int info )
{
	int funcao_hash;

	// 99991 é o maior primo antes de 10^5
	funcao_hash = info % 99991;

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
		inserir_hash_linear_prob( valor );
		if ( i % 1000 == 0 )
		{
			printf( "qtde probs até %d = %d\n", i, qtde_probs );
			qtde_probs = 0;
		}
		
	}


	printf("\nTabela Hash\n");
	imprimir( tabela );
	printf("\n");

	return 0;
}
