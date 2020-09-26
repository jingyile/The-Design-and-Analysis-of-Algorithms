#include <stdio.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10   /* 最大顶点数设为10 */
typedef int Vertex;       /* 用顶点下标表示顶点,为整型 */

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;        /* 邻接点下标 */
    PtrToAdjVNode Next; /* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct Vnode{
    PtrToAdjVNode FirstEdge; /* 边表头指针 */
} AdjList[MaxVertexNum];     /* AdjList是邻接表类型 */

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;     /* 顶点数 */
    int Ne;     /* 边数   */
    AdjList G;  /* 邻接表 */
};
typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */

bool Visited[MaxVertexNum]; /* 顶点的访问标记 */

LGraph CreateGraph(); /* 创建图并且将Visited初始化为false；裁判实现，细节不表 */

void Visit( Vertex V )
{
    printf(" %d", V);
}

void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) );

int main()
{
    LGraph G;
    Vertex S;

    G = CreateGraph();
    scanf("%d", &S);
    printf("BFS from %d:", S);
    BFS(G, S, Visit);

    return 0;
}

/* 你的代码将被嵌在这里 */
void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) )
{
    int queue[MaxVertexNum];
    int head=0,tail=0;//l是队头，r是队尾
    queue[tail++]=S;//插入到队尾
    Visit (S);
    Visited[S]=true;
    PtrToAdjVNode tmp;//边表结点指向下一个临界点的指针，其实就是next
    while(head!=tail)//就是队不空
    {
        tmp=Graph->G[queue[head++]].FirstEdge;//找到当前顶点边表链表头指针,queue[head++]就是每次循环队头都要出队
        while(tmp)
        {
            Vertex pos=tmp->AdjV;//pos为邻接点下标
            if(!Visited[pos])//没访问就访问它
            {
                Visit(pos);
                Visited[pos]=true;
                queue[tail++]=pos;//插入到队尾
            }
            tmp=tmp->Next;//指针指向下一个邻接点
        }
    }
}
