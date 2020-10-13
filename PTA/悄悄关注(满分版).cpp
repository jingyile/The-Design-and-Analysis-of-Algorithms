#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int num;
    char name[50];
} s[10005],xx;
 
map<string,int>mp;
map<string,int>mp1;
char st[50];
int main()
{
    int n,m;
    scanf("%d", &n);
    mp.clear();
    mp1.clear();
    for(int i = 0; i < n; i ++)
    {
        getchar();
        scanf("%s", st);
        mp[st]++;
    }
    scanf("%d",&m);
    int sum = 0;
    for(int i = 0; i < m; i ++)
    {
        getchar();
        scanf("%s %d", s[i].name, &s[i].num);
        sum += s[i].num;
        mp1[s[i].name]= s[i].num;
 
    }
    double ave = (double)sum / (double)m;
    map<string,int>::iterator it;
    bool f = false;
    for(it = mp1.begin(); it != mp1.end(); it ++)
    {
        if((double)(it->second) >= ave && mp[it->first] == 0)
        {
            cout << (it -> first) << endl;
            f = true;
        }
    }
 
    if(!f) printf("Bing Mei You\n");
    return 0;
}




