/*
    ÇóÍØÆËÐò
*/
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN=2e3+10;
int in[MAXN];
vector<int> ptr[MAXN];
queue<int> q;
int dfs(int x,int deep){
    if(in[x]!=-1)return in[x];
    int maxn=1;
    for(int i=0;i<ptr[x].size();i++){
        maxn=max(maxn,dfs(ptr[x][i],deep)+1);
    }
    in[x]=maxn;
    return in[x];

}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int head;
        scanf("%d",&head);
        if(head!=-1){
            in[i]++;
            ptr[head].push_back(i);
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    memset(in,-1,sizeof(in));
    int ans=0,k=0;
    while(!q.empty()){
        int head=q.front();
        q.pop();
        ans=max(ans,dfs(head,1));
    }
    printf("%d",ans);
}
