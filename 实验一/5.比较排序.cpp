#include<iostream>
using namespace std;
int a[6]={60,35,81,98,14,47};
int s[10000],count[10000];
void ComparisonCountingSort(int n)
{
	for(int i=0;i<=n-1;i++)
	count[i]=0;
	for(int i=0;i<=n-2;i++)
	for(int j=i+1;j<=n-1;j++)
	{
		if(a[i]<a[j])
		count[j]++;
		else
		count[i]++;
	}
	for(int i=0;i<=n-1;i++)
	s[count[i]]=a[i];
}
int main()
{
	int n=6;
//	cin>>n;
//	for(int i=0;i<n;i++)
//	cin>>a[i];
	ComparisonCountingSort(n);
	for(int i=0;i<n;i++)
	cout<<s[i]<<" ";	
	return 0;
 } 
