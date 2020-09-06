#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
int n=4;
int MinDistance(int *a)
{
	/*
	明显存在重复比较的情况(一半元素），复杂度高 O(n*n)
	且在已知 a < b < c 而比较过了 a、b 的差的情况下，
	没必要再比较 a 和 c 的差。
	*/
	int dmin=0x3f3f3f3;
	for(int i=0;i<=n-1;i++)
	for(int j=0;j<=n-1;j++)
	{
		if(i!=j&&fabs(a[i]-a[j])<dmin)
		{
			dmin=fabs(a[i]-a[j]);
		}
	}
	return dmin;
} 

int main()
{
int a[]={2,6,10,-1};
cout<<MinDistance(a)<<endl;
return 0;
}

