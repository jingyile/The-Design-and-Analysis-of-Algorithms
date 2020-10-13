#include<stdio.h>
bool a[100]= {0};
int main()
{
    int n,m;
    int s=0,t=0,f=0;
    scanf("%d%d",&n,&m);
    do
    {
        t++;//逐个枚举圈中的所有位置
        if(t>n)
            t=1;//数组模拟环状，最后一个与第一个相连
        if(!a[t])//第t个位置上有人则报数
            s++;
        if(s==m)//当前报的数是m
        {
            s=0;//计数器清零
            printf("%d ",t);
            a[t]=1;//此处人已死
            f++;//死亡人数+1
        }
    }
    while(f!=n);
    return 0;
}
