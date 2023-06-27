#include <stdio.h>
#include <stdlib.h>

/* definição da estrutura de dados */
typedef struct no No;

struct no
{
	int dado;
	No* prox;
};

/*--------------------------------------------------------------------------*/
No* criar()
{
	return NULL;
}

/*--------------------------------------------------------------------------*/
No* inserir( No *lista, int dado )
{
	No *novo;

	novo = (No *)malloc( sizeof( No ) );
	novo->dado = dado;
	novo->prox = lista;
	
	return novo;
}

/*--------------------------------------------------------------------------*/
No* excluir( No *lista )
{
	No *temp;

    temp = lista;

    lista = lista->prox;

    free(temp);

	return lista;

}

/*--------------------------------------------------------------------------*/
void imprimir( No *lista )
{
	No *temp;

	temp = lista;
	
	while( temp != NULL )
	{
		printf( "%d ", temp->dado );
		temp = temp->prox;
	}
	
	printf("\n");
}
