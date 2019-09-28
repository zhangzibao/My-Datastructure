#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
#define N 20

using namespace std;
typedef struct BiTNode{
    char data;
    struct BiTNode* lchild,* rchild; // 左右孩子
}*BTree,BNode;
// 已知满二叉树先序序列，求其后序序列 
char Post[N];
int index = 0;


int Wang_43315(char *pre,int l1,int h1){
	/** 1. 根据先序序列还原满二叉树，再输出后序序列 
		2. 找出满二叉树中先序序列与后序序列的关系
		
	**/ 
	int len = (h1 - l1)/2;
	if(len != 0){
		Wang_43315(pre,l1+1,l1+len);
		Wang_43315(pre,l1+len+1,h1);
	}
	Post[index] = pre[l1];
	index++;
	Post[index] = '\0';
	// Post += pre[11];
	// cout<<pre[l1];	
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
