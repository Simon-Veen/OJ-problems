#include<cstdio>
#include<algorithm>
using namespace std;

int a[210],dp[210][210][2];
int n;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i+n]=a[i];
    }
    for(int i=1;i<=2*n-1;i++) a[i]=a[i]+a[i-1];

    int maxn=0,minx=999999999;

    for(int i=1;i<n;i++){
        for(int j=1;j<=2*n-1;j++){
            int rear=j+i;
            if(rear>2*n-1)break;;
            dp[j][rear][1]=999999999;
            for(int p=j;p<rear;p++){
                dp[j][rear][0]=max(dp[j][rear][0],dp[j][p][0]+dp[p+1][rear][0]+a[rear]-a[j-1]);
                dp[j][rear][1]=min(dp[j][rear][1],dp[j][p][1]+dp[p+1][rear][1]+a[rear]-a[j-1]);
            }
        }
    }
    for(int j=1;j<=n;j++)
    {
        int rear=j+n-1;
        maxn=max(maxn,dp[j][rear][0]);
        minx=min(minx,dp[j][rear][1]);
    }
    printf("%d\n%d",minx,maxn);
}
