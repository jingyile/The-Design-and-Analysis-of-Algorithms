#include <stdio.h>

void dectobin( int n );
int main()
{
    int n;
    scanf("%d", &n);
    dectobin(n);
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
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
