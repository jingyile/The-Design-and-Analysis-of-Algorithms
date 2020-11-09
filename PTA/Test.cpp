#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
#define MAXN 1010 
#define BASE 1007
char NumStr[1007]={'1','2','3'};
int DecodeCount( char NumStr[] )
{
    int L, i;
    int dp[MAXN]; //dp[i] is the solution from NumStr[i] to the end
    L = strlen(NumStr);
    if (L==0) return 0;
    if (L==1) return 1;
    dp[L-1] = 1;
    if (NumStr[L-2]!='1' && (NumStr[L-2]!='2' || NumStr[L-1]>'5'))
        dp[L-2] = 1; 
    else dp[L-2] = 2;
    for (i=L-3; i>=0; i--) {
        if (NumStr[i]!='1' && (NumStr[i]!='2' || NumStr[i+1]>'5'))
             dp[i] = dp[i-1]+1;
        else dp[i] = dp[i-1];
        dp[i] %= BASE; //to avoid overflow
    }
    return dp[i];
}



int main()
{
//cin>>NumStr;
//cout<<NumStr;
cout<<DecodeCount(NumStr);
return 0;
}

