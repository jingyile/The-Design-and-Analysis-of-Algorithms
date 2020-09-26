/*
P(x)=a(n)*pow(x,n)+a(n-1)*pow(x,n-1)+...+a(1)*pow(x,1)+a(0)
*/

#include<iostream>
#include<cstdio>
using namespace std;
int a[2000];

//O(n*n)   按顺序直接算
int fx1(int n,int x) {
	int power,p=0;
	for(int i=n; i>=0; i--) {
		power=1;
		for(int j=1; j<=i; j++) {
			power=power*x;
		}
		p=p+a[i]*power;
	}
	return p;
}

//O(n)    从后往前按X的次方算
int fx2(int n,int x) {
	int power=1,p=a[0];
	for(int i=1; i<=n; i++) {
		power=power*x;  //x的n次幂
		p=p+a[i]*power;
	}
	return p;
}


int main() {
	int n=3;
//printf("输入n的值和系数：");
//scanf("%d",&n);
//for(int i=0;i<=n;i++)
//scanf("%d",&a[i]);
	a[3]=3,a[2]=2,a[1]=1,a[0]=1;
	printf("输入x的值：");
	int x;
	scanf("%d",&x);
	printf("%d\n",fx2(n,x));
	return 0;
}

