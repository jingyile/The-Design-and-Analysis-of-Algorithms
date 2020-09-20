#include <stdio.h>

void dectobin( int n );
int main()
{
    int n;
    scanf("%d", &n);
    dectobin(n);
    return 0;
}

/* 你的代码将被嵌在这里 */
int flag=1;
void dectobin(int n)
{
	if(n==0)
	{
		if(flag)
		{
		printf("0");	
		}
		else 
		return;	
	}
	else
	{
		flag=0;
		dectobin(n/2);
		printf("%d",n%2);	
	}
	return;
}
