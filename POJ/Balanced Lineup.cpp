#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=5e4+10;

struct sege{
    int l,r,maxx,minn;
}t[MAXN<<2];
int x[MAXN];
void build(int p,int l,int r){
    t[p].l=l;
    t[p].r=r;
    if(l==r){
        t[p].maxx=t[p].minn=x[l];
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    t[p].maxx=max(t[p<<1].maxx,t[p<<1|1].maxx);
    t[p].minn=min(t[p<<1].minn,t[p<<1|1].minn);
}
int askmaxx(int p,int l,int r){
    if(l<=t[p].l&&t[p].r<=r){
        return t[p].maxx;
    }
    int mid=t[p].l+t[p].r>>1;
    int big=0;
    if(l<=mid){
        big=askmaxx(p<<1,l,r);

    }
    if(r>mid){
        big=max(big,askmaxx(p<<1|1,l,r));
    }
    return big;
}
int askminn(int p,int l,int r){
    if(l<=t[p].l&&t[p].r<=r){
        return t[p].minn;
    }
    int mid=t[p].l+t[p].r>>1;
    int big=2e9;
    if(l<=mid){
        big=askminn(p<<1,l,r);
    }
    if(r>mid){
        big=min(big,askminn(p<<1|1,l,r));
    }
    return big;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&x[i]);
    }
    build(1,1,n);
    int f,t;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&f,&t);
        printf("%d\n",askmaxx(1,f,t)-askminn(1,f,t));
    }
}
