#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int dx[8]={-1,1,-2,2,-2,2,-1,1};
int dy[8]={-2,-2,-1,-1,1,1,2,2};
int n,m;
int vis[30][30];
bool dfs(int x,int y,int cnt){
    if(cnt>n*m)return true;
    for(int i=0;i<8;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]){
            vis[xx][yy]=cnt;
            if(dfs(xx,yy,cnt+1)){
                return true;
            }
            vis[xx][yy]=0;
        }
    }
    return false;
}
void print(int x,int y,int cnt){
    if(cnt>n*m){
        return;
    }
    for(int i=0;i<8;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&vis[xx][yy]==cnt){
            printf("%c%d",yy-1+'A',xx);
            print(xx,yy,cnt+1);
        }
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("3.txt","w",stdout);
    int t,cnt=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        printf("Scenario #%d:\n",cnt++);
        memset(vis,0,sizeof(vis));
        vis[1][1]=1;
        if(dfs(1,1,2)){
            printf("A1");
            print(1,1,2);
            printf("\n\n");
        }
        else printf("impossible\n\n");
    }
}
