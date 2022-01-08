#include<bits/stdc++.h>
using namespace std;

const int MAXN=505,INF=1e9;
char g[MAXN][MAXN];
int ans[MAXN][MAXN],h,w;

deque<pair<int,int>> q;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int bfs(){
    q.emplace_back(1,1);
    for(int i=0;i<=h;i++){
        for(int j=0;j<=w;j++){
            ans[i][j]=INF;
        }
    }
    ans[1][1]=0;
    while(q.size()){
        auto[x,y]=q.front();q.pop_front();
        for(int i=0;i<4;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(1<=xx&&xx<=h&&1<=yy&&yy<=w&&g[xx][yy]!='#'){
                if(ans[xx][yy]>ans[x][y]){
                    ans[xx][yy]=ans[x][y];
                    q.emplace_front(xx,yy);
                }
            }
        }
        for(int i=-2;i<=2;i++){
            for(int j=-2;j<=2;j++){
                if(abs(i)+abs(j)==4)continue;
                int xx=x+i,yy=y+j;
                if(1<=xx&&xx<=h&&1<=yy&&yy<=w){
                    if(ans[xx][yy]>ans[x][y]+1){
                        ans[xx][yy]=ans[x][y]+1;
                        q.emplace_back(xx,yy);
                    }
                }
            }
        }
    }
    return ans[h][w];
}
int main()
{
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            scanf("\n%c",&g[i][j]);
        }
    }
    printf("%d\n",bfs());
}




//int x[MAXN],y[MAXN],xx[MAXN],yy[MAXN];
/*
bool vis[MAXN];
vector<int> v[MAXN];

void dfs(int now){
    int len=v[now].size();
    printf("%d ",now);
    vis[now]=1;
    for(int i=0;i<len;i++){
        if(!vis[v[now][i]]){
            dfs(v[now][i]);
            printf("%d ",now);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int f,t;
    for(int i=1;i<=n-1;i++){
        scanf("%d%d",&f,&t);
        int lf=v[f].size();
        bool ok=1;
        v[f].push_back(t);
        v[t].push_back(f);
    }
    for(int i=1;i<=n;i++){
        sort(v[i].begin(),v[i].end());
    }
    dfs(1);
}



    /*
    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
        xx[i]=x[i];yy[i]=y[i];
    }
    sort(xx+1,xx+1+n);
    int lenx=unique(xx+1,xx+1+n)-xx;
    sort(yy+1,yy+1+n);
    int leny=unique(yy+1,yy+1+n)-yy;
    for(int i=1;i<=n;i++){
        x[i]=lower_bound(xx+1,xx+lenx,x[i])-xx;
        y[i]=lower_bound(yy+1,yy+leny,y[i])-yy;
    }
    for(int i=1;i<=n;i++){
        printf("%d %d\n",x[i],y[i]);
    }



        /*

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]==b[n-1]){
            printf("%d\n",i);
            break;
        }
    }
    /*
    int a,b,c;
    scanf("%d%d",&a,&b);
    for(int i=0;i<=255;i++){
        int k=a^i;
        if(k==b){
            printf("%d ",i);
        }
    }
    */

