#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+10;
const int INF=99999999;
struct terms{
    int v,power_cast,lamp_cast,num;
};
bool cmp(terms a,terms b){
    return a.v<b.v;
}
terms box[MAXN];
int dp[MAXN];
int s[MAXN];
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int n;
    while(scanf("%d",&n)&&n){
        memset(s,0,sizeof(s));
        for(int i=1;i<=n;i++){
            scanf("%d%d%d%d",&box[i].v,&box[i].power_cast,&box[i].lamp_cast,&box[i].num);
        }
        sort(box+1,box+1+n,cmp);
        for(int i=1;i<=n;i++){
            dp[i]=INF;
            s[i]=s[i-1]+box[i].num;
            for(int j=0;j<i;j++){
                dp[i]=min(dp[i],dp[j]+(s[i]-s[j])*box[i].lamp_cast+box[i].power_cast);
            }
        }
        printf("%d\n",dp[n]);
    }
}
