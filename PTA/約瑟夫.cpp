#include<stdio.h>
bool a[100]= {0};
int main()
{
    int n,m;
    int s=0,t=0,f=0;
    scanf("%d%d",&n,&m);
    do
    {
        t++;//���ö��Ȧ�е�����λ��
        if(t>n)
            t=1;//����ģ�⻷״�����һ�����һ������
        if(!a[t])//��t��λ������������
            s++;
        if(s==m)//��ǰ��������m
        {
            s=0;//����������
            printf("%d ",t);
            a[t]=1;//�˴�������
            f++;//��������+1
        }
    }
    while(f!=n);
    return 0;
}
