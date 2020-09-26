#include <stdio.h>
#include <stdlib.h>
#define MVNum 100
typedef struct ArcNode {   //边结点 
	int adjvex; //与表头结点相邻的顶点编号 
	struct ArcNode * nextarc;//下一个相邻结点 
} ArcNode;
typedef struct VNode {  //顶点表头结点 
	char data;//顶点信息 
	ArcNode * firstarc; //与该顶点相连的第一个顶点组成的边的指针 
} VNode, AdjList[MVNum];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum; //图的顶点数和边数 
} ALGraph;
int visited[MVNum];
int CreateUDG(ALGraph &G);//实现细节隐藏

void DFS(ALGraph G, int v) {
	printf("%c ",G.vertices[v].data);
	visited[v]=1;
	ArcNode *p = G.vertices[v].firstarc;
	while(p) {
		int w = p->adjvex;
		if(!visited[w])
			DFS(G,w);
		p=p->nextarc;
	}
}

void DFSTraverse(ALGraph G) {
	int v;
	for(v = 0; v < G.vexnum; ++v)  visited[v] = 0;
	for(v = 0; v < G.vexnum; ++v)
		if(!visited[v])
			DFS(G,v);
}

int main() {
	ALGraph G;
	CreateUDG(G);
	DFSTraverse(G);
	return 0;
}
