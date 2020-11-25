#include<iostream>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int a[2000];
	int i;
	for(i=0;i<=k;i++){
		cin>>a[i];
		if(a[i]>n) {
			cout<<"No Solution!";
			return 0;
		}
	}
	int count=0;//最少加油次数
	int trans;//暂存的油 
     trans=n;
	for(i=0;i<=k;){
		if(trans-a[i]>0) {
			trans=trans-a[i];
			i++;
		}
		else{
			trans=n;
			count++;
		}
	}
	cout<<count;
	
}

