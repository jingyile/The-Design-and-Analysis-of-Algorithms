#include<iostream>
#include<memory.h>
#include <stdlib.h>
#include<cstdio>
#define MAX 9999
using namespace std;
int main() {
 printf("请输入树的节点的个数\n");
 int n,i,j ;
 scanf("%d",&n);
 printf("请输入每个节点的被查找概率\n");//p[n]用于存储节点概率
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
