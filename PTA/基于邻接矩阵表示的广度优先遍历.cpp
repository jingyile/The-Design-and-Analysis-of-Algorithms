#include <stdio.h>
#include <stdlib.h>
#define MVNum 100

int visited[MVNum];

typedef struct {
	char vexs[MVNum];   //������
	int arcs[MVNum][MVNum]; //����
	int vexnum,arcnum;  //������ ����
} Graph;

void CreateUDN(Graph &G);//ʵ��ϸ������
void BFS(Graph G, int v) {
	char Q[MVNum];
	int f=0,r=0;
	int u,w;
	printf("%d ",G.vexs[v]);
	visited[v] = 1;
	Q[r++]=v;
	while(f<r) {
		u=Q[f++];
		for(w = 0; w < G.vexnum; w++) {
			if(!visited[w]&&G.arcs[u][w]==1) {
				printf("%d ",G.vexs[w]);
				visited[w] = 1;
				Q[r++]=w;
			}
		}
	}
}
void CreateUDN(Graph &G) {
	scanf("%d %d",&G.vexnum,&G.arcnum);
	for(int i=0; i<G.vexnum; i++)
//scanf("%c",&G.vexs[i]);
		G.vexs[i]=i;
	for(int i=0; i<G.vexnum; i++)
		for(int j=0; j<G.vexnum; j++) {
			G.arcs[i][j]=0;
		}
	for(int i=0; i<G.arcnum; i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		G.arcs[u][v]=1;
		G.arcs[v][u]=1;
	}
}


void BFSTraverse(Graph G) {
	int v;
	for(v = 0; v < G.vexnum; ++v)
		visited[v] = 0;
	for(v = 0; v < G.vexnum; ++v)
		if(!visited[v])
			BFS(G, v);
}

int main() {
	Graph G;
	CreateUDN(G);
	BFSTraverse(G);
	return 0;
}
