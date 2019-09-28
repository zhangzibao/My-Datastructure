#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
#define N 20

using namespace std;
typedef struct CSNode{
    char data;
    struct CSNode	*firstchild, *nextsibling; // 第一个孩子和右兄弟指针 
}CSNode,*CSTree;
int num = 0;
void Wang_4445(CSTree C){
	if(C!=NULL){
		if(C->firstchild==NULL){
			num++;
		}else{
			Wang_4445(C->firstchild);		
		}
		Wang_4445(C->nextsibling);
	}	
}
int max_deep = 0;
void Wang_4446(CSTree C,deep){
	
	if(C != NULL ){
		
		if(deep>max_deep){
			
			max_deep = deep;
		}
		Wang_4445(C->firstchild, deep+1);	
		Wang_4445(C->nextsibling, deep);
	}
}
char level[],int d_level[];
void Wang_4447(char data,int i){
	
	
}
int main(){
	char A[] = {'A','B','C','E','D','F','\0'};
	char B[] = {'C','B','E','A','F','D','\0'};
	cout<<endl;
	return 0;
}
