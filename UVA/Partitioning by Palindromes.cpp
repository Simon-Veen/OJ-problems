#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1e3+10;
char a[MAXN];
int cnt=0,dp[MAXN];
int len;
bool istrue(int l,int r){
    while(1){
        if(l>=r)return true;
        if(a[l]==a[r]){
            l++;
            r--;
        }
        else if(a[l]!=a[r])return false;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",a+1);
        len=strlen(a+1);
        memset(dp,0,sizeof(dp));
        for(int j=1;j<=len;j++){
            dp[j]=j+1;
            for(int k=1;k<=j;k++){
                if(istrue(k,j))
                    dp[j]=min(dp[j],dp[k-1]+1);
            }
        }
        printf("%d\n",dp[len]);
    }
}
