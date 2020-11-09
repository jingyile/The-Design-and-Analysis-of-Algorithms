#include "stdlib.h"
#include "stdio.h"

typedef int DataType;
#define MAX 100
/*读入n(n<=100)个两两不等的整数（以-9999结束），构造包含这个n个整数的AVL树，输出该树的前序，中序和高度*/
/*AVL 平衡二叉排序树*/

typedef struct tree
{
	DataType d;
	struct tree *lchild,*rchild;
}Tree,*PTree;

/*接受控制台一串数的输入，从小到大排序*/
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
	//冒泡排序
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
//r表示根节点
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
		p=q; 该注释地方同下面有什么不一样的吗？*/
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
//通过此调用，让数据两端达到平衡
void createAVL(int a[],int s,int e,PTree *p)
{
	int mid;
	if(s>e)return;
	mid=(s+e)/2;
	printf("%d ",a[mid]);//依次将节点插入到平衡二叉树
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
	printf("前序:");
	inOrder(p);
}
