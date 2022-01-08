#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+10;
int g[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
struct node{
    int x,y;
};
queue<node> q;
bool judge(int x,int n,int m){
    memset(vis,0,sizeof(vis));
    vis[1][1]=1;
    node k;
    k.x=1;k.y=1;
    q.push(k);
    bool ok=0;
    while(!q.empty()){
        node p=q.front();q.pop();
        if(p.x==n){
            ok=1;
            break;
        }
        for(int i=0;i<4;i++){
            int xx=p.x+dx[i];
            int yy=p.y+dy[i];
            if(1<=xx&&xx<=n&&1<=yy&&yy<=m&&!vis[xx][yy]&&(g[xx][yy]<=x)){
                node nw;
                nw.x=xx;nw.y=yy;
                q.push(nw);
                vis[xx][yy]=1;
            }
        }
    }
    while(!q.empty())q.pop();//!!!
    return ok;
}
int main()
{
    int n,m;
    int maxx=-MAXN,minn=MAXN;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&g[i][j]);
            maxx=max(g[i][j],maxx);
            minn=min(g[i][j],minn);
        }
    }
    int l=minn,r=maxx;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(judge(mid,n,m))r=mid-1;
        else l=mid+1;
    }
    if(l>maxx||!judge(l,n,m))printf("%d\n",maxx);
    else printf("%d\n",l);
}
