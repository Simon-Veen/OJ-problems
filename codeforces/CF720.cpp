#include<cstdio>
#include<vector>

using namespace std;
const int MAXN=1e5+10;
vector<int> v[MAXN];

int d[MAXN];
int cnt=0;
int f[MAXN];
int dfs(int p,int fa){

    f[p]=fa;
    if(d[p]==1){
        return p;
    }
    int len=v[p].size();
    bool c=0;
    if(d[p]>2){
        int l,r;
        for(int i=0;i<len;i++){
            if(v[p][i]!=p){
                if(!l){
                    l=dfs(v[p][i],p);
                }
                else if(!r){
                    r=dfs(v[p][i],p);
                }
                else if(l&&r){
                    if(c==0){
                        d[p]--;
                        d[fa]--;
                        printf("%d %d %d %d\n",v[p][i],fa,l,r);
                        cnt++;
                        l=r;
                        r=0;
                        c=1;
                    }
                    else{
                        printf("%d %d %d %d\n",f[l],l,l,r);
                        cnt++;
                        d[l]--;
                        d[f[l]]--;
                        l=r;
                        r=0;
                    }
                }
            }
        }
        return p;
    }
    else{
        if(v[p][0]==fa){
            return dfs(v[p][1],p);
        }
        else{
            return dfs(v[p][0],p);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int f,t;
        for(int i=1;i<n;i++){
            scanf("%d%d",&f,&t);
            v[f].push_back(t);
            d[f]++;
            v[t].push_back(f);
            d[t]++;
        }
        dfs(1,-1);
    }
}
/*
B
#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN=2e5+10,INF=2e9;

int a[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int maxn=INF,p;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(maxn>a[i]){
                maxn=a[i];
                p=i;
            }
        }
        printf("%d\n",n-1);
        for(int i=1;i<=n;i++){
            if(i!=p){
                printf("%d %d %d %d\n",i,p,abs(p-i)+a[p],a[p]);
                a[i]=abs(p-i)+a[p];
            }
        }

    }
}

A
#include<cstdio>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        long long int a,b;
        scanf("%lld%lld",&a,&b);
        if(b==1){
            printf("NO\n");
            continue;
        }
        printf("YES\n%lld %lld %lld\n",a,2*a*b-a,2*a*b);
    }
}
*/
