#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0,f=0;
int a[10005];
int ans[10005];
void dfs(int pos,int sum)
{
    if(sum>m) return;
    if(sum==m){
        f=1;
        for(int i=0;i<cnt;i++)
            printf(i==cnt-1?"%d":"%d ",ans[i]);
        return;
    }
    for(int i=pos;i<n;i++){
        ans[cnt++]=a[i];
        dfs(i+1,sum+a[i]);
        if(f) break;
        cnt--;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(sum<m) puts("No Solution");
    else{
        sort(a,a+n);
        dfs(0,0);
        if(!f) puts("No Solution");
    }
	return 0;
}
