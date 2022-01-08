#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=200;

map<string,int> m;
vector<int> v[MAXN+5];
char name[MAXN+5],na[MAXN+5];//string name,na;
int n,d[MAXN+5],s[MAXN+5],gs[MAXN+5],f[MAXN+5];
bool vis[MAXN+5];
bool ans=0;

void dfs(int now,int fa){
    f[now]=fa;
    for(int i=0;i<v[now].size();i++){
        dfs(v[now][i],now);
    }
    if(s[now]==gs[now]+1)vis[now]=1;
    int c,l,le;
    if(!vis[now]&&s[now]>gs[now]+1){
        l=v[now].size();
        for(int i=0;i<l;i++){
            if(vis[v[now][i]]){
                vis[now]=1;
                break;
            }
        }
    }
    if(!vis[now]&&s[now]<gs[now]+1){
        le=v[now].size();
        for(int i=0;i<le;i++){
            c=v[now][i];
            l=v[c].size();
            for(int j=0;j<l;j++){
                if(vis[v[c][j]]){
                    vis[now]=1;
                    break;
                }
            }
            if(vis[now])break;
        }
    }
    d[now]=max(s[now],gs[now]+1);
    if(f[now]!=0)s[fa]+=d[now];
    if(f[fa]!=0)gs[f[fa]]+=d[now];
}
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int cnt;
    while(~scanf("%d",&n)&&n){
        ans=0;
        cnt=1;
        scanf("%s",name);
        m[name]=cnt++;
        for(int i=1;i<n;i++){
            scanf("%s%s",name,na);//cin>>name>>na;
            if(!m.count(name))m[name]=cnt++;
            if(!m.count(na))m[na]=cnt++;
            v[m[na]].push_back(m[name]);
        }
        dfs(1,0);
        printf("%d ",d[1]);
        if(vis[1]) printf("No\n");
        else printf("Yes\n");

        for(int i=0;i<=n;i++){
            d[i]=0;s[i]=0;gs[i]=0;f[i]=0;
            vis[i]=0;
            v[i].clear();
        }
        m.clear();
    }
}
