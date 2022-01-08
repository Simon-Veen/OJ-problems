#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;


int time[55],le[55],ri[55];
int dp[205][55];
bool have_train[205][55][2];

const int MAXN=1e8;

int main()
{
    int n,T,cnt=1;
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    while(scanf("%d",&n)!=EOF&&n)
    {
        scanf("%d",&T);
        if(n==0)break;

        memset(dp,0,sizeof(dp));
        memset(have_train,0,sizeof(have_train));
        memset(le,0,sizeof(le));
        memset(ri,0,sizeof(ri));
        memset(time,0,sizeof(time));


        for(int i=1;i<n;i++){
            scanf("%d",&time[i]);
        }
        int left,right,now;
        scanf("%d",&left);
        for(int i=1;i<=left;i++){
            scanf("%d",&le[i]);
            now=le[i];
            if(now<=T) have_train[now][1][1]=1;
            for(int j=1;j<n;j++){
                if(now+time[j]<=T){
                have_train[now+time[j]][j+1][1]=1;
                now+=time[j];
                }
                else break;
            }
        }
        scanf("%d",&right);
        for(int i=1;i<=right;i++){
            scanf("%d",&ri[i]);
            now=ri[i];
            if(now<=T) have_train[now][n][0]=1;
            for(int j=n-1;j>=1;j--){
                if(now+time[j]<=T){
                    have_train[now+time[j]][j][0]=1;
                    now+=time[j];
                }
                else break;
            }
        }
        for(int i=1;i<=n-1;i++){
            dp[T][i]=MAXN;
        }
        dp[T][n]=0;
        for(int i=T-1;i>=0;i--){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i+1][j]+1;
                if(j>1&&have_train[i][j][0]&&i+time[j-1]<=T){
                    dp[i][j]=min(dp[i][j],dp[i+time[j-1]][j-1]);
                }  //在i时刻j站台有无向zuo开的车

                if(j<n&&have_train[i][j][1]&&i+time[j]<=T){
                    dp[i][j]=min(dp[i][j],dp[i+time[j]][j+1]);
                }  //向you开
            }
        }

        printf("Case Number %d: ",cnt++);
        if(dp[0][1]>=MAXN)  printf("impossible\n");
        else    printf("%d\n",dp[0][1]);
    }
}
