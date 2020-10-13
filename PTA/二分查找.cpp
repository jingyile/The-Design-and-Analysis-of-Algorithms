#include<iostream>
using namespace std;
#define MAXSIZE 100

typedef struct{
    int key;
}ElemType;

typedef struct{
    ElemType *R;
    int length;
}SSTable;

int Create_SSTable(SSTable &L) 
{    int n;
    cin >> n; 
    for(int i=1;i<=n;i++)
    {
        cin >> L.R[i].key;
        L.length++;
    }
    return 1;
}

int Search_Bin(SSTable ST,int key) {
   int low=1,high=ST.length;
   int  mid;
   while(low<high) {
      mid=(low+high) / 2;
      if (ST.R[mid].key==key)  return mid; 
      else if (ST.R[mid].key>key) 
	   high = mid -1;
      else  low =mid +1; 
   }
   return 0;
}

int main()
{
    SSTable ST;
    int key;
    int result;    
    ST.R=new ElemType[MAXSIZE];
    ST.length=0;    
    Create_SSTable(ST);
    cin >> key;
    result=Search_Bin(ST, key);
    if(result)
        cout << "search success£¬The key is located in "<< result;
    else
        cout << "search failed";
    return 0;
}
