#include "Graph.c"
#define VertexNum 6 
int VSet[VertexNum];
bool IsVisited[VertexNum] = {false};
int Mat[VertexNum][VertexNum]; // 有权的邻接矩阵 
void WeightVisited(int v){
	IsVisited[v] = true;
}
void CreateWeightGraph();
void OutputArray(int array[VertexNum][VertexNum], int rows, int cols);
void Prim(int v){
	int i = 0, j = 0, k = 1, CurrentV, CurrentMinDist, CurrentVSet[VertexNum] = {[0] = v};
	int Path[VertexNum] = {0};
	Path[v] = v;
	WeightVisited(v);
	while(k < VertexNum){
		int PreV = 0; 
		CurrentMinDist = INF;
		for(i = 0; i < k; i++){	
			CurrentV = CurrentVSet[i];
			for(j = 0; j < VertexNum; j++){
				if(!IsVisited[j] && Mat[CurrentV][j] != -1 && Mat[CurrentV][j] < CurrentMinDist){	
					CurrentMinDist = Mat[CurrentV][j];
					CurrentVSet[k] = j;
					PreV = CurrentV; // Path 记录上一个节点的值 (CurrentV,CurrentVSet[k])
				}
			}
		}
		Path[CurrentVSet[k]] = PreV;
		WeightVisited(CurrentVSet[k]);
		k++;
	}
	
	// 输出路径
	int S[VertexNum], top = -1;
	for(i = 0; i < VertexNum; i++){
		S[++top] = i;
		
		for(j = Path[i]; j != v; j = Path[j]){
			S[++top] = j;
		}
		S[++top] = v;
		for(k = top;k > 0; k-- ){
			printf("%d -> " ,S[k] + 1);
		}
		printf("%d \n" , S[0] + 1);
		top = -1;
	}
}
int main() {
    CreateWeightGraph();
    // OutputArray(Mat, VertexNum, VertexNum);
    int i = 0;
    Prim(0);
    
    printf("\n");
    return 0;
}
void CreateWeightGraph(){
	FILE *fp;
    char ch;
    fp = fopen("MinimumSpanningTree.txt", "r");
    ch = fgetc(fp);
    int i = 0, j = 0;
    if (fp != NULL) {
        while (ch != EOF) {
        	int IsNegative = 1;
        	switch(ch){
	        	case '\n':
	        	 	i++;
                	j = 0;
					break;
				case '\t':
					j++;
					break;
				case '-':
					IsNegative = -1;
					ch = fgetc(fp);
				default:
					Mat[i][j] = (ch - '0') * IsNegative;
					// printf("%c", ch);
					break;		
	        }
            ch = fgetc(fp);
        }
    } else {
        printf("打开失败");
        return;
    }
    fclose(fp);
}
void OutputArray(int array[VertexNum][VertexNum], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            printf("%d ",array[i][j]);
        }
        printf("\n");
	}
}
