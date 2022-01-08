#include<bits/stdc++.h>

using namespace std;
const int MAXN=2e5+10;
int n,m;
long long s,as;
int w[MAXN],v[MAXN];
int l[MAXN],r[MAXN];
long long pre_w[MAXN],pre_v[MAXN];

bool judge(long long k){
    memset(pre_w,0,sizeof(pre_w));
    memset(pre_v,0,sizeof(pre_v));
    for(int i=1;i<=n;i++){
       if(w[i]>=k) pre_w[i]=pre_w[i-1]+1,pre_v[i]=pre_v[i-1]+v[i];
       else pre_w[i]=pre_w[i-1],pre_v[i]=pre_v[i-1];
    }
    long long wcnt=0,vcnt=0,ans=0;
    for(int i=1;i<=m;i++){
        wcnt=pre_w[r[i]]-pre_w[l[i]-1];
        vcnt=pre_v[r[i]]-pre_v[l[i]-1];
        ans+=wcnt*vcnt;
    }
    as=llabs(s-ans);
    if(ans>s)return true;
    return false;
}


int main()
{
    scanf("%d%d%lld",&n,&m,&s);
    for(int i=1;i<=n;i++)scanf("%d%d",&w[i],&v[i]);
    for(int i=1;i<=m;i++)scanf("%d%d",&l[i],&r[i]);
    long long left=0,right=1e6,mid;
    long long ed=1e18;
    while(left<=right){
        mid=left+right>>1;
        if(judge(mid))left=mid+1;
        else right=mid-1;
        if(as<ed)ed=as;
    }
    printf("%lld",ed);

}
