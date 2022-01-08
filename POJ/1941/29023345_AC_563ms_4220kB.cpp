#include<cstdio>
#include<cmath> 
int n;
char maze[2050][2050];
int maxn,maxx;
void dfs(int t,int x,int y,int x2,int y2)
{
	if(t>maxn)return;
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=2*i;j++)
		{
			maze[x+i-1][y+j-i]=maze[i][j+maxn-i];
			maze[x2+i-1][y2+j-i]=maze[i][j+maxn-i];
		}
	}
	dfs(2*t,x+t,y-t,x2+t,y2+t);
}
int main()
{	
	bool pr=0;
	while(scanf("%d",&n)==1)
	{
		if(pr)printf("\n");
		if(n==0) continue;
		
		pr=1;
		maxn=maxx=1;
		for(int i=1;i<=n;i++)
		{
			maxn*=2;maxx*=2;
		}
		maxx*=2;
		for(int i=1;i<=maxx;i++)
			for(int j=1;j<=maxx;j++)
				maze[i][j]=0;
		maze[1][maxn]='/';maze[1][maxn+1]='\\';
		maze[2][maxn-1]='/';maze[2][maxn]='_';
		maze[2][maxn+1]='_';maze[2][maxn+2]='\\';
		dfs(2,3,maxn-2,3,maxn+2);
		int cnt=1;
		while(cnt<=maxn)
		{
			for(int i=1;i<=maxn+cnt;i++)
			{
				if(maze[cnt][i]==0)printf(" ");
				else 
					printf("%c",maze[cnt][i]);
			}
			printf("\n");
			cnt++;
		}

	}
	
}