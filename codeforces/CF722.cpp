#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN=600+10;
long long int G[MAXN][MAXN];
long long int d[MAXN];
bool v[MAXN];
int n,m;
void dijkstra(int s){
    memset(v,0,sizeof(v));
    long long int maxx=1e12;
    for(int i=0;i<n;i++)d[i]=maxx;
    for(int i=0;i<n;i++){
        if(G[s][i]){
            d[i]=min(d[i],G[s][i]);
        }
    }
    while(1){
        int p=-1;
        maxx=1e12;
        for(int i=0;i<n;i++){
            if(!v[i]&&maxx>d[i]){
                maxx=d[i];
                p=i;
            }
        }
        if(p==-1)break;
        v[p]=1;
        d[(p+1)%n]=min(d[(p+1)%n],d[p]+1);
        for(int i=0;i<n;i++){
           if(G[p][i]){
                int r=(d[p]+i)%n;
                d[r]=min(d[r],d[p]+G[p][i]);
           }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int f,t,c;
        scanf("%d%d%d",&f,&t,&c);
        G[f][t]=c;
    }
    for(int i=0;i<n;i++){
        dijkstra(i);
        for(int j=0;j<n;j++){
            if(i==j)printf("0 ");
            else printf("%lld ",d[j]);
        }
        printf("\n");
    }
}

/*

#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;
const int MAXN=1e5+10,INF=1e9+5;
int a[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,maxx=INF;
        int cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]>0&&a[i]<maxx){
                maxx=a[i];
            }
            if(a[i]<=0){
                cnt++;
            }
        }
        sort(a+1,a+1+n);
        bool ok=0;
        if(maxx==INF) ok=1;
        for(int i=2;i<=n;i++){
            if(a[i]<=0){
                if(abs(a[i]-a[i-1])>=maxx){
                    continue;
                }
                else {
                    ok=1;
                }
            }
        }
        if(ok)printf("%d\n",cnt);
        else printf("%d\n",cnt+1);
    }
}

/*

#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN=105;
int a[MAXN];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);
        bool ok=0;
        int ans=0;
        for(int i=n;i>=1;i--){
            int cnt=1,sum=a[i];
            int mid;
            ok=0;
            for(int j=i-1;j>=1;j--){
                sum+=a[j];
                cnt++;
                mid=sum/cnt;
                if(a[i]>mid){
                    ok=1;
                    break;
                }
            }
            if(ok){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
}

*/
