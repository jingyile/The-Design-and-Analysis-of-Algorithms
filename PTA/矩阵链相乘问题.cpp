#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005;
int p[MAX];
int m[MAX][MAX];
int n;

void  matrix()
{
    int i,j,r,k;
    memset(m,0,sizeof(m));
    for(r = 2; r<=n; r++)
    {
        for(i = 1; i<=n-r+1; i++)
        {
            j = i+r-1;
            m[i][j] = m[i+1][j]+p[i-1]*p[i]*p[j];
            for(k = i+1; k<j; k++)
            {
                int t = m[i][k] +m[k+1][j]+p[i-1]*p[k]*p[j];
                if(t<m[i][j])
                {
                    m[i][j] = t;
                }
            }
        }
    }
}

int main()
{
    cin>>n;
    //记录输入的数字,注意个数比n多1
    for(int i=0; i<n+1; i++)
        cin>>p[i];
    matrix();
    cout<<m[1][n];
    return 0;
}
