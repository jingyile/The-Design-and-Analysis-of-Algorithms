/*
应用选择排序对序列E,X,A,M,P,L,E按照字母顺序排序。

选择排序不稳定，存在交换操作
*/

#include<iostream>
#include<cstdio>
using namespace std;
char A[]= {'E','X','A','M','P','L','E'};
int n=7;
void SelectionSort() {
	int minn;
	for(int i=0; i<=n-2; i++) {
		minn=i;
		for(int j=i+1; j<=n-1; j++) {
			if(A[j]<A[minn])
				minn=j;
		}
		swap(A[i],A[minn]);
	}
}
int main() {
	SelectionSort();
	for(int i=0; i<n; i++)
		printf("%c ",A[i]);
	return 0;
}

