#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
char x1[5],x2[5];
struct p{
    int x;
    int y;
    int s=0;
};
int dx[10]={1,1,2,2,-1,-1,-2,-2};
int dy[10]={2,-2,1,-1,2,-2,1,-1};
bool xy[15][15];
queue<p> q;
int main()
{
    int yy,xx;
    //freopen("1.txt","r",stdin);
	//freopen("2.txt","w",stdout); 
    while(cin>>x1>>x2)
    {
        for(int i=1;i<=8;i++)
            for(int j=1;j<=8;j++)
                xy[i][j]=0;
        p y,h;
		y.x=int(x1[1])-48;
        y.y=int(x1[0])-96;
        h.x=int(x2[1])-48;
        h.y=int(x2[0])-96;
        xy[y.x][y.y]=1;
        q.push(y);
        while(!q.empty())
        {
        	p nw;
            nw=q.front();q.pop();
            if(nw.x==h.x && nw.y==h.y)
            {
                cout<<"To get from "<<x1[0]<<x1[1]<<" to "<<x2[0]<<x2[1]<<" takes "<<nw.s<<" knight moves."<<endl;
                while(!q.empty())q.pop();
                break;
            }
            for(int i=0;i<8;i++)
            {
                xx=nw.x+dx[i];
                yy=nw.y+dy[i];
                if(xx<=8 &&xx>=1&&yy<=8&&yy>=1&&!xy[xx][yy])
                {
                	p w;
                    w.x=xx;
                    w.y=yy;
                    w.s=nw.s+1;
                    xy[w.x][w.y]=1;
                    q.push(w);
                }       
            }       
        }    
    }
}
