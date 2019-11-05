#include <stdio.h>
#include <stdlib.h>

void OutArray( int Array[], int n );

int partition2(int *A, int n){
	int obj = A[0], i = 0, j = n - 1;
	while(i < j){
		while( i < j && A[j] > obj){
			j--;
		}
		A[i] = A[j];
		while( i < j && A[i] <= obj){
			i++;
		}
		A[j] = A[i];
	}
	A[i] = obj;
	return i ;
}

/** if L , length = L->length, A = L->data **/
void move1(int *A, int n){
	int i = 0, j = n - 1;
	while( i < j){
		while(i < j && A[j] % 2 == 0){
			j--;
		}
		while(i < j && A[i] % 2 == 1){
			i++;
		}
		if( i < j){
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
}

void move2(int *A, int n){
	int i = -1;
	for(int j = 0;j < n;j++){
		if( A[j]%2 == 1){
			i++;
			if(i!=j){
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
}

int main( void )
{
	int A[] = { 5, 2, 1, 4, 6, 8, 10, 9, 7, 3 }, n = 10;
	/* create List */
	move2(A, n);
	OutArray(A, n);

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