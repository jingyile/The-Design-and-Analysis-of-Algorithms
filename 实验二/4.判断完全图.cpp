#include<iostream>
#include<cstdio>
using namespace std;
int A[3][3]={
{0,1,1},
{1,0,1},
{1,1,0}
};

int n=3;
int GraphComplete(int n)
{
	if(n==1)
	return 1;
	else{
		if(!GraphComplete(n-1))
		return 0;
		else
		{
			for(int j=0;j<=n-2;j++)
			if(A[n-1][j]==0)
			return 0;
		}
		return 1;
	}
}
int main()
{
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
	printf("%d",A[i][j]);
}
printf("\n");
}

printf("%d\n",GraphComplete(n));
return 0;
}

