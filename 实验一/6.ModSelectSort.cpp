#include<iostream>
using namespace std;
int a[1000];
void ModSelectSort(int n)
{
	for(int i=0;i<=n-2;i++)
	{
	for(int j=i+1;j<=n-1;j++)
	{
		if(a[i]>a[j])
		{
			swap(a[i],a[j]);
		}
	}
	cout<<"µÚ"<<i+1<<"ÌËÅÅÐò½á¹û£º"<<endl;
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	ModSelectSort(n);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	return 0; 
 } 
