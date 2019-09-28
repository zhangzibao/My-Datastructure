#include "Graph.c"

extern int Vertex[];
extern bool Visited[];
extern int A[Graph_vm][Graph_vm];
extern AdjGraph adj;

void Mat_to_Adj(int Mat[Graph_vm][Graph_vm]);

void adjDFS(int v);

void adjBFS(int v);

void DFS2(int v);

void D_IsExistPath(int vi, int vj);

void B_IsExistPath(int vi, int vj);

void FindAllPath(int vi, int vj, int path[], int d); 

// void ExistPath(int u, int v, bool &has);

int main() {
    CreateGraph(A);
    Mat_to_Adj(A);
    // adjDFS(0);
    //adjBFS(4);
    int path[10] = {0};
    FindAllPath(0, 4, path, -1);
    // printArray(A, Graph_vm, Graph_vm);
    printf("\n");
    return 0;
}

void Mat_to_Adj(int Mat[Graph_vm][Graph_vm]) {

    int i, j, e = 0;
    // 初始化顶点个数
    adj.n = Graph_vm;
    // 初始化顶点表 
    for (i = 0; i < Graph_vm; ++i) {
        VNode vnode = {.fristarc = NULL, .info = i};
        adj.adjlist[i] = vnode;
    }
    // 初始化边表 
    for (i = 0; i < Graph_vm; ++i) {
        int flag = 0; // 记录是否为首个邻接节点 
        ArcNode *p = NULL;
        for (j = 0; j < Graph_vm; ++j) {
            if (Mat[i][j] == 1) {
                ArcNode *tmp_node = (ArcNode *) malloc(sizeof(ArcNode));
                tmp_node->adjvex = j;
                tmp_node->weight = 0;
                tmp_node->nextarc = NULL;
                if (!flag) {
                    adj.adjlist[i].fristarc = tmp_node;
                    p = adj.adjlist[i].fristarc;
                    flag = 1;
                } else {
                    p->nextarc = tmp_node;
                    p = p->nextarc;
                }
                e++;
            }
        }
    }
    // 初始化边数 
    adj.e = e / 2;
    // printf("\ne: %d\n", adj.e);
}

void adjDFS(int v){
	
	visit(v);
	ArcNode *p = NULL;
	p = adj.adjlist[v].fristarc;
	
	while(p != NULL){
		if(!Visited[p->adjvex]){
   			adjDFS(p->adjvex);
		}
		p = p->nextarc;
	}
}

void adjBFS(int v){
	
	visit(v);
	int Q[Graph_vm] = {0}, w = 0 , front = -1, rear = -1;
	ArcNode *p = NULL;
	Q[++rear] = v;
	while(rear != front){
		p = adj.adjlist[Q[++front]].fristarc;
		while(p != NULL){
			w = p->adjvex;
			if(!Visited[w]){
				visit(w);
				Q[++rear] = w;
			}
			p = p->nextarc;
		}
	}
}

void DFS2(int v) {
	visit(v);
    int S[Graph_vm],top = -1,temp_v;
    S[++top] = v;
	temp_v = v;
 	ArcNode *p = NULL;
 	
    while (top != -1 || p != NULL) { 
        p = adj.adjlist[temp_v].fristarc;
        while (p != NULL) {
        	
            if (!Visited[p->adjvex]) {
            	
                visit(p->adjvex);
                temp_v = p->adjvex;
                S[++top] = p->adjvex;
                break;
            }
            p = p->nextarc;
        }
        
        if (p == NULL && top != -1) {
            temp_v = S[top];
            top--;
        }
    }
}

void B_IsExistPath(int vi, int vj) {
    printf("visted: %d ", vi);
    Visited[vi] = true;
    int Q[Graph_vm], front = -1, rear = -1;
    Q[++rear] = vi;
    int flag = 0; // 标记是否找到路径 
    int temp;
    while ( rear != front ) {
    	temp = Q[++front];
        ArcNode *p = adj.adjlist[temp].fristarc;
        while (p != NULL) {
            if (!Visited[p->adjvex]) {
                Visited[p->adjvex] = true;
                printf(" go through %d ", p->adjvex);
                Q[++rear] = p->adjvex;
                if (vj == p->adjvex) {
                    flag = 1;
                    printf("\n已找到Vi:%d 和 vj:%d 之间的一条路径\n",vi,vj);
                    return;
                }
            }
            p = p->nextarc;
        }
    }
    printf("\nVi 和 vj 之间的没有路径\n");
}

void D_IsExistPath(int vi, int vj) {
    printf("visted: %d ", vi);
    Visited[vi] = true;
    
    int S[Graph_vm];
    int top = -1, flag = 0,temp;
    S[++top] = vi;
    temp = vi;
    ArcNode *p = NULL;
    while (top != -1 || p!=NULL) { // N 为 0 代表所有的顶点都已经被访问 
    	p = adj.adjlist[temp].fristarc;
        while (p != NULL) {
            if (!Visited[p->adjvex]) {
                printf("visted: %d ", p->adjvex);
                Visited[p->adjvex] = true;
                temp = p->adjvex;
                S[++top] = p->adjvex;
          		if (vj == p->adjvex) {
                    flag = 1;
                    printf("\n已找到Vi:%d 和 vj:%d 之间的一条路径\n",vi,vj);
                    return;
                }
                break;
            }
            p = p->nextarc;
        }
        if (p == NULL && top != -1) {
            temp = S[top];
            top--;
        }
    }
}

/*
void ExistPath(int u, int v, bool &has){
	int w;
	ArcNode *p;
	Visited[u] = true;
	if(u == v){
		has = true;
		return;
	}
	p = adj.adjlist[u]->fristarc;
	while(p != NULL){
		w = p->adjvex;
		if(!Visited[w]){
			ExistPath(w, v, has);
		} 
		p = p->nextarc
	}
}*/

void FindAllPath(int vi, int vj, int path[], int d){
	int w, i;
	ArcNode *p;
	d++;
	path[d] = vi;
	Visited[vi] = true;
	if(vi == vj){
		int i = 0;
		while(i < d){
			printf("%d ->",path[i]);
			i++;
		}
		printf("%d\n",path[d]);
	}
	p = adj.adjlist[vi].fristarc;
	while(p != NULL){
		w = p->adjvex;
		if(!Visited[w]){
			FindAllPath(w, vj, path, d);
		}
		p = p->nextarc;
	}
	Visited[vi] = false; // 注意这步操作！！ 
}
