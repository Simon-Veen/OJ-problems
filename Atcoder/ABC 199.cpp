#include<cstdio>
#include<cmath>

using namespace std;
const int MAXN=20;
int graph[MAXN+5][MAXN+5];
bool vis[MAXN+5];
int ord[MAXN+5];
int color[MAXN+5];
int n,m;
long long int ans;
int cnt=1;
void build(int p){
    ord[cnt++]=p;
    vis[p]=1;
    for(int i=1;i<=n;i++){
        if(graph[p][i]&&!vis[i]){
            build(i);
        }
    }
}
void dfs(int p,int num){
    if(p==num+1){
        ans++;
        return;
    }
    bool ok=1;
    for(int j=1;j<=3;j++){
        ok=1;
        for(int i=1;i<=num;i++){
            if(graph[ord[p]][ord[i]]&&j==color[ord[i]]){
                ok=0;
                break;
            }
        }
        if(ok){
            color[ord[p]]=j;
            dfs(p+1,num);
            color[ord[p]]=0;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    int head=0;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        graph[x][y]=1;
        graph[y][x]=1;
    }
    long long int sum=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt=1;
            build(i);
            ans=0;
            dfs(1,cnt-1);
            for(int j=0;j<cnt;j++)color[ord[j]]=0;
            sum*=ans;
        }
    }
    printf("%lld\n",sum);
}
/*
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

const int MAXN=4e5+10;
char a[MAXN];

int main()
{
    int t,n;
        scanf("%d",&n);
        scanf("%s",a+1);
        scanf("%d",&t);
        int x,y,z;
        bool q=1;
        for(int i=1;i<=t;i++){
            scanf("%d%d%d",&x,&y,&z);
            if(x==1){
                if(q){
                    swap(a[y],a[z]);
                }
                else {
                    if(y>n){
                        swap(a[y-n],a[z-n]);
                    }
                    if(y<=n&&z>n) swap(a[y+n],a[z-n]);
                    if(z<=n){
                        swap(a[y+n],a[z+n]);
                    }
                }
            }
            if(x==2){
                q=!q;
            }
        }
        if(q){
            for(int i=1;i<=2*n;i++)printf("%c",a[i]);
        }
        if(!q){
            for(int i=n+1;i<=2*n;i++)printf("%c",a[i]);
            for(int i=1;i<=n;i++)printf("%c",a[i]);
        }

}
*/
