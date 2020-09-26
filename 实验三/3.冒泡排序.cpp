/*
应用冒泡排序对序列E,X,A,M,P,L,E按照字母顺序排序
*/

#include<iostream>
#include<cstdio>
using namespace std;
char A[]= {'E','X','A','M','P','L','E'};
int n=7;

void BubbleSort() {
	int flag=0;
	for(int i=0; i<=n-2; i++) {
		for(int j=0; j<=n-2-i; j++) {
			if(A[j+1]<A[j]) {
				swap(A[j],A[j+1]);
				flag=1;
			}
		}
		if(!flag)
			return;
	}
}
int main() {
	BubbleSort();
	for(int i=0; i<n; i++)
		printf("%c ",A[i]);
	return 0;
}

