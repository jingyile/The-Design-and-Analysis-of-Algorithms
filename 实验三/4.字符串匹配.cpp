#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int cnt=0;

char T[]="CABAAXBYA";
int BruteForceStringMatch(int n){
	bool flag=false;
	for(int i=0;i<n;i++){
		if(T[i]=='A'&&!flag){
			flag=true;  //��ʼ�� 
		}
		if(T[i]=='B'&&flag){
			flag=false; //������ 
			cnt++;
		}
	}
} 
int main()
{
int n=strlen(T);
//printf("%d %d",n,m);
//printf("%d\n",BruteForceStringMatch(n));
BruteForceStringMatch(n);
printf("%d\n",cnt);
return 0;
}

