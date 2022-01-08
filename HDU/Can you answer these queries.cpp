#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

#define LL long long
#define lson p<<1 
#define rson p<<1|1

const int MAXN=1e5+10;
struct sege{
    int l,r;
    LL num;
}t[MAXN<<2];
LL x[MAXN];
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    if(l==r){
        t[p].num=x[l];
        return;
    }
    int mid=l+r>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
    t[p].num=t[lson].num+t[rson].num;  
}
void change(int p,int l,int r)
{
    if(t[p].num==t[p].r-t[p].l+1)return;  
    if(t[p].l==t[p].r){
        t[p].num=sqrt(t[p].num);   
        return;
    }
    int mid=t[p].l+t[p].r>>1;
    if(l<=mid){
        change(lson,l,r);
    }
    if(r>mid){
        change(rson,l,r);
    }
    t[p].num=t[lson].num+t[rson].num;
}
LL ask(int p,int l,int r){
    if(l<=t[p].l&&t[p].r<=r)return t[p].num;
    int mid=t[p].l+t[p].r>>1;
    LL sum=0;
    if(l<=mid){
        sum+=ask(lson,l,r);
    }
    if(r>mid){
        sum+=ask(rson,l,r);
    }
    return sum;
}
int main()
{
    int n,cnt=1;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
        build(1,1,n);
        int m;
        scanf("%d",&m);
        int f,to,op;
        printf("Case #%d:\n",cnt++);
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&op,&f,&to);
            if(op==1){
                printf("%lld\n",ask(1,min(f,to),max(f,to)));
            }
            else{
                change(1,min(f,to),max(f,to));
            }
        }
        printf("\n");
    }
}

