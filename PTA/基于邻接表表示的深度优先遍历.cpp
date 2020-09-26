#include <stdio.h>
#include <stdlib.h>
#define MVNum 100
typedef struct ArcNode {   //�߽�� 
	int adjvex; //���ͷ������ڵĶ����� 
	struct ArcNode * nextarc;//��һ�����ڽ�� 
} ArcNode;
typedef struct VNode {  //�����ͷ��� 
	char data;//������Ϣ 
	ArcNode * firstarc; //��ö��������ĵ�һ��������ɵıߵ�ָ�� 
} VNode, AdjList[MVNum];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum; //ͼ�Ķ������ͱ��� 
} ALGraph;
int visited[MVNum];
int CreateUDG(ALGraph &G);//ʵ��ϸ������

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
