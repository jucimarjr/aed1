#include "lista_encadeada.h"

int main(int argc, char** argv)
{
    Descritor *d;

	d = criar();
	
	d->lista = inserir( d, 15 );
	d->lista = inserir( d, 25 );
	d->lista = inserir( d, 45 );
	d->lista = inserir( d, 55 );
	d->lista = inserir( d, 51 );
	d->lista = inserir( d, 59 );
	d->lista = inserir( d, 53 );
	d->lista = inserir( d, 12 );
	
	imprimir( d );

	d->lista = excluir( d );
	d->lista = excluir( d );
	d->lista = excluir( d );
	
	imprimir( d );

	return 0;
}