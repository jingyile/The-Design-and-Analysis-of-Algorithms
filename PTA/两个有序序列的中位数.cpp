#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[100009];
int b[100009];int binarysearch1(int l1, int r1, int l2, int r2)
{
    int mid1=(l1+r1)/2;
    int mid2=(l2+r2+1)/2;//+1处理，可以在遇到偶数序列时处理
    
    if (l1== r1&&l2 != r2) {
    if (a[l1] > b[r2])return b[r2];
    else return a[l1];
    }
    if (l2 == r2&&l1 != r1) {
    if (b[l2] > a[r1])return a[r1];
        else return b[l2];
    }    
    if(l1==r1&&l2==r2) {
        if(a[l1]>b[l2]) return b[l2];
        else return a[l1];
    }

    else    
    { 
       if (l1 == r1 - 1 && l2 == r2 - 1) //当a、b数组都只剩两个数字时
        {
        mid1 = (l1 + r1) / 2;
        mid2 = (l2 + r2) / 2;
        }
    if (a[mid1]==b[mid2]) return a[mid1];
    else if (a[mid1] > b[mid2]) binarysearch1(l1, mid1 ,mid2, r2);
    else binarysearch1(mid1, r1, l2, mid2);
    }
    
} 
int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)  cin >> a[i];
    for(int i=0; i<n; i++)  cin >> b[i];
    cout << binarysearch1(0,n-1,0,n-1) << endl;

}
