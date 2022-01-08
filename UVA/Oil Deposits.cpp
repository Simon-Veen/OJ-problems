#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=105;
char box[MAXN][MAXN];
int n,m;
bool vis[MAXN][MAXN];
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={-1,1,-1,0,1,-1,0,1};
void dfs(int x,int y){
    vis[x][y]=1;
    for(int i=0;i<8;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]){
            if(box[xx][yy]=='@'){
                dfs(xx,yy);
            }
        }
    }
}
int main()
{
    //freopen("2.txt","w",stdout);
    while(scanf("%d%d",&n,&m)==2){
        if(n==0&&m==0)break;
        memset(vis,0,sizeof(vis));
        memset(box,0,sizeof(box));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("\n%c",&box[i][j]);
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(box[i][j]=='@'&&!vis[i][j]){
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",cnt);
    }
}
