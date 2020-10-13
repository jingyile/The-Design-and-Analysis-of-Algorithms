#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>mp[110];
int ind[110];
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int v;cin>>v;
            mp[i].push_back(v);
            ind[v]++;
        }
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(ind[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<mp[u].size();i++){
            int v=mp[u][i];
            ind[v]--;
            if(ind[v]==0){
                q.push(v);
            }
        }
        cnt++;
    }
    if(cnt==n)
        cout<<1<<endl;
    else
        cout<<0<<endl;
    return 0;
}

