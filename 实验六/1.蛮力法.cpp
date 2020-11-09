#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
int minx=a[0],maxx=a[0];
for(int i=1;i<n;i++)
{
	if(minx>a[i])
	minx=a[i];
	if(maxx<a[i])
	maxx=a[i];
}
cout<<"min:"<<minx<<endl;
cout<<"max:"<<maxx<<endl;
return 0;
}

