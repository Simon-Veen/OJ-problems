#include<bits/stdc++.h>
using namespace std;
const int MAXN=350+10,INF=45;
int x[MAXN],a,b,c,d;
int dp[INF][INF][INF][INF];
int main()
{

    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&x[i]);
    int num;
    for(int i=1;i<=m;i++){
        scanf("%d",&num);
        if(num==1)a++;
        else if(num==2)b++;
        else if(num==3)c++;
        else if(num==4)d++;
    }
    dp[0][0][0][0]=x[1];
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            for(int p=0;p<=c;p++){
                for(int t=0;t<=d;t++){
                    if(i-1>=0){
                        dp[i][j][p][t]=max(dp[i][j][p][t],dp[i-1][j][p][t]+x[1+i*1+j*2+p*3+t*4]);
                    }
                    if(j-1>=0){
                        dp[i][j][p][t]=max(dp[i][j][p][t],dp[i][j-1][p][t]+x[1+i*1+j*2+p*3+t*4]);
                    }
                    if(p-1>=0){
                        dp[i][j][p][t]=max(dp[i][j][p][t],dp[i][j][p-1][t]+x[1+i*1+j*2+p*3+t*4]);
                    }
                    if(t-1>=0){
                        dp[i][j][p][t]=max(dp[i][j][p][t],dp[i][j][p][t-1]+x[1+i*1+j*2+p*3+t*4]);
                    }
                }
            }
        }
    }
    printf("%d\n",dp[a][b][c][d]);
}
