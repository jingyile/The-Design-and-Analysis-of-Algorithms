#include <stdio.h>
#include <stdlib.h>
 
//typedef enum {false, true} bool;
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */
 
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};
 
typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];
 
typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;
 
LGraph ReadG(); /* details omitted */
 
int CountConnectedComponents( LGraph Graph );
 
int main()
{
    LGraph G = ReadG();
    printf("%d\n", CountConnectedComponents(G));
 
    return 0;
}
 
/* Your function will be put here */


int CountConnectedComponents( LGraph Graph ){
    int cnt = 0;//统计连通分支的个数
    int i,j;
    int vis[MaxVertexNum];//只标记这个点是否已经看过了
    for(i = 0; i < MaxVertexNum; i++)
           vis[i] = 0;//标记数组的初始化
    //用邻接表实现BFS
    for(i = 0; i < Graph->Nv; i++){
        if(vis[i]==0){
            cnt++;
            vis[i] = 1;
            int q[MaxVertexNum];
            int tail = 0,head = 0;
            q[tail++] = i;//创建一个队列，并把第一个顶点入队
            PtrToAdjVNode t;//创建一个指针，用于遍历这个点的邻接表
            while(head<tail){//广搜
                t = Graph->G[q[head]].FirstEdge;//取出队首顶点的邻接表指针，实际上指向的是首顶点下一个连接的顶点
                while(t){
                    if(!vis[t->AdjV]){//如果下一个连接的点没有遍历过
                        vis[t->AdjV] = 1;//标记
                        q[tail++] = t->AdjV;//入队
                    }
                    t = t->Next;//下一个连接的顶点
                }
                head++;//队首pop
            }
        }
    }
    return cnt;
}


 
