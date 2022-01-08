#include<cstdio>
#include<algorithm>

using namespace std;
int n,m;
int a[105],f[105][105];
int maxn=1e6+7;
int dfs(int lv,int sum){
    if(sum>m)return 0;
    if(sum==m)return 1;
    if(lv==n+1) return 0;
    if(f[lv][sum])return f[lv][sum];
    int ans=0;
    for(int i=0;i<=a[lv];i++)
        ans=(ans+dfs(lv+1,sum+i))%maxn;
    f[lv][sum]=ans;
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    printf("%d",dfs(1,0));
}
