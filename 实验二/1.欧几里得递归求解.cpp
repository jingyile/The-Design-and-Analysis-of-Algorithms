#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int m,int n)
{
	if(n==0)
	return m;
	else
	return gcd(n,m%n);
}
int main()
{
printf("%d",gcd(20,5));
return 0;
}

