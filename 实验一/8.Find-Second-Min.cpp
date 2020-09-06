#include<iostream>
#include<cstdio>
using namespace std;
void FindSecondMin(int *s,int n){
	int Minx,SecondMinx;
	if(s[1]<s[2])
	Minx=s[1],SecondMinx=s[2];
	else
	Minx=s[2],SecondMinx=s[1];
	for(int i=3;i<=n;i++)
	{
		if(s[i]<SecondMinx)
		{
			if(s[i]<Minx)
			SecondMinx=Minx,Minx=s[i];
			else
			SecondMinx=s[i];
		}
		}
	cout<<SecondMinx<<endl;		
}

int main()
{
int n=5;
int s[n+1];
//数组下标默认从0开始，而函数中默认从1开始，所以把a[0]空出来！ 
s[1]=9,s[2]=8,s[3]=7,s[4]=1,s[5]=2;
//int s[n]={100,9,8,7,1,2}; 
FindSecondMin(s,n);
return 0;
}

