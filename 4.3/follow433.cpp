#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#define n = 5;
typedef struct BiTNode{
    int weight;
    struct BiTNode* lchild,* rchild; // ×óÓÒº¢×Ó
}*BTree,BNode;
int wang_43319(BTree T,int h){
	if(T!=NULL){
		return T->data*h+wang_43319(T->lchild,h+1)+wang_43319(T->rchild,h+1);	
	}else{
		return 0;
	}
}
int main(){
	char A[] = {'A','B','C','E','D','F','\0'};
	char B[] = {'C','B','E','A','F','D','\0'};
	BTree T = out_BinaryTree(A,B,0,5,0,5);
/*
	int num = wang_4338(T);
	cout<<num<<endl;
	PreOrder(T);*/
	cout<<wang_43310(T,2);
	cout<<endl;
	return 0;
}