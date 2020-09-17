#include<stdio.h>
#include<stdlib.h>
typedef  int  KeyType;
typedef  struct {                      
  KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/                       
  int Length;      
}SqList;
void  CreatSqList(SqList *L);/*待排序列建立，由裁判实现，细节不表*/ 
int Partition ( SqList  L,int low,  int  high );
void Qsort ( SqList  L,int low,  int  high );

int main()
{
  SqList L;
  int i;
  CreatSqList(&L);
  Qsort(L,1,L.Length);
  for(i=1;i<=L.Length;i++)
   {        
     printf("%d ",L.elem[i]);
    }
  return 0;
}

int Partition ( SqList  L,int low,  int  high ) 
{ /*一趟划分*/
  KeyType  pivotkey;
  L.elem[0] = L.elem[low];   
  pivotkey = L.elem[low];
  while(low<high) 
    {
         while ( low < high && L.elem[high] >= pivotkey ) 
                --high;
         L.elem[low] = L.elem[high];
         while ( low < high && L.elem[low] <= pivotkey )
                 ++low;
         L.elem[high] = L.elem[low];
     }
   L.elem[low]=L.elem[0]; 
   return low;
}
void Qsort ( SqList  L,int low,  int  high ) 
{ 
  int  pivotloc;
  if  (low<high) 
    {  
        pivotloc = Partition(L, low, high );
        Qsort (L,low,pivotloc-1); 
        Qsort (L,pivotloc+1,high); 
     }
}
