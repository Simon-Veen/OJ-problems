#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> v[N];
bool vis[N];
int a[N],n,m;
int ans;

void dfs(int p,int left){
    vis[p]=1;
    int len=v[p].size();

    if(a[p])left--;
    else left=m;

    if(left<0)return;
    else{
        bool ok=0;
        for(int i=0;i<len;i++){
            int node=v[p][i];
            if(!vis[node]){
                ok=1;
                dfs(node,left);
            }
        }
        if(!ok&&left>=0)ans++;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int f,t;
    for(int i=1;i<n;i++){
        scanf("%d%d",&f,&t);
        v[f].push_back(t);
        v[t].push_back(f);
    }
    dfs(1,m);
    printf("%d\n",ans);
}
