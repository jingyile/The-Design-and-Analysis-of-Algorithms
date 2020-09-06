#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
int n=4;
int MinDistance(int *a)
{
	/*
	���Դ����ظ��Ƚϵ����(һ��Ԫ�أ������Ӷȸ� O(n*n)
	������֪ a < b < c ���ȽϹ��� a��b �Ĳ������£�
	û��Ҫ�ٱȽ� a �� c �Ĳ
	*/
	int dmin=0x3f3f3f3;
	for(int i=0;i<=n-1;i++)
	for(int j=0;j<=n-1;j++)
	{
		if(i!=j&&fabs(a[i]-a[j])<dmin)
		{
			dmin=fabs(a[i]-a[j]);
		}
	}
	return dmin;
} 

int main()
{
int a[]={2,6,10,-1};
cout<<MinDistance(a)<<endl;
return 0;
}

