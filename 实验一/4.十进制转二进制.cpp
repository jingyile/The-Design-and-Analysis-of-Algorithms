#include<iostream>
using namespace std;
void binary(int n)
{
	if(n==0)
	return;
	else
	{
		binary(n/2);
		cout<<n%2;
	}
	return;
} 

int main()
{
int n;
cin>>n;
binary(n); 
return 0;	
}


