#include "lista_encadeada.h"

int main(int argc, char** argv)
{
    No *lista;

	lista = criar();
	
	lista = inserir( lista, 15 );
	lista = inserir( lista, 25 );
	lista = inserir( lista, 45 );
	lista = inserir( lista, 55 );
	lista = inserir( lista, 51 );
	lista = inserir( lista, 59 );
	lista = inserir( lista, 53 );
	lista = inserir( lista, 12 );
	
	imprimir( lista );

	lista = excluir( lista );
	lista = excluir( lista );
	lista = excluir( lista );
	
	imprimir( lista );

	printf("%d\n", buscar(lista, 59) );
	printf("%d\n", buscar(lista, 55) );

	return 0;
}