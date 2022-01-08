#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=105,INF=2e9;
int a[MAXN];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        bool ok=1;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]<0){
                ok=0;
            }
        }
        if(!ok){
            printf("NO\n");
        }
        else{
            sort(a+1,a+1+n);
            printf("YES\n%d\n",a[n]+1);
            for(int i=0;i<=a[n];i++){
                printf("%d ",i);
            }
            printf("\n");
        }
    }
}
