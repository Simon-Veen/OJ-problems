#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
const int INF=999999;
int t,n,dp[55][55],a[55];

int dfs(int l,int r){
    if(dp[l][r])return dp[l][r];
    if(r-l==1)return 0;
    int ans=INF;
    for(int i=l+1;i<r;i++){
        ans=min(ans,dfs(l,i)+dfs(i,r));
    }
    dp[l][r]=ans+a[r]-a[l];
    return dp[l][r];
}
int main()
{
    while(scanf("%d",&t)&&t){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        a[n+1]=t;
        a[0]=0;
        memset(dp,0,sizeof(dp));
        printf("The minimum cutting is %d.\n",dfs(0,n+1));
    }
}
/*
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int dp[55][55],a[55];

int main()
{
    int t,n;
    while(scanf("%d",&t)&&t){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
           scanf("%d",&a[i]);
        }
        a[0]=0;
        a[n+1]=t;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n+1;i++){
            for(int j=0;j+i<=n+1;j++){
                int r=j+i;
                for(int t=j+1;t<r;t++){
                    if(dp[j][r]==0)
                        dp[j][r]=dp[j][t]+dp[t][r]+a[r]-a[j];
                    else
                        dp[j][r]=min(dp[j][r],dp[j][t]+dp[t][r]+a[r]-a[j]);
                    //printf("%d %d %d\n",j,r,dp[j][r]);
                }
            }
        }
        printf("The minimum cutting is %d.\n",dp[0][n+1]);
    }
}
*/
