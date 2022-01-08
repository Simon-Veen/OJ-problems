#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
const int MAXN=2e5+10;

struct tree{
    int l,r;
    int num;
}t[MAXN<<2];
int a[MAXN];
char b[2];
void build(int p,int l,int r){
    if(l==r){
        t[p].num=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    t[p].num=max(t[p<<1].num,t[p<<1|1].num);
}
void change(int p,int num,int v){
    if(t[p].l==t[p].r&&t[p].l==num){
        t[p].num=v;
        return;
    }
    int mid=(t[p].l+t[p].r)>>1;
    change(p<<1,num,v);
    change(p<<1|1,num,v);
    t[p].num=max(t[p<<1].num,t[p<<1|1].num);
}
int ask(int p,int l,int r){

    if(l<=t[p].l&&t[p].r<=r){
        return t[p].num;
    }
    int mid=(t[p].l+t[p].r)>>1;
    int sum=0;
    if(l<=mid)sum=max(sum,ask(p<<1,l,r));
    if(r>mid) sum=max(sum,ask(p<<1|1,l,r));
    return sum;
}


int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        build(1,1,n);
        int f,z;
        for(int i=1;i<=m;i++){
            scanf("%s %d %d",b,&f,&z);
            if(b[0]=='Q'){
                printf("%d\n",ask(1,f,z));
            }
            else if(b[0]=='U'){
                change(1,f,z);
            }
        }
        memset(t,0,sizeof(t));
    }
}
