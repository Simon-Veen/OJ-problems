#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

struct node{
    int x,y,c;
    bool d;
};
queue<node> q;
char a[15][15][2];
int vis[15][15][2];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int n,m,k;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        for(int p=0;p<2;p++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    scanf("\n\n%c",&a[i][j][p]);
                }
            }
        }
        bool as=0;
        vis[1][1][0]=1;
        node ne;
        ne.x=1;ne.y=1;ne.c=0;ne.d=0;
        q.push(ne);
        int cnt;
        while(!q.empty()){
            node z;
            z=q.front();
            q.pop();
            if(a[z.x][z.y][z.d]=='P'){
                cnt=z.c;
                as=1;
                break;
            }
            for(int i=0;i<4;i++){
                int xx=z.x+dx[i];
                int yy=z.y+dy[i];
                if(xx>=1&&xx<=n&&yy<=m&&yy>=1&&!vis[xx][yy][z.d]&&a[xx][yy][z.d]!='*'){
                    if(a[xx][yy][z.d]=='.'||a[xx][yy][z.d]=='P'){
                        node f;
                        f.x=xx;
                        f.y=yy;
                        f.c=z.c+1;
                        f.d=z.d;
                        vis[xx][yy][z.d]=1;
                        q.push(f);
                    }
                    if(a[xx][yy][z.d]=='#'&&a[xx][yy][!z.d]!='#'&&a[xx][yy][!z.d]!='*'&&!vis[xx][yy][!z.d]){
                        node f;
                        f.x=xx;
                        f.y=yy;
                        f.c=z.c+1;
                        f.d=!z.d;
                        vis[xx][yy][!z.d]=1;
                        q.push(f);
                    }
                }
            }
        }
        if(!as||cnt>k)printf("NO\n");
        else printf("YES\n");
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        while(!q.empty())q.pop();
    }
}
