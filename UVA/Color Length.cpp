#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e3+10;
const int INF=0x7f7f7f7f;
char a[MAXN],b[MAXN];
int dp[MAXN][MAXN],pox_min[30],pox_max[30];
int poxb_min[30],poxb_max[30];
int len_a,len_b;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",a+1,b+1);
        len_a=strlen(a+1);
        len_b=strlen(b+1);
        for(int i=0;i<26;i++){
            pox_min[i]=poxb_min[i]=INF;
            pox_max[i]=poxb_max[i]=0;
        }
        for(int i=1;i<=len_a;i++){
            pox_min[a[i]-'A']=min(pox_min[a[i]-'A'],i);
            pox_max[a[i]-'A']=i;
        }
        for(int i=1;i<=len_b;i++){
            poxb_min[b[i]-'A']=min(poxb_min[b[i]-'A'],i);
            poxb_max[b[i]-'A']=i;
        }
        for(int i=0;i<=len_a;i++){
            for(int j=0;j<=len_b;j++){
                int cnt=0,temp=INF;
                for(int p=0;p<26;p++){
                    if((i>=pox_min[p]||j>=poxb_min[p])&&(i<pox_max[p]||j<poxb_max[p]))cnt++;
                }
                if(i)temp=min(temp,dp[i-1][j]);
                if(j)temp=min(temp,dp[i][j-1]);
                if(temp==INF)temp=0;
                dp[i][j]=temp+cnt;
            }
        }
        printf("%d\n",dp[len_a][len_b]);
    }
}
