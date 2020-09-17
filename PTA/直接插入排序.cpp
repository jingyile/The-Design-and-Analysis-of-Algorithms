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

void InsertSort(SqList &L)
{
int i,j;
for(i=2;i<=L.length;++i)
if(L.r[i].key<L.r[i-1].key)
{                       
L.r[0]=L.r[i];    
L.r[i]=L.r[i-1];
for(j=i-1;L.r[j].key>L.r[0].key&&j>0;--j)
L.r[j+1]=L.r[j];
L.r[j+1]=L.r[0];    
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
 InsertSort(L);
 show(L);
 return 0;
}



