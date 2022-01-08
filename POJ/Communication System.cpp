#include<cstdio>
#include<algorithm>

using namespace std;

const int INF=0x7fffffff;
const int MAXN=105;
int box[MAXN][MAXN];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        double ans=INF;
        scanf("%d",&n);
        double b,p;
        for(int i=1;i<=n;i++){
            int k;
            scanf("%d",&k);
            for(int j=1;j<=k;j++){
                scanf("%lf%lf",&b,&p);
                ans=min(ans,b/p);
            }
        }
        printf("%.3lf\n",ans);
    }
}
