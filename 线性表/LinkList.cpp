#include <stdio.h>
#include <stdlib.h>

/* all the list have the head node*/
typedef struct LinkList{
	int data; // elementType data[];
	struct LinkList* next;
}LinkList,*List;

void OutList( List L);

List CreateList(){
	List L = (List)malloc(sizeof(LinkList));
	L->next = NULL;
	int A[] = { 5, 2, 1, 3, 6, 3, 3, 9, 7, 3 }, n = 10;
	for(int i = 0; i < n; i++){
		List p = (List)malloc(sizeof(LinkList));
		p->data = A[i];
		p->next = NULL;
		p->next = L->next;
		L->next = p;
	}
	return L;
}

/** have the head-node**/
void deleteX( List node, int x){
	List temp = NULL;
	if(node->next!= NULL){
		if(node->next->data == x){
			temp = node->next;
			node->next = node->next->next;
			free(temp); // delete(node->next);
		}
		deleteX(node->next, x);
	}
}
/** don't have the head-node 
	has something wrong
**/
void deleteX2( List node, int x){
	if(node == NULL){
		return;
	}
	List temp = NULL;
	if(node->data == x){
		temp = node->next;
		free(node);
		node = temp;		
	}else{
		node = node->next;
	}
	deleteX2(node, x);
}
/** have the head-node
	no-recurrence
 **/
void deleteX3( List L, int x){

	List p = L->next;
	List pre = L;
	while(p != NULL){
		if(p->data == x){
			List temp = p->next;
			free(p);
			pre->next = temp;
			p = pre->next;
		}else{
			pre = p;
			p = p->next;
		}
	}
}
/** Reverse print**/
void R_Print(List L){
	if(L == NULL){
		return;
	}
	R_Print(L->next);
	
	printf("%d, ", L->data);
}

/** Reverse the List and no-other-space**/
void ReverseList(List L){
	List r = L->next, q = r->next;
	r->next = NULL;
	while(q != NULL){
		List temp = q->next;
		q->next =  r;
		r = q;
		q = temp;	
	}
	L->next = r;
}
/** InsertSort based on List **/
void InsertSort2(List L){
	List new_L = (List)malloc(sizeof(LinkList));
	List p = L->next->next;
	new_L->next = L->next;
	new_L->next->next = NULL;
	while(p != NULL){	
		List q = new_L;
		while(q->next != NULL && q->next->data < p->data){
			q = q->next;
		}
		if(q->next != p){
			List tem1 = q->next;
			List tem2 = p->next;
			q->next = p;
			p->next = tem1;
			p = tem2;
		}else{
			p = p->next;	
		}	
	}
	L->next = new_L->next;
	free(new_L);
}
int main( void )
{
	
	/* create List */
	List L = CreateList();
	// deleteX3(L, 3);
	InsertSort2(L);
	OutList(L);
	printf( "\n" );
	return(0);
}

void OutList( List L )
{
	List p = L->next;
	
	while(p != NULL){
		printf( "%-d\t", p->data );
		p = p->next;
	}
	printf( "\n" );
}
