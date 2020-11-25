#include<iostream>
#include<cstdio>
using namespace std;
int a[10100];
int b[10100];
int ans=0;
int main() {
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=1; i<=n; i++)
		b[i]=100;
	for(int i=0; i<n; i++) {
		int j=1;
		while(a[i]>b[j]) {
			j++;
		}
		b[j]-=a[i];
		cout<<a[i]<<" "<<j<<endl;
		ans=max(ans,j);
	}
	cout<<ans;
	return 0;
}

