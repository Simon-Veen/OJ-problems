#include<cstdio>


typedef long long LL;
//LL 9e18

const int MAXN=3e5+5;
LL h[MAXN],p[MAXN];
LL dp[MAXN][3];
LL min(LL a,LL b)
{
    return a>b? b:a;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        for(int i=1;i<=n;i++){
            scanf("%lld%lld",&h[i],&p[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                dp[i][j]=2e18;
            }
        }
        for(LL i=0;i<3;i++)dp[1][i]=p[1]*i;

        for(LL i=2;i<=n;i++){
            for(LL j=0;j<3;j++){
                for(LL k=0;k<3;k++){
                    if(h[i-1]+k!=h[i]+j){
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+p[i]*j);
                    }
                }
            }
        }
        LL minx=2e18;
        for(int i=0;i<3;i++)
            minx=min(dp[n][i],minx);
        printf("%lld\n",minx);
    }
}
