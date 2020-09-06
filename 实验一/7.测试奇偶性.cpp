#include<iostream>
using namespace std;

int main()
{
	int n=5;
	int a[n]={1,2,3,4,5};
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		cout<<a[i]<<endl;
		else
		cout<<a[i]*2<<endl;
	}
	return 0;
}
