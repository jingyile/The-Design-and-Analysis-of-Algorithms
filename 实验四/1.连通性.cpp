#include<stdio.h>
#define N 100
int Connected(int array[][100],int n)
{
	if(n==1)  return 1;
	else
	{
		if(!Connected(array,n-1))
		    return 0;
		else
		{
			for(int j = 0;j <= n-1; j++)
			if(array[n-1][j])  return 1;
			return 0;
		}
	}
}

int main()
{
	int a[N][N];
	int n;
	printf("输入你的矩阵的阶数：\n");
	scanf("%d",&n);printf("\n");
	printf("输入你的矩阵的元素：\n");
	for(int i=0;i<n;i++)
	   for(int j=0;j<n;j++)
	   {
	   	scanf("%d",&a[i][j]);
	   }
	   printf("%d",Connected(a,n));
}
