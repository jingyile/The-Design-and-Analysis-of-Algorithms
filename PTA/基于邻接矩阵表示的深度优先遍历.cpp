#include <stdio.h>
#define MVNum 100
typedef struct {
	char vexs[MVNum];        //顶点阵
	int arcs[MVNum][MVNum];   //边阵
	int vexnum,arcnum;      //顶点数 边数
} AMGraph;
int visited[MVNum];
void CreateUDN(AMGraph &G);//实现细节隐藏

void DFS(AMGraph G, int v) {
	printf("%d ",G.vexs[v]);
	visited[v] =1;
	int w;
	for(w = 0; w < G.vexnum; w++)
		if((G.arcs[v][w]==1)&& (visited[w]==0))
			DFS(G, w);
}

void DFSTraverse(AMGraph G) {
	int v;
	for(v = 0; v < G.vexnum; ++v)
		visited[v] = 0;
	for(v = 0; v < G.vexnum; ++v)
		if(visited[v]==0)
			DFS(G,v);
}

int main() {
	AMGraph G;
	CreateUDN(G);
	DFSTraverse(G);
	return 0;
}

void CreateUDN(AMGraph &G) {
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
