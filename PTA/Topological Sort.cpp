#include <stdio.h>
#include <stdlib.h>

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

bool TopSort( LGraph Graph, Vertex TopOrder[] );

int main()
{
    int i;
    Vertex TopOrder[MaxVertexNum];
    LGraph G = ReadG();

    if ( TopSort(G, TopOrder)==true )
        for ( i=0; i<G->Nv; i++ )
            printf("%d ", TopOrder[i]);
    else
        printf("ERROR");
    printf("\n");

    return 0;
}

/* Your function will be put here */
int In[MaxVertexNum];//存储各点入度 

bool TopSort( LGraph Graph, Vertex TopOrder[] ){
    memset(In,0,sizeof(In));
    for(int i=0 ; i<Graph->Nv ; i++){
        PtrToAdjVNode t = Graph->G[i].FirstEdge;
        while(t){
            In[t->AdjV]++;
            t = t->Next;
        }
    }                        //求各点入度 

    int queue[Graph->Nv];     //建立队列存储入度为零的点 
    int head,tail;
    head = tail = 0;
    for(int i=0 ; i<Graph->Nv ; i++){
        if(In[i] == 0){
            queue[tail++] = i;
            break;
        }
    }                       //找第一个入度为零的点 

    int index = 0;
    while(head<tail){
        int node = queue[head++];
        TopOrder[index++] = node;
        PtrToAdjVNode t = Graph->G[node].FirstEdge;
        while(t){
            In[t->AdjV]--;
            if(In[t->AdjV] == 0)queue[tail++] = t->AdjV;
            t = t->Next;
        }
    }

    if(index == Graph->Nv)return true;
    else return false;
}
