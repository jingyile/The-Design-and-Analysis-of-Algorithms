#include<iostream>
#include<string.h>
#include<string>
#include<cstdio>
using namespace std;
long a[1000];
int b[10];
int i=0;
long fib1(int n)
{
if(n==0||n==1)
return 1;
else
return fib1(n-1)+fib1(n-2);	
}


long fib2(int n){
	for(int i=2;i<=n;i++)
	a[i]=a[i-1]+a[i-2];
	return a[n];
}

void fx(int n)
{
		if(i<5)
		{
		b[i++]=n%10;
		fx(n/10);	
		}
	return;
}
int main()
{
a[0]=1,a[1]=1;
int n;
scanf("%d",&n);
long ans=fib1(n);
printf("递归求解：%ld\n",ans);
//fib2(n);
//printf("循环求解：%ld\n",a[n]);
if(ans<100000)
printf("后五位:%d",ans);
else
{
fx(ans);
printf("后五位：");
for(int i=4;i>=0;i--)
printf("%d",b[i]);
}
return 0;
}

