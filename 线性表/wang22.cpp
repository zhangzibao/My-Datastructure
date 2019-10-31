#include <stdio.h>
#include <stdlib.h>

/* find the midium-number in sorted sequence S1 and S2 */
void wang11(int	*S1,int *S2, int n1, int n2);

/* find the host-number in one-d array */
int wang12(int *A, int n);

/* find the unshowed min-int in the array*/
int wang13(int *A, int n);

int main(void){	

	int A[] = {3,2,4}, n = 3;
	int min_int = wang13(A, n);
	printf("The unshowed min-int: %d", min_int);
	printf("\n");	
	return 0;
}

void wang11(int	*S1,int *S2, int n1, int n2){
	
	int s1[] = {11,13,15,17,19,20,21,23,25}, N1 = 9;
	int s2[] = {2,4,6,10}, N2 = 4;
	
	int i = 0, j = 0, mid = (n1 + n2 + 1)/2, k = 0, index = 0;
	while(k < mid){
		if(i < n1 && j < n2 && S1[i] < S2[j]){
			index = S1[i];
			i++;
		}else if(j < n2){
			index = S2[j];
			j++;
		}else{
			index = S1[i];
			i++;
		}
		k++;
	}
	printf("the midium-number of S1-S2: %d \n",index);
}

int wang12(int *A, int n){
	int A_[] = {0,5,5,3,5,7,5,5}, n_ = 8;
	
	int *B = (int *)calloc(n ,sizeof(int));
	int host;
	for(int i = 0;i<n;i++){
		B[A[i]]++;
	}
	for(int i = 0;i<n;i++){
		if(B[i] > n/2 ){
			host = i;
			printf("the host-number:%d\n", host);
			return host;
		}
	}
	printf("no host-number\n", host);
	return -1;
}

int wang13(int *A, int n){
	int *B = (int *)calloc(n, sizeof(int));
	for(int i = 0;i<n; i++){
		B[A[i] - 1]++;
	}
	int j;
	for(j = 0;j<n; j++){
		if(B[j]==0){
			return j+1;
		}
	}
	return j+1;
}
