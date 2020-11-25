#include"iostream"
#include"cstdio"
#include"string"
#include"map"
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	map<string,int>mp;
	for(int i=0;i<s1.length();i++){
		for(int j=0;j<s2.length();j++){
			if(s1[i]==s2[j]){
				if(j==0){
					string ss(s1,0,1);
					mp[ss]=(mp[ss]+1)%10007;
					continue;
				}
				string ss(s2,0,j);
				mp[ss+s1[i]]=(mp[ss+s1[i]]+mp[ss])%10007;
			}
		}
	}
	cout<<mp[s2];
	return 0;
}
