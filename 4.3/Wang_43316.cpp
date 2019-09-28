#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
#define N 20

using namespace std;
typedef struct BiTNode{
    char data;
    struct BiTNode* lchild,* rchild; // ×óÓÒº¢×Ó
}*BTree,BNode;

bool Wang_43316(BTree T1,BTree T2){
	
	if((T1 == NULL && T2 ==NULL)){
		return true;
	}else if(T1 != NULL && T2 !=NULL){
		return Wang_43316(T1->lchild,T2->rchild)&&Wang_43316(T1->rchild,T2->rchild);
	}else{
		return false;
	}
}
int main(){
	char *pre = "ABCDEFG";
	// cout<<Wang_43314(T);
 	Wang_43315(pre,0,6);
 	int i = 0;
	while(Post[i]!='\0'){
		cout<<Post[i];
		i++; 
	}
	cout<<endl;
	return 0;
}
