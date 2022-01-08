#include<cstdio>

int m,n,cnt;
void dfs(int k,int v,int p)
{
	if(v==n)
	{
		if(k==m)cnt++;
		return;
	}
	for(int i=p;i<=m;i++)
		dfs(i+k,v+1,i); 
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%d%d",&m,&n);
		dfs(0,0,0);
		printf("%d\n",cnt);
	}
	
 } 