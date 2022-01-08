#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN=5e3+10;
long long int a[MAXN];

struct tree{
    int l,r,num;
}t[MAXN*4];

void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    t[p].num=0;
    if(l==r){
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}
void change(int v,int p){

    if(t[p].l==t[p].r&&t[p].l==v){
        t[p].num=1;
        return;
    }
    int mid=(t[p].l+t[p].r)>>1;
    if(v<=mid)change(v,p<<1);
    if(v>mid)change(v,p<<1|1);
    t[p].num=t[p<<1].num+t[p<<1|1].num;
}
int ask(int p,int l,int r){

    if(l<=t[p].l&&t[p].r<=r){
        return t[p].num;
    }
    int mid=(t[p].l+t[p].r)>>1;
    int sum=0;
    if(l<=mid){
        sum+=ask(p<<1,l,r);
    }
    if(r>mid){
        sum+=ask(p<<1|1,l,r);
    }
    return sum;

}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        build(1,0,n-1);
        long long int s=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            //线段树写法62ms
            change(a[i],1);
            s+=ask(1,a[i]+1,n-1);
        }
        /*
        暴力写法109ms
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i]>a[j]){
                    sum++;
                }
            }
        }

        */
        long long int ans=s;
        for(int i=1;i<n;i++){
            s=s-a[i]+(n-1-a[i]);
            ans=min(ans,s);
        }
        printf("%lld\n",ans);
        memset(t,0,sizeof(t));
    }
}
