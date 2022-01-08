#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=2e4+10;

struct segement{
    int l,r,num;
}t[MAXN<<2];
struct line{
    int l,r;
}d[MAXN];
int x[MAXN<<1];
bool vis[MAXN<<1];
int ans=0;
int lisan(int tot,int n){
    sort(x+1,x+1+tot);
    int len=unique(x+1,x+1+tot)-x-1;
    for(int i=1;i<=n;i++){
        d[i].l=lower_bound(x+1,x+1+len,d[i].l)-x;
        d[i].r=lower_bound(x+1,x+1+len,d[i].r)-x;
    }
    return len;
}
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    t[p].num=0;
    if(l==r)return;
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}
void pushdown(int p){
    if(t[p].num==-1)return;
    t[p<<1].num=t[p].num;
    t[p<<1|1].num=t[p].num;
    t[p].num=-1;
}
void change(int p,int l,int r,int c){
    if(l<=t[p].l&&t[p].r<=r){
        t[p].num=c;
        return;
    }
    pushdown(p);
    int mid=t[p].l+t[p].r>>1;
    if(l<=mid)change(p<<1,l,r,c);
    if(r>mid)change(p<<1|1,l,r,c);
}
void ask(int p){

    if(t[p].num!=-1){
        if(!vis[t[p].num]){
            vis[t[p].num]=1;
            ans++;
        }
        return;
    }
    ask(p<<1);
    ask(p<<1|1);
}
int main(){
    int _;
    scanf("%d",&_);
    while(_--){
        int n;
        scanf("%d",&n);
        ans=0;
        int tot=0; 
        for(int i=1;i<=n;i++){
            scanf("%d%d",&d[i].l,&d[i].r);
            x[++tot]=d[i].l;x[++tot]=d[i].r;
            x[++tot]=d[i].r+1;   //为了离散化不导致区间关系丢失
        }
        int len=lisan(tot,n);
        build(1,1,len);
        for(int i=1;i<=n;i++){
            change(1,d[i].l,d[i].r,i);
        }
        vis[0]=1;
        ask(1);
        printf("%d\n",ans);
        memset(vis,0,sizeof(vis));
    }

}
