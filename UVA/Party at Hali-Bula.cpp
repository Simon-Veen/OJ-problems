#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

vector<int> v[210];
map<string,int> m;
char a[210],b[210];
int ans[210][2];
bool vis[210][2];

void dfs(int now){
    ans[now][1]=1;
    for(int i=0;i<v[now].size();i++){
        dfs(v[now][i]);
        int s=v[now][i];
        ans[now][1]+=ans[s][0];
        vis[now][1]|=vis[s][0];
        ans[now][0]+=max(ans[s][0],ans[s][1]);
        if(ans[s][1]==ans[s][0])vis[now][0]=1;
        else if(ans[s][1]>ans[s][0])vis[now][0]|=vis[s][1];
        else if(ans[s][0]>ans[s][1])vis[now][0]|=vis[s][0];
    }
}
int main()
{
    int t,cnt;
    while(~scanf("%d",&t)&&t){
        scanf("%s",a);
        cnt=1;
        m[a]=cnt++;
        for(int i=1;i<t;i++){
            scanf("%s%s",a,b);
            if(!m.count(a))m[a]=cnt++;
            if(!m.count(b))m[b]=cnt++;
            v[m[b]].push_back(m[a]);
        }
        dfs(1);
        printf("%d ",max(ans[1][0],ans[1][1]));
        if(ans[1][0]>ans[1][1]){
            if(vis[1][0]) puts("No");
            else puts("Yes");
        }
        else if(ans[1][0]<ans[1][1]){
            if(vis[1][1]) puts("No");
            else puts("Yes");
        }
        else if(ans[1][0]==ans[1][1])puts("No");
        m.clear();
        for(int i=0;i<=t;i++){
            v[i].clear();
            ans[i][1]=ans[i][0]=0;
            vis[i][0]=vis[i][1]=0;
        }
    }
}
