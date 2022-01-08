/*
    求羊的连通块，在其周围加D
*/
#include<cstdio>
const int MAXN=505;
char map[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
int n,m;
void dfs(int x,int y){
    vis[x][y]=1;
    if(x+1<=n&&map[x+1][y]=='.')map[x+1][y]='D';
    if(x-1>=1&&map[x-1][y]=='.')map[x-1][y]='D';
    if(y+1<=m&&map[x][y+1]=='.')map[x][y+1]='D';
    if(y-1>=1&&map[x][y-1]=='.')map[x][y-1]='D';

    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(!vis[xx][yy]&&xx<=n&&xx>=1&&yy<=m&&yy>=1&&map[xx][yy]=='S'){
            dfs(xx,yy);
        }
    }

}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("\n%c",&map[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(map[i][j]=='S'){
                if(map[i+1][j]=='W'||map[i-1][j]=='W'||map[i][j-1]=='W'||map[i][j+1]=='W'){
                    printf("No\n");
                    return 0;
                }
            }
            if(!vis[i][j]&&map[i][j]=='S'){
                dfs(i,j);
            }
        }
    }
    printf("Yes\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%c",map[i][j]);
        }
        putchar('\n');
    }
}
