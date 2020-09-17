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


void SelectSort(SqList &L) 
{ 
 int i,j,k;
 ElemType t;
 for(i=1;i<=L.length;++i) 
  {
    k=i;                 
    for(j=i+1;j<=L.length;++j)
      if(L.r[j].key<L.r[k].key)  k=j;    
    if(k!=i) 
    {t=L.r[i];L.r[i]=L.r[k];L.r[k]=t;}       
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
 SelectSort(L);
 show(L);
 cout<<L.length;
 return 0;
}
