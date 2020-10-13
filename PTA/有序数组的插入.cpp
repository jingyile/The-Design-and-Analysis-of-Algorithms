#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef enum {false, true} bool;
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�0��ʼ�洢 */
void PrintList( List L ); /* ����ʵ�֣�ϸ�ڲ��� */
bool Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;

    L = ReadInput();
    scanf("%d", &X);
    if ( Insert( L, X ) == false )
        printf("Insertion failed.\n");
    PrintList( L );

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
bool Insert( List L, ElementType X ){
if(L->Last+1==MAXSIZE)//�������鳤�� 
    return false;
for (int i=0; i<=L->Last; i++) {
    if(L->Data[i]==X)
        return false;//����x
    
    else if (L->Data[i]<X) {///������ͷ����ʹ��м����
        for (int j=L->Last; j>=i; j--) {
            L->Data[j+1]=L->Data[j];//��Ϊ����֮��Ҫ������һλ 
        }
        L->Data[i]=X;
        L->Last=L->Last+1;//��Ҫ���ǳ��ȼ�һ
        break;
    }
    else if(i==L->Last&&L->Data[i]>X){//�����һ��ʱ�����������Ϊ�ǴӴ�С�� 
        L->Data[L->Last+1]=X;
        L->Last=L->Last+1;//��Ҫ���ǳ��ȼ�һ
        break;///����ѭ������return true
    }
}
return true;
}

