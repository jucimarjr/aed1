/*------------------------------------------------------------------
	Universidade Federal de Minas Gerais
	Escola de Engenharia
	Programa de Pós-Graduação em Engenharia Elétrica
	Estrutura de Dados e Algoritmos para Eng da Computação
	Prof: Guilherme Augusto
	Aluno: Jucimar Junior ( jucimar.jr@gmail.com )

	Ordena um vetor usando diversos métodos de ordenação

	exemplo de uso: usa quicksort e grava o tempo em q100.txt

	% ./ordenador q 100 < 100.txt > q100.txt
-------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge( int v[], int inicio, int meio, int fim )
{
	int i = inicio;
	int j = meio + 1;
	int k = 0;
	int aux[fim - inicio + 1];

	while ((i <= meio) && (j <= fim))
	{
		if (v[i] <= v[j])
		{
			aux[k] = v[i];
			i++;
		}
		else
		{
			aux[k] = v[j];
			j++;
		}
		k++;
	}

	if (i <= meio)
	{
		j = meio;
		
		while (j >= i)
		{
			v[fim - meio + j] = v[j];
			j--;
		}
	}

	for (i = 0;i < k;i++) 
		v[inicio + i] = aux[i];
}


void mergesort( int inicio, int fim, int v[] )
{
	if (fim <= inicio) return;

	int m = (fim+inicio)/2;
	
	mergesort( inicio, m, v );
	
	mergesort( m+1, fim, v );
	
	merge( v, inicio, m, fim );
}



/*--------------------------- quicksort --------------------------*/
int partition(int inicio, int fim, int v[] ) {
	int i = inicio-1, j = fim; 
	int x = v[fim];
	int t;
	
	for (;;) {
		while ( v[++i] < x ) ;
		while ( x < v[--j] ) if ( j == inicio ) break;
		if ( i >= j ) break;
		
		t = v[i];
		v[i] = v[j];
		v[j] = t;
	}
	
	t = v[i];
	v[i] = v[fim];
	v[fim] = t;
	
	return i;
}

void quicksort( int inicio, int fim, int v[] )
{
	if (fim <= inicio) return;
	
	int i = partition( inicio, fim, v );

	quicksort( inicio, i-1, v );
	quicksort( i+1, fim,v );
}


/*-------------------------- heapsort ------------------------*/
void heap_inserir( int m, int v[] )
{
	int t;
	int f = m + 1;
	
	while ( f > 1 && v[ f/2 ] < v[f] )
	{
		t = v[f/2];
		v[f/2] = v[f];
		v[f] = t;
		f = f/2;
	}
}

void heap_sacodir( int m, int v[] )
{
	int t;
	int f = 2;
	
	while ( f <= m )
	{
		if ( f < m && v[f] < v[ f + 1 ] ) ++f;
		
		if ( v[f/2] >= v[f] ) break;

		t = v[f/2];
		v[f/2] = v[f];
		v[f] = t;
		f *= 2;
	}
}

void heapsort( int n, int v[] )
{
	int m;

	for ( m = 1; m < n; m++ )
		heap_inserir( m, v );
	
	for ( m = n; m > 1; m-- )
	{
		int t = v[1];
		v[1] = v[m];
		v[m] = t;
		heap_sacodir( m - 1, v );
	}
}
	
/*-------------------------- fim heapsort ------------------------*/

void insertionsort(int inicio, int fim, int v[] )
{ 
	int i,j,t;

	for ( i = inicio+1; i <= fim; i++ )

	for ( j = i; j > inicio; j-- )
		if ( v[j-1] > v[j] )
		{
			t = v[j-1];
			v[j-1] = v[j];
			v[j] = t;
		}	
}


/*--------------------------- selectionsort --------------------------*/

void selectionsort( int inicio, int fim , int v[] )
{
	int i,j,t;

	for ( i = inicio; i < fim; i++ )
	{
		int min = i;
		
		for ( j = i+1; j <= fim; j++)
			if (v[j] < v[min]) min = j;
	
		t = v[min];
		v[min] = v[i];
		v[i] = t;
	}
}


void bubblesort( int inicio, int fim, int v[] )
{ 
	int i,j,t;

	for ( i = inicio; i < fim; i++)
		for ( j = fim; j > i; j--)

	if ( v[j-1] > v[j] )
	{
		t = v[j-1];
		v[j-1] = v[j];
		v[j] = t;
	}	
}


int main( int argc, char *argv[] )
{
	int n,i;

	char c;
		
	double start, finish, elapsed;
	
	n = atoi( argv[2] );

	c = *argv[1];

	int v[n];

	for ( i = 1; i < n; i++ )
		scanf("%d",&v[i] );

	start = (double) clock() / CLOCKS_PER_SEC;
	
	switch ( c )
	{
		case 'h': 
			heapsort(n,v);
			break;
		case 'i': 
			insertionsort(1,n,v);
			break;
		case 'b': 
			bubblesort(1,n,v);
			break;
		case 's': 
			selectionsort(1,n,v);
			break;
		case 'q': 
			quicksort(1,n,v);
			break;
		case 'm': 
			mergesort(1,n,v);
			break;
	}

	finish = (double) clock() / CLOCKS_PER_SEC;
	
	elapsed = (double) finish - start;

	printf( "%c %d %f\n", c, n, elapsed);
	
	//for ( i = 1; i < n; i++ )
	//	printf("%d ",v[i] );
	
	return( 0 );
	
}	
