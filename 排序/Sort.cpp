#include <stdlib.h>
#include <stdio.h>

#define MIN	-6555
#define MAX	6555
#define MAXD	10

typedef struct node
{
	int		data;
	struct node	*next;
} node;

void OutArray( int Array[], int n );

int partition( int Array[], int low, int high );

void QuickSort( int Array[], int low, int high );

void SelectSort( int Array[], int n );

void HeapSort( int Array[], int low, int high );

void Merge( int Array[], int low, int mid, int high );

void MergeSort( int Array[], int low, int high );

int GetRadix( int data, int order );


void RadixSort( node * &head, int radix, int degree );


void TestRadixSort();


int main( void )
{
	int A[] = { 2, 5, 1, 4, 6, 8, 10, 9, 7, 3 }, n = 10;
	/* create List */
	TestRadixSort();
	/*
	 * MergeSort(A, 0, 9);
	 * OutArray(A, n);
	 */
	printf( "\n" );
	return(0);
}


void OutArray( int Array[], int n )
{
	int i = 0;
	for (; i < n; ++i )
	{
		printf( "%-d\t", Array[i] );
	}
	printf( "\n" );
}


int partition( int Array[], int low, int high )
{
	int	i	= low, j = high;
	int	tmp	= Array[low];
	while ( i < j )
	{
		while ( j > i && tmp <= Array[j] )
		{
			j--;
		}
		Array[i] = Array[j];;
		while ( i < j && tmp >= Array[i] )
		{
			i++;
		}
		Array[j] = Array[i];
	}
	Array[i] = tmp;
	return(i);
}


void QuickSort( int Array[], int low, int high )
{
	if ( low >= high )
	{
		return;
	}
	int index = partition( Array, low, high );
	QuickSort( Array, low, index - 1 );
	QuickSort( Array, index + 1, high );
}


void SelectSort( int Array[], int n )
{
	int min, i, j;
	for ( i = 0; i < n - 1; i++ )
	{
		min = Array[i];
		for ( j = i + 1; j < n; j++ )
		{
			if ( Array[j] < min )
			{
				min		= Array[j];
				Array[j]	= Array[i];
				Array[i]	= min;
			}
		}
	}
}

void HeapSort( int Array[], int low, int high ){
	
}


void Merge( int Array[], int low, int mid, int high )
{
	int	*R1	= (int *) malloc( sizeof(int) * (mid - low + 2) ), front1 = -1, rear1 = -1;
	int	*R2	= (int *) malloc( sizeof(int) * (high - mid + 2) ), front2 = -1, rear2 = -1;
	int	i;

	for ( i = low; i <= mid; i++ )
	{
		R1[++rear1] = Array[i];
	}

	for (; i <= high; i++ )
	{
		R2[++rear2] = Array[i];
	}

	R1[++rear1] = R2[++rear2] = MAX;

	for ( i = low; i <= high; i++ )
	{
		if ( R2[front2 + 1] < R1[front1 + 1] )
		{
			Array[i] = R2[++front2];
		}else  {
			Array[i] = R1[++front1];
		}
	}

	free( R1 );
	free( R2 );
}


void MergeSort( int Array[], int low, int high )
{
	if ( low >= high )
	{
		return;
	}
	int mid = (low + high) / 2;
	MergeSort( Array, low, mid );
	MergeSort( Array, mid + 1, high );
	Merge( Array, low, mid, high );
}


int GetRadix( int data, int order )
{
/* È¡»ùÊý£¬@order 1:¸öÎ», 2:Ê®Î», ... */
	int i, num = data;
	for ( i = 0; i < order; i++ )
	{
		num	= data % 10;
		data	/= 10;
	}
	return(num);
}


void RadixSort( node * &head, int radix, int degree )
{
	node	*r_head[10], *r_tail[10], *p; /* 0,1,2,3,4,5,6,7,8,9 */
	int	i, j, currentR;
	for ( i = 1; i <= degree; i++ )	{
		
		/* ³õÊ¼»¯ */
		for ( j = 0; j < radix; j++ ){
			r_head[j] = r_tail[j] = NULL;
		}
		
		/* ·ÖÅä */
		p = head;
		while ( p != NULL ){
			currentR = GetRadix( p->data, i );
			if ( r_head[currentR] == NULL ){
				r_head[currentR]	= p;
				r_tail[currentR]	= p;
			}else{
				r_tail[currentR]->next	= p;
				r_tail[currentR]	= p;
			}
			p = p->next;
		}

		/* ÊÕ¼¯ */
		p = head = NULL;
		for ( j = 0; j < radix; j++ ){
			if ( r_head[j] != NULL ){
				if ( head == NULL ){
					head	= r_head[j];
					p	= r_tail[j];
				}else{
					p->next = r_head[j];
					p	= r_tail[j];
				}
			}
		}
		p->next = NULL;
	}
}


void TestRadixSort()
{
	int	A[]	= { 75, 23, 98, 44, 57, 12, 29, 64, 38, 82 }, n = 10;
	node	*head	= NULL;
	node	*p	= head;
	int	i	= 0;
	for (; i < n; ++i )
	{
		node *tmp = (node *) malloc( sizeof(node) );
		tmp->data	= A[i];
		tmp->next	= NULL;
		if ( p == NULL )
		{
			head	= tmp;
			p	= head;
		}else  {
			p->next = tmp;
			p	= tmp;
		}
	}
	RadixSort( head, 10, 2 );
	p = head;
	while ( p != NULL )
	{
		printf( "%d\t", p->data );
		p = p->next;
	}
	printf( "\n" );
}

