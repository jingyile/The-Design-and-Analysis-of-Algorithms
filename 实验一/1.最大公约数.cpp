#include<iostream>
using  namespace std;

//Euclid
int gcd(int m,int n)
{   
	int r;
	while(n!=0)
	{
	r=m%n;
	m=n;
	n=r;	
	}
	return m;
}

//�����������
//int gcd(int m,int n){
//   int t;
////   t=min(m,n);
//   t=m>n?n:m;
//   while(m%t==0)
//   {
//   	if(n%t==0)
//   	break;
//   else
//   {
//   	t--;
//	continue;	
//   }
//   }
//   return t;
//}

//������������У� 
//int gcd (int a,int b)
//{
//    while(a!=b)
//    {
//    if(a>b)
//        a=a-b;
//    if(b>a)
//        b=b-a;
//    }
//    return a;
//}

int main()
{
	int m,n;
	cin>>m>>n;
	cout<<gcd(m,n)<<endl;
	return 0;
} 
