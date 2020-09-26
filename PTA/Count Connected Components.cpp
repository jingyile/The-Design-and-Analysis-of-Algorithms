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
    int cnt = 0;//ͳ����ͨ��֧�ĸ���
    int i,j;
    int vis[MaxVertexNum];//ֻ���������Ƿ��Ѿ�������
    for(i = 0; i < MaxVertexNum; i++)
           vis[i] = 0;//�������ĳ�ʼ��
    //���ڽӱ�ʵ��BFS
    for(i = 0; i < Graph->Nv; i++){
        if(vis[i]==0){
            cnt++;
            vis[i] = 1;
            int q[MaxVertexNum];
            int tail = 0,head = 0;
            q[tail++] = i;//����һ�����У����ѵ�һ���������
            PtrToAdjVNode t;//����һ��ָ�룬���ڱ����������ڽӱ�
            while(head<tail){//����
                t = Graph->G[q[head]].FirstEdge;//ȡ�����׶�����ڽӱ�ָ�룬ʵ����ָ������׶�����һ�����ӵĶ���
                while(t){
                    if(!vis[t->AdjV]){//�����һ�����ӵĵ�û�б�����
                        vis[t->AdjV] = 1;//���
                        q[tail++] = t->AdjV;//���
                    }
                    t = t->Next;//��һ�����ӵĶ���
                }
                head++;//����pop
            }
        }
    }
    return cnt;
}


 
