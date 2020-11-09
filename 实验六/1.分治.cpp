#include<iostream>
#include<cstdio>
using namespace std;
void MaxMin(int a[],int low,int high,int &maxe,int &mine) {
	if(low==high) { //jin仅一个元素
		maxe=a[low];
		mine=a[low];
	} else if(high-low==1) { //两个元素
		maxe=max(a[low],a[high]);
		mine=min(a[low],a[high]);
	} else {
		int mid=(low+high)/2;
		int lmaxe,lmine;
		MaxMin(a,low,mid,lmaxe,lmine);
		int rmaxe,rmine;
		MaxMin(a,mid+1,high,rmaxe,rmine);
		maxe=max(lmaxe,rmaxe);
		mine=min(lmine,rmine);
	}
}

int main() {
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int maxe;
	int mine;
	MaxMin(a,0,n-1,maxe,mine);
	cout<<"min:"<<a[0]<<endl;
	cout<<"max:"<<a[n-1]<<endl;
}
