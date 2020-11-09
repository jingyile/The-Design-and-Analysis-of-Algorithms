#include "stdlib.h"
#include "stdio.h"

typedef int DataType;
#define MAX 100
/*����n(n<=100)���������ȵ���������-9999������������������n��������AVL�������������ǰ������͸߶�*/
/*AVL ƽ�����������*/

typedef struct tree
{
	DataType d;
	struct tree *lchild,*rchild;
}Tree,*PTree;

/*���ܿ���̨һ���������룬��С��������*/
void inputData(int a[],int *al )
{
	int i,j,temp;
	int flag = 0;
	*al=0;
	do
	{
		scanf("%d",&i);
		if(i==-9999)break;
		a[(*al)++]=i;
	}while(9);
	//ð������
	for(i=0;i<*al;i++)
	{
		flag=0;
		for(j=0;j<*al-i;j++)
			if(a[j]<a[j+1])
			{
				flag=1;
				temp=a[j];a[j]=a[j+1];a[j+1]=temp;
			}
		if(flag==0)break;
	}
}
//r��ʾ���ڵ�
void insertSortTree(PTree *r,int x)
{
	PTree p,q;
	q=(PTree)malloc(sizeof(Tree));
	q->d=x;
	q->lchild=NULL;q->rchild=NULL;
	if(*r==NULL)
	{
		*r=q;return;
	}
		p=*r;
		/*
		while(p)
		{
			if(p->d>x)
				p=p->lchild;
			else
				p=p->rchild;
		}
		p=q; ��ע�͵ط�ͬ������ʲô��һ������*/
		while(1)
		{
			if(x<p->d)
				if(p->lchild)
					p=p->lchild;
				else
				{
					p->lchild=q;
					return;
				}
			else
				if(p->rchild)
					p=p->rchild;
				else 
				{
					p->rchild=q;return;
				}	
		}


}
//ͨ���˵��ã����������˴ﵽƽ��
void createAVL(int a[],int s,int e,PTree *p)
{
	int mid;
	if(s>e)return;
	mid=(s+e)/2;
	printf("%d ",a[mid]);//���ν��ڵ���뵽ƽ�������
	insertSortTree(p,a[mid]);
	createAVL(a,s,mid-1,p);
	createAVL(a,mid+1,e,p);
}
void inOrder(PTree r)
{
	if(r)
	{
		inOrder(r->lchild);
		printf("%d ",r->d);
		inOrder(r->rchild);
	}
}
int main()
{
	int a[MAX],al;
	PTree p=NULL;
	inputData(a,&al);
	createAVL(a,0,al-1,&p);
	printf("ǰ��:");
	inOrder(p);
}
