#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN=1e5;
int sum[MAXN],a[MAXN],c[MAXN];
int acnt,scnt;
void jc(int p){
    acnt=1;
    memset(a,0,sizeof(a));
    a[1]=1;
    for(int i=1;i<=p;i++){
        for(int j=1;j<=acnt;j++){
            a[j]*=i;
        }
        for(int j=1;j<=acnt;j++){
            if(a[j]>=10){
                a[j+1]+=a[j]/10;
                a[j]=a[j]%10;
                if(j==acnt)acnt++;
            }
        }
    }
    while(a[acnt]==0&&acnt>1)acnt--;
}
void BigSum(){

    int len=max(acnt,scnt);
    for(int i=1;i<=len;i++){
        if(sum[i]+a[i]>=10){
            if(i==len)len++;
            sum[i+1]+=(sum[i]+a[i])/10;
        }
        sum[i]=(sum[i]+a[i])%10;
    }
    scnt=len;
}
int main()
{
    int n;
    scanf("%d",&n);
    scnt=1;
    for(int i=1;i<=n;i++){
        jc(i);
        BigSum();
    }
    for(int i=scnt;i>=1;i--)printf("%d",sum[i]);
}
