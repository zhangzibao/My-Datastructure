#include <stdio.h>
void printArray(int arr[],int length);
void changeArray(int arr[],int length){
	int i = 0;
	for(;i<length;++i){
		arr[i] *= arr[i];
	}
}
int main(){
	int arr[6] = {[1]=5,4,2,[5]=3 };
	int length = sizeof(arr)/sizeof(arr[0]);
	printArray(arr,length);
	changeArray(arr,length);
	printArray(arr,length);
	return 0;
}
void printArray(int arr[],int length){
	int i = 0;
	for(;i<length;++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
