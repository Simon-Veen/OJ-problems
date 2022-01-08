#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
struct Ball{
    int x,y,z;
};
Ball Circle[1005];
int n;
queue<Ball> q;

bool vis[1005];

bool dis(int x1,int y1,int r1,int x2,int y2,int r2)
{
    if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=(r1+r2)*(r1+r2))return true;  //两点距离小于半径之和则两圆相交,等于则相切
    return false;
}
bool Line_Circle(int a,int b,int c,int x,int y,int r)  //边界线与圆相交
{
    if(r*r-(a*x+b*y-c)*(a*x+b*y-c)>=0)return true;  //点到线距离公式
    return false;
}
bool BFS()
{
    double left_y=1000,right_y=1000;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){  //找与上边界相交或相切的圆
        if(Line_Circle(0,1,1000,Circle[i].x,Circle[i].y,Circle[i].z)){
            double r=(double)Circle[i].z,a=(double)Circle[i].x,b=(double)Circle[i].y;
            if(Line_Circle(1,0,0,Circle[i].x,Circle[i].y,Circle[i].z)){
                double k=sqrt(r*r-a*a);
                if(k+b>=0&&k+b<=1000)left_y=min(left_y,k+b);
                if(-k+b>=0&&-k+b<=1000)left_y=min(left_y,-k+b);
            }
            if(Line_Circle(1,0,1000,Circle[i].x,Circle[i].y,Circle[i].z)){
                double k=sqrt(r*r-(1000-a)*(1000-a));
                if(k+b>=0&&k+b<=1000)right_y=min(right_y,k+b);
                if(-k+b>=0&&-k+b<=1000)right_y=min(right_y,-k+b);
            }
            q.push(Circle[i]);
            vis[i]=1;
        }
    }
    while(!q.empty()){
        Ball a;
        a=q.front();
        q.pop();
        if(Line_Circle(0,1,0,a.x,a.y,a.z)){  //圆与下边界有交点
            return false;
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]&&dis(a.x,a.y,a.z,Circle[i].x,Circle[i].y,Circle[i].z)){
                double r=(double)Circle[i].z,a=(double)Circle[i].x,b=(double)Circle[i].y;
                if(Line_Circle(1,0,0,Circle[i].x,Circle[i].y,Circle[i].z)){
                    double k=sqrt(r*r-a*a);
                    if(k+b>=0&&k+b<=1000)left_y=min(left_y,k+b);
                    if(-k+b>=0&&-k+b<=1000)left_y=min(left_y,-k+b);
                }

                if(Line_Circle(1,0,1000,Circle[i].x,Circle[i].y,Circle[i].z)){
                    double k=sqrt(r*r-(1000-a)*(1000-a));
                    if(k+b>=0&&k+b<=1000)right_y=min(right_y,k+b);
                    if(-k+b>=0&&-k+b<=1000)right_y=min(right_y,-k+b);
                }
                q.push(Circle[i]);
                vis[i]=1;
            }
        }
    }
    printf("0.00 %.2lf 1000.00 %.2lf\n",left_y,right_y);
    return true;
}

int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&Circle[i].x,&Circle[i].y,&Circle[i].z);
        }
        if(BFS()) continue;
        else printf("IMPOSSIBLE\n");
    }
}
