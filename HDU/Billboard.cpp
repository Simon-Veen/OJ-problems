#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN=2e5+10;

struct tree{
    int l,r;
    int maxx;
}t[MAXN*4];


void build(int p,int l,int r,int v){

    t[p].l=l;t[p].r=r;
    if(l==r){
        t[p].maxx=v;
        return;
    }
    int mid=(l+r)/2;
    build(p<<1,l,mid,v);
    build(p<<1|1,mid+1,r,v);
    t[p].maxx=max(t[p<<1].maxx,t[p<<1|1].maxx);
}
int ask(int p,int v){
    int ans=-1;
    if(t[p].l==t[p].r&&t[p].maxx>=v){
        t[p].maxx-=v;
        return t[p].l;
    }
    if(t[p<<1].maxx>=v){
        ans=ask(p<<1,v);
    }
    else if(t[p<<1|1].maxx>=v){
        ans=ask(p<<1|1,v);
    }
    t[p].maxx=max(t[p<<1].maxx,t[p<<1|1].maxx);
    return ans;
}
int main()
{
    int h,w,n;
    while(scanf("%d%d%d",&h,&w,&n)!=EOF){
        int f;
        build(1,1,min(h,n),w);
        for(int i=1;i<=n;i++){
            scanf("%d",&f);
            printf("%d\n",ask(1,f));
        }
        memset(t,0,sizeof(t));
    }
}
