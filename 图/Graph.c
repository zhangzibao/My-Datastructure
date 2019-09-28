#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include <stdbool.h>

#define Graph_vm  5

int Vertex[Graph_vm] = {0, 1, 2, 3, 4}; // 顶点集
bool Visited[Graph_vm] = {false}; // 顶点是否访问过
int A[Graph_vm][Graph_vm] = {0}; // 邻接矩阵 
AdjGraph adj; // 邻接表 

void visit(int v){
	
	printf("visted: %d ", v);
	Visited[v] = true;	
}

int GraphForEach() {
    int i;
    CreateGraph(A);
    // 广度优先遍历 
    for (i = 0; i < Graph_vm; ++i) {
        if (!Visited[i]) {
            BFS(i);
        }
    }
    printf("\n");

    for (i = 0; i < Graph_vm; ++i) {
        Visited[i] = false;
    }
    // 深度优先遍历
    for (i = 0; i < Graph_vm; ++i) {
        if (!Visited[i]) {
            DFS(i);
        }
    }

    // SaveGraph(A,Graph_vm,Graph_vm);
    printf("\n");
    return 0;
}

void CreateGraph() {
    FILE *fp;
    char ch;
    fp = fopen("G1.txt", "r");
    ch = fgetc(fp);
    int i = 0, j = 0;
    if (fp != NULL) {
        while (ch != EOF) {
            if (ch == '\n') {
                i++;
                j = 0;
            } else if (ch == ' ') {
                j++;
            } else {
                A[i][j] = (int) (ch - '0');
            }
            ch = fgetc(fp);
        }
    } else {
        printf("打开失败");
        return;
    }
    fclose(fp);
}

void SaveGraph() {
    FILE *fp;
    char ch;
    fp = fopen("saveG1.txt", "w+");
    if (fp != NULL) {
        int i, j;
        for (i = 0; i < Graph_vm; ++i) {
            for (j = 0; j < Graph_vm; ++j) {
                fprintf(fp, "%d", A[i][j]);
                if (j < Graph_vm - 1) {
                    fprintf(fp, " ");
                }
            }
            fprintf(fp, "\n");
        }
    } else {
        printf("打开失败");
        return;
    }
    fclose(fp);
}

void printArray(int A[][Graph_vm], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void BFS(int v) {
	visit(v);
    int Q[Graph_vm] = {0}, top = -1, rear = -1;

    Q[++rear] = v;
    while (rear != top) {
        v = Q[++top];
        int j;
        for (j = 0; j < Graph_vm; j++) {
            if (A[v][j] == 1 && !Visited[j]) {
                Q[++rear] = j;
                visit(j);
            }
        }
    }
}

void DFS(int v) {
	visit(v);
    int S[Graph_vm], top = -1;
    int j = 0;
    // 这里没有回退的步骤 
    while (j < Graph_vm) {

        if (A[v][j] == 1 && !Visited[j]) {
      		visit(j);
            // 往更深一层走并入栈 
            v = j;
            S[++top] = v;
            j = -1;
        }
        j++;
        // 回退 
        if (j == Graph_vm && top != -1) {
            v = S[top];
            top--;
            j = 0;
        }
    }
}
