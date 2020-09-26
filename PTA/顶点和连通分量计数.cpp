#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 20  /* 最大顶点数设为20 */
struct Graph {
	int v;  // amount of vertices
	int Adj[MaxVertexNum][MaxVertexNum]; /* Adj Matrix */
};
int visited[MaxVertexNum];  /* visited flag */
struct Graph* CreateGraph() {
	int v;
	scanf("%d",&v);
	struct Graph* g;
//    g = malloc(sizeof(struct Graph));
	if(!g) return NULL;
	g->v = v;
	for(int i=0; i<v; i++) {
		visited[i] = 0;   // clear the array visited[ ]
		for(int j=0; j<v; j++)
			scanf("%d",&(g->Adj[i][j]));
	}
	return g;
}
int countComponents(struct Graph* g);
int main() {
	struct Graph* g;
	g = CreateGraph();
	printf("Components:%d\n", countComponents(g));
	return 0;
}
/* 你提交的代码将被嵌入在这儿 */
int maxn=0;
int f[1000];
int people[1000];
int findx(int x) {
	int r=x;
	while(f[r]!=r) {
		r=f[r];
	}
	return r;
}
void merge(int x,int y) { //让X和Y做朋友
	int fx,fy;
	fx=findx(x);
	fy=findx(y);
	if(fx!=fy) {
		f[fx]=fy;
		people[fy] += people[fx];
	}
}
int countComponents(struct Graph* g) {
	int cnt=0;
	int i,j;
	for(i=0; i<g->v; i++) {
		people[i]=1;
		f[i]=i;
	}
	for(i=0; i<g->v; i++) {
		for(j=0; j<g->v; j++) {
			if(g->Adj[i][j]==1) {
				merge(i,j);
			}
		}
	}
//for(i=1;i<g->v;i++)
//printf("%d ",people[i]);
	for(i=0; i<g->v; i++)
		if(f[i]==i) {
			maxn=maxn>people[f[i]]? maxn:people[f[i]];
			cnt++;
		}
	printf("%d\n",maxn);
	return cnt;
}
