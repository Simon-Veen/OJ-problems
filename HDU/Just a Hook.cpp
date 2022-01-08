#include<cstdio>
const int MAXN=1e5+10;
struct segement{
    int l,r,num;
    int lazy;
}t[MAXN<<2];
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    t[p].lazy=0;
    if(l==r){
        t[p].num=1;
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    t[p].num=t[p<<1].num+t[p<<1|1].num;
}
void pushdown(int p){
    if(t[p].lazy){
        t[p<<1].num=(t[p<<1].r-t[p<<1].l+1)*t[p].lazy;
        t[p<<1|1].num=(t[p<<1|1].r-t[p<<1|1].l+1)*t[p].lazy;
        t[p<<1].lazy=t[p<<1|1].lazy=t[p].lazy;
        t[p].lazy=0;
    }
}
void change(int p,int l,int r,int c){
    if(l<=t[p].l&&t[p].r<=r){
        t[p].num=(t[p].r-t[p].l+1)*c;
        t[p].lazy=c;
        return;
    }
    pushdown(p);
    int mid=t[p].l+t[p].r>>1;
    if(l<=mid){
        change(p<<1,l,r,c);
    }
    if(r>mid){
        change(p<<1|1,l,r,c);
    }
    t[p].num=t[p<<1].num+t[p<<1|1].num;
}
int ask(int p){
    return t[p].num;
}

int main()
{
    int _;
    scanf("%d",&_);
    for(int i=1;i<=_;i++){
        int n;
        scanf("%d",&n);
        build(1,1,n);
        int k;
        scanf("%d",&k);
        int f,t,c;
        for(int i=1;i<=k;i++){
            scanf("%d%d%d",&f,&t,&c);
            change(1,f,t,c);
        }
        int ans=ask(1);
        printf("Case %d: The total value of the hook is %d.\n",i,ans);
    }
}