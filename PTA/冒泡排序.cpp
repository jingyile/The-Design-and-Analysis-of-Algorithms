#include <iostream>
#define MAXSIZE 1000
using namespace std;

typedef struct
{
 int key;
 char *otherinfo;
}ElemType;

typedef struct
{
 ElemType *r;
 int  length;
}SqList;

void BubbleSort(SqList &L)
{
 int m,j,flag;
 ElemType t;
 m=L.length-1; flag=1; 
 while(flag)
  {
    flag=0; 
    for(j=1;j<=m;j++)
      if(L.r[j].key>L.r[j+1].key) 
        {
          flag=1;    
          t=L.r[j];L.r[j]=L.r[j+1];L.r[j+1]=t;
        }
    --m;
  }
}

void Create_Sq(SqList &L)
{
 int i,n;
 cin>>n;    //输入的值不大于 MAXSIZE
 for(i=1;i<=n;i++)
 {
  cin>>L.r[i].key;
  L.length++;
 }
}
void show(SqList L)
{
 int i;
 for(i=1;i<=L.length;i++)
  if(i==1) 
   cout<<L.r[i].key;
  else
   cout<<" "<<L.r[i].key;
}

int main()
{
 SqList L;
 L.r=new ElemType[MAXSIZE+1];
 L.length=0;
 Create_Sq(L);
 BubbleSort(L);
 show(L);
 return 0;
}
