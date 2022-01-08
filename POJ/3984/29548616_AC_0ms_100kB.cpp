#include<cstdio>
#include<vector>
#include<queue>

using namespace std;
struct POINT{
    int x,y,dis;
};
queue<POINT> q;
vector<POINT> v;
int map[10][10];
bool cp[10][10];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main()
{
    int g;
    for(int i=0;i<=4;i++)
    {
        for(int j=0;j<=4;j++)
        {
            scanf("%d",&g);
            if(g==1)map[i][j]=-1;
        }
    }

    POINT nw;
    nw.x=0;nw.y=0;nw.dis=0;
    q.push(nw);
    cp[0][0]=1;
    v.push_back(nw);
    while(!q.empty())
    {
        POINT k=q.front();
        q.pop();
        if(k.x==4&&k.y==4)break;
        for(int i=0;i<4;i++)
        {
            int x=k.x+dx[i];
            int y=k.y+dy[i];
            if(y<=4&&y>=0&&x>=0&&x<=4&&map[x][y]==0&&cp[x][y]==0)
            {
                POINT d;
                d.x=x;d.y=y;
                d.dis=k.dis+1;
                q.push(d);
                cp[x][y]=1;
                map[x][y]=d.dis;
            }
        }
    }
    POINT a;
    a.x=0;a.y=0;a.dis=0;
    //printf("%d\n",map[4][4]);
    while(1)
    {
        if(a.x==4&&a.y==4) break;
        for(int i=0;i<4;i++)
        {
            int x=a.x+dx[i];
            int y=a.y+dy[i];
            if(x>=0&&x<=4&&y>=0&&y<=4&&map[x][y]==a.dis+1&&map[x][y]>0)
            {
                a.x=x;
                a.y=y;
                a.dis++;
                v.push_back(a);
                break;
            }
        }
    }
    for(int i=0;i<v.size();i++)
        printf("(%d, %d)\n",v[i].x,v[i].y);
}
