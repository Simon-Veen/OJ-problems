/*
Bugs:
    1.图的构建，无向图
    2.初始化状态
    3.选择合适答案输出
*/


#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN=1e4+10;
vector<int> a[MAXN];
int ans[MAXN][3];


void dfs(int r,int f){
    int len=a[r].size();

    ans[r][0]=1;
    ans[r][1]=0;
    ans[r][2]=MAXN;

    for(int i=0;i<len;i++){
        int s=a[r][i];
        if(s!=f){
            dfs(s,r);
            ans[r][0]+=min(ans[s][0],ans[s][1]);
            ans[r][1]+=ans[s][2];
        }
    }
    for(int i=0;i<len;i++){
        int s=a[r][i];
        if(s!=f){
            ans[r][2]=min(ans[r][2],ans[r][1]-ans[s][2]+ans[s][0]);
        }
    }
    return;
}

int main()
{
    int t;
    while(scanf("%d",&t)&&t!=-1){
        int s,e;
        for(int i=1;i<t;i++){
            scanf("%d%d",&s,&e);
            a[s].push_back(e);
            a[e].push_back(s);
        }
        dfs(1,-1);
        printf("%d\n",min(ans[1][0],ans[1][2]));
        scanf("%d",&s);
        if(s==-1)break;
        for(int i=0;i<=t;i++){
            ans[i][0]=ans[i][1]=ans[i][2]=0;
            a[i].clear();
        }
    }
}
