#include<iostream>
#include<memory.h>
#include <stdlib.h>
#include<cstdio>
#define MAX 9999
using namespace std;
int main() {
 printf("���������Ľڵ�ĸ���\n");
 int n,i,j ;
 scanf("%d",&n);
 printf("������ÿ���ڵ�ı����Ҹ���\n");//p[n]���ڴ洢�ڵ����
 double *p;
 p=(double *)malloc(n * sizeof(double));
 for(i=1; i<=n; i++) {
  scanf("%lf",&p[i]);
 }
 
 double c[n+2][MAX];
 int r[n+2][MAX]; 
 memset(r,0,sizeof(r));
    memset(c,0,sizeof(c));
}
