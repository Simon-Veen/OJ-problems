#include<cstdio>
#include<cmath>
using namespace std;

const int MAXN=1e5+10;
int a[MAXN];

int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int n;
    while(scanf("%d",&n)&&n){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        long long int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=0){
                ans+=abs(a[i]);
                a[i+1]+=a[i];
            }
        }
        printf("%lld\n",ans);

    }
}
