#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=1e6+3;
int Bucket[MAXN],a[MAXN];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){

        memset(Bucket,0,sizeof(Bucket));
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            Bucket[a[i]]++;
        }
        long long int ans=0;
        for(int i=1;i<=n;i++){
            ans+=Bucket[i]/2;
            Bucket[i]=Bucket[i]%2;
            if(Bucket[i-1]&&Bucket[i]&&Bucket[i+1]){
                Bucket[i-1]--;
                Bucket[i]--;
                Bucket[i+1]--;
                ans++;
            }
        }
        printf("%lld\n",ans);
    }
}
