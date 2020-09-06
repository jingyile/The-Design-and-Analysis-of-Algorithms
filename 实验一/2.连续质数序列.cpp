#include<iostream>
#include<math.h>
using namespace std;
int a[10000];
int m=0;
//求一个不大于给定整数n的连续质数序列 
void prime(int n)
{
	int k;
	for(int i=2;i<=n;i++)
	{
	  k=sqrt(i);
	  for(int j=2;j<=k;j++)
	  {
	  	if(i%j==0)
	  	break;
	  	if(i>k)
	  	{
	  		a[m]=i;
	  		m++;
		}
	   }	
	}
}

int Sieve(int n)
{
	
}


int main()
{
	int n;
	cin>>n;
	prime(n);
	for(int i=0;i<m;i++)
	cout<<a[i]<<endl;
	return 0;
}
