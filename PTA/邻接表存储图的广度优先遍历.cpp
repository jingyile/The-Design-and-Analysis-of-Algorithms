#include <stdio.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10   /* ��󶥵�����Ϊ10 */
typedef int Vertex;       /* �ö����±��ʾ����,Ϊ���� */

/* �ڽӵ�Ķ��� */
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;        /* �ڽӵ��±� */
    PtrToAdjVNode Next; /* ָ����һ���ڽӵ��ָ�� */
};

/* �����ͷ���Ķ��� */
typedef struct Vnode{
    PtrToAdjVNode FirstEdge; /* �߱�ͷָ�� */
} AdjList[MaxVertexNum];     /* AdjList���ڽӱ����� */

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;     /* ������ */
    int Ne;     /* ����   */
    AdjList G;  /* �ڽӱ� */
};
typedef PtrToGNode LGraph; /* ���ڽӱ�ʽ�洢��ͼ���� */

bool Visited[MaxVertexNum]; /* ����ķ��ʱ�� */

LGraph CreateGraph(); /* ����ͼ���ҽ�Visited��ʼ��Ϊfalse������ʵ�֣�ϸ�ڲ��� */

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

/* ��Ĵ��뽫��Ƕ������ */
void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) )
{
    int queue[MaxVertexNum];
    int head=0,tail=0;//l�Ƕ�ͷ��r�Ƕ�β
    queue[tail++]=S;//���뵽��β
    Visit (S);
    Visited[S]=true;
    PtrToAdjVNode tmp;//�߱���ָ����һ���ٽ���ָ�룬��ʵ����next
    while(head!=tail)//���ǶӲ���
    {
        tmp=Graph->G[queue[head++]].FirstEdge;//�ҵ���ǰ����߱�����ͷָ��,queue[head++]����ÿ��ѭ����ͷ��Ҫ����
        while(tmp)
        {
            Vertex pos=tmp->AdjV;//posΪ�ڽӵ��±�
            if(!Visited[pos])//û���ʾͷ�����
            {
                Visit(pos);
                Visited[pos]=true;
                queue[tail++]=pos;//���뵽��β
            }
            tmp=tmp->Next;//ָ��ָ����һ���ڽӵ�
        }
    }
}
