#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 250
int a[maxn][maxn]; 
int mincost[maxn];
int main()
{
int n;
cin>>n;
for(int i=1;i<=n;i++)
for(int j=i+1;j<=n;j++)
{
	cin>>a[i][j];
}
mincost[1]=0;
mincost[2]=a[1][2];
for(int i=3;i<=n;i++)
{
	mincost[i]=a[1][i];
	for(int j=2;j<i;j++)
	if(mincost[i]>mincost[j]+a[j][i])
	{
	mincost[i]=mincost[j]+a[j][i];
	}
}
cout<<mincost[n];
return 0;
}

