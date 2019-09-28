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
void PreOrder(BTree T){
	if(T!=NULL){
		cout<<T->data;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(BTree T){ 
	if(T!=NULL){
		InOrder(T->lchild);
		cout<<T->data;	
		InOrder(T->rchild);
	}
}
BTree Out_BinaryTree(char A[],char B[],int l1,int h1,int l2, int h2){
	// A 先序序列
 	// B 中序序列
 	BTree root = (BTree) malloc(sizeof(BNode));
 	root->data = A[l1];
 	int i = l2;
 	for(;B[i]!=A[l1];i++);
 	int l_len = i - l2;
	int r_len = h2 - i;
	root->lchild = l_len?Out_BinaryTree(A,B,l1+1,l1+l_len,l2,i-1):NULL;
	root->rchild = r_len?Out_BinaryTree(A,B,l1+l_len+1,h1,i+1,h2):NULL;
	return root;
}
void Wang_4336(){
	char A[] = {'A','B','C','D','E','F','\0'};
	char B[] = {'C','B','A','E','D','F','\0'};
	BTree T = Out_BinaryTree(A,B,0,5,0,5);
	PreOrder(T);
	cout<<endl;
	InOrder(T);
	
}
void Wang_4337(BTree T){
	queue<BTree> Q;
	BTree p;
	Q.push(T);
	while(!Q.empty()){
		
		p = Q.front();
		Q.pop();
		if(p!=NULL){
			Q.push(p->lchild);
			Q.push(p->rchild);
		}else{
			while(!Q.empty()){
				if(Q.front()!=NULL){
					cout<<"T不是完全二叉树"<<endl;
					return ;
				}
				Q.pop();		
			}
		}	
	}
	cout<<"T是完全二叉树"<<endl;
	return ;	
}
int Wang_4338(BTree T){
	if(T!=NULL){
		if(T->lchild!=NULL&&T->rchild!=NULL){
			return Wang_4338(T->lchild)+Wang_4338(T->rchild)+1;
		}else{
			return Wang_4338(T->lchild)+Wang_4338(T->rchild)+0;
		}
	}else{
		return 0;
	}
}
void Wang_4339(BTree T){
	if(T!=NULL){
		BTree temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = temp;
		Wang_4339(T->lchild);
		Wang_4339(T->rchild);
	}
}
char Wang_43310(BTree T,int k){
	stack<BTree> S;
	S.push(T);
	BTree p;
	int i = 0;
	while(!S.empty()){
		p = S.top();
		if(++i==k){
			return p->data;	
		}
		// cout<<p->data;
		S.pop();
		if(p->rchild!=NULL){
			S.push(p->rchild);
		}
		if(p->lchild!=NULL){
			S.push(p->lchild);
		}
	} 
}
void Destory_tree(BTree T){
	if(T!=NULL){
		Destory_tree(T->lchild);
		Destory_tree(T->rchild);
		free(T);
	}
} 
void Wang_43311(BTree T,char x){
	if(T!=NULL){
		if(T->data == x){
			Destory_tree(T);
			T = NULL;
		}else{
			Wang_43311(T->lchild,x);
			Wang_43311(T->rchild,x);
		}
	}
}
void Wang_43312(BTree T,char x){
	stack<BTree> S;
	BTree p,pre;
	p = T;
	pre = T;
	while(!S.empty()|| p!=NULL){
		if(p->lchild!=NULL&&p->lchild!=pre&&p->rchild!=pre){
			S.push(p);
			p = p->lchild;
		}else if (p->rchild!=NULL&&p->rchild!=pre){
			if(S.top()!= p){
				S.push(p);
			}
			p = p->rchild;
		}else{
			// cout<<p->data;
			if(S.top() == p){
				S.pop();
			}
			if(p->data==x){
				while(!S.empty()){
					cout<<S.top()->data;
					S.pop();
				}
				break;
			}
			pre = p;
			p = S.empty()?NULL:S.top();
		}
	}
}
void Wang_43313(BTree root,BTree p0,BTree q0,BTree r0){
	stack<BTree> S,Sc;
	BTree p,pre;
	bool flag[] = {false,false};
	p = root;
	pre = root;
	while(!S.empty()|| p!=NULL){
		if(p->lchild!=NULL&&p->lchild!=pre&&p->rchild!=pre){
			S.push(p);
			p = p->lchild;
		}else if (p->rchild!=NULL&&p->rchild!=pre){
			if(S.top()!= p){
				S.push(p);
			}
			p = p->rchild;
		}else{
			// cout<<p->data;
			if(S.top() == p){
				S.pop();
			}
			if(p == p0 || p == q0){
				Sc = stack<BTree>(S);
				// Sc 是一节点的所有爸爸
				// S 另一节的所有爸爸
				// 从S和Sc里边找相同的爸爸且最靠近右边的爸爸
				// 所以 此时的S的第一个节点必然是先出来节点的爸爸。 
				cout<<"Sc: ";
				if(!Sc.empty()){
					while(!Sc.empty()){
						cout<<Sc.top()->data;
						Sc.pop();
					}
					cout<<endl;
					cout<<"S: ";
					while(!S.empty()){
						cout<<S.top()->data;
						S.pop();
					}
					cout<<endl;
					return ;
				}	
			}
			pre = p;
			p = S.empty()?NULL:S.top();
		}
	}
	r0 = NULL; 
}
void Wang_43313_copy(BTree root,char p0,char q0,char r0){
	
	BTree S[N],Sc[N];
	
	int top1 = -1,top2 = -1;
	
	BTree p = root,pre = root;
	
	while(top1 != -1 || p!=NULL){
		if(p->lchild!=NULL&&p->lchild!=pre&&p->rchild!=pre){
			S[++top1] = p;
			p = p->lchild;
		}else if (p->rchild!=NULL&&p->rchild!=pre){
			if(S[top1]!= p){
				S[++top1] = p;
			}
			p = p->rchild;
		}else{
			// cout<<p->data;
			if(S[top1] == p){
				top1--;
			}
			if(p->data == p0 || p->data == q0){
				// 第二次进入这个if判断里 
				if(top2 != -1){
					for(int i = top2 ;i>=0;i--){
						for(int j = top1 ;j>=0;i--){
							if(S[j]->data == Sc[i]->data){
								r0 = S[j]->data;
								cout<<"r0： "<<r0;	
								return;
							}
						}
					}
					r0 = '#'; 
					cout<<"r0： "<<r0;
					return;
				}	
				// 第一次匹配只复制：copy S to Sc;
				for(int i = 0;i<=top1;i++){
					Sc[++top2] = S[i];
				}
			}
			pre = p;
			p = top1 == -1?NULL:S[top1];
		}
	}
}
// 求非空二叉树的宽度 
int Wang_43314(BTree T){
	
	BTree Q[N];
	BTree p;
	int front = -1, rear = -1, last = 0, max_width = 0,width = 0;
	Q[++rear] = T;
	
	while(front != rear){
		
		p = Q[++front];
		width++;
		if(p->lchild != NULL){
			
			Q[++rear] = p->lchild;
			
		}
		if(p->rchild != NULL){
			
			Q[++rear] = p->rchild;
		}
		if(front == last){
			
			if(width > max_width){
				max_width = width;
			}
			last = rear;
			width = 0;
		}
	}
	return max_width;
}
int main(){
	char A[] = {'A','B','C','E','D','F','\0'};
	char B[] = {'C','B','E','A','F','D','\0'};
	BTree T = Out_BinaryTree(A,B,0,5,0,5);
	char r0;
	
/*
	int num = Wang_4338(T);
	cout<<num<<endl;
	PreOrder(T);*/
	// cout<<Wang_43310(T,2);
	// Wang_43313(T,T->lchild,T->lchild->rchild,r);
	// Wang_43313_copy(T,'E','C',r0);
	cout<<endl;
	return 0;
}
