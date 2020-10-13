#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef enum {false, true} bool;
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList( List L ); /* 裁判实现，细节不表 */
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

/* 你的代码将被嵌在这里 */
bool Insert( List L, ElementType X ){
if(L->Last+1==MAXSIZE)//超过数组长度 
    return false;
for (int i=0; i<=L->Last; i++) {
    if(L->Data[i]==X)
        return false;//已有x
    
    else if (L->Data[i]<X) {///含量从头插入和从中间插入
        for (int j=L->Last; j>=i; j--) {
            L->Data[j+1]=L->Data[j];//因为插入之后都要往后移一位 
        }
        L->Data[i]=X;
        L->Last=L->Last+1;//不要忘记长度加一
        break;
    }
    else if(i==L->Last&&L->Data[i]>X){//到最后一个时，插入最后，因为是从大到小拍 
        L->Data[L->Last+1]=X;
        L->Last=L->Last+1;//不要忘记长度加一
        break;///跳出循环进行return true
    }
}
return true;
}

