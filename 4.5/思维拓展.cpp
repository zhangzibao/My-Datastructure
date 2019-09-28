#include <cstdlib>
#include <iostream>
using namespace std;
#define n = 5;

typedef struct BiTNode{
    int weight;
    struct BiTNode* lchild,* rchild; // ×óÓÒº¢×Ó
}*BTree,BNode;
void PreOrder(BTree T){
	if(T != NULL){
		cout<<T->weight;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InsertTree(BTree &root, int weight, int direction){
	BTree T = (BTree)malloc(sizeof(BNode));
	T->weight = weight;
	T->lchild = NULL;
	T->rchild = NULL;
	if(root == NULL){
		root = T;
		return;
	}
	switch(direction){
		case 0:
			root->lchild = T;
			break;
		case 1:
			root->rchild = T;
			break;
		default:
			break;
	}	
}
BTree CreateTree(){
	BTree root = NULL;
	InsertTree(root,10,0);
	InsertTree(root,5,0);
	InsertTree(root,12,1);
	InsertTree(root->lchild,4,0);
	InsertTree(root->lchild,7,1);
	return root;
}
void FindPath(BTree root, int path[], int d, int sum_weight, int the_weight){
	if(root != NULL){
		sum_weight += root->weight;
		d++;
		path[d] = root->weight;
		if(root->lchild == NULL && root->rchild == NULL && sum_weight == the_weight){
			int i = 0;
			while(i < d){
				printf("%d-> ",path[i]);
				i++;
			}
			printf("%d\n", path[d]);
		}
		FindPath(root->lchild, path, d, sum_weight, the_weight);
		FindPath(root->rchild, path, d, sum_weight, the_weight);
	}
}
int main(){
	BTree T = CreateTree();
	int path[10] = {0};
	FindPath(T, path, -1,0 ,22);
	// PreOrder(T);
	cout<<endl;
	return 0;
}
