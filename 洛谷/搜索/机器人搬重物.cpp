#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

struct node{

    int x,y,d;
    int c;
};
queue<node> q;
bool vis[55][55][4];  //0-E;1-S;2-W;3-N
int a[55][55];
int n,m;
int num(char x){
    if(x=='E')return 0;
    else if(x=='S')return 1;
    else if(x=='W')return 2;
    else if(x=='N')return 3;
}
bool pan(int x,int y){

    if(!a[x][y]&&!a[x+1][y]&&!a[x][y+1]&&!a[x+1][y+1]){
        return true;
    }
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int sx,sy,ex,ey;
    char dir;
    scanf("%d%d%d%d %c",&sx,&sy,&ex,&ey,&dir);
    vis[sx][sy][num(dir)]=1;
    node z;
    z.x=sx;z.y=sy;z.d=num(dir);
    z.c=0;
    q.push(z);
    bool ok=0;
    int ans=1e9;
    while(!q.empty()){
        node j=q.front();
        q.pop();
        if(j.x==ex&&j.y==ey&&!a[ex][ey]&&!a[ex+1][ey]&&!a[ex][ey+1]&&!a[ex+1][ey+1]){
            ok=1;
            printf("%d\n",j.c);
            break;
        }
        int fx=j.d;
        if(fx==0){
            int xx=j.x;
            int yy=j.y+3;
            if(xx+1<=n&&yy+1<=m&&!vis[xx][yy][fx]&&pan(xx,yy)&&pan(xx,yy-1)&&pan(xx,yy-2)){
                vis[xx][yy][fx]=1;
                node b;
                b.x=xx;b.y=yy;b.d=j.d;b.c=j.c+1;
                q.push(b);
            }
            yy=j.y+2;
            if(xx+1<=n&&yy+1<=m&&!vis[xx][yy][fx]&&pan(xx,yy)&&pan(xx,yy-1)){
                vis[xx][yy][fx]=1;
                node b;
                b.x=xx;b.y=yy;b.d=j.d;b.c=j.c+1;
                q.push(b);
            }
            yy=j.y+1;
            if(xx+1<=n&&yy+1<=m&&!vis[xx][yy][fx]&&pan(xx,yy)){
                vis[xx][yy][fx]=1;
                node b;
                b.x=xx;b.y=yy;b.d=j.d;b.c=j.c+1;
                q.push(b);
            }
            if(!vis[j.x][j.y][3]){
                node b;
                b.x=j.x;b.y=j.y;b.d=3;b.c=j.c+1;
                vis[j.x][j.y][3]=1;
                q.push(b);
            }
            if(!vis[j.x][j.y][1]){
                node b;
                b.x=j.x;b.y=j.y;b.d=1;b.c=j.c+1;
                vis[j.x][j.y][1]=1;
                q.push(b);
            }
        }
        else if(fx==1){
            int xx=j.x+3;
            int yy=j.y;
            if(xx+1<=n&&yy+1<=m&&!vis[xx][yy][fx]&&pan(xx,yy)&&pan(xx-1,yy)&&pan(xx-2,yy)){
                vis[xx][yy][fx]=1;
                node b;
                b.x=xx;b.y=yy;b.d=j.d;b.c=j.c+1;
                q.push(b);
            }
            xx=j.x+2;
            yy=j.y;
            if(xx+1<=n&&yy+1<=m&&!vis[xx][yy][fx]&&pan(xx,yy)&&pan(xx-1,yy)){
                vis[xx][yy][fx]=1;
                node b;
                b.x=xx;b.y=yy;b.d=j.d;b.c=j.c+1;
                q.push(b);
            }
            xx=j.x+1;
            yy=j.y;
            if(xx+1<=n&&yy+1<=m&&!vis[xx][yy][fx]&&pan(xx,yy)){
                vis[xx][yy][fx]=1;
                node b;
                b.x=xx;b.y=yy;b.d=j.d;b.c=j.c+1;
                q.push(b);
            }
            if(!vis[j.x][j.y][0]){
                node b;
                b.x=j.x;b.y=j.y;b.d=0;b.c=j.c+1;
                vis[j.x][j.y][0]=1;
                q.push(b);
            }
            if(!vis[j.x][j.y][2]){
                node b;
                b.x=j.x;b.y=j.y;b.d=2;b.c=j.c+1;
                vis[j.x][j.y][2]=1;
                q.push(b);
            }
        }
        else if(fx==2){
            int xx=j.x;
            int yy=j.y-3;
            if(xx+1<=n&&yy+1<=m&&yy>=1&&!vis[xx][yy][fx]&&pan(xx,yy)&&pan(xx,yy+1)&&pan(xx,yy+2)){
                vis[xx][yy][fx]=1;
                node b;
                b.x=xx;b.y=yy;b.d=j.d;b.c=j.c+1;
                q.push(b);
            }
            yy=j.y-2;
            if(xx+1<=n&&yy+1<=m&&yy>=1&&!vis[xx][yy][fx]&&pan(xx,yy)&&pan(xx,yy+1)){
                vis[xx][yy][fx]=1;
                node b;
                b.x=xx;b.y=yy;b.d=j.d;b.c=j.c+1;
                q.push(b);
            }
            yy=j.y-1;
            if(xx+1<=n&&yy+1<=m&&yy>=1&&!vis[xx][yy][fx]&&pan(xx,yy)){
                vis[xx][yy][fx]=1;
                node b;
                b.x=xx;b.y=yy;b.d=j.d;b.c=j.c+1;
                q.push(b);
            }
            if(!vis[j.x][j.y][3]){
                node b;
                b.x=j.x;b.y=j.y;b.d=3;b.c=j.c+1;
                vis[j.x][j.y][3]=1;
                q.push(b);
            }
            if(!vis[j.x][j.y][1]){
                node b;
                b.x=j.x;b.y=j.y;b.d=1;b.c=j.c+1;
                vis[j.x][j.y][1]=1;
                q.push(b);
            }
        }
        else if(fx==3){

            int xx=j.x-3;
            int yy=j.y;
            if(xx+1<=n&&xx>=1&&yy+1<=m&&!vis[xx][yy][fx]&&pan(xx,yy)&&pan(xx+1,yy)&&pan(xx+2,yy)){
                vis[xx][yy][fx]=1;
                node b;
                b.x=xx;b.y=yy;b.d=j.d;b.c=j.c+1;
                q.push(b);
            }
            xx=j.x-2;
            if(xx>=1&&xx+1<=n&&yy+1<=m&&!vis[xx][yy][fx]&&pan(xx,yy)&&pan(xx+1,yy)){
                vis[xx][yy][fx]=1;
                node b;
                b.x=xx;b.y=yy;b.d=j.d;b.c=j.c+1;
                q.push(b);
            }
            xx=j.x-1;
            if(xx>=1&&xx+1<=n&&yy+1<=m&&!vis[xx][yy][fx]&&pan(xx,yy)){
                vis[xx][yy][fx]=1;
                node b;
                b.x=xx;b.y=yy;b.d=j.d;b.c=j.c+1;
                q.push(b);
            }
            if(!vis[j.x][j.y][0]){
                node b;
                b.x=j.x;b.y=j.y;b.d=0;b.c=j.c+1;
                vis[j.x][j.y][0]=1;
                q.push(b);
            }
            if(!vis[j.x][j.y][2]){
                node b;
                b.x=j.x;b.y=j.y;b.d=2;b.c=j.c+1;
                vis[j.x][j.y][2]=1;
                q.push(b);
            }
        }
    }
    if(!ok)printf("-1");
}
