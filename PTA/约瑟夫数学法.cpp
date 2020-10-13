#include <stdio.h>
int main()
{
    int n,m,i,s=0;
    scanf("%d %d",&n,&m);
    for(i=2;i<=n;i++)
        s=(s+m)%i;
    printf("%d",s+1);
    return 0;
}



