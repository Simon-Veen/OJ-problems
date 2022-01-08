#include<iostream>
#include<queue>
using namespace std;
int map[25][25][25];
int xdir[5]={0,0,1,-1};
int ydir[5]={1,-1,0,0};
bool mp[25][25][25];
struct node{
	int x,y,cost,jump;
};
queue<node> q;
int main()
{
	int n,x,y,step;
	bool pr=0;
	//freopen("1.txt","r",stdin);
	//freopen("2.txt","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>x>>y>>step;
		for(int i=1;i<=x;i++)
	 		for(int j=1;j<=y;j++)
	 		{
	 			cin>>map[i][j][0];
	 			for(int p=1;p<25;p++)map[i][j][p]=map[i][j][0];
			}
		for(int i=0;i<25;i++)
			for(int j=0;j<25;j++)
				for(int p=0;p<25;p++)
					mp[i][j][p]=0;
		pr=0; 
	 	node nw;
	 	nw.x=1;nw.y=1;nw.cost=0;nw.jump=0;
	 	mp[1][1][0]=1;
		q.push(nw);
	 	while(!q.empty())
	 	{
	 		node k;
			k=q.front();q.pop();
			if(k.x==x&&k.y==y)
			{
				cout<<k.cost<<endl;
				pr=1;
				while(!q.empty())q.pop();
				break; 
			} 
			int cnt=0;
			for(int i=0;i<4;i++)
			{
				int xx=k.x+xdir[i];
				int yy=k.y+ydir[i];
				if(xx>=1&&xx<=x&&yy>=1&&yy<=y&&!mp[xx][yy][k.jump])
				{
					if(map[xx][yy][k.jump]&&k.jump+1<=step)   //由于要花费一步来跨越障碍 
					{
						node w;
						w.x=xx;w.y=yy;w.cost=k.cost+1;w.jump=k.jump+1;
						mp[xx][yy][k.jump]=1;
						q.push(w);
					}
					else if(!map[xx][yy][k.jump])
					{
						cnt=0;
						node w;
						w.x=xx;w.y=yy;w.cost=k.cost+1;w.jump=0;
						mp[xx][yy][k.jump]=1;
						q.push(w);
					}
				}
			}	
		}
		if(!pr)cout<<-1<<endl;
	}
 } 