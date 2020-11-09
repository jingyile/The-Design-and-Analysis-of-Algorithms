#include<iostream>
#include<string>
using namespace std;
//bool vis[1010];  // Ä¬ÈÏfalse 
//int c[1010];
//bool fx(int k){
//	int cnt=0;
//	for(int i=0;i<k;i++)
//	{
//		if(vis[c[i]])
//		{
//			cnt++;
//		}
//		if(cnt==k)
//		return false;
//		return true;
//	}
//}
int main()
{
	string a;
	string b;
	int count=0;
	cin>>a;
	cin>>b;
//	for(int i=0;i<a.length();i++)
//	{
//		int k=0;
//		int j=0;
//		if(a[i]==b[j++])
//		{
//			vis[i]=true;
//			c[k++]=i;
//		}
//		if(k==b.length() & fx(k))
//		{
//			count++;
//		}
//	}
		cout<<count<<endl;	
	return 0;
} 


