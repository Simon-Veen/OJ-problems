//¼ÇÒä»¯ËÑË÷
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long int a[20];
long long int getsum(int l,int r){

    long long int k=a[l];
    for(int i=l+1;i<=r;i++){
        k*=a[i];
    }
    return k;
}
long long int dfs(int l,int r){

    long long int sum=0;
    for(int i=l;i<=r;i++){
        sum=max(getsum(l,i),sum);
        sum=max(sum,getsum(i,r));
    }
    return sum;
}
bool pan(int l,int r){
    for(int i=l;i<=r;i++){
        if(a[i]==0)return false;
    }
    return true;
}
int main(){

    int t,cnt=1;
    while(~scanf("%d",&t)){
        for(int i=1;i<=t;i++){
          scanf("%lld",&a[i]);
        }
        long long int sum=0,ans=0;
        for(int i=1;i<=t;i++){
            for(int j=i;j<=t;j++){
                if(pan(i,j)){
                    ans=max(ans,dfs(i,j));
                }
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n",cnt++,ans);
    }
}
