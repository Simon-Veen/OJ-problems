#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

typedef long long LL;
LL n,m,k;

int judge(LL p)
{
    LL cnt=0,sum=0,minx;
    for(LL i=1;i<=n;i++)
    {
        minx=min(p,i*m);
        sum+=minx/i;
    }
    return sum<k;
}
int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    LL left=1,right=n*m;
    LL mid,ans;
    while(left<right)
    {
        mid=(left+right)>>1;
        if(judge(mid))left=mid+1;
        else right=mid;
    }
    printf("%lld",left);
}
