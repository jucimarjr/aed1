#include <stdio.h>
#include <stdlib.h>

/* definição da estrutura de dados */
typedef struct no No;

struct no
{
	int dado;
	No* prox;
};

/* definição do descritor */
typedef struct descritor
{
	int qtde;
	No* lista;
} Descritor;


/*--------------------------------------------------------------------------*/
Descritor* criar()
{
	Descritor *d;

	d = (Descritor *)malloc( sizeof( Descritor ) );
	d->qtde = 0;
	d->lista = NULL;
	
	return d;
}

/*--------------------------------------------------------------------------*/
No* inserir( Descritor *d, int dado )
{
	No *novo;

	novo = (No *)malloc( sizeof( No ) );
	novo->dado = dado;
	novo->prox = d->lista;
	d->qtde++;
	
	return novo;
}

/*--------------------------------------------------------------------------*/
void imprimir( Descritor *d )
{
	No *temp;

	temp = d->lista;
	
	while( temp != NULL )
	{
		printf( "%d ", temp->dado );
		temp = temp->prox;
	}
	
	printf("\n");
	printf("%d \n", d->qtde );

}


/*----------------------------------------------------------------------*/
No* excluir( Descritor *d )
{
	No *temp;

    temp = d->lista;
    d->lista = d->lista->prox;
	
	temp->prox = NULL;
    free(temp);

	d->qtde--;

	return d->lista;

}

