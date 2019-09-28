#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
#define N 20
using namespace std;
typedef struct node{
    char data[10];
    struct node *left, *right; // ×óÓÒº¢×Ó
}BTree;
void InOrder(BTree *T,int deep){
	if(T != NULL){
		if(T->left == NULL&&T->right == NULL){
			cout<<T->data[0];
		}
		else{
			if(deep > 1){
				cout<<"(";					
			} 
			InOrder(T->left,deep+1);
			cout<<T->data[0];
			InOrder(T->right,deep+1);
			if(deep > 1){
				cout<<")";					
			} 
		}
	}
}
void InOrder2(BTree *T){
	BTree *S[N];
	int top = -1;
	BTree *p = T;
	while(top != -1 || p!=NULL){
		if(p != NULL){
			S[++top] = p;
			p = p->left;
		}else{
			p = S[top];
			top--;
			cout<<p->data[0];
			p = p->right; 
		}
	}
}
void CreateBTree(BTree* &T, char str[]) {
    BTree *S[N];
    int top = -1, i = 0, k = 0;
    BTree *p = NULL;
    while (str[i] != '\0') {
        switch (str[i]) {
            case '(':
            	S[++top] = p;
                k = 1;
                break;
            case ')':
                top--;
                break;
            case ',':
                k = 2;
                break;
            default:
            
                p = (BTree *) malloc(sizeof(struct node));
                p->data[0] = str[i];
                p->left = NULL;
                p->right = NULL;
                
                if (T == NULL) {
                    T = p;
                } else {
                    switch (k) {
                        case 1:
                        	S[top]->left = p; 
                            break;
                        case 2:
                            S[top]->right = p; 
                            break;
                        default:
                            break;
                    }
                }
                break;
        }
        i++;
    }
}
void InExpression(BTree T){
	
}
int main(){
	BTree *B = NULL;
    char *str = "*(+(a,b),*(c,-(,d)))";
    CreateBTree(B,str);
    InOrder(B,1);
    InOrder2(B);
	cout<<endl;
	return 0;
}
