/*
    dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
    dp[i][1]=dp[i-1][0]+i*cnt[i];
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N],b[N];
long long ans[N][2];
int main()
{
    int n;
    scanf("%d",&n);
    int x,len=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int l=lower_bound(a+1,a+1+n,a[i])-a;
        int r=upper_bound(a+1,a+1+n,a[i])-a;
        b[a[i]]=r-l;
    }
    len=a[n];
    for(long long i=1;i<=len;i++){
        ans[i][1]=ans[i-1][0]+i*b[i];
        ans[i][0]=max(ans[i-1][0],ans[i-1][1]);
    }
    printf("%lld\n",max(ans[len][0],ans[len][1]));
}
