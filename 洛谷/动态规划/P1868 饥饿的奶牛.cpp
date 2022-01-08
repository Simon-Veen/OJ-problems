/*
    线性结构的状态转移
*/
#include<bits/stdc++.h>
using namespace std;
const int N=3e6+10;
vector<int> v[N];
long long ans[N];
int main()
{
    int n,maxx=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int f,t;
        cin>>f>>t;
        maxx=max(maxx,t);
        v[t].push_back(f);
    }
    for(int i=0;i<=maxx;i++){
        int len=v[i].size();
        if(i)ans[i]=ans[i-1];
        for(int j=0;j<len;j++){
            if(v[i][j])ans[i]=max(ans[i],ans[v[i][j]-1]+i-v[i][j]+1);
        }
    }
    cout<<ans[maxx]<<endl;
}
