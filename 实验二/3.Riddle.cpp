#include<iostream>
#include<cstdio>
using namespace std;
int n=8;
int Riddle(int *A)
{
	int temp;
	if(n==1)
	return A[0];
	else
	{
	for(int i=0;i<n-1;i++)
	{
		temp=A[i];
		if(temp<=A[n-1])
		return temp;
		else
		return A[n-1];
	}
	}
}

int main()
{
int A[]={6,2,3,4,5,8,7,3};
printf("%d",Riddle(A));
return 0;
}

