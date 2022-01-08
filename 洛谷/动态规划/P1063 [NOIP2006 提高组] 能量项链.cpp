#include<cstdio>
#include<algorithm>

using namespace std;
int a[210];
int dp[210][210];

int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i+n]=a[i];
    }
    for(int i=2;i<=n;i++){
        for(int f=1;f<=2*n;f++){
            int rear=f+i;
            if(rear<=2*n){
                for(int k=f+1;k<=rear-1;k++)
                    dp[f][rear]=max(dp[f][rear],dp[f][k]+dp[k][rear]+a[f]*a[k]*a[rear]);
                ans=max(ans,dp[f][rear]);
            }
            else break;
        }
    }
    printf("%d",ans);
}
