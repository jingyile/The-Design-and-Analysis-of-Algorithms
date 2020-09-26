#include <stdio.h>
#include <stdlib.h>
#define MVNum 100
#define MAXQSIZE 100

int visited[MVNum];
typedef struct ArcNode {
	int adjvex;  /* �ڽӵ��±� */
	struct ArcNode *nextarc; /* ָ����һ���ڽӵ��ָ�� */
	int info;
} ArcNode;

typedef struct VNode {
	char data;//�����Ϣ 
	ArcNode *firstarc;//�߱�ͷָ�� 
} VNode, AdjList[MVNum];

typedef struct {
	AdjList vertices;/* �ڽӱ� */
	int vexnum, arcnum;/* �������ͱ���   */
} ALGraph;

int CreateUDG(ALGraph &G);//ʵ��ϸ������

void BFS(ALGraph G, int v) {
	int Q[MAXQSIZE],f=0,r=0,u,w;
	printf("%c ",G.vertices[v].data);
	visited[v] = 1;
	Q[r++]=v;
	while(f!=r) {
		u=Q[f++];
		ArcNode *p = G.vertices[u].firstarc;
		while(p) {
			w=p->adjvex;
			if(!visited[w]) {
				printf("%c ",G.vertices[w].data);
				visited[w] = 1;
				Q[r++]=w;
			}
			p = p->nextarc;
		}
	}
}

void BFSTraverse(ALGraph G) {
	int v;
	for(v = 0; v < G.vexnum; ++v)  
	visited[v] = 0;
	for(v = 0; v < G.vexnum; ++v)
		if(!visited[v])  
		BFS(G, v);
}

int main() {
	ALGraph G;
	CreateUDG(G);
	BFSTraverse(G);
	return 0;
}
