#include<cstdio>
#include<algorithm>

using namespace std;
const int MAXN=1e4+10;
const int INF=10000000000000;
struct Graph{
    int to,next;
    long long w;
}edge[MAXN];
int head[MAXN];
int cnt=1;
long long int d[MAXN];
bool vis[MAXN];
void add(int f,int t,long long int c){
    edge[cnt].to=t;
    edge[cnt].w=c;
    edge[cnt].next=head[f];
    head[f]=cnt++;    
}
void dijkstra(int s,int len){
    for(int i=1;i<len;i++)d[i]=INF;
    long long int maxx=INF;
    while(1){
        int ff=-1;
        maxx=INF;
        for(int i=1;i<=len;i++){
            if(!vis[i]&&(maxx>d[i]||ff==-1)){
                ff=i;
                maxx=d[i];
            }
        }
        if(ff==-1)break;
        vis[ff]=1;
        for(int s=head[ff];s;s=edge[s].next){
            d[edge[s].to]=min(d[edge[s].to],d[ff]+edge[s].w);
        }
    }
}
int main(){

    int t,n;
    scanf("%d%d",&t,&n);
    
    for(int i=1;i<=t;i++){
        int f,k;
        long long int c;
        scanf("%d%d%lld",&f,&k,&c);
        add(f,k,c);
        add(k,f,c);
    }
    dijkstra(n,n);
    printf("%lld",d[1]);
}