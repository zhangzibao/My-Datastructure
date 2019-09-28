#include <cstdlib>
#include <stdio.h>
void findpath(int arr[],int i){
	i++;
	arr[i] = i;
	if( i < 5 ){
		findpath(arr, i);		
	}
} 

int main(void){
	int a[13] = {0};
	findpath(a,0);
	int i = 0;
	while(i<13){
		printf("%d,",a[i]);
		i++; 
	}
	
	return 0;
}
