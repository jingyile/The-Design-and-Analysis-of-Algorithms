#include<iostream>
#include<string.h>
using namespace std;
int a[]={2,5,5};
int b[]={2,2,3,5,5,7}; 
int main()
{
int cnt=0;
int i=0,j=0;
while(i<3&&j<6)
{
if(a[i]==b[j])
{
	cout<<a[i]<<" ";
	cnt++;
	i++,j++;
}
else if(a[i]<b[j])
{
	i++;
	cnt++;
}
else if(a[i]>b[j])
{
	j++;
	cnt++;
}	
}
cout<<endl<<"比较次数为"<<cnt<<endl;
return 0; 
}
