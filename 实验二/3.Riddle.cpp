#include<iostream>
#include<cstdio>
using namespace std;
int n=8;
int A[]={8,2,5,4,5,8,7,3};
int Riddle(int n)
{
	int temp;
	if(n==1)
	return A[0];
	else
	{
	for(int i=0;i<n-1;i++)
	{
		temp=Riddle(n-1);
		if(temp<=A[n-1])
		return temp;
		else
		return A[n-1];
	}
	}
}

int main()
{
printf("%d",Riddle(n));
return 0;
}

