#include<cstdio>
#include<algorithm>

const int MAXN=405;
int v[MAXN],m[MAXN],c[MAXN];
int dp[MAXN][MAXN];


int main()
{
    int Vmax,Mmax,n;
    scanf("%d%d",&Vmax,&Mmax);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
     scanf("%d%d%d",&v[i],&m[i],&c[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=Mmax;j>=m[i];j--){
            for(int k=Vmax;k>=v[i];k--){
                dp[k][j]=std::max(dp[k][j],dp[k-v[i]][j-m[i]]+c[i]);
            }
        }
    }
    printf("%d\n",dp[Vmax][Mmax]);
}
