#include<iostream>
#include<cstdio>
#include<math.h> 
using namespace std;
//int BinRec(int n)
//{
//	if(n==1)
//	return 1;
//	else
//	return BinRec(floor(n/2))+1;
//}

int BinRec(int n)
{
int cnt=1;
while(floor(n/2))
{
cnt++;
n=n/2;	
}
return cnt;	
}
 
int main()
{
printf("%d",BinRec(8));
return 0;
}

