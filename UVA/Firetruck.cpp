#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>

using namespace std;

queue<int> q;
vector<int> ans;
int maxx;
int p[25][25],cnt=0,cast=1;
bool v[25];
void dfs(int first,int rear)
{
    if(first==rear)
    {
        cnt++;
        for(int i=0;i<ans.size()-1;i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[ans.size()-1]);
        return;
    }
    for(int i=1;i<=maxx;i++)
    {
        if(p[first][i]&&!v[i])
        {
            ans.push_back(i);
            v[i]=1;
            dfs(i,rear);
            v[i]=0;
            ans.pop_back();
        }
    }
}
bool BFS(int t)
{
    q.push(1);
    v[1]=1;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        if(f==t)return true;
        for(int i=1;i<=maxx;i++)
        {
            if(p[f][i]&&!v[i])
            {
                q.push(i);
                v[i]=1;
            }
        }
    }
    return false;
}
int main()
{
    int k,from,to;
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    while(scanf("%d",&k)!=EOF)
    {
        for(int i=0;i<25;i++)
        {
            v[i]=0;
            for(int j=0;j<25;j++)
                p[i][j]=0;
        }
        while(scanf("%d%d",&from,&to))
        {
            if(from==0&&to==0)break;
            p[from][to]=1;
            p[to][from]=1;
            maxx=max(from,maxx);
            maxx=max(to,maxx);
        }

        ans.clear();
        ans.push_back(1);
        cnt=0;
        bool ok=BFS(k);
        for(int i=0;i<25;i++)v[i]=0;
        v[1]=1;
        //if(cast!=1)printf("\n");
        printf("CASE %d:\n",cast++);
        if(ok)dfs(1,k);
        printf("There are %d routes from the firestation to streetcorner %d.\n",cnt,k);
    }
}
