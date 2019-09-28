#define MAXV 20
#define INF 32767
#define InfoType int

// 邻接表 
typedef struct ANode {
	int adjvex;
	int weight;
	struct ANode *nextarc;
}ArcNode;
typedef struct VNode{
	InfoType info;
	ArcNode *fristarc;
}VNode;
typedef struct AdjGraph{
	VNode adjlist[MAXV];
	int n,e;
}AdjGraph;

// 邻接矩阵
typedef struct{
	int id;
	InfoType info;
}VertexType;
typedef struct{
	int edges[MAXV][MAXV];
	int n,e;
	VertexType vexs[MAXV];
}MatGraph;

void visit(int v);

// 以下是邻接矩阵的操作 

void CreateGraph();

void SaveGraph();

void BFS(int v);

void DFS(int v);

// 以上是邻接矩阵的操作 

