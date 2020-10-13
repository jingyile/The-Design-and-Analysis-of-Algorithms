#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
int flag2=0;
typedef struct{
	char name[5];
	int cnt;
}User;
User followers[5005];
User people[10010];
User ans[1010];
bool cmp1(User user1,User user2){
	return user1.name[0]<user2.name[0];
}
int main()
{
int i=0,n;
scanf("%d",&n);
int nn=n;
while(n--)
{
	scanf("%s",&followers[i++].name);
}
int j=0,m,sum=0;
scanf("%d",&m);
int mm=m;
while(m--)
{
	scanf("%s %d",&people[j].name,&people[j].cnt);
	sum+=people[j].cnt;
	j++;
}
int ave=sum/mm;
//printf("%d ",ave);
int l=0;
for(i=0;i<mm;i++)
{
//	printf("%s",people[i].name);
	if(people[i].cnt>ave)
	ans[l++]=people[i];
}
sort(ans,ans+l,cmp1);
//for(j=0;j<l;j++)
//printf("%s\n",ans[j].name);
//printf("66666666\n");
for(j=0;j<l;j++)
{
//	printf("%s",ans[j]);
	int flag=1;
	for(int i=0;i<nn;i++)
	{
//		printf("%s\n",ans[j].name);
//		printf("%s\n",followers[i].name);
		if(strcmp(ans[j].name,followers[i].name)==0)
		{
		flag=0;
		break;
	}
}
	if(flag)
	{
		flag2=1;
		printf("%s\n",ans[j].name);
	}
}
if(flag2==0)
printf("Bing Mei You");
return 0;
}

