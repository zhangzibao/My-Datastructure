#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
#define N 20

using namespace std;
typedef struct BiTNode{
    char data;
    struct BiTNode* lchild,* rchild; // ���Һ���
}*BTree,BNode;
// ��֪���������������У������������ 
char Post[N];
int index = 0;


int Wang_43315(char *pre,int l1,int h1){
	/** 1. �����������л�ԭ����������������������� 
		2. �ҳ���������������������������еĹ�ϵ
		
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
